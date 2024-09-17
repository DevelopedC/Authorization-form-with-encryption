#pragma once

namespace ApplicationanddatasecurityLR1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Ñâîäêà äëÿ WorkPage
	/// </summary>
	public ref class WorkPage : public System::Windows::Forms::Form
	{
	public:
		bool demoVersionVariant;

		WorkPage(bool dVersionV) : demoVersionVariant(dVersionV)
		{
			InitializeComponent();
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~WorkPage()
		{
			if (components)
			{
				delete components;
			}
		}
		  
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ â³äêğèòèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ñòâîğèòèÔàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ â³äêğèòèToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ çáåğåãòèToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
 
	protected:
		 
	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->â³äêğèòèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñòâîğèòèÔàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->â³äêğèòèToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çáåğåãòèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->â³äêğèòèToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1048, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// â³äêğèòèToolStripMenuItem
			// 
			this->â³äêğèòèToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ñòâîğèòèÔàéëToolStripMenuItem,
					this->â³äêğèòèToolStripMenuItem1, this->çáåğåãòèToolStripMenuItem
			});
			this->â³äêğèòèToolStripMenuItem->Name = L"â³äêğèòèToolStripMenuItem";
			this->â³äêğèòèToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->â³äêğèòèToolStripMenuItem->Text = L"Ôàéë";
			// 
			// ñòâîğèòèÔàéëToolStripMenuItem
			// 
			this->ñòâîğèòèÔàéëToolStripMenuItem->Name = L"ñòâîğèòèÔàéëToolStripMenuItem";
			this->ñòâîğèòèÔàéëToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->ñòâîğèòèÔàéëToolStripMenuItem->Text = L"Ñòâîğèòè";
			this->ñòâîğèòèÔàéëToolStripMenuItem->Click += gcnew System::EventHandler(this, &WorkPage::ñòâîğèòèÔàéëToolStripMenuItem_Click);
			// 
			// â³äêğèòèToolStripMenuItem1
			// 
			this->â³äêğèòèToolStripMenuItem1->Name = L"â³äêğèòèToolStripMenuItem1";
			this->â³äêğèòèToolStripMenuItem1->Size = System::Drawing::Size(126, 22);
			this->â³äêğèòèToolStripMenuItem1->Text = L"Â³äêğèòè";
			this->â³äêğèòèToolStripMenuItem1->Click += gcnew System::EventHandler(this, &WorkPage::â³äêğèòèToolStripMenuItem1_Click);
			// 
			// çáåğåãòèToolStripMenuItem
			// 
			this->çáåğåãòèToolStripMenuItem->Name = L"çáåğåãòèToolStripMenuItem";
			this->çáåğåãòèToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->çáåğåãòèToolStripMenuItem->Text = L"Çáåğåãòè";
			this->çáåğåãòèToolStripMenuItem->Click += gcnew System::EventHandler(this, &WorkPage::çáåğåãòèToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 27);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(1024, 628);
			this->textBox1->TabIndex = 3;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// WorkPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1048, 667);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"WorkPage";
			this->Text = L"WorkPage";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: String^ FileName = "";
	private: System::Void ñòâîğèòèÔàéëToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Open the dialog to select where to save the new file
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Text Files|*.txt|All Files|*.*";

		if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			try
			{
				// unlock the input form
				textBox1->ReadOnly = false;

				// clean the form
				textBox1->Text = "";

				// write the file path
				FileName = saveFileDialog1->FileName;
				MessageBox::Show("File has been created and is open for writing", "OK", MessageBoxButtons::OK);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Failed to create a file", "Error", MessageBoxButtons::OK);
			}
		}
	}

	private: System::Void â³äêğèòèToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			// write the file path
			FileName = openFileDialog1->FileName;

			try
			{
				// unlock the input form
				textBox1->ReadOnly = false;

				// open a file for recording
				StreamReader^ file_r = File::OpenText(FileName);

				// read data from a file
				textBox1->Text = file_r->ReadToEnd();

				file_r->Close();

				MessageBox::Show("File is open for writing", "OK", MessageBoxButtons::OK);
			}
			catch (Exception^ e)
			{
				MessageBox::Show("File was not opened", "Error", MessageBoxButtons::OK);
			}
		}
	}
	
	private: System::Void çáåğåãòèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (demoVersionVariant)
		{
			MessageBox::Show("Please register to receive the full version", "Demo version", MessageBoxButtons::OK);
			return;
		}

		if (String::IsNullOrEmpty(FileName))
		{
			MessageBox::Show("The file to save was not found", "Error", MessageBoxButtons::OK);
			return;
		}
		
		try
		{
			// Open file for recording
			StreamWriter^ file_w = gcnew StreamWriter(FileName);
			// Write text from the TextBox to a file
			file_w->Write(textBox1->Text);

			file_w->Close();

			MessageBox::Show("File has been saved", "OK", MessageBoxButtons::OK);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error saving file", "Error", MessageBoxButtons::OK);
		}
			 
	}
};
}
