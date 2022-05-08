#include "hacks.h"
#include "gui.h"
#include "globals.h"
#include <thread>
#define FL_ONGROUND (1 << 0)

using namespace gui;
void Hacks::VisualThread(const Memory& mem) noexcept
{

	while (gui::isRunning) {
		std::this_thread::sleep_for(std::chrono::microseconds(1));
		//Vars
		const auto LocalPlayer = mem.Read<uintptr_t>(globals::clientAddress + offsets::dwLocalPlayer);
		if (!LocalPlayer)
			continue;
		const auto Flags = mem.Read<BYTE>(LocalPlayer + offsets::m_fFlags);
		const auto Fov = mem.Read<int>(LocalPlayer + offsets::m_iFOV);
		const auto Crosshair = mem.Read<int>(LocalPlayer + offsets::m_iCrosshairId);
		const auto LocalTeam = mem.Read<uintptr_t>(LocalPlayer + offsets::m_iTeamNum);
		const auto EnemyInCross = mem.Read<uintptr_t>(globals::clientAddress + offsets::dwEntityList + (Crosshair - 1) * 0.10);
		const auto Entity = mem.Read<uintptr_t>(globals::clientAddress + offsets::dwEntityList + (64 * 0x10));
		const auto EnemyTeam = mem.Read<int>(EnemyInCross + offsets::m_iTeamNum);
		const auto EnemyHealth = mem.Read<int>(EnemyInCross + offsets::m_iHealth);
		const auto Scoped = mem.Read<bool>(LocalPlayer + offsets::m_bIsScoped);



		if (globals::Bunnyhop) {
			if (Flags & FL_ONGROUND && GetAsyncKeyState(VK_SPACE)) {
				mem.Write<DWORD>(globals::clientAddress + offsets::dwForceJump, 6);

			}
		}

		if (globals::radar) {
			for (int i = 0; i < 64; i++) {
				const auto Entity = mem.Read<uintptr_t>(globals::clientAddress + offsets::dwEntityList + (i * 0x10));
				mem.Write<bool>(Entity + offsets::m_bSpotted, true);
			}

		}
		if (globals::FovChanger) {
		mem.Write<int>(LocalPlayer + offsets::m_iFOV, globals::EFOV);
	}
	while (Scoped) {
		mem.Write<int>(LocalPlayer + offsets::m_iFOV, 90);
		break;
	}


		if (globals::TriggerBot) {
			if (EnemyTeam && Crosshair != 0 && Crosshair < 64) {

				if (EnemyHealth != 0 && EnemyHealth < 101) {
					mem.Write<DWORD>(globals::clientAddress + offsets::dwForceAttack, 5);
					Sleep(1);
					mem.Write<DWORD>(globals::clientAddress + offsets::dwForceAttack, 4);
					Sleep(1);
				}


			}
		}

	}




}
		

