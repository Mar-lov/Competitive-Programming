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

int t;
ll n,l,r;
ll mv;
int f(ll cv){
	ll temp=mv-cv+1;
	int msb=0;
	while(temp!=0){
		temp/=2;
		msb++;
	}
	ll vl=n+1-msb;
	cv-=(((n-1)+(vl-1))*(n-vl+1));
	if(cv%2==1){
		return (vl==n?1:vl);
	}else{
		return vl+cv/2;
	}
}


int main() {
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		mv=n*(n-1)+1;

		for(ll i=l;i<=r;i++){
			cout<<f(i)<<" ";
		}
		cout<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/