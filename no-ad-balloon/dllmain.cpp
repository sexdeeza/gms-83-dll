#include <Windows.h>
#include <memedit.h>

const DWORD dwWinMain = 0x009F19F2;
const DWORD dwWinMainShowADBalloonConditional = dwWinMain + 0xA3D;

// main thread
VOID __stdcall MainProc()
{
    // Noop Ad Balloon
    MemEdit::WriteBytes(dwWinMainShowADBalloonConditional, new BYTE[1]{0xEB}, 1);
}

// dll entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: {
            DisableThreadLibraryCalls(hModule);
            CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) &MainProc, nullptr, 0, nullptr);
            break;
        }
    }
    return TRUE;
}