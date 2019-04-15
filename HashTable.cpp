#include "HashTable.h"
#include "WordEntry.h"


/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s)
{
	hashTable = new list<WordEntry>[s];		// dinamicaly allocates memory for the an array of lists of size s
	size = s;								
}

/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  polinomial acumulation method is used for obtaining hash
*/
int HashTable::computeHash(string s)
{
	unsigned int hash = 0;					// unsigned int is used instead of int to ensure overflow wont ocur
    for (int j = 0; j < (int) s.size(); j++) {
		hash = 31 * hash + int(s[j]);
	}
	return (hash % size);
}

/*	finds
*  input: string word to be found in the table
*  output: returns pointer to the object corresponding to input s
*			if s is not in the table, returns NULL
*/
WordEntry* HashTable::finds(string s) {
	// i is the index of the list of WordEntry's with the same hash
	int i = computeHash(s);						
	// alist is the list of the elements with the hash key i
	list<WordEntry>& alist = hashTable[i];					

	// uses iterator of the list class to traverse the list
	// if a WordEntry with s is found, returns a pointer to it
	for (auto it = alist.begin(); it != alist.end(); ++it)
		if (it->getWord() == s)
			return &(*it);

	return NULL;
}

/* put
*  input: string word and int score to be inserted
*  First, looks to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::puts(string s, int score, int phrase_id) {

	transform(s.begin(), s.end(),s.begin(), ::toupper);
	WordEntry* wordp = finds(s);

	// refine the entry here!
	if (wordp != NULL) {
		wordp->addNewAppearance(score);
        wordp->addPhrase(phrase_id);
	}
	else {
		int index = computeHash(s);
		WordEntry word(s, score);
        //if()

        word.addPhrase(phrase_id);
        //cout << word.phrases[word.phrases.size()-1] << endl;
		hashTable[index].push_back(word);
	}
}

/* getAverage
*  input: string word
*  output: average score of the word
*  First, finds the WordEntry in the hash table
*  If not found, returns the value 2.0 (neutral result)
*  If found, returns the average score
*/
double HashTable::getAverage(string s) {
	WordEntry* wordp = finds(s);
	if (wordp == NULL)
		return 2.0;
	else
		return wordp->getAverage();
}


/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
* uses the same approach of the finds() function
*/
bool HashTable::contains(string s) {
	int i = computeHash(s);
	list<WordEntry> alist = hashTable[i];

	for (auto it = alist.begin(); it != alist.end(); ++it)
		if (it->getWord() == s)
			return true;
	return false;
}

/*	print
*	prints the hash table
*/
void HashTable::print() {
	for (int i = 0; i < size; i++){
		for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
			cout << it->getWord() << ", " << it->getAverage() << endl;
	cout << endl;
	}
}

/**
*
*	Returns the most negative word
*
*/
vector<WordEntry> HashTable::worstWords(int num){					
	string word;
	double low;

	
	vector<WordEntry> topWorstWords;
	WordEntry rWord;
	for (int j=0; j<num; j++){
		low = 6.0;
		for (int i = 0; i < size; i++){
			for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
			{
				// if the word is not in the array, and it is lower than the last lower
				if (it->getAverage() < low && !this->inArray(topWorstWords, it->getWord())) {
					low = it->getAverage();
					word = it->getWord();
				}
			}
				
		}
		// we add the worst word for each loop
		rWord.setWord(word);
		rWord.setAverage(low);
		topWorstWords.push_back(rWord);
	}
	return topWorstWords;
}

/**
*
*	Returns the best word
*
*/
vector<WordEntry> HashTable::bestWords(int num){					
	string word;
	double high;
	WordEntry rWord;
	vector<WordEntry> topbestWords;
	for(int i = 0; i < num; i++){
		high = -1.0;
		for (int i = 0; i < size; i++){
			for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
				if (it->getAverage() > high && !this->inArray(topbestWords, it->getWord())){
					high = it->getAverage();
					word = it->getWord();
				}
			}
		rWord.setWord(word);
		rWord.setAverage(high);
		topbestWords.push_back(rWord);
	}
	rWord.setAverage(high);
	rWord.setWord(word);
	return topbestWords;
}

/**
 * @brief HashTable::inArray
 * @param vec
 * @param word
 * @return
 */
bool HashTable::inArray(vector<WordEntry> vec, string word){
            for(int i = 0; i < (int) vec.size(); i++){
			if(vec[i].getWord() == word)
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
bool HashTable::inArray(vector<string> vec, string word){
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
bool HashTable::inArray(vector<int> vec, int num){
            for(int i = 0; i < (int) vec.size(); i++){
            if(vec[i] == num)
        return true;
        }


    return false;
}


/**
 * @brief HashTable::freqWords return the num most freq words from the training file
 * @param num: Int that represent the number of words that will be returned
 * @return vectore of WordEntry's
 */
vector<WordEntry> HashTable::freqWords(int num){
	int max = 0;
	double avg = 0.0;
	string word;
	vector<WordEntry> mfq;
	WordEntry rWord;
	for (int j=0; j<num; j++){
		max = 0;
		for (int i = 0; i < this->size; i++){
			for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
			{
				// if the word is not in the array, and it is lower than the last lower
				if (it->getAppearences() > max && !this->inArray(mfq, it->getWord())) {
					max = it->getAppearences();
					avg = it->getAverage();
					word = it->getWord();
				}
			}
				
		}
		// we add the word with a the begest number of appearences
		rWord.setWord(word);
		rWord.setAverage(avg);
		rWord.setAppearences(max);
		mfq.push_back(rWord);
	}



	return mfq;

}

/**
 * @brief HashTable::stopWord: Function that will verify if a word is an stop word.
 * @param word: string that represents the word that will be analized
 * @param stopWords: vector of strings that represent the stopwords
 * @return: True if the word is in the array or false, otherwise
 */
bool HashTable::stopWord(string word, vector<string> stopWords){
    if(this->inArray(stopWords, word)){
        return true;
    }
    return false;
}

/**
 * @brief HashTable::get_stopWords
 * @param file
 * @return
 */
vector<string> HashTable::get_stopWords(string file){

    vector<string> words;
    string line;

    ifstream myfile (file);
    if (myfile.fail() )
    {
        cout << "error: file not opened" <<endl;
        exit(0);
    }
    while (! myfile.eof() )
    {
        getline(myfile,line);
        transform(line.begin(), line.end(),line.begin(), ::toupper);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        words.push_back(line);
    }



    return words;
}


