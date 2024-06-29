#include "Irondick.h"

// stores the game window structure address
CGameWindow* gGameWindow;

// spoofs the main thread id
BOOL SpoofMainThread()
{
	// gets and validates the static master class
	if (CMaster* pMaster = CMaster::Get())
	{
		// sets the current thread id
		__writefsdword(0x24, pMaster->pSystem->MainThreadId);
		// function succeeded
		return TRUE;
	}
	// function failed
	return FALSE;
}

// the main entry point of the dll thread
DWORD WINAPI Irondick(LPVOID lpParameter)
{
	// logs a message to the debug
	Debug::Log(LOG_DEBUG, "[Irondick] Started successfully.");
	// gets and validates the control structure
	if (CControl* pControl = CControl::Get())
		// logs the current map name
		while (TRUE)
			// logs a message to the debug
			memcpy(&pControl->MapName, "map\\pvp\\riverside\\riverside.bsn", 0x80);
	// gets and validates the static window structure
	// if (gGameWindow = CGameWindow::Get())
	// spoofs the main thread id
	// if (SpoofMainThread())
	// {
	// notifies the debug
	// Debug::Log(LOG_DEBUG, "[Irondick] Successfully spoofed main thread.");
	// gets the static game structure
	// CGame* pGame = CGame::Get();
	// initalizes the map
	// if (pGame->InitMap("map\\pvp\\airport\\airport.bsn"))
	// {
	// logs a message to the debug
	// Debug::Log(LOG_DEBUG, "[Irondick] Map initalized.");
	// }
	// else
	// {
	// logs a message to the debug
	// Debug::Log(LOG_DEBUG, "[Irondick] Map initalization unsuccessful.");
	// }
	// }
	// function succeeded
	return TRUE;
}

// the main entry point of the dll
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	// if the dll is being attached to a process
	// if (fdwReason == DLL_PROCESS_ATTACH)
	// creates a thread to run our dll
	CreateThread(NULL, NULL, Irondick, NULL, NULL, NULL);
	// function succeeded
	return TRUE;
}