/*
Problem: 85. Maximal Rectangle
Link: https://leetcode.com/problems/maximal-rectangle/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
	int ans = 0;
	if (matrixSize == 0 || matrixColSize[0] == 0) {
		return ans;
	}
	
	int heights[matrixColSize[0] + 1];
  memset(heights, 0, sizeof(heights));
	int i, j;
	
	for (i = 0; i < matrixSize; i++) {
		int stack[matrixColSize[0] + 1], stackTop = -1;
		memset(stack, 0, sizeof(stack));
		
		for (j = 0; j < matrixColSize[0] + 1; j++) {
			if (j < matrixColSize[0]) {
				heights[j] = (matrix[i][j] == '1') ? heights[j]+1 : 0;
			}
			
			while (stackTop >= 0 && heights[j] < heights[stack[stackTop]]) {
				int c = stack[stackTop--];
				ans = MAXVAL(ans, heights[c] * (stackTop == -1 ? j : (j - 1 - stack[stackTop])));
			}
			
			stack[++stackTop] = j;
		}
	}
	
    return ans;
}
