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
typedef pair<ll,ll> pi;

#define maxV 5005
#define MOD 1000000007

ll power(ll b,ll p){
	if(p==1) return b;
	ll save=power(b,p/2);
	save*=save;
	save%=MOD;
	if(p%2==1) save*=b;
	return save%MOD;
}

ll N,M,K;
pair<ll,ll> words[maxV];
ll knap[maxV];
vector<ll> gps;
vector<ll> lns;
ll result=1;
int main() {
	ifstream cin("poetry.in");
	ofstream cout("poetry.out");
	cin>>N>>M>>K;
	for(ll i=0;i<N;i++){
		cin>>words[i].second>>words[i].first;
	}
	sort(words,words+N);
	knap[0]=1;
	for(ll i=0;i<=K;i++){
		if(knap[i]>0){
		for(ll j=0;j<N;j++){
			ll nl=i+words[j].second;
			if(nl<=K){
				knap[nl]+=knap[i];
				knap[nl]%=MOD;
			}
		}
		}
	}
	ll cg=words[0].first;
	gps.push_back(0);
	for(ll i=0;i<N;i++){
		if(words[i].first==cg){
			gps.back()+=knap[K-words[i].second];
			
		}else{
			gps.push_back(knap[K-words[i].second]);
			cg=words[i].first;
		}
		gps.back()%=MOD;
	}
	map<char,ll> ctns;
	char cur;
	for(ll i=0;i<M;i++){
		cin>>cur;
		ctns[cur]++;
	}
	for(map<char,ll>::iterator it=ctns.begin();it!=ctns.end();++it){
		lns.push_back(it->second);
		//cout<<it->second<<'\n';
	}
	for(ll i=0;i<lns.size();i++){
		ll cv=0;
		for(ll j=0;j<gps.size();j++){
			cv+=power(gps[j],lns[i]);
			//cout<<gps[j]<<" "<<lns[i]<<" "<<power(gps[j],lns[i])<<'\n';
			cv%=MOD;
		}
		result*=cv;
		result%=MOD;
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/