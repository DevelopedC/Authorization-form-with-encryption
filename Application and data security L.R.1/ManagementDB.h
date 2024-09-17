#pragma once
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "User.h"

using namespace System;
using namespace System::Data::SqlClient;

public ref class ManagementDB
{
private:
	String^ connString = "Data Source = DMITRIYPC\\SQL_EXP; Initial Catalog = UserDataBase; Integrated Security = True; Encrypt = False";

	String^ sqlGetHashSalt = "SELECT hash, salt FROM dbo.DataHash WHERE email = @email";

	String^ sqlSearchNumbEmails = "SELECT COUNT(*) FROM dbo.DataHash WHERE email = @email";

	String^ sqlGetUserData = R"(SELECT dbo.Users.* FROM dbo.Users JOIN dbo.DataHash ON 
					dbo.Users.id = dbo.DataHash.id	WHERE dbo.DataHash.email = @email)";

	String^ sqlSetNewUser = "INSERT INTO dbo.DataHash (email, hash, salt) VALUES(@email, @hash, @salt)";

	String^ sqlSetDataUser = "INSERT INTO Users(name, phone, address) VALUES(@name, @phone, @address)";

	String^ sqlBlockUser = R"(UPDATE Users
								SET lockedAt = @lockedAt,
								lockDuration = @lockDuration
								FROM Users
								INNER JOIN dbo.DataHash ON dbo.Users.id = dbo.DataHash.id
								WHERE dbo.DataHash.email = @email)";

	String^ sqlSelectBlockUser = R"(SELECT lockedAt, lockDuration
                              FROM Users u
                              INNER JOIN DataHash dh ON u.id = dh.id
                              WHERE dh.email = @email)";

	SqlConnection^ sqlConn;
	String^ SaltDB;
	String^ HashDB;
	String^ email;

public:

	ManagementDB()
	{   // create and open a database connection
		sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();
	}

	ManagementDB(String^ user_email) : ManagementDB()
	{
		email = user_email;
	}

	bool CreateNewUser(UserData^ usrData, LoginData^ logData)
	{
		SqlCommand^ command = gcnew SqlCommand(sqlSearchNumbEmails, sqlConn);
		command->Parameters->AddWithValue("@email", logData->email);

		// if the email already exists
		if ((int)command->ExecuteScalar() > 0)
		{
			return 0;
		}

		command = gcnew SqlCommand(sqlSetNewUser, sqlConn);

		command->Parameters->AddWithValue("@email", logData->email);
		command->Parameters->AddWithValue("@hash", logData->hash);
		command->Parameters->AddWithValue("@salt", logData->salt);

		// ñreate a new user
		command->ExecuteNonQuery();

		command = gcnew SqlCommand(sqlSetDataUser, sqlConn);

		command->Parameters->AddWithValue("@name", usrData->name);
		command->Parameters->AddWithValue("@phone", usrData->phone);
		command->Parameters->AddWithValue("@address", usrData->addres);

		// add user data
		command->ExecuteNonQuery();

		return 1;
	}


	bool GetHashSalt()
	{
		SqlCommand^ command = gcnew SqlCommand(sqlSearchNumbEmails, sqlConn);
		command->Parameters->AddWithValue("@email", email);

		// if the email already exists
		if ((int)command->ExecuteScalar() < 1)
		{
			return false;
		}

		command = gcnew SqlCommand(sqlGetHashSalt, sqlConn);
		command->Parameters->AddWithValue("@email", email);

		// get password data
		SqlDataReader^ reader = command->ExecuteReader();

		if (reader->Read())
		{
			// get hash
			HashDB = reader->GetString(0);
			// get salt
			SaltDB = reader->GetString(1);

			reader->Close();
			return true;
		}
		else
		{
			reader->Close();
			return false;
		}
	}

	UserData^ GetUserInfo()
	{
		// get and return user data
		SqlCommand command(sqlGetUserData, sqlConn);
		command.Parameters->AddWithValue("@email", email);

		SqlDataReader^ reader = command.ExecuteReader();

		UserData^ usrData;
		if (reader->Read())
		{
			usrData = gcnew UserData;
			usrData->id = reader->GetInt32(0);
			usrData->name = reader->GetString(1);
			usrData->phone = reader->GetString(2);
			usrData->addres = reader->GetString(3);
		}
		reader->Close();

		return usrData;
	}

	String^ getSalt() {
		return SaltDB;
	}

	String^ getHash() {
		return HashDB;
	}

	void BlockUser()
	{
		SqlCommand^ command = gcnew SqlCommand(sqlBlockUser, sqlConn);

		// Use DateTime for parameters
		command->Parameters->AddWithValue("@lockedAt", DateTime::Now);
		command->Parameters->AddWithValue("@lockDuration", 30);
		command->Parameters->AddWithValue("@email", email);

		command->ExecuteNonQuery();
	}

	bool SelectBlockUser()
	{
		SqlCommand^ command = gcnew SqlCommand(sqlSelectBlockUser, sqlConn);

		command->Parameters->AddWithValue("@email", email);

		SqlDataReader^ reader = command->ExecuteReader();

		String^ lockedAt = nullptr;
		int lockDuration = 0;

		if (reader->Read())
		{
			// Checking for NULL for the date
			if (!reader->IsDBNull(0)){
				lockedAt = reader->GetDateTime(0).ToString();
			}

			// Checking for NULL for the duration of the lock
			if (!reader->IsDBNull(1)){
				lockDuration = reader->GetInt32(1);
			}
		}

		reader->Close();

		if (!String::IsNullOrEmpty(lockedAt))
		{
			DateTime lockedAtDateTime;
			DateTime::TryParse(lockedAt, lockedAtDateTime);

			TimeSpan duration = TimeSpan::FromMinutes(lockDuration);
			DateTime unlockAtDateTime = lockedAtDateTime.Add(duration);

			DateTime currentDateTime = DateTime::Parse(DateTime::Now.ToString());

			// Comparison of the received time with the current one
			return unlockAtDateTime > currentDateTime;
		}

		return false;
	}

	~ManagementDB()
	{
		if (sqlConn != nullptr)
		{
			if (sqlConn->State == System::Data::ConnectionState::Open)
			{
				sqlConn->Close();
			}
			delete sqlConn;
			sqlConn = nullptr;
		}
	}
};