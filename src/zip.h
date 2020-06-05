#include <stdio.h>
#include <stdlib.h>

#define SIGNATURE 0x504b0304
#define OTHER_SIG 0x04034b50 //???

typedef struct zipMeta {
	long signature;			// = 0x504b0304; //4 bytes constant
	short version;			// 2 bytes
	short flags;			// 2 bytes
	short compression;		// 2 bytes
	short modTime;			// 2 bytes MS-DOS format (bit0-4 s/2, b5-10 m, b 11-15 h)
	short modDate;			// 2 bytes MS-DOS format (bit0-4 day, b5-8 M, bit9-15 y+1980)
	long crc32; 			// checksum of file data in CRC-32 with magic number '0xdebb20e3 (little endian)'
	long compressedSize;	// 4bytes if zip64 format, filled with 0xffffffff length in extra field
	long uncompressedSize;	// 4 bytes, if zip64 same as above.
	long fileNameLen;		// 4bytes, length of file name field
	long extraFieldLen;		// 4bytes, length of extra field
	char* fileName;			// fileNameLen size. all slashes should be forward '/'
	short* extraField;		// extraFieldLen size. 2byte headers followed by 2 byte data.
} zipMeta;

int readZip(FILE*);