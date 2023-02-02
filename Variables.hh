#define WINVER 0x0500

#include <Windows.h>
#include <iostream>

class Variables {
public:
    INPUT ip;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    BOOL bProcess = NULL;
};

namespace cnVariables {

    static Variables* variablesInstance = new Variables();

}

