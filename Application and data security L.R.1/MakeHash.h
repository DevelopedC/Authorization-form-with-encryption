#pragma once

#include <windows.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>

#include <openssl/evp.h>
#include <openssl/rand.h>
 
class MakeHash
{
public:

    // Function for converting bytes to a string in hex format
    static System::String^ to_hex_string(const unsigned char* data, size_t length)
    {
        std::ostringstream oss;
        for (size_t i = 0; i < length; ++i) {
            oss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
        }

        return gcnew System::String(oss.str().c_str());
    }

    // Function for salt generation
    static System::String^ generate_salt(size_t length)
    {
        std::vector<unsigned char> salt(length);
        if (RAND_bytes(salt.data(), length) != 1)
        {
            throw std::runtime_error("An error occurred when generating salt.");
        }
        return to_hex_string(salt.data(), length);
    }

    // Function for hashing a string (password + salt)
    static System::String^ hash_password(const std::string& password, const std::string& salt)
    {
        // Concatenate the password and salt
        std::string salted_password = password + salt;

        // Using SHA-256 for hashing
        unsigned char hash[EVP_MAX_MD_SIZE];
        unsigned int hash_len;

        EVP_MD_CTX* context = EVP_MD_CTX_new();
        EVP_DigestInit_ex(context, EVP_sha256(), nullptr);
        EVP_DigestUpdate(context, salted_password.c_str(), salted_password.size());
        EVP_DigestFinal_ex(context, hash, &hash_len);
        EVP_MD_CTX_free(context);

        // Converting the hash to a string in hex format
        return to_hex_string(hash, hash_len);
    }
};