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
#define maxN 50002
#define INF 1000000000
int N;
int asx=INF,alx=-1,asy=INF,aly=-1;
pi pts[2][maxN];


long long solve(int q){
	ll minA=1000000000000000000;
	vector<int> s;
	for(int i=0;i<N;i++){
		s.push_back(pts[q][i].second);
	}
	sort(s.begin(),s.end());
	int rmin=INF;
	int rmax=-1;
	int j=0;
	while(j+1<N){
		rmin=min(rmin,pts[q][j].second);
		rmax=max(rmax,pts[q][j].second);
		s.erase(lower_bound(s.begin(),s.end(),pts[q][j].second));
		if(pts[q][j].first!=pts[q][j+1].first){
			ll lb=(ll)(rmax-rmin)*(ll)(pts[q][j].first-pts[q][0].first);
			ll rb=(ll)(s.back()-s.front())*(ll)(pts[q][N-1].first-pts[q][j+1].first);
			minA=min(minA,lb+rb);
			//cout<<"left:"<<(ll)(rmax-rmin)*(ll)(pts[q][j].first-pts[q][0].first)<<'\n';
			//cout<<"right:"<<(ll)(s.back()-s.front())*(ll)(pts[q][N-1].first-pts[q][j+1].first)<<'\n';
		}
		//cout<<j<<'\n';
		j++;
	}
	return minA;
}

int main() {
	ifstream cin("split.in");
	ofstream cout("split.out");
	cin>>N;
	int u,v;
	for(int i=0;i<N;i++){
		cin>>u>>v;
		pts[0][i]=make_pair(u,v);
		pts[1][i]=make_pair(v,u);
		asx=min(asx,u);
		alx=max(alx,u);
		asy=min(asy,v);
		aly=max(aly,v);
	}
	sort(pts[0],pts[0]+N);
	sort(pts[1],pts[1]+N);
	ll tA=(ll)(alx-asx)*(ll)(aly-asy);
	cout<<tA-min(solve(0),solve(1))<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/