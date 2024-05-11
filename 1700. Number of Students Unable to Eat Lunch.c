/*
 * Problem: 1700. Number of Students Unable to Eat Lunch
 * Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
 * */

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int i, count[2] = {0};

    for (i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }

    for (i = 0; i < sandwichesSize; i++) {
        if (count[sandwiches[i]] == 0) {
            return sandwichesSize - i;
        }

        count[sandwiches[i]]--;
    }

    return 0;
}
