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
typedef pair<long long,pair<int,int> > pii;

#define maxN 7502

int N,K;
pii arr[maxN*maxN/2];
ll calc(ll x,ll y){
	return (2019201913*x+2019201949*y)%2019201997;
}

int p[maxN];
int r[maxN];
int tsg;
int findP(int n){
	if(p[n]==n) return n;
	p[n]=findP(p[n]);
	return p[n];
}

void combine(int a,int b){
	if(r[a]<r[b]) swap(a,b);
	r[a]=max(r[a],r[b]+1);
	p[b]=a;
	tsg--;
}

int main() {
	ifstream cin("walk.in");
	ofstream cout("walk.out");
	cin>>N>>K;
	tsg=N;
	int ci=0;
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			arr[ci]=(make_pair(calc(i,j),make_pair(i,j)));
			ci++;
		}
	}
	sort(arr,arr+ci);
	for(int i=0;i<maxN;i++){
		p[i]=i;
		r[i]=0;
	}
	int i=0;
	while(tsg>K){
		int p1=findP(arr[i].second.first);
		int p2=findP(arr[i].second.second);
		i++;
		if(p1!=p2) combine(p1,p2);
	}
	while(findP(arr[i].second.first)==findP(arr[i].second.second)) i++;
	cout<<arr[i].first<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/