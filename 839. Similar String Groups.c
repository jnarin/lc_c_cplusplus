/*
Link: https://leetcode.com/problems/similar-string-groups/submissions/
Problem: 839. Similar String Groups
*/

static int getDiff(char *s1, char *s2){
    assert(s1);
    assert(s2);
    
    int len = strlen(s1), diff = 0, i;
    for (i = 0; i < len; i++){
        if (s1[i] != s2[i]){
            diff++;
        }
    }
    
    return diff;
}

static void dfs(char **strs, int strsSize, int i, bool *visited){
    if (i >= strsSize){
        return;
    }
    
    int j;
    
    for (j = 0; j < strsSize; j++){
        if (i == j){
            continue;
        }
        
        assert(strs[j]);
        
        visited[i] = true;
        if (visited[j] == false){
            if (getDiff(strs[i], strs[j]) <= 2){
                dfs(strs, strsSize, j, visited);
            }
        }
    }
}

int numSimilarGroups(char ** strs, int strsSize){
    assert(strs);

    bool visited[strsSize];
    memset(visited, 0, sizeof(visited));
    
    int i, ans = 0;
    
    for (i = 0; i < strsSize; i++){
        assert(strs[i]);
        if (visited[i] == false){
            dfs(strs, strsSize, i, visited);
            ans++;
        }
    }

    return ans;
}