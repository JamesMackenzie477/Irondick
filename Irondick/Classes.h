#include <Windows.h>
#include <stdio.h>

// defines the unique fourcc code used to identify the file format
#define FOURCC 0x474B5052
// defines the max length of a package name
#define MAX_PACK_NAME 0x80

// iterates sections,
// offsets to data,
// check if compressed or encrypted

// definiton of the resource load manager class
// used by iron engine to manage loaded packages
class ResourceLoadManager
{
	// contains the core load speed
	DWORD LoadSpeed; // 0x8

	// a pointer to the start of a pointer array of loaded packages
	PDWORD PackagesStart; // 0xE4
	// a pointer to the end of a pointer array of loaded packages
	PDWORD PackagesEnd; // 0xE8
};

// definiton of the master class
// used by iron engine to control many other classes
class CMaster
{
	// set to true when class is initialized
	DWORD dwInitialized; // 0x0
	// a pointer to the system info class
	PVOID SystemInfo; // 0x4
	// a pointer to the config class
	PVOID pConfig; // 0x8
	// a pointer to the crash implementation class
	PVOID pCrashImpl; // 0xC
	// a pointer to the performance class
	PVOID pPerformance; // 0x10
	// a pointer to the resource load manager class
	ResourceLoadManager* pResourceLoadManager; // 0x14
	// a pointer to the localization class
	PVOID pLocalization; // 0x18
};

// definiton of the resource package class
// used by iron engine to interact with it's packages
class ResourcePackage
{
	// a referance counter
	DWORD dwReferance; // 0x4
	// the name of the package
	CHAR PackageName[MAX_PACK_NAME]; // 0x8
	// the root name of the package
	CHAR PackageRoot[MAX_PACK_NAME]; // 0x88
	// a pointer to a buffer that contains the package sections
	PVOID pSections; // 0x108
	// a pointer to the end of the sections buffer
	PVOID pSectionsEnd1; // 0x10C
	// another pointer to the end of the sections buffer
	PVOID pSectionsEnd2; // 0x110
	// a file stream pointer (set at the end of the package sections)
	FILE* pFileSections; // 0x114
	// a file stream pointer (set at the start of the package)
	FILE* pFileStart; // 0x118

	// defines the class constructor
	ResourcePackage(LPCSTR lpPackageName);
	// opens the package associated with the class
	BOOL ResourcePackage::Open();
};

// definition of the structure of a package file header
typedef struct _PACKAGE_HEADER
{
	// the package fourcc code
	DWORD FourCC; // 0x0
	// the package version
	DWORD Version; // 0x4
	// contains the package root name
	CHAR PackageRoot[MAX_PACK_NAME]; // 0x8
	// contains the number of sections within the package
	DWORD NumberOfSections; // 0x88
} PACKAGE_HEADER, *PPACKAGE_HEADER;

// definition of the structure of a package file section
typedef struct _PACKAGE_SECTION
{
	// the name of the file accociated with the section
	CHAR FileName[MAX_PACK_NAME]; // 0x0
	// the offset of the data block from the base of the file
	DWORD DataOffset; // 0x80
	// the size of the data block
	DWORD DataSize; // 0x84
	// contains information on whether the data is encrypted or compressed
	// and with bitmask 1 to see if the data is compressed
	// and with bitmast 2 to see if data is encrypted
	DWORD DataInfo; // 0x88
} PACKAGE_SECTION, *PPACKAGE_SECTION;

// first 4 bytes of data section contains the actual data size
// read the chosen file
// validate file using the methods provided in ironsight (size calculation, checking offset is always equal to the size plus the offset of the previous section, checking DataInfo is set properly, etc)
// iterate through section headers
// when user choses a file, offset to the data associated with the section
// check if data is encrypted or compressed and act accordingly
// write decrypted/uncompressed raw data to file of the correct name and launch the file
// allow uses to make changes to the file, then reencrypt/recompress the file, resize the data area to allow the new file size to fit, then fix each section header to map to the correct data.

// typedef bool __thiscall sub_64ECF0();

// opens the package associated with the class
BOOL ResourcePackage::Open()
{
	// checks if the file is already open
	// if (this->pFileEnd)
		// no need to open the file
		// function suceeded
		return TRUE;
	// stores the file name
	// char* FileName[0x104];
	// concatenates the package name with the path
	// stores the file stream
	FILE* pFile;
	// opens the package as a binary stream
	if (fopen_s(&pFile, this->PackageName, "rb") == 0)
	{
		// stores the package header
		PACKAGE_HEADER Header;
		// reads the package header
		if (fread(&Header, 1, sizeof(PACKAGE_HEADER), pFile) == sizeof(PACKAGE_HEADER))
		{
			// indentifies the fourcc code
			if (Header.FourCC == FOURCC)
			{
				// checks the package version is below or equal to 1
				if (Header.Version <= 1)
				{
					// calculates the size of the sections array
					DWORD SectionsSize = Header.NumberOfSections * sizeof(PACKAGE_SECTION);
					// creates a buffer to store sections
					PPACKAGE_SECTION pPackageSections = new PACKAGE_SECTION[SectionsSize];
					// reads the package sections array into a buffer
					if (fread(pPackageSections, 1, SectionsSize, pFile) == SectionsSize)
					{

					}
				}
			}
		}
		// closes the file
		fclose(pFile);
	}
	// function failed
	return FALSE;
}

// definition of the cryptor seed cbc class
// used to encrypt and decrypt data with seeded cipher block chaining
class CryptorSeedCBC
{
public:
	BYTE byte_0x4[0xF]; // 0x4
	DWORD dword_0xA4; // 0xA4
	DWORD dword_0xB8; // 0xB8
	BYTE byte_0x12170[0xF]; // 0x12170
	BOOL CryptorSeedCBC::init(PVOID, PVOID);
};


// initializes the cbc cryptor with a seed
BOOL CryptorSeedCBC::init(PVOID Seed1, PVOID Seed2)
{
	// zeros out some of the structure
	memset(&this->byte_0x4, 0, 0xB8);
	// validates the arguments
	if (Seed1 && Seed2)
	{
		// copies the third arguments data to the structure
		memcpy(&this->byte_0x4, Seed2, 0xF);
		// nulls out a dword on the structure
		this->dword_0xA4 = 0;
		// nulls out a dword on the structure
		this->dword_0xB8 = 0;
		// copies the third arguments data to the structure
		memcpy(&this->byte_0x12170, Seed2, 0xF);
	}
	// function failed
	return FALSE;
}