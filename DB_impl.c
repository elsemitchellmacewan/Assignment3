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

PicnicTable *createPicnicTable(char *input){
    PicnicTable* pt = calloc(1, sizeof(PicnicTable));
    char* token = strtok(input, ",");
    int i = 0;
    while(token != NULL){
        if(i == 0){
            pt->tableId = atio(token);
        } else if(i == 1){
            pt->siteId = atio(token);
        } else if(i == 2){
            pt->tableTypeId = (unsigned int)atio(token);
        } else if(i == 3){
            pt->surfaceMaterialId = (unsigned int)atio(token);
        } else if(i == 4){
            pt->structuralMaterialId = (unsigned int)atio(token);
        } else if(i == 5){
            pt->streetAve = malloc(strlen(token) + 1);
            if(pt->streetAve == NULL){
                fprintf(stderr, "Could not allocate memory for streetAve");
                return;
            }
            strcpy(pt->streetAve, token);
        } else if(i == 6){
            pt->neighbourhoodId = (unsigned int)atio(token);
        } else if(i == 7){
            pt->neighbourhoodName = malloc(strlen(token) + 1);
            if(pt->neighbourhoodName == NULL){
                fprintf(stderr, "Could not allocate memory for neighbourhoodName");
                return;
            }
            strcpy(pt->neighbourhoodName, token);
        } else if(i == 8){
            pt->ward = malloc(strlen(token) + 1);
            if(pt->ward == NULL){
                fprintf(stderr, "Could not allocate memory for ward");
                return;
            }
            strcpy(pt->ward, token);
        } else if(i == 9){
            pt->latitude = (double)atof(token);
        } else if(i == 10){
            pt->longitude = (double)atof(token);
        }
        token = strtok(NULL, ",");
        i++;
    }
}