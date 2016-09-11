#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
213. House Robber I
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for 
his thievery so that he will not get too much attention. This time, all houses at this
place are arranged in a circle. That means the first house is the neighbor of the last
one. Meanwhile, the security system for these houses remain the same as for those in the
previous street.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/
int rob(vector<int>& nums) {
	int len = nums.size();
	if (len == 0) return 0;
	if (len == 1) return nums[0];
	if (len == 2) return max(nums[0], nums[1]);
	vector<int> result(len, 0);
	int i;
	/*第一个到倒数第二个的最大值*/
	result[0] = nums[0];
	result[1] = max(nums[0], nums[1]);//
	for (i = 2; i<len - 1; i++)
		result[i] = max(result[i - 2] + nums[i], result[i - 1]);
	int res1 = result[len - 2];
	/*第二个到倒数第一个*/
	result[1] = nums[1]; //重新赋值
	result[2] = max(nums[1], nums[2]);
	for (i = 3; i<len; i++)
		result[i] = max(result[i - 2] + nums[i], result[i - 1]);

	int res2 = result[len - 1];
	return max(res1, res2);
}
int main(){
	return 0;
}