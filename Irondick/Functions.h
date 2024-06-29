#include <Windows.h>

// defines a few assembly based intrinsics
// rotates a four byte value left
#define __ROL4__(x, n) ((x << n) | (x >> (32 - n)))
// rotates a four byte value right
#define __ROR4__(x, n) ((x >> n) | (x << (32 - n)))
// performs some actions on a four byte value in order to generate a key
#define __KEY4__(I) ((__ROR4__(I, 8) & 0xFF00FF00) | (__ROL4__(I, 8) & 0xFF00FF))
#define BYTE0(I) ((BYTE)((I >> (8 * 0)) & 0xFF))
#define BYTE1(I) ((BYTE)((I >> (8 * 1)) & 0xFF))
#define BYTE2(I) ((BYTE)((I >> (8 * 2)) & 0xFF))
#define BYTE3(I) ((BYTE)((I >> (8 * 3)) & 0xFF))

// decrypts the given data buffer
// pData - a pointer to the data to be decrypted
// dwSize - the length of the data in bytes
// returns the amount of data decrypted in bytes
DWORD Decrypt(PVOID pData, DWORD dwSize)
{
	// validates the size of the buffer is large enough
	if (dwSize & 0xF)
	{

		// function succeeded
		return;
	}
	// function failed
	return NULL;
}

// stolen from iron engine
DWORD DecryptBlock(PVOID pDecryptionKey, PVOID pSource, PVOID pDestination)
{
	int v3; // edx@1
	int v4; // ebx@1
	int v5; // esi@1
	int v6; // edi@1
	int v7; // eax@1
	unsigned int v9; // ebx@1
	int v10; // edx@1
	unsigned int v11; // ST14_4@1
	int v12; // ebx@1
	int v13; // edx@1
	int v14; // ecx@1
	unsigned int v15; // ebx@1
	int v16; // edx@1
	int v17; // ebx@1
	int v18; // ecx@1
	unsigned int v19; // ST0C_4@1
	int v20; // esi@1
	unsigned int v21; // esi@1
	int v22; // ebx@1
	int v23; // ecx@1
	unsigned int v24; // ebx@1
	int v25; // edx@1
	int v26; // ecx@1
	int v27; // ST14_4@1
	int v28; // ebx@1
	int v29; // ecx@1
	unsigned int v30; // ebx@1
	int v31; // edx@1
	int v32; // ecx@1
	int v33; // esi@1
	int v34; // edi@1
	int v35; // ebx@1
	int v36; // ecx@1
	unsigned int v37; // ebx@1
	int v38; // edx@1
	int v39; // ecx@1
	int v40; // ST14_4@1
	int v41; // ebx@1
	int v42; // ecx@1
	unsigned int v43; // ebx@1
	int v44; // edx@1
	int v45; // ecx@1
	int v46; // esi@1
	int v47; // edi@1
	int v48; // ebx@1
	int v49; // ecx@1
	unsigned int v50; // ebx@1
	int v51; // edx@1
	int v52; // ecx@1
	int v53; // ST14_4@1
	int v54; // ebx@1
	int v55; // ecx@1
	unsigned int v56; // ebx@1
	int v57; // edx@1
	int v58; // ecx@1
	int v59; // edi@1
	int v60; // esi@1
	int v61; // ebx@1
	int v62; // ecx@1
	unsigned int v63; // ebx@1
	int v64; // edx@1
	int v65; // ecx@1
	int v66; // ST14_4@1
	int v67; // ebx@1
	int v68; // ecx@1
	unsigned int v69; // ebx@1
	int v70; // edx@1
	int v71; // ecx@1
	int v72; // esi@1
	int v73; // edi@1
	int v74; // ebx@1
	int v75; // ecx@1
	unsigned int v76; // ebx@1
	int v77; // edx@1
	int v78; // ecx@1
	int v79; // ST14_4@1
	int v80; // ebx@1
	int v81; // ecx@1
	unsigned int v82; // ebx@1
	int v83; // edx@1
	int v84; // ecx@1
	int v85; // esi@1
	int v86; // edi@1
	int v87; // ebx@1
	int v88; // ecx@1
	unsigned int v89; // ebx@1
	int v90; // edx@1
	int v91; // ecx@1
	int v92; // ST14_4@1
	int v93; // ebx@1
	int v94; // ecx@1
	unsigned int v95; // ebx@1
	int v96; // edx@1
	int v97; // ecx@1
	int v98; // esi@1
	int v99; // edi@1
	int v100; // ebx@1
	int v101; // ecx@1
	unsigned int v102; // ebx@1
	int v103; // edx@1
	int v104; // ecx@1
	int v105; // ST14_4@1
	int v106; // ebx@1
	int v107; // ecx@1
	unsigned int v108; // ebx@1
	int v109; // edx@1
	int v110; // ecx@1
	int v111; // esi@1
	int v112; // edi@1
	int v113; // ebx@1
	int v114; // ecx@1
	unsigned int v115; // ebx@1
	int v116; // edx@1
	int v117; // ecx@1
	int v118; // edx@1
	int v119; // eax@1
	int v120; // eax@1
	int v121; // ebx@1
	int v122; // eax@1
	int v123; // eax@1
	unsigned int result; // eax@1
	unsigned int v125; // [sp+20h] [bp+8h]@1
	int v126; // [sp+20h] [bp+8h]@1
	int v127; // [sp+20h] [bp+8h]@1
	int v128; // [sp+20h] [bp+8h]@1
	int v129; // [sp+20h] [bp+8h]@1
	int v130; // [sp+20h] [bp+8h]@1
	int v131; // [sp+20h] [bp+8h]@1
	int v132; // [sp+20h] [bp+8h]@1

	v3 = *(DWORD*)(pSource + 8);
	v4 = v3;
	v5 = *(DWORD*)pSource;
	v6 = *(DWORD*)(pSource + 4);
	v7 = *(DWORD*)(pSource + 12);
	v3 = __ROL4__(v3, 8);
	v4 = __ROR4__(v4, 8);
	v9 = v3 & 0xFF00FF | v4 & 0xFF00FF00;
	v10 = v7;
	v7 = __ROL4__(v7, 8);
	v10 = __ROR4__(v10, 8);
	v11 = v9;
	v12 = v9 ^ *(DWORD*)(this + 140);
	v125 = v7 & 0xFF00FF | v10 & 0xFF00FF00;
	v13 = v125 ^ v12 ^ *(DWORD*)(this + 144);
	v14 = dword_AF8C00[(unsigned __int8)(v125 ^ v12 ^ *(_BYTE *)(this + 144))] ^ dword_AF9000[BYTE1(v13)] ^ dword_AF9400[(unsigned __int8)((v125 ^ v12 ^ *(DWORD*)(this + 144)) >> 16)] ^ dword_AF9800[(v125 ^ v12 ^ *(DWORD*)(this + 144)) >> 24];
	v15 = v14 + v12;
	v16 = dword_AF8C00[(unsigned __int8)v15] ^ dword_AF9000[BYTE1(v15)] ^ dword_AF9400[(unsigned __int8)(v15 >> 16)] ^ dword_AF9800[v15 >> 24];
	v17 = __ROR4__(v5, 8);
	v5 = __ROL4__(v5, 8);
	v18 = dword_AF8C00[(unsigned __int8)(v16 + v14)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v16 + v14) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v16 + v14) >> 16)] ^ dword_AF9800[(unsigned int)(v16 + v14) >> 24];
	v19 = (v18 + v16) ^ (v5 & 0xFF00FF | v17 & 0xFF00FF00);
	v20 = __ROR4__(v6, 8);
	v6 = __ROL4__(v6, 8);
	v21 = v18 ^ (v6 & 0xFF00FF | v20 & 0xFF00FF00);
	v22 = v19 ^ *(DWORD*)(this + 132);
	v23 = dword_AF8C00[(unsigned __int8)(v21 ^ v22 ^ *(_BYTE *)(this + 136))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v21 ^ v22 ^ *(_WORD *)(this + 136)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v21 ^ v22 ^ *(DWORD*)(this + 136)) >> 16)] ^ dword_AF9800[(v21 ^ v22 ^ *(DWORD*)(this + 136)) >> 24];
	v24 = v23 + v22;
	v25 = dword_AF8C00[(unsigned __int8)v24] ^ dword_AF9000[BYTE1(v24)] ^ dword_AF9400[(unsigned __int8)(v24 >> 16)] ^ dword_AF9800[v24 >> 24];
	v26 = dword_AF8C00[(unsigned __int8)(v25 + v23)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v25 + v23) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v25 + v23) >> 16)] ^ dword_AF9800[(unsigned int)(v25 + v23) >> 24];
	v126 = v26 ^ v125;
	v27 = (v26 + v25) ^ v11;
	v28 = v27 ^ *(DWORD*)(this + 124);
	v29 = dword_AF8C00[(unsigned __int8)(v126 ^ v28 ^ *(_BYTE *)(this + 128))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v126 ^ v28 ^ *(_WORD *)(this + 128)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v126 ^ (unsigned int)v28 ^ *(DWORD*)(this + 128)) >> 16)] ^ dword_AF9800[(v126 ^ (unsigned int)v28 ^ *(DWORD*)(this + 128)) >> 24];
	v30 = v29 + v28;
	v31 = dword_AF8C00[(unsigned __int8)v30] ^ dword_AF9000[BYTE1(v30)] ^ dword_AF9400[(unsigned __int8)(v30 >> 16)] ^ dword_AF9800[v30 >> 24];
	v32 = dword_AF8C00[(unsigned __int8)(v31 + v29)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v31 + v29) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v31 + v29) >> 16)] ^ dword_AF9800[(unsigned int)(v31 + v29) >> 24];
	v33 = v32 ^ v21;
	v34 = (v32 + v31) ^ v19;
	v35 = v34 ^ *(DWORD*)(this + 116);
	v36 = dword_AF8C00[(unsigned __int8)(v33 ^ v35 ^ *(_BYTE *)(this + 120))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v33 ^ v35 ^ *(_WORD *)(this + 120)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v33 ^ (unsigned int)v35 ^ *(DWORD*)(this + 120)) >> 16)] ^ dword_AF9800[(v33 ^ (unsigned int)v35 ^ *(DWORD*)(this + 120)) >> 24];
	v37 = v36 + v35;
	v38 = dword_AF8C00[(unsigned __int8)v37] ^ dword_AF9000[BYTE1(v37)] ^ dword_AF9400[(unsigned __int8)(v37 >> 16)] ^ dword_AF9800[v37 >> 24];
	v39 = dword_AF8C00[(unsigned __int8)(v38 + v36)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v38 + v36) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v38 + v36) >> 16)] ^ dword_AF9800[(unsigned int)(v38 + v36) >> 24];
	v127 = v39 ^ v126;
	v40 = (v39 + v38) ^ v27;
	v41 = v40 ^ *(DWORD*)(this + 108);
	v42 = dword_AF8C00[(unsigned __int8)(v127 ^ v41 ^ *(_BYTE *)(this + 112))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v127 ^ v41 ^ *(_WORD *)(this + 112)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v127 ^ (unsigned int)v41 ^ *(DWORD*)(this + 112)) >> 16)] ^ dword_AF9800[(v127 ^ (unsigned int)v41 ^ *(DWORD*)(this + 112)) >> 24];
	v43 = v42 + v41;
	v44 = dword_AF8C00[(unsigned __int8)v43] ^ dword_AF9000[BYTE1(v43)] ^ dword_AF9400[(unsigned __int8)(v43 >> 16)] ^ dword_AF9800[v43 >> 24];
	v45 = dword_AF8C00[(unsigned __int8)(v44 + v42)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v44 + v42) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v44 + v42) >> 16)] ^ dword_AF9800[(unsigned int)(v44 + v42) >> 24];
	v46 = v45 ^ v33;
	v47 = (v45 + v44) ^ v34;
	v48 = v47 ^ *(DWORD*)(this + 100);
	v49 = dword_AF8C00[(unsigned __int8)(v46 ^ v48 ^ *(_BYTE *)(this + 104))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v46 ^ v48 ^ *(_WORD *)(this + 104)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v46 ^ (unsigned int)v48 ^ *(DWORD*)(this + 104)) >> 16)] ^ dword_AF9800[(v46 ^ (unsigned int)v48 ^ *(DWORD*)(this + 104)) >> 24];
	v50 = v49 + v48;
	v51 = dword_AF8C00[(unsigned __int8)v50] ^ dword_AF9000[BYTE1(v50)] ^ dword_AF9400[(unsigned __int8)(v50 >> 16)] ^ dword_AF9800[v50 >> 24];
	v52 = dword_AF8C00[(unsigned __int8)(v51 + v49)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v51 + v49) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v51 + v49) >> 16)] ^ dword_AF9800[(unsigned int)(v51 + v49) >> 24];
	v128 = v52 ^ v127;
	v53 = (v52 + v51) ^ v40;
	v54 = v53 ^ *(DWORD*)(this + 92);
	v55 = dword_AF8C00[(unsigned __int8)(v128 ^ v54 ^ *(_BYTE *)(this + 96))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v128 ^ v54 ^ *(_WORD *)(this + 96)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v128 ^ (unsigned int)v54 ^ *(DWORD*)(this + 96)) >> 16)] ^ dword_AF9800[(v128 ^ (unsigned int)v54 ^ *(DWORD*)(this + 96)) >> 24];
	v56 = v55 + v54;
	v57 = dword_AF8C00[(unsigned __int8)v56] ^ dword_AF9000[BYTE1(v56)] ^ dword_AF9400[(unsigned __int8)(v56 >> 16)] ^ dword_AF9800[v56 >> 24];
	v58 = dword_AF8C00[(unsigned __int8)(v57 + v55)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v57 + v55) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v57 + v55) >> 16)] ^ dword_AF9800[(unsigned int)(v57 + v55) >> 24];
	v59 = (v58 + v57) ^ v47;
	v60 = v58 ^ v46;
	v61 = v59 ^ *(DWORD*)(this + 84);
	v62 = dword_AF8C00[(unsigned __int8)(v60 ^ v61 ^ *(_BYTE *)(this + 88))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v60 ^ v61 ^ *(_WORD *)(this + 88)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v60 ^ (unsigned int)v61 ^ *(DWORD*)(this + 88)) >> 16)] ^ dword_AF9800[(v60 ^ (unsigned int)v61 ^ *(DWORD*)(this + 88)) >> 24];
	v63 = v62 + v61;
	v64 = dword_AF8C00[(unsigned __int8)v63] ^ dword_AF9000[BYTE1(v63)] ^ dword_AF9400[(unsigned __int8)(v63 >> 16)] ^ dword_AF9800[v63 >> 24];
	v65 = dword_AF8C00[(unsigned __int8)(v64 + v62)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v64 + v62) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v64 + v62) >> 16)] ^ dword_AF9800[(unsigned int)(v64 + v62) >> 24];
	v129 = v65 ^ v128;
	v66 = (v65 + v64) ^ v53;
	v67 = v66 ^ *(DWORD*)(this + 76);
	v68 = dword_AF8C00[(unsigned __int8)(v129 ^ v67 ^ *(_BYTE *)(this + 80))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v129 ^ v67 ^ *(_WORD *)(this + 80)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v129 ^ (unsigned int)v67 ^ *(DWORD*)(this + 80)) >> 16)] ^ dword_AF9800[(v129 ^ (unsigned int)v67 ^ *(DWORD*)(this + 80)) >> 24];
	v69 = v68 + v67;
	v70 = dword_AF8C00[(unsigned __int8)v69] ^ dword_AF9000[BYTE1(v69)] ^ dword_AF9400[(unsigned __int8)(v69 >> 16)] ^ dword_AF9800[v69 >> 24];
	v71 = dword_AF8C00[(unsigned __int8)(v70 + v68)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v70 + v68) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v70 + v68) >> 16)] ^ dword_AF9800[(unsigned int)(v70 + v68) >> 24];
	v72 = v71 ^ v60;
	v73 = (v71 + v70) ^ v59;
	v74 = v73 ^ *(DWORD*)(this + 68);
	v75 = dword_AF8C00[(unsigned __int8)(v72 ^ v74 ^ *(_BYTE *)(this + 72))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v72 ^ v74 ^ *(_WORD *)(this + 72)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v72 ^ (unsigned int)v74 ^ *(DWORD*)(this + 72)) >> 16)] ^ dword_AF9800[(v72 ^ (unsigned int)v74 ^ *(DWORD*)(this + 72)) >> 24];
	v76 = v75 + v74;
	v77 = dword_AF8C00[(unsigned __int8)v76] ^ dword_AF9000[BYTE1(v76)] ^ dword_AF9400[(unsigned __int8)(v76 >> 16)] ^ dword_AF9800[v76 >> 24];
	v78 = dword_AF8C00[(unsigned __int8)(v77 + v75)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v77 + v75) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v77 + v75) >> 16)] ^ dword_AF9800[(unsigned int)(v77 + v75) >> 24];
	v130 = v78 ^ v129;
	v79 = (v78 + v77) ^ v66;
	v80 = v79 ^ *(DWORD*)(this + 60);
	v81 = dword_AF8C00[(unsigned __int8)(v130 ^ v80 ^ *(_BYTE *)(this + 64))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v130 ^ v80 ^ *(_WORD *)(this + 64)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v130 ^ (unsigned int)v80 ^ *(DWORD*)(this + 64)) >> 16)] ^ dword_AF9800[(v130 ^ (unsigned int)v80 ^ *(DWORD*)(this + 64)) >> 24];
	v82 = v81 + v80;
	v83 = dword_AF8C00[(unsigned __int8)v82] ^ dword_AF9000[BYTE1(v82)] ^ dword_AF9400[(unsigned __int8)(v82 >> 16)] ^ dword_AF9800[v82 >> 24];
	v84 = dword_AF8C00[(unsigned __int8)(v83 + v81)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v83 + v81) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v83 + v81) >> 16)] ^ dword_AF9800[(unsigned int)(v83 + v81) >> 24];
	v85 = v84 ^ v72;
	v86 = (v84 + v83) ^ v73;
	v87 = v86 ^ *(DWORD*)(this + 52);
	v88 = dword_AF8C00[(unsigned __int8)(v85 ^ v87 ^ *(_BYTE *)(this + 56))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v85 ^ v87 ^ *(_WORD *)(this + 56)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v85 ^ (unsigned int)v87 ^ *(DWORD*)(this + 56)) >> 16)] ^ dword_AF9800[(v85 ^ (unsigned int)v87 ^ *(DWORD*)(this + 56)) >> 24];
	v89 = v88 + v87;
	v90 = dword_AF8C00[(unsigned __int8)v89] ^ dword_AF9000[BYTE1(v89)] ^ dword_AF9400[(unsigned __int8)(v89 >> 16)] ^ dword_AF9800[v89 >> 24];
	v91 = dword_AF8C00[(unsigned __int8)(v90 + v88)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v90 + v88) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v90 + v88) >> 16)] ^ dword_AF9800[(unsigned int)(v90 + v88) >> 24];
	v131 = v91 ^ v130;
	v92 = (v91 + v90) ^ v79;
	v93 = v92 ^ *(DWORD*)(this + 44);
	v94 = dword_AF8C00[(unsigned __int8)(v131 ^ v93 ^ *(_BYTE *)(this + 48))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v131 ^ v93 ^ *(_WORD *)(this + 48)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v131 ^ (unsigned int)v93 ^ *(DWORD*)(this + 48)) >> 16)] ^ dword_AF9800[(v131 ^ (unsigned int)v93 ^ *(DWORD*)(this + 48)) >> 24];
	v95 = v94 + v93;
	v96 = dword_AF8C00[(unsigned __int8)v95] ^ dword_AF9000[BYTE1(v95)] ^ dword_AF9400[(unsigned __int8)(v95 >> 16)] ^ dword_AF9800[v95 >> 24];
	v97 = dword_AF8C00[(unsigned __int8)(v96 + v94)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v96 + v94) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v96 + v94) >> 16)] ^ dword_AF9800[(unsigned int)(v96 + v94) >> 24];
	v98 = v97 ^ v85;
	v99 = (v97 + v96) ^ v86;
	v100 = v99 ^ *(DWORD*)(this + 36);
	v101 = dword_AF8C00[(unsigned __int8)(v98 ^ v100 ^ *(_BYTE *)(this + 40))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v98 ^ v100 ^ *(_WORD *)(this + 40)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v98 ^ (unsigned int)v100 ^ *(DWORD*)(this + 40)) >> 16)] ^ dword_AF9800[(v98 ^ (unsigned int)v100 ^ *(DWORD*)(this + 40)) >> 24];
	v102 = v101 + v100;
	v103 = dword_AF8C00[(unsigned __int8)v102] ^ dword_AF9000[BYTE1(v102)] ^ dword_AF9400[(unsigned __int8)(v102 >> 16)] ^ dword_AF9800[v102 >> 24];
	v104 = dword_AF8C00[(unsigned __int8)(v103 + v101)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v103 + v101) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v103 + v101) >> 16)] ^ dword_AF9800[(unsigned int)(v103 + v101) >> 24];
	v132 = v104 ^ v131;
	v105 = (v104 + v103) ^ v92;
	v106 = v105 ^ *(DWORD*)(this + 28);
	v107 = dword_AF8C00[(unsigned __int8)(v132 ^ v106 ^ *(_BYTE *)(this + 32))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v132 ^ v106 ^ *(_WORD *)(this + 32)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v132 ^ (unsigned int)v106 ^ *(DWORD*)(this + 32)) >> 16)] ^ dword_AF9800[(v132 ^ (unsigned int)v106 ^ *(DWORD*)(this + 32)) >> 24];
	v108 = v107 + v106;
	v109 = dword_AF8C00[(unsigned __int8)v108] ^ dword_AF9000[BYTE1(v108)] ^ dword_AF9400[(unsigned __int8)(v108 >> 16)] ^ dword_AF9800[v108 >> 24];
	v110 = dword_AF8C00[(unsigned __int8)(v109 + v107)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v109 + v107) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v109 + v107) >> 16)] ^ dword_AF9800[(unsigned int)(v109 + v107) >> 24];
	v111 = v110 ^ v98;
	v112 = (v110 + v109) ^ v99;
	v113 = v112 ^ *(DWORD*)(this + 20);
	v114 = dword_AF8C00[(unsigned __int8)(v111 ^ v113 ^ *(_BYTE *)(this + 24))] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v111 ^ v113 ^ *(_WORD *)(this + 24)) >> 8)] ^ dword_AF9400[(unsigned __int8)((v111 ^ (unsigned int)v113 ^ *(DWORD*)(this + 24)) >> 16)] ^ dword_AF9800[(v111 ^ (unsigned int)v113 ^ *(DWORD*)(this + 24)) >> 24];
	v115 = v114 + v113;
	v116 = dword_AF8C00[(unsigned __int8)v115] ^ dword_AF9000[BYTE1(v115)] ^ dword_AF9400[(unsigned __int8)(v115 >> 16)] ^ dword_AF9800[v115 >> 24];
	v117 = dword_AF8C00[(unsigned __int8)(v116 + v114)] ^ dword_AF9000[(unsigned __int8)((unsigned __int16)(v116 + v114) >> 8)] ^ dword_AF9400[(unsigned __int8)((unsigned int)(v116 + v114) >> 16)] ^ dword_AF9800[(unsigned int)(v116 + v114) >> 24];
	v118 = (v117 + v116) ^ v105;
	v119 = v118;
	v118 = __ROL4__(v118, 8);
	v119 = __ROR4__(v119, 8);
	*(DWORD*)a3 = v118 & 0xFF00FF | v119 & 0xFF00FF00;
	v120 = __ROR4__(v117 ^ v132, 8);
	v121 = __ROL4__(v117 ^ v132, 8);
	*(DWORD*)(a3 + 4) = v121 & 0xFF00FF | v120 & 0xFF00FF00;
	v122 = __ROR4__(v112, 8);
	v112 = __ROL4__(v112, 8);
	*(DWORD*)(a3 + 8) = v112 & 0xFF00FF | v122 & 0xFF00FF00;
	v123 = v111;
	v111 = __ROL4__(v111, 8);
	v123 = __ROR4__(v123, 8);
	result = v111 & 0xFF00FF | v123 & 0xFF00FF00;
	*(DWORD*)(a3 + 0xC) = result;
	return result;
}