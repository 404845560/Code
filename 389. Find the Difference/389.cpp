#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
389. Find the Difference  QuestionEditorial Solution  My Submissions

Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.
*/
char findTheDifference(string s, string t) {
	int i;
	map<char, int> m;
	for (i = 0; i<s.size(); i++){
		if (m.count(s[i]) == 0)    m[s[i]] = 1;
		else m[s[i]] ++;
	}

	for (i = 0; i<t.size(); i++){
		if (m.count(t[i]) == 0) return t[i];
		else m[t[i]]--;
	}
	map<char, int>::iterator  iter;
	for (iter = m.begin(); iter != m.end(); iter++){
		if (iter->second != 0) break;
	}
	return iter->first;
}

int main(){
	return 0;
}