#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
*/

int firstUniqChar(string s) {
	int i, j, len = s.size();
	if (len == 0) return -1;
	//if(len == 1) return 0;
	vector<int> index(len, 0);
	for (i = 0; i<len; i++){
		if (index[i] == 1) continue;
		for (j = i + 1; j<len; j++){
			if (s[j] == s[i]){
				index[j] = 1;
				index[i] = 1;
			}
		}
		if (index[i] == 0) return i;
	}
	return -1;
}

int main(){
	cout << firstUniqChar("leetcode") << endl;
	return 0;
}
