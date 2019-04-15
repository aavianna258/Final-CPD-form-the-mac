#ifndef TRIETREE_H
#define TRIETREE_H

#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include "WordEntry.h"
#include <map>
#include <vector> 

using namespace std;


class Node {
public:
    Node() { 
    	mContent = ' '; mMarker = false; 
    }
    ~Node() {

    }
    char content() { 
    	return mContent; 
    }
    void setContent(char c) { 
    	mContent = c; 
    }
    bool wordMarker() { 
    	return mMarker; 
    }
    void setWordMarker() { 
    	mMarker = true; 
    }
    Node* findChild(char c);
    void appendChild(Node* child) { 
    	mChildren.push_back(child); }
    vector<Node*> children() { return mChildren;}

    string getWord();
	void setWord(string s);

private:
	string word;
    char mContent;
    bool mMarker;
    vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s);
    vector<string>  searchPrefix(string s);
    vector<string> getBellow(Node* current);
    void deleteWord(string s);
private:
    Node* root;
};




#endif
