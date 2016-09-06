#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	while (cin >> n >> m){
		vector<int> price(n, 0);
		vector<string> name(m, "");
		int minprice = 0, maxprice = 0;

		int i, j;
		for (i = 0; i < n; i++) cin >> price[i];
		sort(price.begin(), price.end());//对价格升序
		for (i = 0; i < m; i++) cin >> name[i];
		map<string, int> m_name;
		for (i = 0; i < m; i++){
			if (m_name.count(name[i]) == 0) m_name[name[i]] = 1;
			else m_name[name[i]]++;
		}
		vector<int> uniquename;
		for (map<string, int>::iterator itr = m_name.begin(); itr != m_name.end(); itr++){
			uniquename.push_back(itr->second);
		}
		sort(uniquename.begin(), uniquename.end());//升序
		for (i = 0; i < uniquename.size(); i++){
			minprice += price[uniquename.size()-i-1] * uniquename[i];
			maxprice += price[n - uniquename.size()+i] * uniquename[i];

		}
		cout << minprice << " " << maxprice << endl;
	}
	return 0;
}