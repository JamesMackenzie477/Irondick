// contains functions and methods that directly manipulate ironsight
#include "Ironsight.h"

// various functions used for game debugging
namespace Debug
{
	// logs a given message to a log file stored in the %temp% directory
	// lpCppFile - the file associated with the log message (so the developer can tell where the issue lies).
	// dwType - the type of message to log, ranging from: debug, information, warning, error or fatal.
	// lpMessage - the message to be logged to the log file, it can be a format string with addition variable arguments.
	BOOL Log(DWORD dwType, LPCSTR lpMessage, ...)
	{
		// defines the function return type, calling convention and arguments
		typedef DWORD(__cdecl * _DebugLog)(DWORD, DWORD, DWORD, DWORD, LPCSTR, ...);
		// sets the function address
		_DebugLog DebugLog = (_DebugLog)((__int64)GetModuleHandleW(IMAGE_NAME) + DEBUG_LOG_OFFSET);
		// calls the function and returns the result
		return DebugLog(NULL, NULL, NULL, dwType, lpMessage);
	}
}

// gets the static game window class instance
CGameWindow* CGameWindow::Get()
{
	// defines the function return type, calling convention and arguments
	typedef CGameWindow*(__cdecl * _GetWindowClass)();
	// sets the function address
	_GetWindowClass GetWindowClass = (_GetWindowClass)((__int64)GetModuleHandleW(IMAGE_NAME) + GET_WINDOW_CLASS_OFFSET);
	// calls the function and returns the result
	return GetWindowClass();
	// gets and return the static game window class address cast as a game window pointer
	// return (CGameWindow*)((__int64)GetModuleHandleW(IMAGE_NAME) + WINDOW_CLASS_OFFSET);
}

// gets the static game class instance
CGame* CGame::Get()
{
	// gets and return the static game window class address cast as a game window pointer
	return (CGame*)((__int64)GetModuleHandleW(IMAGE_NAME) + GAME_CLASS_OFFSET);
}

// gets the static system class instance
CMaster* CMaster::Get()
{
	// defines the function return type, calling convention and arguments
	typedef CMaster*(__cdecl * _GetMasterClass)();
	// sets the function address
	_GetMasterClass GetMasterClass = (_GetMasterClass)((__int64)GetModuleHandleW(IMAGE_NAME) + GET_MASTER_CLASS_OFFSET);
	// calls the function and returns the result
	return GetMasterClass();
}

// gets the static control class instance
CControl* CControl::Get()
{
	// defines the function return type, calling convention and arguments
	typedef CControl*(__cdecl * _GetControlClass)();
	// sets the function address
	_GetControlClass GetControlClass = (_GetControlClass)((__int64)GetModuleHandleW(IMAGE_NAME) + GET_CONTROL_CLASS_OFFSET);
	// calls the function and returns the result
	return GetControlClass();
}

// initalizes the specified map
BOOL CGame::InitMap(LPCSTR lpMapName)
{
	// defines the function return type, calling convention and arguments
	typedef BOOL(__thiscall * _InitMap)(CGame*, LPCSTR);
	// sets the function address
	_InitMap InitMap = (_InitMap)((__int64)GetModuleHandleW(IMAGE_NAME) + INIT_MAP_OFFSET);
	// calls the function and returns the result
	return InitMap(this, lpMapName);
}