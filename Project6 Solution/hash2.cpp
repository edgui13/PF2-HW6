//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "hash2.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
    Size = size;
    Value = new int[Size];
    Key = new string[Size];
    Collisions = 0;

    // The hash function parameters below result in 1400 collisions
    // when inserting 10,000 words into a hash table of size 40,009.
    // These three values were found by evaluating 1,000,000 random
    // combinations of parameter values between [2..1000].  John
    Num1 = 144; // Used in Hash
    Num2 = 388; // Used in Hash
    Num3 = 102; // Used in Hash2

    for (int index = 0; index < Size; index++)
    {
        Value[index] = NONE;
        Key[index] = EMPTY;
    }
}

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size, int num1, int num2, int num3)
{
    Size = size;
    Value = new int[Size];
    Key = new string[Size];
    Collisions = 0;
    Num1 = num1;
    Num2 = num2;
    Num3 = num3;

    for (int index = 0; index < Size; index++)
    {
        Value[index] = NONE;
        Key[index] = EMPTY;
    }
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable &ht)
{
    Size = ht.Size;
    Value = new int[Size];
    Key = new string[Size];
    Collisions = ht.Collisions;
    Num1 = ht.Num1;
    Num2 = ht.Num2;
    Num3 = ht.Num3;

    for (int index = 0; index < Size; index++)
    {
        Value[index] = ht.Value[index];
        Key[index] = ht.Key[index];
    }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
    if (Value != NULL)
        delete[] Value;
    Value = NULL;
    if (Key != NULL)
        delete[] Key;
    Key = NULL;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(string key, int value)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Insert value into hash table
    Value[index] = value;
    Key[index] = key;
    return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(string key, int &value)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Return value from hash table
    if (Key[index] == key)
        value = Value[index];
    return (Key[index] == key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(string key)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Delete value from hash table
    if (Key[index] == key)
    {
        Value[index] = NONE;
        Key[index] = DELETED;
        return true;
    }
    return false;
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(string key)
{
    long int hash = Num1;
    for (int i = 0; i < int(key.length()); i++)
        hash = (hash * Num2 + key[i]) % Size;
    return hash;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
    Collisions++;
    return (index + Num3) % Size;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    for (int index = 0; index < Size; index++)
        if (Value[index] > 0)
            cout << index << "\t" << Value[index] << "\t" << Key[index] << "\n";
}

//-----------------------------------------------------------
// Get collision count
//-----------------------------------------------------------
int HashTable::GetCollisions()
{
    return Collisions;
}
