#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/
bool isIsomorphic(string s, string t) {
	if (s.size() != t.size()) return false;
	if (s == t) return true;
	map<char, char> m1;
	for (int i = 0; i<s.size(); i++){
		if (m1.count(s[i]) == 0) m1[s[i]] = t[i];
		else{
			if (m1[s[i]] != t[i]) return false;
		}
	}
	map<char, int> m2;
	for (map<char, char>::iterator itr = m1.begin(); itr != m1.end(); itr++){
		if (m2.count(itr->second) == 0) m2[itr->second] = 1;
		else return false;
	}
	return true;
}
int main(){
	return 0;
}