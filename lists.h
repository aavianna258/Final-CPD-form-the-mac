#ifndef SCORESLIST_H
#define SCORESLIST_H

#include "WordEntry.h"
#include <vector>
#include <HashTable.h>

class Lists
{
public:

    Lists(HashTable* table);
    void addEntry(WordEntry entry);
    void quick_sort();
    vector<WordEntry> getBestWords(int k);
    vector<WordEntry> getWorstWords(int k);
    vector<WordEntry> getFreqWords(int k);
    void quickSortR(vector<WordEntry>& arr, int left, int right);
    void quickSortR_Freq(vector<WordEntry>& arr, int left, int right);


private:
    vector<WordEntry> lista;
    vector<WordEntry> freq_list;
};

#endif // SCORESLIST_H
