#include <iostream>
#include <vector>
using namespace std;
/*
313. Super Ugly Number  QuestionEditorial
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/
int min(vector<int>& primes, vector<int>& index, vector<int>& result){
	int minnum = primes[0] * result[index[0]];
	for (int i = 1; i<index.size(); i++){
		if (primes[i] * result[index[i]]<minnum)
			minnum = primes[i] * result[index[i]];
	}
	return minnum;
}
int nthSuperUglyNumber(int n, vector<int>& primes) {
	if (n == 1) return 1;
	vector<int> result(n, 0);
	result[0] = 1;
	int i, j;
	int primesnum = primes.size();
	vector<int> index(primesnum, 0); //初始值为0
	/*去重
	for(i=1;i<n;){
	int minnum = min(primes,index,result);
	if(result[i-1] != minnum){ //去重
	result[i] = minnum;
	i++;
	}

	for(j=0;j<primesnum;j++){
	if(primes[j]*result[index[j]] == minnum){
	index[j]++;
	break;
	}
	}

	}
	*/
	//不需要去重
	for (i = 1; i<n; i++){
		int minnum = min(primes, index, result);
		result[i] = minnum;

		for (j = 0; j<primesnum; j++){
			if (primes[j] * result[index[j]] == minnum){
				index[j]++; //因为重复的话 索引都会增加
			}
		}

	}
	return result[n - 1];
}

int main(){
	return 0;
}