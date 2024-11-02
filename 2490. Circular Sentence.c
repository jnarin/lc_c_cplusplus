/*
Problem: 2490. Circular Sentence
Link: https://leetcode.com/problems/circular-sentence/
*/

bool isCircularSentence(char* sentence) {
    int len = strlen(sentence), i;
    
    for (i = 0; i < len; i++) {
        if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
            return false;
        }
    }
    
    return sentence[0] == sentence[len - 1];
}
