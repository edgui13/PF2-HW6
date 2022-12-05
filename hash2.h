#ifndef HASH_H
#define HASH_H

//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
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
    HashTable(const HashTable &ht);
    ~HashTable();

    // Methods
    void ReadTxt(string filename);
    string getVectValue(int pos);
    int getVectSize();
    int getNumCollision();
    int clearNumCollision();
    int getNumCounter();

    bool Insert(string key, int value);
    bool Search(string key, int &value);
    bool Delete(string key);
    void Print();

private:
    // Private methods
    int Hash(string key);
    int Hash2(int index);

    // Private data
    int Size;
    int *Value;
    string *Key;
    vector<string> wordStorage;
    int NumCounter = 0;
    int NumCollision;
};

#endif