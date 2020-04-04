/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <iterator>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;



int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t!=0){

		map< string, vector<string> > orders;
		for(int j=0;j<t;j++){
		string line;
		getline(cin,line);
		stringstream ss(line);
		string person;
		ss>>person;
		string cur;
		while(ss>>cur){
			orders[cur].push_back(person);
		}
		}

		for(map<string, vector<string> >::iterator it=orders.begin();it!=orders.end();++it){
			vector<string> cv=it->second;
			sort(cv.begin(),cv.end());
			cout<<it->first<<" ";
			for(int i=0;i<cv.size();i++){
				cout<<cv[i]<<" ";
			}
			cout<<'\n';
		}
		cout<<'\n';

		cin>>t;
		cin.ignore();
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/