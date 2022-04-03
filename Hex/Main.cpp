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
		std::cout << "[Hex] Minecraft instance not found!" << std::endl;
		return;
	}
	std::cout << "[Hex] Minecraft instance found!" << std::endl;
	std::cout << "[Hex] Hecks injected successfully!!" << std::endl;

	bool activated = false;
	while (true)
	{
		if (activated)
		{
			try
			{
				setSprinting(true);
				playerJump(false);
			}
			catch (std::exception&)
			{
				std::cout << "exception..." << std::endl;
			}
			Sleep(30);
		}

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			while (GetAsyncKeyState(VK_NUMPAD0)) {}
			activated = !activated;
		}
	}
}

