#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include "WordEntry.h"

#include <fstream>
#include <cstdlib>


using namespace std;

class HashTable {

    public:
        HashTable(int);
        WordEntry* finds(string);
        bool contains(string);
        double getAverage(string);
        void puts(string,int, int);
        void print();
        vector<WordEntry> worstWords(int num);
        vector<WordEntry> bestWords(int num);
        vector<WordEntry> freqWords(int num);
        bool inArray(vector<WordEntry> vec, string word);
        bool inArray(vector<string> vec, string word);
        bool inArray(vector<int> vec, int num);
        bool stopWord(string word, vector<string> stopWords);
        vector<string> get_stopWords(string file);

        list<WordEntry> *hashTable;		// array of doubly linked lists
        int size;						// size/length of the hash table
        int computeHash(string);

};

#endif
