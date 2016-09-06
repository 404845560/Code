#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
290. Word Pattern
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

*/
vector<string> split(string str){
	vector<string> result;
	string tmp = str;
	while (tmp.find_first_of(" ") != -1){
		result.push_back(tmp.substr(0, tmp.find_first_of(" ")));
		tmp = tmp.substr(tmp.find_first_of(" ") + 1);
	}
	result.push_back(tmp);
	return result;
}
bool wordPattern(string pattern, string str) {
	if (pattern.size() == 0 || str.size() == 0) return false;
	vector<string> s = split(str);
	if (s.size() != pattern.size()) return false;
	map<char, string> m; //判断同类是否不同
	for (int i = 0; i<s.size(); i++){
		if (m.count(pattern[i]) == 0) m[pattern[i]] = s[i];
		else{
			if (m[pattern[i]] != s[i]) return false;
		}
	}
	map<string, int> m1; //判断不同类是否相同
	for (map<char, string>::iterator itr = m.begin(); itr != m.end(); itr++){
		if (m1.count(itr->second) == 0) m1[itr->second] = 1;
		else return false;
	}
	return true;
}
int main(){
	cout << wordPattern("abba", "dog dog dog dog") << endl;

	return 0;
}