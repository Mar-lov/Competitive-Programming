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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

string br(int n){
	string s="";
	while(n>0){
		if((n&1)==1) s+="1";
		else s+="0";
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}

bool isCyclops(int n){
	string s=br(n);
	//cout<<s<<'\n';
	int zc=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0') zc++;
	}
	return s.length()%2==1&&zc==1&&s[s.length()/2]=='0';
}


int main() {
	int cur;
	while(cin>>cur){
		//cout<<cur<<'\n';
		cout<<cur<<" "<<(isCyclops(cur)?"yes":"no")<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/