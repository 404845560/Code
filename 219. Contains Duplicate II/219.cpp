#include <iostream>
#include <map>
#include <vector>
using namespace std;
/*

219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two 
distinct indices i and j in the array such that nums[i] = nums[j] and the 
difference between i and j is at most k.
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	int i, j;
	map<int, int> m;
	for (i = 0; i<nums.size(); i++){
		if (m.count(nums[i]) == 0) m[nums[i]] = i;
		else{
			if (i - m[nums[i]] <= k) return true;
			else m[nums[i]] = i;
		}
	}
	return false;
}

int main(){
	return 0;
}