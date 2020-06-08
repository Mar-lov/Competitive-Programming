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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

string s;

bool isPeriod(int k){
	string c=s.substr(0,k);
	for(int l=0;l<s.length();l+=k){
		if(c!=s.substr(l,k)) return false;
		if(k>1){
			c.insert(c.begin(),c.back());
			c.erase(c.end()-1);
		}
		//cout<<c<<'\n';
	}
	return true;
};

int main() {
	getline(cin,s);
	for(int i=1;i<=s.length();i++){
		//cout<<i<<"\n";
		if(s.length()%i==0&&isPeriod(i)){
			cout<<i<<'\n';
			return 0;
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/