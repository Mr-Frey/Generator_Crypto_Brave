
#include "MyProject.hh"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	MessageBox(NULL, L"To stop the program, press the \"Caps Lock\" and hold until you close all brave tabs!",
		L"ATENTION", MB_OK | MB_ICONEXCLAMATION);

	MessageBox(NULL, L"Brave limits generation per hour, so the result is not great. This software was developed "\
		"with the intention of applying my learning, not making an extra source of income.",
		L"Warning", MB_OK | MB_ICONWARNING);

	cnVariables::variablesInstance->ip.type = INPUT_KEYBOARD;

	cnVariables::variablesInstance->ip.ki.wScan = 0;

	cnVariables::variablesInstance->ip.ki.time = 0;

	cnVariables::variablesInstance->ip.ki.dwExtraInfo = 0;

	while ((GetAsyncKeyState(VK_CAPITAL) & 0x0001) == 0) {

		if (OpenBrave() != true) break;

		Sleep(1100);

		for (int j = 0; j < 7; j++) {
			CreateTab();
			Sleep(500);
		}

		for (int k = 0; k < 8; k++) {
			CloseTab();
			Sleep(200);
		}

	}

	return 0;
}