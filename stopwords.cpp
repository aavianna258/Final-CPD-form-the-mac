#include "stopwords.h"

StopWords::StopWords()
{

    string file = "stopwords.txt";
    vector<string> temp_words;
    string line;

    ifstream myfile (file);
    if (myfile.fail() )
    {
        cout << "error: stopwords file not opened" <<endl;
        exit(0);
    }
    while (! myfile.eof() )
    {
        myfile >> line;
        transform(line.begin(), line.end(),line.begin(), :: toupper);
        this->words.push_back(line);
    }
    myfile.close();


/*
    this->words.push_back("A");
    this->words.push_back("THE");
    this->words.push_back(".");
    this->words.push_back(",");
    this->words.push_back("AN");
    this->words.push_back("IS");
    this->words.push_back("OF");
    this->words.push_back("IT");
    this->words.push_back("AND");
    this->words.push_back("AS");
    this->words.push_back("THAT");
    this->words.push_back("BUT");

*/

}

/**
 * @brief StopWords::addWord
 * @param s
 */
void StopWords::addWord(string s){
    this->words.push_back(s);
}

/**
 * @brief StopWords::getWords
 * @return
 */
vector<string> StopWords::getWords(){
    return this->words;
}


/**
 * @brief StopWords::inArray overload
 * @param word
 * @return
 */
bool StopWords::inArray(string word){

    auto found = find(this->words.begin(), this->words.end(), word);
            if(found == this->words.end())
                return false;
            else
                return true;


    /*
    for(int i = 0; i < (int) this->words.size(); i++){
        if(this->words[i] == word)
            return true;
    }


    return false;
    */
}
