#include <iostream>
#include <vector>
using namespace std;
/*
264. Ugly Number II 

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/
int minnum(int a, int b, int c){
	int min = a>b ? b : a;
	return min>c ? c : min;
}
int nthUglyNumber(int n) {
	/*
	1��N�ĳ���Ϊ 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, �� ��
	���Էֳ��������飺

	(1) 1��2, 2��2, 3��2, 4��2, 5��2, ��
	(2) 1��3, 2��3, 3��3, 4��3, 5��3, ��
	(3) 1��5, 2��5, 3��5, 4��5, 5��5, ��
	ע�⣺ÿ�У�2��3��5����ϵ��Ϊresult�в�����ϵ��

	ֻ��Ҫ��֤ÿ�ε����Ĺ�����ѡȡ��С�ĳ���������˵�������������������Ϊ�����������ǰ����������2,3,5�ĳ˻���
	*/
	int i;
	if (n == 1) return 1;
	vector<int> result(n, 0);
	result[0] = 1;
	int index2, index3, index5;
	index2 = index3 = index5 = 0;  //��ʼֵΪ0
	/*
	for(i=1;i<n;){
	int min=minnum(2*result[index2],3*result[index3],5*result[index5]);

	if(result[i-1] != min){ //ȥ��
	result[i]=min;
	i++;
	}

	if(min == 2*result[index2]) index2++;
	else if(min == 3*result[index3]) index3++;
	else index5++;
	}
	*/
	//
	for (i = 1; i<n; i++){
		int min = minnum(2 * result[index2], 3 * result[index3], 5 * result[index5]);
		result[i] = min;
		//������ ���������ӣ���ʱֻ���һ��
		if (min == 2 * result[index2]) index2++;
		if (min == 3 * result[index3]) index3++;
		if (min == 5 * result[index5]) index5++;
	}
	return result[n - 1];
}

int main(){
	return 0;
}