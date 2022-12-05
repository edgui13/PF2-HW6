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
    if (Key != NULL)
        delete[] Key;
    Value = NULL;
    Key = NULL;
    Size = 0;
}

void HashTable::ReadTxt(string filename)
{
    // Open input file
    string word;
    ifstream din;
    din.open(filename);
    if (din.fail())
        return;

    // Loop reading houses
    // HashTable hash;
    // hash.clear();
    while (!din.eof())
    {
        // Read from input file
        // house.read_txt(din);
        getline(din, word);
        // Store in vector
        if (!din.eof())
            wordStorage.push_back(word);
    }

    // Close files
    din.close();
}

string HashTable::getVectValue(int pos)
{
    return wordStorage[pos];
}

int HashTable::getVectSize()
{
    return wordStorage.size();
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
    if (NumCounter >= Size)
    {
        return 0;
    }
    NumCounter--;
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
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(string key, int value)
{
    if (NumCounter >= Size)
    {
        return 0;
    }
    NumCounter++;
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
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(string key)
{
    int num = 42;
    for (int i = 0; i < int(key.length()); i++)
    {

        // num = (num * 1312 + key[i]) % Size;
        // num = (num * 1311 + key[i]) % Size;
        num = (num * 131 + key[i]) % Size;
    }
    return num;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
    // cout << "collision\n";
    NumCollision++;
    // return (index + 99) % Size;
    // return (index + 7) % Size;
    return (index + 13) % Size;
}

//----------------`-------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    for (int index = 0; index < Size; index++)
        if (Value[index] > 0)
            cout << Value[index] << "\t" << Key[index] << "\n";
}

//-----------------------------------------------------------
// get counter from number of collisions
//-----------------------------------------------------------
int HashTable::getNumCollision()
{
    return NumCollision;
}

int HashTable::clearNumCollision()
{
    NumCollision = 0;
    return NumCollision;
}

//-----------------------------------------------------------
// get counter from number of items in the hashtable
//-----------------------------------------------------------
int HashTable::getNumCounter()
{
    return NumCounter;
}