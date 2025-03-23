/*
 * dashboard.c
 *
 * TODO: Provide a high-level description of what is contained
 * in this file.
 *
 * Author: <TODO: Group Member Names>
 * Lab instructor: <TODO: Your lab instructor's name here>
 * Lecture instructor: <TODO: Your lecture instructor's name here>
*/

//You may include other original headers as you see fit
#include "DB.h"
#include "DB_impl.h"
#include <stdio.h>
#include <stdlib.h>

void printTable(PicnicTable **pt, int len);

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }
    char inputBuf[200];
    PicnicTable **pt = calloc(12, sizeof(PicnicTable));
    if(pt == NULL){
        fprintf(stderr, "Could not allocate memory for picnic table");
        return 1;
    }
    int i = 0;
    fgets(inputBuf, 200, fp);
    while(fgets(inputBuf, 200, fp) != NULL){
        *(pt+i) = createPicnicTable(inputBuf);
        if(pt == NULL){
            fprintf(stderr, "Could not create picnic table\n");
            return 1;
        }
        i++;
    }
    fclose(fp);

    printTable(pt, 12);

    for(int j = 0; j < i; j++){
        free(pt[j]->streetAve);
        free(pt[j]->neighbourhoodName);
        free(pt[j]->ward);
        free(pt[j]);
    }
    free(pt);

    return 0;
}

void printTable(PicnicTable **pt, int len){
    for(int i = 0; i < len; i++){
        printf("Table ID: %d\n", pt[i]->tableId);
        printf("Site ID: %u\n", pt[i]->siteId);
        printf("Table Type ID: %u\n", pt[i]->tableTypeId);
        printf("Surface Material ID: %u\n", pt[i]->surfaceMaterialId);
        printf("Structural Material ID: %u\n", pt[i]->structuralMaterialId);
        printf("Street/Ave: %s\n", pt[i]->streetAve);
        printf("Neighbourhood ID: %d\n", pt[i]->neighbourhoodId);
        printf("Neighbourhood Name: %s\n", pt[i]->neighbourhoodName);
        printf("Ward: %s\n", pt[i]->ward);
        printf("Latitude: %lf\n", pt[i]->latitude);
        printf("Longitude: %lf\n", pt[i]->longitude);
    }
}
