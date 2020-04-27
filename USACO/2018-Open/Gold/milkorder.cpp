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

#define maxN 100005
#define maxM 50005

int N,M;
int result[maxN];
vector<pi> edges[maxM];

vector<int> succ[maxN];
int pres[maxN];

bool doable(int k){
	for(int i=1;i<=N;i++){
		succ[i].clear();
		pres[i]=0;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<edges[i].size();j++){
			succ[edges[i][j].second].push_back(edges[i][j].first);
			pres[edges[i][j].first]++;
		}
	}
	priority_queue< int , vector<int> , greater<int> > pq;
	for(int i=1;i<=N;i++){
		if(pres[i]==0){
			pq.push(i);
		}
	}

	for(int i=0;i<N;i++){
		if(pq.empty()) return false;
		int cv=pq.top();
		pq.pop();
		result[i]=cv;
		for(int j=0;j<succ[cv].size();j++){
			pres[succ[cv][j]]--;
			if(pres[succ[cv][j]]==0){
				pq.push(succ[cv][j]);
			}
		}
	}
	return true;
}

int main() {
	ifstream cin("milkorder.in");
	ofstream cout("milkorder.out");
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int m;
		cin>>m;
		int last;
		int cur;
		for(int j=0;j<m;j++){
			cin>>cur;
			if(j>0) edges[i].push_back(make_pair(cur,last));
			last=cur;
		}
	}
	int lo=0;
	int hi=M;
	while(lo<hi){
		int mid=(lo+hi+1)/2;
		if(doable(mid)){
			lo=mid;
		}else{
			hi=mid-1;
		}
	}
	//cout<<lo<<'\n';
	doable(lo);
	for(int i=0;i<N;i++){
		cout<<result[i]<<(i==N-1?"\n":" ");
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/