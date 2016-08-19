#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
		P   A   H   N
		A P L S I I G
		Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
*/
string convert(string s, int numRows) {
	int len = s.size();
	if (numRows == 1 || numRows >= len) return s;
	vector<string> tmp(numRows, "");
	int i, j;
	int start = 0, flag = 0;
	for (i = 0; i<len; i++){
		if (start == 0) flag = 0;
		else if (start == numRows-1) flag = 1;
		if (flag == 0){
			tmp[start] += s[i];
			start++;
		}
		else if (flag == 1){
			tmp[start] += s[i];
			start--;
		}
	}
	string result = "";
	for (i = 0; i<numRows; i++)
		result += tmp[i];
	return result;

}

int main(){
	string str = "ABC";
	cout << convert(str, 2) << endl;
	return 0;
}