#include <Windows.h>
#include "MainForm.h"
#include "WorkPage.h"
#include "RegisterForm.h"
 
using namespace ApplicationanddatasecurityLR1;
using namespace System;
using namespace System::Windows::Forms;
 
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ManagementDB^ user = nullptr;
	bool continueLoop = true;

	while (continueLoop)
	{
		// show the login form
		MainForm login;
		login.ShowDialog();

		if (login.switchToRegister)
		{
			// show the registration form
			RegisterForm registerForm;
			registerForm.ShowDialog();
		}
		else if (login.authorized == 1 ||
				login.demoVersionVariant)
		{
			// show a custom form
			WorkPage wp(login.demoVersionVariant);
			Application::Run(% wp);
			continueLoop = false;
		}
		else
		{
			continueLoop = false;
		}
	}
 
	return 0;
}

