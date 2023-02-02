
#include "Variables.hh"

bool OpenBrave() {

	ZeroMemory(&cnVariables::variablesInstance->si, sizeof(cnVariables::variablesInstance->si));

	ZeroMemory(&cnVariables::variablesInstance->pi, sizeof(cnVariables::variablesInstance->pi));

	cnVariables::variablesInstance->bProcess = CreateProcess(L"C:\\Program Files\\BraveSoftware\\Brave-Browser\\Application\\brave.exe",
		NULL, NULL, NULL, FALSE, 0, NULL, NULL, &cnVariables::variablesInstance->si, &cnVariables::variablesInstance->pi);

	if (cnVariables::variablesInstance->bProcess == FALSE) {

		MessageBox(NULL, L"Error the open Brave", L"Error", MB_OK | MB_ICONERROR);

		return false;
	}

	return true;
}

void CreateTab() {

	cnVariables::variablesInstance->ip.ki.wVk = VK_CONTROL;
	cnVariables::variablesInstance->ip.ki.dwFlags = 0;
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

	cnVariables::variablesInstance->ip.ki.wVk = 'T';
	cnVariables::variablesInstance->ip.ki.dwFlags = 0;
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

	cnVariables::variablesInstance->ip.ki.wVk = 'T';
	cnVariables::variablesInstance->ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

	cnVariables::variablesInstance->ip.ki.wVk = VK_CONTROL;
	cnVariables::variablesInstance->ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

}

void CloseTab() {

	cnVariables::variablesInstance->ip.ki.wVk = VK_CONTROL;
	cnVariables::variablesInstance->ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

	cnVariables::variablesInstance->ip.ki.wVk = 'W';
	cnVariables::variablesInstance->ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

	cnVariables::variablesInstance->ip.ki.wVk = 'W';
	cnVariables::variablesInstance->ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

	cnVariables::variablesInstance->ip.ki.wVk = VK_CONTROL;
	cnVariables::variablesInstance->ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &cnVariables::variablesInstance->ip, sizeof(INPUT));

}