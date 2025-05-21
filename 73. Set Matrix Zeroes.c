/*
Problem: 73. Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/
*/

typedef struct {
    int *elements;
    int size;
    int capacity;
} UnorderedSet;

static UnorderedSet *create_set(int initial_capacity) {
    UnorderedSet *set = malloc(sizeof(UnorderedSet));
    set->elements = malloc(sizeof(int) * initial_capacity);
    set->size = 0;
    set->capacity = initial_capacity;
  
    return set;
}

static void resize_set(UnorderedSet *set) {
    set->capacity *= 2;
    set->elements = realloc(set->elements, sizeof(int) * set->capacity);
  
    return;
}

static void insert(UnorderedSet *set, int element) {
    int i;
    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return; // Element already exists
        }
    }
  
    if (set->size == set->capacity) {
        resize_set(set);
    }
  
    set->elements[set->size++] = element;
    return;  
}

static void free_set(UnorderedSet *set) {
    free(set->elements);
    free(set);
    return;  
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    UnorderedSet *rows = create_set(matrixSize);
    UnorderedSet *cols = create_set(matrixColSize[0]);
    int i, j;

    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                insert(rows, i);
                insert(cols, j);
            }
        }
    }

    for (i = 0; i < rows->size; i++) {
        for (j = 0; j < matrixColSize[0]; j++) {
            matrix[rows->elements[i]][j] = 0;
        }
    }

    for (j = 0; j < cols->size; j++) {
        for (i = 0; i < matrixSize; i++) {
            matrix[i][cols->elements[j]] = 0;
        }
    }

    free_set(rows);
    free_set(cols);

    return;
}
