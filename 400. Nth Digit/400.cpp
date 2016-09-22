#include <string>
#include <iostream>
using namespace std;
/*
400. Nth Digit
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
int findNthDigit(int n) {
	//if(n<10) return n;
	int m = n;
	long long num = 9;  //考虑越界
	long long s = 1;    //考虑越界
	long long start = 1;  //考虑越界
	int result;
	while (m>num){ //
		s++;
		start *= 10;
		int tmp = 9 * start;
		m -= num;
		num = s*tmp;
	}
	int index = (m - 1) % s;
	string str = to_string(start + (m - 1) / s);
	result = str[index] - '0';

	return result;
}
int main(){
	return 0;
}