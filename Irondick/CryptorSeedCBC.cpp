#include "CryptorSeedCBC.h"

// defines the class constructor
CryptorSeedCBC::CryptorSeedCBC()
{
	this->dword_0x1214C = 0;
	this->dword_0x12150 = 0;
	this->dword_0x12154 = 0;
	this->dword_0x12158 = 0;
	this->dword_0x1215C = 0;
	this->dword_0x12160 = 0;
	this->dword_0x12164 = 0;
	this->dword_0x1216C = 0;
}

// initializes the cryptor
/*BOOL CryptorSeedCBC::init(DWORD* dwSeed, DWORD* dwKey)
{
	// nulls the region of the cryptor structure this function will be filling out
	memset(&this->dword_0x4, 0, 0xB8);
	// validates the arguments
	if (dwSeed && dwKey)
	{
		// moves the key to the structure
		this->dword_0x4[0] = dwKey[0];
		this->dword_0x4[1] = dwKey[1];
		this->dword_0x4[2] = dwKey[2];
		this->dword_0x4[3] = dwKey[3];
		// nulls some attributes
		this->dword_0xA4 = 0;
		this->dword_0xB8 = 0;
		// moves the key to the structure
		this->dword_0x12170[0] = dwKey[0];
		this->dword_0x12170[1] = dwKey[1];
		this->dword_0x12170[2] = dwKey[2];
		this->dword_0x12170[3] = dwKey[3];
		// dwKey is not used past this point
		// generates some sort of key via the seed
		// dwSeed is a 128 bit value (according to https://en.wikipedia.org/wiki/SEED)
		// so we have to take it four bytes at a time (since we are in 32 bit)
		DWORD dwKey1 = __KEY4__(dwSeed[0]); // @ebx and @[ebp+arg_4]
		DWORD dwKey2 = __KEY4__(dwSeed[1]); // @edi
		DWORD dwKey3 = __KEY4__(dwSeed[2]); // @ecx and @[ebp+arg_0]
		DWORD dwKey4 = __KEY4__(dwSeed[3]); // @eax and @[ebp+var_8]
		// incrments the first part of the key by 0x61C88647 and adds the third part of the key
		DWORD dwVar1 = (dwKey1 + 0x61C88647) + dwKey3; // @edx

		(dwKey2 - dwKey4) - 0x61C88647; // @ebx
	}
	// function failed
	return FALSE;
}*/

BOOL CryptorSeedCBC::init(DWORD* dwSeed, DWORD* dwKey)
{
	int v19; // eax@3
	unsigned int v20; // edi@3
	unsigned int v21; // ebx@3
	unsigned int v22; // edx@3
	unsigned int v23; // eax@3
	unsigned int v24; // ST18_4@3
	unsigned int v25; // esi@3
	unsigned int v26; // ebx@3
	unsigned int v27; // edi@3
	unsigned int v28; // ebx@3
	int v29; // edx@3
	unsigned int v30; // esi@3
	unsigned int v31; // ST18_4@3
	int v32; // edx@3
	unsigned int v33; // edx@3
	unsigned int v34; // edx@3
	unsigned int v35; // ebx@3
	unsigned int v36; // edx@3
	unsigned int v37; // ST1C_4@3
	unsigned int v38; // edi@3
	unsigned int v39; // ebx@3
	int v40; // edx@3
	unsigned int v41; // ST18_4@3
	unsigned int v42; // edx@3
	unsigned int v43; // esi@3
	unsigned int v44; // ebx@3
	int v45; // edx@3
	unsigned int v46; // ST1C_4@3
	unsigned int v47; // edx@3
	unsigned int v48; // ebx@3
	unsigned int v49; // edx@3
	unsigned int v50; // edi@3
	unsigned int v51; // ebx@3
	int v52; // edx@3
	unsigned int v53; // esi@3
	unsigned int v54; // edx@3
	unsigned int v55; // ebx@3
	int v56; // ecx@3
	int v57; // edx@3
	unsigned int v58; // ST1C_4@3
	unsigned int v59; // esi@3
	unsigned int v60; // edi@3
	unsigned int v61; // ebx@3
	unsigned int v62; // ebx@3
	int v63; // ebx@3
	unsigned int v64; // ST18_4@3
	unsigned int v65; // ST1C_4@3
	unsigned int v66; // ebx@3
	int v67; // esi@3
	int v68; // edx@3
	unsigned int v69; // ebx@3
	unsigned int v70; // edx@3
	unsigned int v71; // ebx@3
	char result; // al@3
	int pCryptor; // [sp+14h] [bp-4h]@1
	unsigned int dwKey3; // [sp+20h] [bp+8h]@3
	unsigned int v75; // [sp+20h] [bp+8h]@3
	unsigned int v76; // [sp+20h] [bp+8h]@3
	unsigned int v77; // [sp+20h] [bp+8h]@3
	unsigned int dwKey1; // [sp+24h] [bp+Ch]@3
	int v79; // [sp+24h] [bp+Ch]@3
	int v80; // [sp+24h] [bp+Ch]@3
	unsigned int v81; // [sp+24h] [bp+Ch]@3
	unsigned int v82; // [sp+24h] [bp+Ch]@3
	unsigned int v83; // [sp+24h] [bp+Ch]@3
	unsigned int v84; // [sp+24h] [bp+Ch]@3
	int v85; // [sp+24h] [bp+Ch]@3

	// nulls the region of the cryptor structure this function will be filling out
	memset(&this->dword_0x4, 0, 0xB8);
	// validates the arguments
	if (dwSeed && dwKey)
	{
		// moves the key to the structure
		this->dword_0x4[0] = dwKey[0];
		this->dword_0x4[1] = dwKey[1];
		this->dword_0x4[2] = dwKey[2];
		this->dword_0x4[3] = dwKey[3];
		// nulls some attributes
		this->dword_0xA4 = 0;
		this->dword_0xB8 = 0;
		// moves the key to the structure
		this->dword_0x12170[0] = dwKey[0];
		this->dword_0x12170[1] = dwKey[1];
		this->dword_0x12170[2] = dwKey[2];
		this->dword_0x12170[3] = dwKey[3];
		// dwKey is not used past this point
		// generates some sort of key via the seed
		// dwSeed is a 128 bit value (according to https://en.wikipedia.org/wiki/SEED)
		// so we have to take it four bytes at a time (since we are in 32 bit)
		DWORD dwKey1 = __KEY4__(dwSeed[0]);
		DWORD dwKey2 = __KEY4__(dwSeed[1]);
		DWORD dwKey3 = __KEY4__(dwSeed[2]);
		DWORD dwKey4 = __KEY4__(dwSeed[3]);
		// calculates the table offsets
		DWORD dwOffset1 = dwKey3 + dwKey1 + 1640531527;
		DWORD dwOffset2 = dwKey2 - dwKey4 - 1640531527;
		// constructs some dwords and saves them to the structure
		this->dword_0x14 = dword_AF8C00[FIRST_BYTE(dwKey3 + dwKey1 + 71)] ^ dword_AF9000[SECOND_BYTE(dwOffset1)] ^ dword_AF9400[THIRD_BYTE(dwOffset1)] ^ dword_AF9800[FOURTH_BYTE(dwOffset1)];
		this->dword_0x18 = dword_AF8C00[FIRST_BYTE(dwKey2 - dwKey4 - 71)] ^ dword_AF9000[SECOND_BYTE(dwOffset2)] ^ dword_AF9400[THIRD_BYTE(dwOffset2)] ^ dword_AF9800[FOURTH_BYTE(dwOffset2)];


		v79 = (dwKey2 >> 8) ^ (dwKey1 << 24);
		v20 = (dwKey1 >> 8) ^ (dwKey2 << 24);
		v21 = v79 - dwKey4 + 1013904243;

		// constructs some dwords and saves them to the structure
		this->dword_0x1C = dword_AF8C00[FIRST_BYTE(v20 + dwKey3 - 115)] ^ dword_AF9000[SECOND_BYTE(v20 + dwKey3 + 3213)] ^ dword_AF9400[THIRD_BYTE(v20 + dwKey3 - 1013904243)] ^ dword_AF9800[FOURTH_BYTE(v20 + dwKey3 - 1013904243)];
		this->dword_0x20 = dword_AF8C00[FIRST_BYTE(v79 - dwKey4 + 115)] ^ dword_AF9000[SECOND_BYTE(v21)] ^ dword_AF9400[THIRD_BYTE(v21)] ^ dword_AF9800[FOURTH_BYTE(v21)];

		v22 = ((dwKey3 << 8) ^ (dwKey4 >> 24)) + v20 - 2027808486;
		v23 = (dwKey4 << 8) ^ (dwKey3 >> 24);
		v24 = (dwKey3 << 8) ^ (dwKey4 >> 24);
		v25 = v79;
		v26 = v79 - v23 + 2027808486;

		this->dword_0x24 = dword_AF8C00[(unsigned __int8)(FOURTH_BYTE(dwKey4) + v20 + 26)] ^ dword_AF9000[SECOND_BYTE(v22)] ^ dword_AF9400[(unsigned __int8)(v22 >> 16)] ^ dword_AF9800[v22 >> 24];
		this->dword_0x28 = dword_AF8C00[(unsigned __int8)(v79 - FOURTH_BYTE(dwKey3) - 26)] ^ dword_AF9000[SECOND_BYTE(v26)] ^ dword_AF9400[(unsigned __int8)(v26 >> 16)] ^ dword_AF9800[v26 >> 24];
		
		v80 = (v20 >> 8) ^ (v79 << 24);
		v27 = (v25 >> 8) ^ (v20 << 24);
		v28 = v27 - v23 - 239350324;
		v29 = v80 + v24 + 239350324;
		
		this->dword_0x2C = dword_AF8C00[(unsigned __int8)(v80 + FOURTH_BYTE(dwKey4) + 52)] ^ dword_AF9000[SECOND_BYTE(v29)] ^ dword_AF9400[(unsigned __int8)((v80 + v24 + 239350324) >> 16)] ^ dword_AF9800[(v80 + v24 + 239350324) >> 24];
		this->dword_0x30 = dword_AF8C00[(unsigned __int8)(v27 - FOURTH_BYTE(dwKey3) - 52)] ^ dword_AF9000[SECOND_BYTE(v28)] ^ dword_AF9400[(unsigned __int8)(v28 >> 16)] ^ dword_AF9800[v28 >> 24];
		
		v30 = (v23 << 8) ^ (v24 >> 24);
		v31 = (v24 << 8) ^ (v23 >> 24);
		v32 = v31 + v80 + 478700647;
		
		this->dword_0x34 = dword_AF8C00[(unsigned __int8)(v31 + v80 + 103)] ^ dword_AF9000[SECOND_BYTE(v32)] ^ dword_AF9400[(unsigned __int8)((v31 + v80 + 478700647) >> 16)] ^ dword_AF9800[(v31 + v80 + 478700647) >> 24];
		this->dword_0x38 = dword_AF8C00[(unsigned __int8)(v27 - v30 - 103)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v27 - v30 - 25703) >> 8)] ^ dword_AF9400[(unsigned __int8)((v27 - v30 - 478700647) >> 16)] ^ dword_AF9800[(v27 - v30 - 478700647) >> 24];
		
		v33 = ((unsigned __int64)(unsigned int)v80 >> 8) ^ (v27 << 24);
		v75 = v33;
		v81 = (v27 >> 8) ^ (v80 << 24);
		v34 = v31 + v33 + 957401293;
		v35 = v81 - v30 - 957401293;
		
		this->dword_0x3C = dword_AF8C00[(unsigned __int8)v34] ^ dword_AF9000[SECOND_BYTE(v34)] ^ dword_AF9400[(unsigned __int8)(v34 >> 16)] ^ dword_AF9800[v34 >> 24];
		this->dword_0x40 = dword_AF8C00[(unsigned __int8)(v81 - v30 + 51)] ^ dword_AF9000[SECOND_BYTE(v35)] ^ dword_AF9400[(unsigned __int8)(v35 >> 16)] ^ dword_AF9800[v35 >> 24];
		
		v36 = ((v31 << 8) ^ (v30 >> 24)) + v75 + 1914802585;
		v37 = (v31 << 8) ^ (v30 >> 24);
		v38 = (v30 << 8) ^ (v31 >> 24);
		v39 = v81 - v38 - 1914802585;
		
		this->dword_0x44 = dword_AF8C00[(unsigned __int8)(FOURTH_BYTE(v30) + v75 - 103)] ^ dword_AF9000[SECOND_BYTE(v36)] ^ dword_AF9400[(unsigned __int8)(v36 >> 16)] ^ dword_AF9800[v36 >> 24];
		this->dword_0x48 = dword_AF8C00[(unsigned __int8)(v81 - FOURTH_BYTE(v31) + 103)] ^ dword_AF9000[SECOND_BYTE(v39)] ^ dword_AF9400[(unsigned __int8)(v39 >> 16)] ^ dword_AF9800[v39 >> 24];
		
		v40 = (v75 >> 8) ^ (v81 << 24);
		v41 = v40;
		v42 = v37 - 465362127 + v40;
		v43 = (v81 >> 8) ^ (v75 << 24);
		v44 = v43 - v38 + 465362127;
		
		this->dword_0x4C = dword_AF8C00[(unsigned __int8)v42] ^ dword_AF9000[SECOND_BYTE(v42)] ^ dword_AF9400[(unsigned __int8)(v42 >> 16)] ^ dword_AF9800[v42 >> 24];
		this->dword_0x50 = dword_AF8C00[(unsigned __int8)(SECOND_BYTE(v81) - v38 - 49)] ^ dword_AF9000[SECOND_BYTE(v44)] ^ dword_AF9400[(unsigned __int8)(v44 >> 16)] ^ dword_AF9800[v44 >> 24];
		
		v45 = (v37 << 8) ^ (v38 >> 24);
		v82 = v45;
		v46 = (v38 << 8) ^ (v37 >> 24);
		v47 = v41 + v45 - 930724254;
		v48 = v43 - v46 + 930724254;
		
		this->dword_0x54 = dword_AF8C00[(unsigned __int8)v47] ^ dword_AF9000[SECOND_BYTE(v47)] ^ dword_AF9400[(unsigned __int8)(v47 >> 16)] ^ dword_AF9800[v47 >> 24];
		this->dword_0x58 = dword_AF8C00[(unsigned __int8)(v43 - v46 - 98)] ^ dword_AF9000[SECOND_BYTE(v48)] ^ dword_AF9400[(unsigned __int8)(v48 >> 16)] ^ dword_AF9800[v48 >> 24];
		
		v49 = ((v41 >> 8) ^ (v43 << 24)) + v82 - 1861448508;
		v50 = (v43 >> 8) ^ (v41 << 24);
		v51 = v50 - v46 + 1861448508;
		
		this->dword_0x5C = dword_AF8C00[(unsigned __int8)(SECOND_BYTE(v41) + v82 - 60)] ^ dword_AF9000[SECOND_BYTE(v49)] ^ dword_AF9400[(unsigned __int8)(v49 >> 16)] ^ dword_AF9800[v49 >> 24];
		this->dword_0x60 = dword_AF8C00[(unsigned __int8)(SECOND_BYTE(v43) - v46 + 60)] ^ dword_AF9000[SECOND_BYTE(v51)] ^ dword_AF9400[(unsigned __int8)(v51 >> 16)] ^ dword_AF9800[v51 >> 24];
		
		v52 = (v82 << 8) ^ (v46 >> 24);
		v76 = v52;
		v53 = (v41 >> 8) ^ (v43 << 24);
		v83 = (v46 << 8) ^ (v82 >> 24);
		v54 = v53 + v52 + 572070280;
		v55 = v50 - v83 - 572070280;
	
		this->dword_0x64 = dword_AF8C00[(unsigned __int8)v54] ^ dword_AF9000[SECOND_BYTE(v54)] ^ dword_AF9400[(unsigned __int8)(v54 >> 16)] ^ dword_AF9800[v54 >> 24];
		this->dword_0x68 = dword_AF8C00[(unsigned __int8)(v50 - v83 + 120)] ^ dword_AF9000[SECOND_BYTE(v55)] ^ dword_AF9400[(unsigned __int8)(v55 >> 16)] ^ dword_AF9800[v55 >> 24];
		
		v56 = (v53 >> 8) ^ (v50 << 24);
		v57 = v56 + v76 + 1144140559;
		v58 = (v53 >> 8) ^ (v50 << 24);
		v59 = (v50 >> 8) ^ (v53 << 24);
		v60 = v83;
		v61 = v59 - v83 - 1144140559;
		
		this->dword_0x6C = dword_AF8C00[(unsigned __int8)(v56 + v76 + 15)] ^ dword_AF9000[SECOND_BYTE(v57)] ^ dword_AF9400[(unsigned __int8)((v56 + v76 + 1144140559) >> 16)] ^ dword_AF9800[(v56 + v76 + 1144140559) >> 24];
		this->dword_0x70 = dword_AF8C00[(unsigned __int8)(v59 - v83 - 15)] ^ dword_AF9000[SECOND_BYTE(v61)] ^ dword_AF9400[(unsigned __int8)(v61 >> 16)] ^ dword_AF9800[v61 >> 24];
		
		v84 = (v76 << 8) ^ (v83 >> 24);
		v77 = (v60 << 8) ^ (v76 >> 24);
		v62 = v59 - v77 + 2006686179;

		this->dword_0x74 = dword_AF8C00[(unsigned __int8)(v84 + v58 + 29)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v84 + v58 + 26141) >> 8)] ^ dword_AF9400[(unsigned __int8)((v84 + v58 - 2006686179) >> 16)] ^ dword_AF9800[(v84 + v58 - 2006686179) >> 24];
		this->dword_0x78 = dword_AF8C00[(unsigned __int8)(v59 - v77 - 29)] ^ dword_AF9000[SECOND_BYTE(v62)] ^ dword_AF9400[(unsigned __int8)(v62 >> 16)] ^ dword_AF9800[v62 >> 24];
		
		v63 = (v59 >> 8) ^ (v58 << 24);
		v64 = (v58 >> 8) ^ (v59 << 24);
		v65 = v63;
		v66 = v63 - v77 - 281594938;
		
		this->dword_0x7C = dword_AF8C00[(unsigned __int8)(v84 + v64 + 58)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v84 + v64 - 13254) >> 8)] ^ dword_AF9400[(unsigned __int8)((v84 + v64 + 281594938) >> 16)] ^ dword_AF9800[(v84 + v64 + 281594938) >> 24];
		this->dword_0x80 = dword_AF8C00[(unsigned __int8)v66] ^ dword_AF9000[SECOND_BYTE(v66)] ^ dword_AF9400[(unsigned __int8)(v66 >> 16)] ^ dword_AF9800[v66 >> 24];
		
		v67 = (v84 << 8) ^ (v77 >> 24);
		v85 = (v77 << 8) ^ (v84 >> 24);
		v68 = v67 + v64 + 563189875;
		v69 = v65 - v85 - 563189875;
		
		this->dword_0x84 = dword_AF8C00[(unsigned __int8)(v67 + v64 + 115)] ^ dword_AF9000[SECOND_BYTE(v68)] ^ dword_AF9400[(unsigned __int8)((v67 + v64 + 563189875) >> 16)] ^ dword_AF9800[(v67 + v64 + 563189875) >> 24];
		this->dword_0x88 = dword_AF8C00[(unsigned __int8)(v65 - v85 - 115)] ^ dword_AF9000[SECOND_BYTE(v69)] ^ dword_AF9400[(unsigned __int8)(v69 >> 16)] ^ dword_AF9800[v69 >> 24];
		
		v70 = v67 + ((v64 >> 8) ^ (v65 << 24)) + 1126379749;
		v71 = ((v65 >> 8) ^ (v64 << 24)) - v85 - 1126379749;
		
		this->dword_0x8C = dword_AF8C00[(unsigned __int8)(v67 + SECOND_BYTE(v64) - 27)] ^ dword_AF9000[SECOND_BYTE(v70)] ^ dword_AF9400[(unsigned __int8)(v70 >> 16)] ^ dword_AF9800[v70 >> 24];
		this->dword_0x90 = dword_AF8C00[(unsigned __int8)v71] ^ dword_AF9000[SECOND_BYTE(v71)] ^ dword_AF9400[(unsigned __int8)(v71 >> 16)] ^ dword_AF9800[v71 >> 24];
		// function succeeded
		return TRUE;
	}
	// function failed
	return FALSE;
}

// decrypts the given data buffer
// pData - a pointer to the data to be decrypted
// dwSize - the length of the data in bytes
// returns the amount of data decrypted in bytes
DWORD SeedDecrypt(PVOID pData, DWORD dwSize)
{
	// validates the size of the buffer is large enough
	if (dwSize & 0xF)
	{

	}
	// function failed
	return NULL;
}

BOOL Decrypt(PVOID pData)
{
	// passes the data size and pointer to the decryption function
	SeedDecrypt((PVOID)((__int64)pData + 0x4), *(DWORD*)pData);
}

// stolen from iron engine
DWORD DecryptBlock(PVOID pDecryptionKey, PVOID pSource, PVOID pDestination)
{

}