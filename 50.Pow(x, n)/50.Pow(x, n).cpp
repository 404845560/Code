#include <iostream>
using namespace std;
/*
50. Pow(x, n)
Implement pow(x, n).
*/
double myPow(double x, int n) {
	//���õݹ� n�Ķ�����
	if (n == 0) return 1;
	if(x == 1) return 1;
	//�˴���Ҫע��
	if (n == INT_MIN) return (1 / x)*myPow(x, n + 1); // -2147483648 ==> -2147483647
	
	if (n<0) x = 1 / x;

	int nn = abs(n);
	double result = 1;
	int i;
	double tmp = x;
	while (nn != 0){
		i = nn % 2;
		if (i == 1){
			result *= tmp;
		}
		tmp *= (tmp); //�˴���Ҫע��
		nn = nn >> 1;
	}
	return result;

}

int main(){
	cout << myPow(2.000,-2147483648) << endl;

	return 0;

}