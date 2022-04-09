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
				setKeyBindAttack(true);
				//setRightClickDelayTimer(0);
				//setSprinting(true);
				//playerJump();
				/*
				std::cout << "X: ";
				std::cout << getPosX() << std::endl;
				std::cout << "Y: ";
				std::cout << getPosY() << std::endl;
				std::cout << "Z: ";
				std::cout << getPosZ() << std::endl;
				*/
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

		if (GetAsyncKeyState(VK_END))
		{
			while (GetAsyncKeyState(VK_END)) {}
			sendChatMessage(mc.env->NewStringUTF("heck"));
			setPitch(90.0f);
		}

		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			while (GetAsyncKeyState(VK_NUMPAD1)) {}
			//Fullbright
			setGammaSetting(1000.0f);
		}

		// only works on MP
		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			while (GetAsyncKeyState(VK_NUMPAD2)) {}
			logout();
		}

		if (GetAsyncKeyState(VK_NUMPAD3))
		{
			while (GetAsyncKeyState(VK_NUMPAD3)) {}
		}
	}
}

