#include <Windows.h>

#include "MainForm.h"

//#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "Core.h"

using namespace std;
using namespace Core;

int main_t()
{
	int wid, hei;
	int x, y, im = 0;

	cout << "Enter width height = "; cin >> wid >> hei;
	
	Core::cMatrix Mat(wid, hei);
	printf("Matrix %d x %d created\n", wid, hei);

	for (y = 0; y < hei; y++) {
		for (x = 0; x < wid; x++) {
			Mat.set(x, y, im);
			cout << setfill('0')<<setw(2)<<Mat.get(x, y) << " ";
			im++;
		}
		cout << endl;
	}
	cout << endl;

	while (1)
	{
		cout << "enter x y: "; cin >> x >> y;
		if (x < 0 || y < 0) break;
		printf("Mas[%d, %d] = %d\n\n", x, y, Mat.get(x, y));
	}

	y = 0;
	while (1)
	{
		cout << "Enter Row: "; cin >> y;
		if (y < 0) break;
		cout << Mat.get_productRow(y)<<"\n\n";
	}

	Mat.~cMatrix();

	return 0;
}
#endif // DEBUG

using namespace System;

[STAThreadAttribute]
int main()
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

#ifdef DEBUG 
	system("cls");
	cout << "Welcome in DEBUG mode!\n";

	try
	{
		main_t();
	}
	catch (char* exc)
	{
		int ch = 0;
		cout << "\n" << exc << "\nExit(0) or try again?";
		cin >> ch;
		if (ch != 0) {
			cout << "Restarting...\n";
			main();
		}
	}

	cout << endl;
	system("pause");

#else
	FreeConsole();
	
	Proj::MainForm MF;

	try
	{
		System::Windows::Forms::Application::Run(% MF);
	}
	catch (char *exc)
	{
		System::Windows::Forms::MessageBox::Show(gcnew System::String(exc), "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}

	
#endif // DEBUG 

	return 0;
}

