/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

ll N,K,M;

ll solve(ll X){
	ll cn=N;
	ll td=0;
	while((cn/X)>M&&td<=K){
		ll cv=floor(cn/X);
		ll md=floor((double)(cn-cv*X)/(double)(cv)+1);
		td+=md;
		cn-=cv*md;
	}
	//cout<<'\n';
	td+=ceil((double)cn/(double)M);
	return td;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("loan.in");
	ofstream cout("loan.out");
	cin>>N>>K>>M;
	ll a=1;
	ll b=N;
	while(a<b){
		ll mid=(a+b+1)/2;
		//cout<<mid<<" "<<solve(mid)<<'\n';
		if(solve(mid)<=K){
			a=mid;
		}else{		
			b=mid-1;
		}
	}
	cout<<b<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/