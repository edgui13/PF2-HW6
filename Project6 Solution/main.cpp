//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "hash2.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>

//-----------------------------------------------------------
// Function that checks if an integer is prime.
//-----------------------------------------------------------
bool check_prime(long number)
{
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (long factor = 3; factor <= sqrt(number); factor += 2)
        if (number % factor == 0)
            return false;
    return true;
}

//-----------------------------------------------------------
// Testing function
//-----------------------------------------------------------
int test(int size, int num1, int num2, int num3)
{
    // Create hash table
    HashTable hash(size, num1, num2, num3);

    // Open input file
    ifstream din;
    string filename = "google10000.txt";
    din.open(filename);
    if (din.fail())
    {
        cout << "Error: Could not open " << filename << " file\n";
        return -1;
    }

    // Read input file
    int count = 0;
    string word = "";
    while ((count < size) && (din >> word))
    {
        // Insert into hash table
        if (!hash.Insert(word, count++))
        {
            cout << "Error: Insert " << word << " " << count << " failed\n";
            return -1;
        }
    }

    // Close input file
    din.close();

    // Return collision count
    return hash.GetCollisions();
}

//-----------------------------------------------------------
// Main program
//-----------------------------------------------------------
int main()
{
    // Calculate table size
    int size = 40000;
    while (check_prime(size) == false)
        size++;

    // Calculate collisions for different hash functions
    srandom(time(0));
    for (int i = 0; i < 1000000; i++)
    {
        int num1 = 2 + random() % 1000;
        int num2 = 2 + random() % 1000;
        int num3 = 2 + random() % 1000;
        int collisions = test(size, num1, num2, num3);
        cout << collisions << " " << size << " "
             << num1 << " " << num2 << " " << num3 << endl;
    }
    return 0;
}
