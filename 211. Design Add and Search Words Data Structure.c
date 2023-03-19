/*
Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/
Problem: 211. Design Add and Search Words Data Structure
Approach:
Implement trie (prefix tree) data structure
*/

#define NUM_ALPHABETS   (26)
#define DEBUG 1
#define dprint(fmt, ...) do { if (DEBUG) printf("%s:%d:%s(): " fmt, __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)


typedef struct {
    struct WordDictionary *child[NUM_ALPHABETS];
    int end;
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    WordDictionary *obj = calloc(1, sizeof(WordDictionary));
    assert(obj);
    
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    assert(obj);
    assert(word);
    
    int len = strlen(word), i;
    char c;
    
    for (i = 0; i < len; i++){
        c = word[i] - 'a';
        if (obj->child[c] == NULL){
            obj->child[c] = calloc(1, sizeof(WordDictionary));
            assert(obj->child[c]);
        }
        
        obj = obj->child[c];
    }
    
    obj->end++;
}

static bool trieSearch(WordDictionary* obj, const const char * word, const int len, const int pos){
    if (word[pos] == '.'){
        bool ret = false;
        int i;
        WordDictionary *t = obj;
        for (i = 0; i < NUM_ALPHABETS; i++){
            if (pos == len - 1 && obj->child[i]){
                t = obj->child[i];
                ret |= t->end > 0 ? true : false;
            } else if (obj->child[i] && trieSearch(obj->child[i], word, len, pos + 1)){
                return true;
            }
        }
        
        return ret;
    } else if (obj->child[word[pos] - 'a']){
        if (pos == len - 1){
            obj = obj->child[word[pos] - 'a'];
            return obj->end > 0 ? true : false;
        }
        
        return trieSearch(obj->child[word[pos] - 'a'], word, len, pos + 1);
    }
    
    return false;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    assert(obj);
    assert(word);
    
    return trieSearch(obj, word, strlen(word), 0);
}

void wordDictionaryFree(WordDictionary* obj) {
    if (obj == NULL){
        return;
    }
   
    int i;
    
    for (i = 0; i < NUM_ALPHABETS; i++){
        if (obj->child[i]){
            wordDictionaryFree(obj->child[i]);
        }
    }
    
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
