/* DB.c
 *
 * TODO: Provide a high-level description of what is contained
 * in this file.
 *
 * Author: <TODO: Group Member Names>
 * Lab instructor: <TODO: Your lab instructor's name here>
 * Lecture instructor: <TODO: Your lecture instructor's name here>
 */

#include "DB.h"       /* Import the public database header. */
#include "DB_impl.h"  /* Import the private database header */
#include <stdlib.h>

DataBase *Db = NULL;

void freeDB(){
    for(int i = 0; i < Db->picnicTableTable->count; i++){
        free(Db->picnicTableTable->picnicTables[i]->streetAve);
        free(Db->picnicTableTable->picnicTables[i]->neighbourhoodName);
        free(Db->picnicTableTable->picnicTables[i]->ward);
        free(Db->picnicTableTable->picnicTables[i]);
    }
    free(Db->picnicTableTable->picnicTables);
    free(Db->picnicTableTable);
    free(Db);
}