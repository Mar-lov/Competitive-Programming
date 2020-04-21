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

ll N,M,R;
ll gal[100005];
ll gs[100005];
pair<ll,ll> sell[100005];
ll rent[100005];
ll pr[100005];


int main() {
	ifstream cin("rental.in");
	ofstream cout("rental.out");
	cin>>N>>M>>R;
	for(int i=0;i<N;i++){
		cin>>gal[i];
	}
	sort(gal,gal+N);

	for(int i=0;i<M;i++){
		cin>>sell[i].second>>sell[i].first;
	}
	sort(sell,sell+M);

//greedy
	int ci=M-1;
	for(int i=1;i<=N;i++){
		int cs=0;
		while(gal[N-i]>0&&ci>=0){
			if(gal[N-i]>sell[ci].second){
				gal[N-i]-=sell[ci].second;
				cs+=sell[ci].second*sell[ci].first;
				ci--;
			}else{
				sell[ci].second-=gal[N-i];
				cs+=gal[N-i]*sell[ci].first;
				gal[N-i]=0;
			}
		}
		gs[i]=gs[i-1]+cs;
	}

	for(int i=0;i<R;i++){
		cin>>rent[i];
	}
	sort(rent,rent+R);
	for(int i=1;i<=R;i++){
		pr[i]=rent[R-i]+pr[i-1];
	}

	ll maxt=0;
	for(int i=0;i<N;i++){
		maxt=max(maxt,pr[i]+gs[N-i]);
	}
	cout<<maxt<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/