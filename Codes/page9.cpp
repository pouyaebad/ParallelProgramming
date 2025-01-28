// Pre-requirement : None
//
// On Windows      : Visual Studio (MSVC)
//

#include <iostream>
#include <Windows.h>

int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    TCHAR cmd[] = TEXT("calc");//The name of an executable file to run as new proc.

    // Start the child process. 
    if (!CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        std::cout << " creating the New Process Failed\n";
        return -1;
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}


// Result: Creates and Runs a New Process Which is Windows Calculator
