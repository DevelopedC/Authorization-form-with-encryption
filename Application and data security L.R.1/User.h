#pragma once

using namespace System;

// Table 1, login information
public ref class LoginData
{
public:
	String^ email;
	String^ hash;
	String^ salt;
};

// Table 2, user data
public ref class UserData
{
public:
	int id;
	String^ name;
	String^ phone;
	String^ addres;
};

