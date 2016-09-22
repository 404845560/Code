#include <string>
#include <iostream>
using namespace std;
/*
38. Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
*/
string say(string str){
	string result = "";
	int i, j;
	int len = str.size();
	for (i = 0; i<len;){
		int num = 1;
		for (j = i + 1; j<len; j++){
			if (str[j] == str[i]) num++;
			else break;
		}
		result += (to_string(num) + str.substr(i, 1));
		i = j;

	}
	return result;
}
string countAndSay(int n) {
	int i;
	string tmp = "1";
	string result = "1";
	for (i = 1; i<n; i++){
		result = say(tmp);
		tmp = result;
	}
	return result;
}
int main(){
	return 0;
}