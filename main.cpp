#include "Trie.h"
//======================================================================================================================

int main() {

	std::string keys[] = {"today","tool","tomorrow","the","thin","thick","thanks",
					"summer", "sunday","squiz","afterparty" };

	//std::string keys[] = { "today","tool","the","thin","thick" };
					


	int n = sizeof(keys) / sizeof(keys[0]);

	struct TrieNode* root = getNewNode();
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	std::string key;
	std::vector<std::string> words;

	while (true) {
		std::cout << "Type initial part of word(* to exit) :\n";
		std::cin >> key;
		
		if (key == "*")
			break;


		propose_words(root, key, words);

		std::cout << "Possible words:\n";

		if (!words.size())
			std::cout << '\t' << "! no match !" << std::endl;
		else
			for (const auto& w : words)
				std::cout << '\t' << w << std::endl;

		key.clear();
		words.clear();

	}

	clean_up(root);

	return 0;
}