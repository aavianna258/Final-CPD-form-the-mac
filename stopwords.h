#ifndef STOPWORDS_H
#define STOPWORDS_H

#include <string>
#include <vector>
#include <fstream>


#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

class StopWords
{
public:
    StopWords();
    vector<string> getWords();
    void addWord(string s);
    bool inArray(string word);

private:
    vector <string> words;

};

#endif // STOPWORDS_H
