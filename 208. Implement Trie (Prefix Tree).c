/*
Link: https://leetcode.com/problems/implement-trie-prefix-tree/
Problem: 208. Implement Trie (Prefix Tree)
Approach:
Implement trie data structure
*/


typedef struct {
	int end;
	struct Trie *child[26];
} Trie;


Trie* trieCreate() {
	Trie *obj = calloc(1, sizeof(Trie));
	assert(obj);
	return obj;
}

void trieInsert(Trie* obj, char * word) {
	assert(obj);
	assert(word);
	
	int len = strlen(word), i, idx;
	Trie *node = obj;
	
	for (i = 0; i < len; i++){
		idx = word[i] - 'a';
		if (node->child[idx] == NULL){
			node->child[idx] = calloc(1, sizeof(Trie));
		}
		node = node->child[idx];
	}
	
	node->end += 1;
}

bool trieSearch(Trie* obj, char * word) {
	assert(word);
	
	int len = strlen(word), i, idx;
	Trie *node = obj;
	
	if (node == NULL){
		return false;
	}
	
	for (i = 0; i < len; i++){
		node = node->child[word[i] - 'a'];
		if (node == NULL){
			return false;
		}
	}
	
	return node->end ? true : false;
}

bool trieStartsWith(Trie* obj, char * prefix) {
	assert(prefix);
	
	int len = strlen(prefix), i, idx;
	Trie *node = obj;
	
	if (node == NULL){
		return false;
	}
	
	for (i = 0; i < len; i++){
		node = node->child[prefix[i] - 'a'];
		if (node == NULL){
			return false;
		}
	}
	
	return true;
}

void trieFree(Trie* obj) {
	int i;
	
	if (obj == NULL){
		return;
	}
	
	for (i = 0; i < 26; i++){
		if (obj->child[i] != NULL){
			trieFree(obj->child[i]);
		}
	}
	
	free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/