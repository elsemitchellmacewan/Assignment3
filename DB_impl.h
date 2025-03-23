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

//this is where all picnic tables will be stored - hash created by unique identifier
typedef struct{
    entry* entries; //pointer to entries in hashtable
    size_t size; //size of hashtable
    size_t count; //number of entries in hashtable
}MainHashtable;

PicnicTable *createPicnicTable(char *input);

#endif