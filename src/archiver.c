#include <stdio.h>
#include "zip.h"

int main (int argc, char* argv[]) {
	printf("Starting.\n");
	
	int err, argn=1;
	char mode[] = {'r', 'b'};
	char* filename;
	FILE* fp;
	while (argn < argc) {
		filename = argv[argn];
		printf("Reading zip: %s\n", filename);
		
		fp = fopen(filename, mode);
		readZip(fp);
		err = fclose(fp); 
		if (err != 0)
			if (err == EOF)	printf("Error EOF on file close.\n");
			else		printf("Error closing file.\n");
		
		argn++;
	}

	return 0;
}
