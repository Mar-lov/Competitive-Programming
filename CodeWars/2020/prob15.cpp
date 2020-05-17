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

string toLower(string s){
	for(int i=0;i<s.length();i++){
		s[i]=tolower(s[i]);
	}
	return s;
}

int main() {
	int n,m;
	cin>>n>>m;
	cin.ignore();
	while(!(n==0&&m==0)){
		//cout<<n<<" "<<m<<'\n';
		 string f,s;
		 getline(cin,f);
		 getline(cin,s);

		//begin solution
	unordered_set<string> ctns;
	stringstream fs(f);
	stringstream ss(s);
	set<string> ans;
	string cur;
	for(int i=0;i<n;i++){
		fs>>cur;
		ctns.insert(toLower(cur));
	}
	for(int i=0;i<m;i++){
		ss>>cur;
		cur=toLower(cur);
		if(ctns.count(cur)==1){
			ans.insert(cur);
		}
	}
	cout<<f<<'\n';
	cout<<s<<'\n';
	cout<<ans.size()<<" ";
	for(set<string>::iterator it=ans.begin();it!=ans.end();++it){
			cout<<*it<<" ";
	}
	cout<<'\n';
		//end solution 
		cin>>n>>m;
		cin.ignore();
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/