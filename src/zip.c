#include "zip.h"

int freeZipMeta(zipMeta* zipM){
    // TODO:
    // free(zipM->fileName);
    // free (zipM->extraField);
    free(zipM);
    return 0;
}

zipMeta* readMeta(FILE* fp) {
    zipMeta* zipM = malloc(sizeof(zipMeta));
    zipM->signature = 0;
    fread(&zipM->signature, 4, 1, fp);

    if (zipM->signature == SIGNATURE) printf("Validated header signature.\n");
    else if (zipM->signature == SIGNATURE) printf("Validated header to other signature.\n");
    else {
        printf("Failed to validate signature.\n");
        return NULL;
    }
    printf("Signature: %#lx~~\n", zipM->signature);
    
    return zipM;
}

/* Errors:
    1. failed to load meta
 */
int readZip(FILE* fp) {
	//fread(void ptr, size_t size of elements, size_t number of elements, fp);
    zipMeta* zipM = readMeta(fp);
    if (zipM == NULL) {
        printf("Encountered an error loading Meta data, exiting.");
        return 1;
    }

    freeZipMeta(zipM);
    return 0;
}
