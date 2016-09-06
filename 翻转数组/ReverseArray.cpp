#include <iostream>
#include <vector>
using namespace std;
/*
翻转数组

题目描述

给定一个长度为n的整数数组a，元素均不相同，问数组是否存在这样一个片段，只将该片段翻转就可以使整个数组升序排列。
其中数组片段[l,r]表示序列a[l], a[l+1], ..., a[r]。原始数组为

a[1], a[2], ..., a[l-2], a[l-1], a[l], a[l+1], ..., a[r-1], a[r], a[r+1], a[r+2], ..., a[n-1], a[n]，

将片段[l,r]反序后的数组是

a[1], a[2], ..., a[l-2], a[l-1], a[r], a[r-1], ..., a[l+1], a[l], a[r+1], a[r+2], ..., a[n-1], a[n]。

输入:

第一行数据是一个整数：n (1≤n≤105)，表示数组长度。

第二行数据是n个整数a[1], a[2], ..., a[n] (1≤a[i]≤109)。

输出:

输出“yes”，如果存在；否则输出“no”，不用输出引号。

样例输入

4

2 1 3 4

样例输出

yes
*/
bool findarray(vector<int>& a){
	if (a.size() == 1) return true;
	int i;
	int indexi, indexj;
	for (i = 1; i < a.size(); i++){
		if (a[i] < a[i - 1]){
			indexi = i - 1;
			indexj = i;
			while (a[indexj] < a[indexj - 1] && indexj < a.size()) indexj++;
			if (indexi == 0 && indexj == a.size()) return  true;
			else if (indexi == 0){
				return a[indexi] < a[indexj];
			}
			else if (indexj == a.size()){
				return a[indexi - 1] < a[indexj - 1];
			}
			else{
				return a[indexi] < a[indexj] && a[indexi - 1] < a[indexj - 1];
			}
		}
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (findarray(a)) cout << "yes";
	else cout << "no";
	return 0;
}