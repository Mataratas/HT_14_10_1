#include "Trie.h"

//======================================================================================================================
TrieNode* getNewNode() {
    // ¬ыдел€ем пам€ть под новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым указателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}
//-----------------------------------------------------------------------------------------------------------------------
void insert(TrieNode* root, const std::string& key) {
    struct TrieNode* current = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!current->children[index])
            current->children[index] = getNewNode();

        current = current->children[index];
    }

    current->isEndOfWord = true;
}
//-----------------------------------------------------------------------------------------------------------------------
bool search(struct TrieNode* root, std::string key) {
    struct TrieNode* current = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!current->children[index])
            return false;

        current = current->children[index];
    }

    return (current->isEndOfWord);

}
//-----------------------------------------------------------------------------------------------------------------------
void get_word(struct TrieNode* root, std::string& word, bool& found, std::vector<std::string>& v) {
    for (size_t i = 0; i < ALPHABET_SIZE; i++){
        if (root->children[i]) {
            word.push_back(static_cast<char>(i + 'a'));
            if (root->children[i]->isEndOfWord) {
                v.push_back(word);
                found = true;
                word = word.substr(0,word.size()-1);
                continue;
            }                
            struct TrieNode* current = root->children[i];
            get_word(current, word,found,v);
        }
    }
    if(found)
        word = word.substr(0, word.size() - 1);//

}
//-----------------------------------------------------------------------------------------------------------------------
void propose_words(struct TrieNode* root, const std::string& key,std::vector<std::string>& v) {

    int num_found{};
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (root->children[index])
            num_found++;

        if (num_found == key.length()) {
            for (size_t j = 0; j < ALPHABET_SIZE; j++){
                if (root->children[index]->children[j]) {
                    std::string word = key;
                    bool found{ false };
                    word.push_back(static_cast<char>(j + 'a'));
                    if (root->children[index]->children[j]->isEndOfWord) {
                        v.push_back(word);
                        word = key;
                    }else
                        get_word(root->children[index]->children[j], word, found, v);
                }
            }
        }
        root = root->children[index];
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void clean_up(struct TrieNode* &root) {
    for (size_t i = 0; i < ALPHABET_SIZE; i++){
        if (root->children[i]) {
            struct TrieNode* current = root->children[i];
            clean_up(current);
        }
    }
    if (root) {
        delete root;
        root = nullptr;
    }
        
}
//-----------------------------------------------------------------------------------------------------------------------

