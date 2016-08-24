#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
189. Rotate Array  
Difficulty: Easy
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

void reverse(vector<int>& nums, int start, int end){
	int i;
	while (start<end){
		int tmp = nums[start - 1];
		nums[start - 1] = nums[end - 1];
		nums[end - 1] = tmp;
		start++;
		end--;
	}
}
void rotate(vector<int>& nums, int k) {
	k = k%nums.size();
	if (k == 0) return;
	reverse(nums, 1, nums.size() - k);
	reverse(nums, nums.size() - k + 1, nums.size());
	reverse(nums, 1, nums.size());
}

int main(){
	
	return 0;
}
