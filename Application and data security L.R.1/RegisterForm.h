#pragma once

#include <msclr/marshal_cppstd.h>

#include "User.h"
#include "ManagementDB.h"
#include "MakeHash.h"

using std::string;

namespace ApplicationanddatasecurityLR1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// —водка дл€ RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbName;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbEmail;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbPhone;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbAddress;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tbConfPassword;
	private: System::Windows::Forms::Button^ bntOK;
	private: System::Windows::Forms::Button^ btnCancel;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPhone = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbAddress = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbConfPassword = (gcnew System::Windows::Forms::TextBox());
			this->bntOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(627, 69);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Register";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(14, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name";
			// 
			// tbName
			// 
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbName->Location = System::Drawing::Point(265, 89);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(374, 35);
			this->tbName->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(14, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 29);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Email";
			// 
			// tbEmail
			// 
			this->tbEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbEmail->Location = System::Drawing::Point(265, 130);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(374, 35);
			this->tbEmail->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(14, 177);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 29);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Phone";
			// 
			// tbPhone
			// 
			this->tbPhone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPhone->Location = System::Drawing::Point(265, 171);
			this->tbPhone->Name = L"tbPhone";
			this->tbPhone->Size = System::Drawing::Size(374, 35);
			this->tbPhone->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(14, 218);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 29);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Address";
			// 
			// tbAddress
			// 
			this->tbAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbAddress->Location = System::Drawing::Point(265, 212);
			this->tbAddress->Name = L"tbAddress";
			this->tbAddress->Size = System::Drawing::Size(374, 35);
			this->tbAddress->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(14, 259);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(120, 29);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Password";
			// 
			// tbPassword
			// 
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPassword->Location = System::Drawing::Point(265, 253);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(374, 35);
			this->tbPassword->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(14, 300);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(210, 29);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Confirm Password";
			// 
			// tbConfPassword
			// 
			this->tbConfPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbConfPassword->Location = System::Drawing::Point(265, 294);
			this->tbConfPassword->Name = L"tbConfPassword";
			this->tbConfPassword->Size = System::Drawing::Size(374, 35);
			this->tbConfPassword->TabIndex = 2;
			// 
			// bntOK
			// 
			this->bntOK->Location = System::Drawing::Point(265, 351);
			this->bntOK->Name = L"bntOK";
			this->bntOK->Size = System::Drawing::Size(184, 38);
			this->bntOK->TabIndex = 3;
			this->bntOK->Text = L"OK";
			this->bntOK->UseVisualStyleBackColor = true;
			this->bntOK->Click += gcnew System::EventHandler(this, &RegisterForm::bntOK_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(455, 351);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(184, 38);
			this->btnCancel->TabIndex = 4;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &RegisterForm::btnCancel_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 404);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->bntOK);
			this->Controls->Add(this->tbConfPassword);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbAddress);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tbPhone);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	 
	
	// Converting System::String^ to std::string
	private: std::string ToStdString(System::String^ str)
	{
		return msclr::interop::marshal_as<std::string>(str);
	}

	private: System::Void bntOK_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// set the user data
		UserData^ userData = gcnew UserData;
		userData->name = tbName->Text;
		userData->phone = tbPhone->Text;
		userData->addres = tbAddress->Text;
		
		// set the password data
		LoginData^ logData = gcnew LoginData;
		logData->email = tbEmail->Text;
		
		String^ password = tbPassword->Text;
		String^ confPassword = tbConfPassword->Text;

		// check for emptiness
		if (userData->name->Length == 0 || logData->email->Length == 0 || userData->phone->Length == 0 ||
			userData->addres->Length == 0 || password->Length == 0 || confPassword->Length == 0)
		{
			MessageBox::Show("Please enter all the fields",
				"On or more empty fields", MessageBoxButtons::OK);
			return;
		}

		// compare entered passwords
		if (String::Compare(password, confPassword) != 0)
		{
			MessageBox::Show("Password and Confirm Password do not match",
				"Password Error", MessageBoxButtons::OK);
			return;
		}
		 
		string cnvrt_password = ToStdString(password);

		// generate a 16-bit salt for the password
		logData->salt = MakeHash::generate_salt(16); // 16 byte
		string generate_salt = ToStdString(logData->salt->ToString());

		// get a hashed password
		logData->hash = MakeHash::hash_password(cnvrt_password, generate_salt);
		
		try
		{
			// connect to the database
			ManagementDB^ db_conn = gcnew ManagementDB();

			// create a new user in the database
			if (!db_conn->CreateNewUser(userData, logData))
			{
				tbEmail->Focus();

				MessageBox::Show("Email name is already in use, try another one",
					"Error", MessageBoxButtons::OK);
			}
			else
			{
				this->Close();
			}
		}
		catch (Exception^ )
		{
			MessageBox::Show("Database request execution error",
				"Error DB", MessageBoxButtons::OK);
			Application::Exit();
		}	 
	}
};
}
