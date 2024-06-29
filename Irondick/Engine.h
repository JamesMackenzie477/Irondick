#include <Windows.h>

// create iron engine class that wraps everything
// use signatures to find addresses!!!

class IronEngine
{
private:
	// stores the module handle
	HMODULE hModule;
public:
	// connects to the iron engine instance
	static IronEngine* Open()
	{
		// creates a new iron engine object
		if (IronEngine* pIronEngine = new IronEngine())
		{
			// gets a handle to the module
			if (HMODULE hModule = GetModuleHandleW(L"ironsight.exe"))
			{
				// sets the class module handle
				pIronEngine->hModule = hModule;
				// function succeeded
				return pIronEngine;
			}
		}
		// function failed
		return nullptr;
	}
};