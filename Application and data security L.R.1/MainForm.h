#pragma once

#include <string>

#include "User.h"
#include "MakeHash.h"
#include "ManagementDB.h"
#include <msclr/marshal_cppstd.h>

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
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Login;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ email;
	private: System::Windows::Forms::TextBox^ password;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ Sign_in;
	private: System::Windows::Forms::LinkLabel^ registration;

 
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
			this->Login = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->registration = (gcnew System::Windows::Forms::LinkLabel());
			this->Sign_in = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Login
			// 
			this->Login->AutoSize = true;
			this->Login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Login->Location = System::Drawing::Point(146, 5);
			this->Login->Name = L"Login";
			this->Login->Size = System::Drawing::Size(98, 29);
			this->Login->TabIndex = 0;
			this->Login->Text = L"Login in";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Email";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Password";
			// 
			// email
			// 
			this->email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->email->Location = System::Drawing::Point(90, 52);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(226, 29);
			this->email->TabIndex = 3;
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password->Location = System::Drawing::Point(90, 100);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(226, 29);
			this->password->TabIndex = 4;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->registration);
			this->panel1->Controls->Add(this->Sign_in);
			this->panel1->Controls->Add(this->password);
			this->panel1->Controls->Add(this->Login);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->email);
			this->panel1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(46, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(357, 224);
			this->panel1->TabIndex = 5;
			// 
			// registration
			// 
			this->registration->AutoSize = true;
			this->registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->registration->Location = System::Drawing::Point(215, 187);
			this->registration->Name = L"registration";
			this->registration->Size = System::Drawing::Size(101, 24);
			this->registration->TabIndex = 6;
			this->registration->TabStop = true;
			this->registration->Text = L"registration";
			this->registration->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::registration_LinkClicked);
			// 
			// Sign_in
			// 
			this->Sign_in->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->Sign_in->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Sign_in->Location = System::Drawing::Point(90, 150);
			this->Sign_in->Name = L"Sign_in";
			this->Sign_in->Size = System::Drawing::Size(226, 34);
			this->Sign_in->TabIndex = 5;
			this->Sign_in->Text = L"Sign in";
			this->Sign_in->UseVisualStyleBackColor = false;
			this->Sign_in->Click += gcnew System::EventHandler(this, &MainForm::Sign_in_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(471, 248);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->Text = L"LoginForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	// Converting System::String^ to std::string
	private: std::string ToStdString(System::String^ str)
	{
		return msclr::interop::marshal_as<std::string>(str);
	}

	public: ManagementDB^ db_conn = nullptr;
	public: bool authorized = 0;
	private: System::Void Sign_in_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ email = this->email->Text;
		String^ password = this->password->Text;

		// check for emptiness
		if (email->Length == 0 || password->Length == 0)
		{
			MessageBox::Show("Please enter email and password",
				"Email or Password Empty", MessageBoxButtons::OK);
			return;
		}
		 
		try
		{
			// connect to the database
			db_conn = gcnew ManagementDB(email);
			
			if (db_conn->GetHashSalt())
			{
				string SaltDB = ToStdString(db_conn->getSalt());
				string StrConvPass = ToStdString(password);

				// get a hashed password
				String^ hashed_password = MakeHash::hash_password(StrConvPass, SaltDB);

				// hash comparison
				if (String::Compare(hashed_password, db_conn->getHash()) == 0)
				{
					authorized = 1;
					this->Close();
				}
				else
				{
					MessageBox::Show("Email or password is incorrect",
						"Email or Password Empty", MessageBoxButtons::OK);
				}
			}
			else
			{
				MessageBox::Show("Email or password is incorrect",
					"Email or Password Empty", MessageBoxButtons::OK);
			}
		}
		catch (Exception^ )
		{
			MessageBox::Show("Database request execution error",
				"Error DB", MessageBoxButtons::OK);
			Application::Exit();
		}
	}

	public: bool switchToRegister = false;
	private: System::Void registration_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) 
	{
		this->switchToRegister = true;
		this->Close();
	}
};
}
