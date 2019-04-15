#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

#include "phrasetable.h"


using namespace std;

class WordEntry {

    private:
        string word;
        int numAppearances;
        int totalScore;
        double average;


    public:
    	WordEntry();
        WordEntry(string,int);
        void addNewAppearance(int);
        string getWord();
        void setWord(string word);
        double getAverage();
        void calcAverage();
        void setAverage(double score);
        int getAppearences();
        void setAppearences(int num);
        void addPhrase(int id);
        vector<string> getPhrases(PhraseTable *t_phrases);
        vector<int> phrases;
        bool inArray(vector<string> vec, string word);
        bool inArray(vector<int> vec, int num);

};
#endif
