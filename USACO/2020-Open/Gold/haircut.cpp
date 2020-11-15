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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define maxN 100005

ll N;
vector<pair<ll,ll> > arr;

ll ft[100013];
void update(ll x, ll v) {while(x<=N) ft[x]+=v, x+=(x&-x);}
ll query (ll x) {return (x>0 ? ft[x]+query(x-(x&-x)):0);}


int main() {
	ifstream cin("haircut.in");
	ofstream cout("haircut.out");
	cin>>N;
	ll curv;
	for(ll i=0;i<N;i++){
		cin>>curv;
		arr.push_back(make_pair(curv,i+1));
	}
	sort(arr.begin(),arr.end());

	ll inv=0;
	ll ci=0;
	for(ll j=1;j<N;j++){
		cout<<inv<<'\n';
		ll tci=ci;
		while(arr[tci].first==j-1){
			update(arr[tci].second,1);
			tci++;
		}
		while(arr[ci].first==j-1){
			inv+=arr[ci].second-query(arr[ci].second);
			ci++;
		}
	}
	cout<<inv<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/