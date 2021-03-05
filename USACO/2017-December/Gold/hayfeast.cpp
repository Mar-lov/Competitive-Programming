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
typedef pair<ll,ll> pi;

#define maxN 100002

ll N,M;
ll maxSpicy=0;
pi arr[maxN];

bool doable(ll s){
	ll cm=0;
	for(int i=0;i<N;i++){
		if(arr[i].second<=s){
			cm+=arr[i].first;
			if(cm>=M) return true;
		}else{
			cm=0;
		}
	}
	return false;
}

int main() {
	ifstream cin("hayfeast.in");
	ofstream cout("hayfeast.out");
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>arr[i].first>>arr[i].second;
     maxSpicy=max(maxSpicy,arr[i].second);
	}
	ll lo=0;
	ll hi=maxSpicy;
	while(lo<hi){
		ll mid=(lo+hi)/2;
		
		if(doable(mid)){
			hi=mid;
		}else{
			lo=mid+1;
		}
	}
	cout<<hi<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/