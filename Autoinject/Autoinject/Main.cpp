#include "stdinc.h"

BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
	if (DLL_PROCESS_ATTACH)
	{
		// Simply load the SKSE library
		// Main work is done in SDLLP
		// It basically installs a proxy for dinput8.dll
		// d3d9.dll would have been better, but it's already used for ENB proxies.
		LoadLibraryA("skse_steam_loader.dll");
	}

	return TRUE;
}
