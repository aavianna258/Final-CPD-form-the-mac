#ifndef PHRASETABLE_H
#define PHRASETABLE_H

#include <string>
#include <tuple>
#include <vector>
using namespace std;

class PhraseTable
{
public:
    PhraseTable();
    void add_phrase(string phrase);
    string get_phrase(int id);
    bool inArray(vector<string> vec, string word);
    vector<string> phrases_table;
private:   
    //the first indice corresponds to the first phrase and so on


};

#endif // PHRASETABLE_H
