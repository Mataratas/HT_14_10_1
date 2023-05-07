#pragma once
#include<iostream>
#include <vector>
#include <string>

#define ALPHABET_SIZE 26



struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, если ключ является концом слова
	bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, const std::string&);
bool search(struct TrieNode*, std::string);
void propose_words(struct TrieNode*, const std::string& key,std::vector<std::string>&);
void clean_up(TrieNode*&);

