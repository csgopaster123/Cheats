#include "gui.h"
#include "hacks.h"
#include <thread>
#include "globals.h"

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow)
{
	Memory mem{ "csgo.exe" };
	globals::clientAddress = mem.GetModuleAddress("client.dll");
	std::thread(Hacks::VisualThread, mem).detach();
	// create gui
	gui::CreateHWindow("6THSense External");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::isRunning)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	// destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}
