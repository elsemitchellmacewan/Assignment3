/* DB_impl.c
 *
 * TODO: Provide a high-level description of what is contained
 * in this file.
 *
 * Author: <TODO: Group Member Names>
 * Lab instructor: <TODO: Your lab instructor's name here>
 * Lecture instructor: <TODO: Your lecture instructor's name here>
 */

#include "DB.h"      /* Import the public database header. */
#include "DB_impl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long hash(int h){
    unsigned long long hash = 5831;
    double gr = 1.618033988;
    hash *= gr * h;
    return hash % 12;
}

unsigned int tableType(char *str){
    if(strcmp(str, "Square Picnic Table") == 0){
        return 1;
    } else if(strcmp(str, "Round Picnic Table") == 0){
        return 2;
    } else if(strcmp(str, "Other Table") == 0){
        return 3;
    } else {
        return 0;
    }
}

unsigned int surfaceMaterial(char *str){
    if(strcmp(str, "Wood") == 0){
        return 1;
    } else if(strcmp(str, "Concrete") == 0){
        return 2;
    } else if(strcmp(str, "Metal") == 0){
        return 3;
    } else {
        return 0;
    }
}

unsigned int structuralMaterial(char *str){
    if(strcmp(str, "Aggregate") == 0){
        return 1;
    } else if(strcmp(str, "Metal") == 0){
        return 2;
    } else if(strcmp(str, "Wood") == 0){
        return 3;
    } else {
        return 0;
    }
}

PicnicTableData *createPicnicTable(char *input){
    PicnicTableData* pt = calloc(1, sizeof(PicnicTableData));
    if(pt == NULL){
        fprintf(stderr, "Could not allocate memory for picnic table");
        return NULL;
    }
    char* token = strtok(input, ",");
    int i = 0;
    while(token != NULL){
        if(i == 0){
            pt->tableId = atoi(token);
        } else if(i == 1){
            pt->siteId = hash(pt->tableId);
            i++;
            continue;
        } else if(i == 2){
            pt->tableTypeId = tableType(token);
        } else if(i == 3){
            pt->surfaceMaterialId = surfaceMaterial(token);
        } else if(i == 4){
            pt->structuralMaterialId = structuralMaterial(token);
        } else if(i == 5){
            pt->streetAve = malloc(strlen(token) + 1);
            if(pt->streetAve == NULL){
                fprintf(stderr, "Could not allocate memory for streetAve");
                return NULL;
            }
            strcpy(pt->streetAve, token);
        } else if(i == 6){
            pt->neighbourhoodId = (unsigned int)atoi(token);
        } else if(i == 7){
            i++;
            continue;
        } else if(i == 8){
            pt->ward = 1;
        } else if(i == 9){
            pt->latitude = (double)atof(token);
        } else if(i == 10){
            pt->longitude = (double)atof(token);
        }
        token = strtok(NULL, ",");
        i++;
    }
    return pt;
}