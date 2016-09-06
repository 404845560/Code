#include <iostream>
#include <vector>
using namespace std;
int f(int x){
	int result = 0;
	while (x>0){

		result += x % 10;
		x = x / 10;

	}
	return result;
}
int g(int x){
	int result = 0;
	while (x > 0){
		if(x % 2 == 1) result++;
		x = x >> 1;
	}
	return result;
}
int main(){
	int n;
	cin >> n;
	int i,j;
	vector<int> m(n);
	int max = -1;
	for (i = 0; i < n; i++){
		cin >> m[i];
		if (max < m[i]) max = m[i];
	}
	vector<int> v(max,0);
	v[0] = 1;
	for (i = 1; i < max; i++){
		if (f(i + 1) == g(i + 1)) v[i] = v[i - 1] + 1;
		else v[i] = v[i - 1];
	}

	for (i = 0; i < n; i++) cout << v[m[i]-1] << endl;
	return 0;
}