#include "stdinc.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
#ifdef _DEBUG
		FILE* fp;
		AllocConsole();
		AttachConsole(GetCurrentProcessId());
		if (!freopen_s(&fp, "CONOUT$", "w", stdout)) fclose(fp);
		if (!freopen_s(&fp, "CONOUT$", "w", stderr)) fclose(fp);
		if (!freopen_s(&fp, "CONIN$", "r", stdin))   fclose(fp);
#endif

		// Simply load the SKSE library
		// Main work is done in SDLLP
		// It basically installs a proxy for dinput8.dll
		// d3d9.dll would have been better, but it's already used for ENB proxies.
		LoadLibraryA("skse_steam_loader.dll");
	}

	return TRUE;
}
