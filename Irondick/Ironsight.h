// contains the defintions for classes, structs, functions, constants and enums within ironsight
#include <Windows.h>

// make this class based to avoid having to get the module base each time

// defines the name of the main executable image
#define IMAGE_NAME L"ironsight.exe"

// defines the debug log function offset
#define DEBUG_LOG_OFFSET 0x243180
// defines the window class offset
#define WINDOW_CLASS_OFFSET 0xA1B0E0
// defines the get window class offset
#define GET_WINDOW_CLASS_OFFSET 0x138080
// defines the constant game structor offset
#define GAME_CLASS_OFFSET 0xA17DA4
// defines the game init map method offset
#define INIT_MAP_OFFSET 0x14ACB0
// defines the constant master class offset
#define GET_MASTER_CLASS_OFFSET 0x80C20

#define GET_CONTROL_CLASS_OFFSET 0xA5B10

// defines the different message types for the debug log function
#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERROR 3
#define LOG_FATAL 4

// various functions used for game debugging
namespace Debug
{
	// logs a given message to a log file stored in the %temp% directory
	// lpCppFile - the file associated with the log message (so the developer can tell where the issue lies).
	// dwType - the type of message to log, ranging from: debug, information, warning, error or fatal.
	// lpMessage - the message to be logged to the log file, it can be a format string with addition variable arguments.
	BOOL Log(DWORD dwType, LPCSTR lpMessage, ...);
}

// definition of the game client class
// this class is used by iron engine to interact with eac
class CGameClient {
public:
	// a handle to the eac dll
	HMODULE hEasyAntiCheat;
	// a pointer to the eac game client class
	PVOID pGameClient;
	// defines the init method
	// this is where the eac dll is loaded and the eac game client is created
	virtual bool Init();
	// defines the cleanup method
	// this is where the eac dll is unloaded and the eac game client is destroyed
	virtual bool Cleanup();
	// defines the other virtual methods
	virtual int OnClientIntegrityViolation();
	virtual int OnGameServerConnect();
	virtual int OnGameServerDisconnect();
	virtual int DoStuffWithEACClient();
	virtual int DoMoreStuffWithEACClient();
	virtual int SendEACMessageToServer();
	virtual int QuitMessage();
	virtual int ShowErrorDialog();
};

// definition of the game window class
// this class is used by iron engine to interact with the game window
class CGameWindow {
public:
	// some padding
	char padding_0x4[0x4]; // 0x4
	// a handle to the window instance
	HINSTANCE hInstance; // 0x8
	// a handle to the window
	HWND hWindow; // 0xC
	// some padding
	char padding_0x10[0xA0]; // 0x10
	// a pointer to a game client class
	CGameClient* pGameClient; // 0xB0
	// defines the other virtual methods
	virtual int Function1();
	virtual int Function2();
	virtual int Function3();
	virtual int Function4();
	virtual int Function5();
	virtual int Function6();
	// runs the window message loop
	virtual int MessageLoop();
	// gets the static game window class instance
	static CGameWindow* Get();
};

// defintion of the game class
// this class is used by iron engine to interact with the game
class CGame
{
public:
	// gets the static game class instance
	static CGame* Get();
	// initalizes the specified map
	BOOL InitMap(LPCSTR lpMapName);
};

// defintion of the system information class
// this class is used by iron engine to store system information
class CSystem
{
public:
	char padding_0x0[0x7D8]; // 0x0
	DWORD MainThreadId; // 0x7D8
};

// defintion of the master class
// this class is used by iron engine to interact with non static classes
class CMaster
{
public:
	// set to true when class is initialized
	BOOL IsInitialized; // 0x0
	// a pointer to the system  class
	CSystem* pSystem; // 0x4
	// a pointer to the config class
	PVOID pConfig; // 0x8
	// a pointer to the crash implementation class
	PVOID pCrashImpl; // 0xC
	// a pointer to the performance class
	PVOID pPerformance; // 0x10
	// a pointer to the resource load manager class
	PVOID pResourceLoadManager; // 0x14
	// a pointer to the localization class
	PVOID pLocalization; // 0x18
	// gets the static master class instance
	static CMaster* Get();
};

class CControl
{
public:
	char padding_0x0[0x18B]; // 0x0
	// the current map name
	CHAR MapName[0x80]; // 0x18B
	// gets the static master class instance
	static CControl* Get();
};