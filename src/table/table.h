#ifndef __TABLE_H_
#define __TABLE_H_

#include "../../libs/EmeraldsBool/export/EmeraldsBool.h"

#include <stddef.h> /* size_t */

/**
 * @brief Data oriented table with open addressing and linear probing
 * @param keys -> The keys of the hash table
 * @param values -> The values of the hash table
 * @param buckets -> The buckets of the hash table
 * @param size -> The size of the hash table
 */
typedef struct EmeraldsHashtable {
  const char **keys;
  size_t *values;
  size_t *buckets;
  size_t size;
} EmeraldsHashtable;

/**
 * @brief Creates a new hash table
 * @return EmeraldsHashtable* -> A new allocation
 */
EmeraldsHashtable *hashtable_new(void);

/**
 * @brief Rehashes when bucket count reaches the laod factor
 * @param self -> The hash table
 * @param bucket_count_new -> The new bucket count
 */
void hashtable_rehash(EmeraldsHashtable *self, size_t bucket_count_new);

/**
 * @brief Inserts a key-value pair into the hash table (open addressing)
 * @param self -> The hash table
 * @param key -> The key
 * @param value -> The value
 */
void hashtable_insert(EmeraldsHashtable *self, const char *key, size_t value);

/**
 * @brief Linear probing lookup
 * @param self -> The hash table
 * @param key -> The key
 * @return size_t* -> The pointer to the value or NULL if not found
 */
size_t *hashtable_lookup(EmeraldsHashtable *self, const char *key);

/**
 * @brief Removes a key-value pair from the hash table
 * @param self -> The hash table
 * @param key -> The key
 * @return true -> The key-value pair was removed
 * @return false -> The key-value pair was not found
 */
bool hashtable_remove(struct EmeraldsHashtable *self, char *key);

/**
 * @brief Deallocates all vectors
 * @param self -> The hash table
 */
void hashtable_free(EmeraldsHashtable *self);

#endif
