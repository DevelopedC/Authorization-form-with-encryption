#pragma once
#include <string>
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

	String^ getSalt(){
		return SaltDB;
	}

	String^ getHash(){
		return HashDB;
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