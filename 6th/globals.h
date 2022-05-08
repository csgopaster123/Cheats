#pragma once
#include <cstdint>
#include <cstddef>
namespace globals
{
	inline std::uintptr_t clientAddress = 0;
	inline bool Glow = false;
	inline bool FovChanger = false;
	inline bool Bunnyhop = false;
	inline float glowColor[] = { 1.f, 0.f, 0.f, 1.f };
	inline bool radar = false;
	inline bool TriggerBot = false;
	inline int EFOV = 0;
}

namespace offsets 
{

	constexpr ::std::ptrdiff_t m_iHealth = 0x100;
	constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDB75DC;
	constexpr ::std::ptrdiff_t m_iFOV = 0x31F4;
	constexpr ::std::ptrdiff_t m_iCrosshairId = 0x11838;
	constexpr ::std::ptrdiff_t m_iDefaultFOV = 0x333C;
	constexpr ::std::ptrdiff_t m_iTeamNum = 0xF4;
	constexpr ::std::ptrdiff_t m_fFlags = 0x104;
	constexpr ::std::ptrdiff_t dwForceJump = 0x527D390;
	constexpr ::std::ptrdiff_t dwEntityList = 0x4DD347C;
	constexpr ::std::ptrdiff_t dwForceAttack = 0x3203948;
	constexpr ::std::ptrdiff_t m_bSpotted = 0x93D;
	constexpr ::std::ptrdiff_t m_zoomLevel = 0x33E0;
	constexpr ::std::ptrdiff_t m_hViewModel = 0x3308;
	constexpr ::std::ptrdiff_t m_bIsScoped = 0x9974;
}