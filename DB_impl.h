/* DB_impl.h
 *
 * For any "private"  declarations that should not be visible to the public
 * users of the database, but might want to be shared across various source
 * files in database implementation.
 * 
 * It is a common convention to append "_impl" to a private implementation of
 * some public interface, so we do so here.
 *
 * Author: <TODO: Group Member Names>
 * Lab instructor: <TODO: Your lab instructor's name here>
 * Lecture instructor: <TODO: Your lecture instructor's name here>
 */


#ifndef DB_IMPL_H
#define DB_IMPL_H

#include <stddef.h>

typedef struct{
    int tableId;
    int siteId;
    unsigned int tableTypeId : 4;
    unsigned int surfaceMaterialId : 4;
    unsigned int structuralMaterialId : 4;
    char* streetAve;
    unsigned int neighbourhoodId;
    char* neighbourhoodName;
    char* ward;
    double latitude;
    double longitude;
}PicnicTable;

//Table and NeighbourhoodTable structs will be created depending on user request to save memory
typedef struct{
    unsigned int code : 4; //specifies what data the table is holding
    char value[25]; //string to specify table
    PicnicTable** entries; //2D array to hold entries depending on their specification
    int count; //total entries in table
}Table;

typedef struct{
    void* key; //key for hashing
    void* values; //could be one value could be linked list or array
    size_t count; //number of entries with associated key
}entry;

typedef struct{
    entry* entries; //pointer to entries in hashtable
    size_t size; //size of hashtable
    size_t countKey; //number of entries in hashtable
    size_t countVals; //total picnic tables
}NeighbourhoodTable;

//this is where all picnic tables will be stored - hash created by unique identifier
typedef struct{
    entry* entries; //pointer to entries in hashtable
    size_t size; //size of hashtable
    size_t count; //number of entries in hashtable
}MainHashtable;


#endif