/*
 This file is part of GMS-83-DLL.

 GMS-83-DLL is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 GMS-83-DLL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with Foobar. If not, see <https://www.gnu.org/licenses/>.
 */

#include <Windows.h>
#include <memedit.h>
#include "memory_map.h"

// main thread
DWORD WINAPI MainProc(LPVOID lpParam) {
    if (strcmp(BUILD_REGION, "GMS") == 0) {
        auto *instance = reinterpret_cast<unsigned int *>(C_CONFIG_SYS_OPT_WINDOWED_MODE);
        *instance = 0;
    } else if (strcmp(BUILD_REGION, "JMS") == 0) {
        MemEdit::WriteBytes(0x00ADA8D7+0x94, new BYTE[7]{0xC7, 0x45, 0xDC, 0x00, 0x00, 0x00, 0x00}, 7);
    }
    return 0;
}

// dll entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: {
            DisableThreadLibraryCalls(hModule);
            CreateThread(nullptr, 0, &MainProc, nullptr, 0, nullptr);
            break;
        }
    }
    return TRUE;
}