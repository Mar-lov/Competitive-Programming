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

int shares=0;
double ac=0;

void buy(int x,double y){
	ac+=x*y;
	shares+=x;
}
void sell(int x,double y){
	ac-=x*((ac/shares));
	//ac+=x*(y-(ac/shares));
	shares-=x;
}
void split(int x){
	shares*=x;
}
void merge(int x){
	sell(shares%x,ac/shares);
	shares-=shares%x;
	shares/=x;
}

int main() {
	string s;
	cin>>s;
	int x;
	double y;
	while(s!="die"){
		if(s=="buy"){
			cin>>x>>y;
			buy(x,y);
		}else if(s=="sell"){
			cin>>x>>y;
			sell(x,y);
		}else if(s=="split"){
			cin>>x;
			split(x);
		}else if(s=="merge"){
			cin>>x;
			merge(x);
		}
		//cout<<shares<<" "<<ac<<'\n';
		cin>>s;
	}
	cin>>y;
	cout<<fixed;
	//cout<<shares<<" "<<ac<<'\n';
	double val=(y-(ac/shares));
	if(val>0){
	cout<<setprecision(2)<<shares*(y-(0.3*val))<<'\n';
	}else{
		cout<<setprecision(2)<<ac+(shares*val)<<'\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/