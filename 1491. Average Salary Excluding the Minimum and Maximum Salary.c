/*
Link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
Problem: 1491. Average Salary Excluding the Minimum and Maximum Salary
*/
double average(int* salary, int salarySize){
    assert(salary);
    assert(salarySize > 2);
    int sum = 0, max = INT_MIN, min = INT_MAX, i;
    
    for (i = 0; i < salarySize; i++){
        sum += salary[i];
        max = salary[i] > max ? salary[i] : max;
        min = salary[i] < min ? salary[i] : min;
    }
    
    sum = sum - max - min;
    
    return (double)(sum)/(salarySize - 2);
}
