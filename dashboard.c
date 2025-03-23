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

void readFile(char *filename, DataBase *db);
void printTable(DataBase *db, int len);

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    Db = malloc(sizeof(DataBase));
    if(Db == NULL){
        fprintf(stderr, "Memory allocation failed for Database!\n");
        return 1;
    }
    readFile(argv[1], Db);

    printTable(Db, 11);

    freeDB();

    return 0;
}

void readFile(char *str, DataBase *db){
    FILE *fp = fopen(str, "r");
    if(fp == NULL){
        fprintf(stderr, "Could not open file %s\n", str);
        return;
    }
    char inputBuf[200];
    db->picnicTableTable = malloc(sizeof(PicnicTable));
    db->picnicTableTable->picnicTables = calloc(11, sizeof(PicnicTableData));
    if(db->picnicTableTable->picnicTables == NULL){
        fprintf(stderr, "Could not allocate memory for picnic table");
        return;
    }
    int i = 0;
    fgets(inputBuf, 200, fp);
    while(fgets(inputBuf, 200, fp) != NULL){
        *(db->picnicTableTable->picnicTables+i) = createPicnicTable(inputBuf);
        if(db->picnicTableTable->picnicTables == NULL){
            fprintf(stderr, "Could not create picnic table\n");
            return;
        }
        db->picnicTableTable->count = ++i;
    }
    fclose(fp);
}

void printTable(DataBase *db, int len){
    for(int i = 0; i < len; i++){
        printf("Table ID: %d\n", db->picnicTableTable->picnicTables[i]->tableId);
        printf("Site ID: %u\n", db->picnicTableTable->picnicTables[i]->siteId);
        printf("Table Type ID: %u\n", db->picnicTableTable->picnicTables[i]->tableTypeId);
        printf("Surface Material ID: %u\n", db->picnicTableTable->picnicTables[i]->surfaceMaterialId);
        printf("Structural Material ID: %u\n", db->picnicTableTable->picnicTables[i]->structuralMaterialId);
        printf("Street/Ave: %s\n", db->picnicTableTable->picnicTables[i]->streetAve);
        printf("Neighbourhood ID: %d\n", db->picnicTableTable->picnicTables[i]->neighbourhoodId);
        printf("Neighbourhood Name: %s\n", db->picnicTableTable->picnicTables[i]->neighbourhoodName);
        printf("Ward: %s\n", db->picnicTableTable->picnicTables[i]->ward);
        printf("Latitude: %lf\n", db->picnicTableTable->picnicTables[i]->latitude);
        printf("Longitude: %lf\n\n", db->picnicTableTable->picnicTables[i]->longitude);
    }
}
