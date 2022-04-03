#include "Main.h"

void init() 
{
    DWORD id = GetCurrentProcessId();
    if (id == NULL) 
    {
        MessageBox(NULL, "Invalid process ID.", "Hex", MB_ICONERROR);
        exit(-1);
    }

    HWND window = FindWindow(NULL, "Minecraft 1.8.9");
    if (!window) 
    {
        MessageBox(NULL, "Minecraft instance not found make sure you are playing 1.8.9.", "Hex", MB_ICONERROR);
    }

    jsize vmCount;
    if (JNI_GetCreatedJavaVMs(&mc.vm, 1, &vmCount) != JNI_OK || vmCount == 0) 
    {
        MessageBoxA(NULL, "JVM not found.", "Hex", MB_ICONERROR | MB_OK);
        return;
    }

    jint res = mc.vm->GetEnv((void**)&mc.env, JNI_VERSION_1_6);
    if (res == JNI_EDETACHED) 
    {
        res = mc.vm->AttachCurrentThread((void**)&mc.env, nullptr);
    }

    if (res != JNI_OK) 
    {
        MessageBoxA(NULL, "Failed to create a java environnement.", "Hex", MB_ICONERROR | MB_OK);
        return;
    }

    if (mc.env != nullptr) 
    {
        run();
    }
    else 
    {
        MessageBoxA(NULL, "Failed to create a java environnement.", "Hex", MB_ICONERROR | MB_OK);
        return;
    }

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

