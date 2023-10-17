/*
Link: https://leetcode.com/problems/validate-binary-tree-nodes/
Problem: 1361. Validate Binary Tree Nodes
*/
#define MEMCLEAR(a) memset(a, 0, sizeof(a))

static int countNodes(int root, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){
    if (root == -1){
        return 0;
    }
    
    return 1 
        + countNodes(leftChild[root], leftChild, leftChildSize, rightChild, rightChildSize) 
        + countNodes(rightChild[root], leftChild, leftChildSize, rightChild, rightChildSize);
}

bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){
    int inDegree[n], root = -1, i;
    
    MEMCLEAR(inDegree);
    
    for (i = 0; i < leftChildSize; i++){
        if (leftChild[i] != -1){
            inDegree[leftChild[i]]++;
            if (inDegree[leftChild[i]] >= 2){
                return false;
            }
        }
    }
    
    for (i = 0; i < rightChildSize; i++){        
        if (rightChild[i] != -1){
            inDegree[rightChild[i]]++;
            if (inDegree[rightChild[i]] >= 2){
                return false;
            }
        }
    }
        
    for (i = 0; i < n; i++){
        if (inDegree[i] == 0){
            if (root != -1) {            
                return false;
            }
            
            root = i;
        }
    }
    
    if (root == -1){
        return false;
    }

    
    return countNodes(root, leftChild, leftChildSize, rightChild, rightChildSize) == n;
}