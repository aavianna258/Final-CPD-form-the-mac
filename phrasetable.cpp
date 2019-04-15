#include "phrasetable.h"


/**
 * @brief PhraseTable::PhraseTable
 * Constructor
 */


PhraseTable::PhraseTable()
{

}


void PhraseTable::add_phrase(string phrase)
{
    this->phrases_table.push_back(phrase);
}

string PhraseTable::get_phrase(int id)
{
    return this->phrases_table[id];
}
