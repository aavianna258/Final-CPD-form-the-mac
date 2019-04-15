#include "TrieTree.h"
#include "WordEntry.h"

Node* Node::findChild(char c)
{
    for ( int i = 0; i < (int) mChildren.size(); i++ )
    {
        Node* tmp = mChildren.at(i);
        if ( tmp->content() == c )
        {
            return tmp;
        }
    }

    return NULL;
}


string Node::getWord(){
	return this->word;
}

void Node::setWord(string s){
	this->word = s;
}

Trie::Trie()
{
    root = new Node();
}

Trie::~Trie()
{
    // Free memory
}

void Trie::addWord(string s)
{
	transform(s.begin(), s.end(),s.begin(), ::toupper);
    Node* current = root;

    if ( s.length() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < (int) s.length(); i++ )
    {        
        Node* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == (int) s.length() - 1 ){
        	current->setWord(s);
            current->setWordMarker();
        }
    }
}


bool Trie::searchWord(string s)
{
    Node* current = root;

    while ( current != nullptr )
    {
    	// passes throught the string letter by letter
        for ( int i = 0; i < (int) s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == nullptr )
                return false;
            current = tmp;
        }

        if ( current->wordMarker() ){
            return true;
        }
        else{
            return false;
        }
    }

    return false;
}


/* 
	Returns all elements that have the given string as prefix 
*/


vector<string> Trie::searchPrefix(string s)
{
	transform(s.begin(), s.end(),s.begin(), ::toupper);
    Node* current = root;
    vector<string> vet;

    while ( current != nullptr )
    {
    	// passes throught the string letter by letter
        for ( int i = 0; i < (int) s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == nullptr )
                return vet;
            current = tmp;
        }

        if (current->wordMarker())
        	vet.push_back(s); 

        return getBellow(current);
    }

    return vet;

}


/**
 * @brief Trie::getBellow
 * @param current
 * @return
 */
vector<string> Trie::getBellow(Node* current)
{
    vector<string> vet;
    if ( current != nullptr && current->wordMarker() ){
    	vet.push_back(current->getWord());
    }

    for( int k = (int)' '; k < (int)'~'; k++ ){
    	Node* temp = current->findChild((char)k);
    	if( temp != nullptr){
    		vector<string> rec = this->getBellow(temp);
    		vet.insert(vet.end(), rec.begin(), rec.end());
    	}

    }
    return vet; 
}
