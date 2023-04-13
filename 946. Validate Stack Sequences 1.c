/*
Link: https://leetcode.com/problems/validate-stack-sequences/
Problem: 946. Validate Stack Sequences 1
*/

#define MAX_SIZE	(1001)

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	int stack[MAX_SIZE], sp = 0;
	int i, j, t;
	
	assert(pushed);
	assert(pushedSize != 0);
	assert(popped);
	assert(poppedSize != 0);
	
	i = j = 0;
	while (i < pushedSize && j < poppedSize){
		if (sp && stack[sp - 1] == popped[j]){
            sp--;
            j++;
            continue;
		}
        
        stack[sp] = pushed[i];
        sp++;
        i++;
	}
	
	if (i >= pushedSize){
		while (j < poppedSize){
			if (sp){
				if (stack[sp - 1] == popped[j]){
					sp--;
					j++;
					continue;
				} else {
					break;
				}
			}
		}
	}
	
	return (i == j && sp == 0);
}