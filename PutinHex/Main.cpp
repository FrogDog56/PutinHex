#include "Main.h"
#include "wrapper.h"
#include <exception>
#include <iostream>

FILE* pFile = nullptr;

void run() 
{
	AllocConsole();
	freopen_s(&pFile, "CONOUT$", "w", stdout);


	if (getMinecraft() == nullptr)
	{
		std::cout << "[PutinHex] Minecraft instance not found!" << std::endl;
		return;
	}
	std::cout << "[PutinHex] Minecraft instance found!" << std::endl;
	std::cout << "[PutinHex] Hecks injected successfully!!" << std::endl;

	bool activated = false;
	while (true) 
	{
		if (activated) 
		{
			setSprinting(true);
			playerJump(false);

			Sleep(30);
		}
		if (GetAsyncKeyState(VK_NUMPAD0) && 0x8000) 
		{
			activated = !activated;
		}
	}

}


