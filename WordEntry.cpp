#include "WordEntry.h"

/* WordEntry contructors
* input: the string text (word) and the intial score the
*         word should be assigned to
*  note that numAppearances should be set to 1 here
*
*	The second just initialize an instance without atributes
*/
WordEntry::WordEntry(string text, int score){
 	word = text;
 	totalScore = score;
 	numAppearances = 1;
 	average = 0.0;
}

WordEntry::WordEntry(){
 	word = "";
 	totalScore = 0.0;
 	numAppearances = 0.0;
 	average = 0.0;
}

/* addNewAppearance
* input integer that is a new score for a word that is
* already in the hash table
* function should increase total score by s
* also should increase numAppearances
*/
void WordEntry::addNewAppearance(int s){
 	this->numAppearances += 1;
 	this->totalScore += s;
}

/*getWord
* this accessor function is needed
* particularly in the HashTable code to get the word to be
* used for the hash value
* simple accessor function  
*/
string WordEntry::getWord(){
    return word;
}

/*
	To insert word in a WordEntry that is not related to the hash
*/
void WordEntry::setWord(string word){
	this->word = word;
}

/* 
	This function is used to set the average for a instance that is being created and it not related to the main 
	Hash.
*/
void WordEntry::setAverage(double score){
	this->average = score;
}

/* getAverage
*  returns the average score of the word
*  based on totalScore and numAppearances
*  note that typecasting -- turning one of the integers
*  to a double will be necessary to avoid integer division
*/
double WordEntry::getAverage(){
	return double(totalScore)/numAppearances;
}

/* calcAverage
* Updates the instance's average
*/
void WordEntry::calcAverage(){
	this->average = double(totalScore)/numAppearances;
}



/* getApearences
*  output: the num of occurrences of a word
*/
int WordEntry::getAppearences(){
	return this->numAppearances;
}

/* setApearences
*  num: int that represents the number that will be set to the entry's appearence atribute
*/
void WordEntry::setAppearences(int num){
	this->numAppearances = num;
}

/**
 * @brief WordEntry::addPhrase: used to map the phrase id's to
 * @param id: int that represents the phrase's id
 */
void WordEntry::addPhrase(int id){
    if(!inArray(this->phrases, id)){
        this->phrases.push_back(id);
    }
}


/**
 * @brief WordEntry::getPhrases: used to get all the phrases that are linked to the word entry;
 * @return returns a vector of indices that are the phrase indices
 */
vector<string> WordEntry::getPhrases(PhraseTable* t_phrases){

    vector<string> s_phrases;

    for(int i=0; i< (int)this->phrases.size(); i++){
        // add all the phrases that are linked to the word to s_phrases vector
        string temp = t_phrases->get_phrase((int)this->phrases[i]);
        s_phrases.push_back(temp);
        temp.clear();
    }
    return s_phrases;
}


/**
 * @brief WordEntry::inArray overload
 * @param vec
 * @param word
 * @return
 */
bool WordEntry::inArray(vector<string> vec, string word){
            for(int i = 0; i < (int) vec.size(); i++){
            if(vec[i] == word)
        return true;
        }


    return false;
}


/**
 * @brief HashTable::inArray overload
 * @param vec
 * @param word
 * @return
 */
bool WordEntry::inArray(vector<int> vec, int num){
            for(int i = 0; i < (int) vec.size(); i++){
            if(vec[i] == num)
        return true;
        }


    return false;
}
