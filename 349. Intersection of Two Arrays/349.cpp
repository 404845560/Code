#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
349. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> result;
	if (nums1.size() == 0 || nums2.size() == 0) return result;
	map<int, int> m;
	int i;
	for (i = 0; i < nums1.size(); i++){
		if (m.count(nums1[i]) == 0) m[nums1[i]] = 1;
		//else m[nums1[i]] ++;
	}
	for (i = 0; i < nums2.size(); i++){
		if (m.count(nums2[i]) == 1 && m[nums2[i]] != 0){ //±ÜÃâmapÉ¾³ý²Ù×÷
			result.push_back(nums2[i]);
			m[nums2[i]] = 0;
		}

	}
	return result;
}

int main(){
	return 0;
}