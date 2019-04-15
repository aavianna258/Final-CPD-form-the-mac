#include "lists.h"



//  this class is being created in order to maintain the score order.
//  All the items will be added to the class at the same time they are added to the hash table
//  After finishing all the insertions, we order the vector. That makes the process really fast to get the worst and the best words


/**
 * @brief ScoresList::ScoresList
 * Class constructor
 */
Lists::Lists(HashTable *table)
{
    for (int i = 0; i < table->size; i++){
        for (auto it = table->hashTable[i].begin(); it != table->hashTable[i].end(); ++it)
        {
            if (it->getWord() != ""){
                this->addEntry(*it);
            }
        }
    }
    this->quick_sort();
}


/**
 * @brief ScoresList::addEntry
 * @param entry
 */
void Lists::addEntry(WordEntry entry){
    this->lista.push_back(entry);
    this->freq_list.push_back(entry);
}

/**
 * @brief ScoresList::getBestWords
 * @param k
 */
vector<WordEntry> Lists::getBestWords(int k){
    vector<WordEntry> ret;
    int start = this->lista.size()-1;
    int end = start-k;
    for (int i=start; i>end; i--){
        ret.push_back(this->lista[i]);
    }
    return ret;
}


/**
 * @brief ScoresList::getWorstWords
 * @param k
 */
vector<WordEntry> Lists::getWorstWords(int k){
    vector<WordEntry> ret;
    for (int i=0; i<k; i++){
        ret.push_back(this->lista[i]);
    }

    return ret;
}

/**
 * @brief ScoresList::quick_sort
 * Executes quick sort on the entries
 */
void Lists::quick_sort(){
    // sort by score
    this->quickSortR(this->lista, 0, this->lista.size()-1);
    //sort by frequency
    this->quickSortR_Freq(this->freq_list, 0, this->freq_list.size()-1);
}


/**
 * @brief ScoresList::quickSortR
 * @param arr
 * @param left
 * @param right
 *
 */
void Lists::quickSortR(vector<WordEntry>& arr, int left, int right) {
      int i = left, j = right;
      WordEntry tmp;
      double pivot = arr[(left + right) / 2].getAverage();

      /* partition */
      while (i <= j) {
            while (arr[i].getAverage() < pivot)
                  i++;
            while (arr[j].getAverage() > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            this->quickSortR(arr, left, j);
      if (i < right)
            this->quickSortR(arr, i, right);
}


/**
 * @brief Lists::quickSortR_Freq
 * @param arr
 * @param left
 * @param right
 */
void Lists::quickSortR_Freq(vector<WordEntry>& arr, int left, int right) {
      int i = left, j = right;
      WordEntry tmp;
      int pivot = arr[(left + right) / 2].getAppearences();

      /* partition */
      while (i <= j) {
            while (arr[i].getAppearences() < pivot)
                  i++;
            while (arr[j].getAppearences() > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            this->quickSortR_Freq(arr, left, j);
      if (i < right)
            this->quickSortR_Freq(arr, i, right);
}

vector<WordEntry> Lists::getFreqWords(int k){
    vector<WordEntry> ret;
    int start = this->freq_list.size()-1;
    int end = start-k;
    for (int i=start; i>end; i--){
        ret.push_back(this->freq_list[i]);
    }

    return ret;
}
