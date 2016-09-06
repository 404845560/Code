#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
136. Single Number  QuestionEditorial Solution  My Submissions

Given an array of integers, every element appears twice except for one. Find that single one.
*/
int singleNumber(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	map<int, int> m;
	int i;
	for (i = 0; i<nums.size(); i++){
		if (m.count(nums[i]) == 0) m[nums[i]] = 1;
		else{
			m[nums[i]]++;
		}
	}
	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++){
		if (iter->second == 1) break;
	}

	return iter->first;
}

int main(){
	return 0;
}