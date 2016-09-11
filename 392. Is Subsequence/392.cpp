#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
392. Is Subsequence
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t.
t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original 
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (ie, "ace" is a subsequence of
"abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.
*/
bool isSubsequence(string s, string t) {
	int s_size = s.size();
	int t_size = t.size();
	if (s_size == 0) return true;
	vector<int> result(s_size, 0);
	int start = 0;
	for (int i = 0; i<t_size; i++){
		for (int j = start; j<s_size; j++){
			if (s[j] == t[i]){
				result[j] = j == 0 ? 1 : result[j - 1] + 1;
				j++;
				while (j<s_size){
					result[j] = result[j - 1]; j++;
				}
				start++;
			}
		}
		if (start == s_size) return true;
	}
	return false;
}
int main(){
	return 0;
}