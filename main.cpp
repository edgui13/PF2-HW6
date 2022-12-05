//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     Edgar Alcocer
//-----------------------------------------------------------
#include "hash2.h"
#include <stdlib.h>
#include <vector>

//-----------------------------------------------------------
//  Testing function
//-----------------------------------------------------------
int main()
{
    int size = 10000;

    HashTable wordsTable(2 * size);
    cout << "-----Welcome to Project 6-----" << endl;
    wordsTable.ReadTxt("google10000.txt");
    // Test insert method
    for (int count = 0; count < size; count++)
    {
        if (wordsTable.Insert(wordsTable.getVectValue(count - 1), count))
        {
            wordsTable.getVectValue(count);
            // cout << "Insert " << wordsTable.getVectValue(count) << "\n";
        }
        else
        {
            wordsTable.getVectValue(count);
            // cout << "Insert " << wordsTable.getVectValue(count) << " failed\n";
        }
    }
    wordsTable.Print();
    cout << "size of the hash table is " << wordsTable.getNumCounter() << endl;
    cout << "The number of collisions for inserting are " << wordsTable.getNumCollision() << endl;
    wordsTable.clearNumCollision();

    // Test search method
    cout << endl;
    for (int count = 0; count < size; count++)
    {
        if (wordsTable.Search(wordsTable.getVectValue(count), count))
        {
            wordsTable.getVectValue(count);
            // cout << "Search " << wordsTable.getVectValue(count) << " found\n";
        }
        else
        {
            wordsTable.getVectValue(count);
            // cout << "Search " << wordsTable.getVectValue(count) << " not found\n";
        }
    }
    cout << "The number of collisions for search are " << wordsTable.getNumCollision() << endl;
    wordsTable.clearNumCollision();

    // Test delete method
    cout << endl;
    for (int count = 0; count < size; count++)
    {
        if (wordsTable.Delete(wordsTable.getVectValue(count)))
        {
            wordsTable.getVectValue(count);
            // cout << "Delete " << wordsTable.getVectValue(count) << "\n";
        }
        else
        {
            wordsTable.getVectValue(count);
            // cout << "Delete " << wordsTable.getVectValue(count) << " failed\n";
        }
    }
    cout << "The number of collisions for deleting are " << wordsTable.getNumCollision() << endl;
    wordsTable.clearNumCollision();
    wordsTable.Print();
    cout << "size of the hash table is " << wordsTable.getNumCounter() << endl;
}