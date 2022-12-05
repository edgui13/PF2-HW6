#ifndef HASH_H
#define HASH_H

//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
using namespace std;
const int NONE = 0;
const string EMPTY = "-1";
const string DELETED = "-2";

//-----------------------------------------------------------
// Define the HashTable class interface
//-----------------------------------------------------------
class HashTable
{
public:
    // Constructors
    HashTable(int size);
    HashTable(int size, int num1, int num2, int num3);
    HashTable(const HashTable &ht);
    ~HashTable();

    // Methods
    bool Insert(string key, int value);
    bool Search(string key, int &value);
    bool Delete(string key);
    void Print();
    int GetCollisions();

private:
    // Private methods
    int Hash(string key);
    int Hash2(int index);

    // Private data
    int Size;
    int *Value;
    string *Key;
    int Collisions;
    int Num1;
    int Num2;
    int Num3;
};

#endif
