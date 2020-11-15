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
typedef pair<int,int> pi;

#define maxN 2505

int N;
int grid[maxN][maxN];
int p[maxN];
int r[maxN];
vector<pair<int,int> > result;
vector< pair<int, pair<int,int> > > paths;

int findP(int n){
	if(n==p[n]) return n;
	int cp=findP(p[n]);
	p[n]=cp;
	return cp;
}

void combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1!=p2){
	if(r[p1]<r[p2]) swap(p1,p2);
	p[p2]=p1;
	r[p1]=max(r[p1],r[p2]+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>grid[i][j];
		}
	}
	for(int i=0;i<N;i++){
		p[i]=i;
		r[i]=0;
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			paths.push_back(make_pair(grid[i][j],make_pair(i,j)));
		}
	}
	sort(paths.begin(),paths.end());
	for(int i=0;i<paths.size();i++){
		int fn=paths[i].second.first;
		int sn=paths[i].second.second;
		int p1=findP(fn);
		int p2=findP(sn);
		if(p1!=p2){
			if(fn>sn) swap(fn,sn);
			combine(p1,p2);
			result.push_back(make_pair(fn,sn));
		}
	}
	sort(result.begin(),result.end());
	for(int i=0;i<result.size();i++){
		cout<<result[i].first+1<<" "<<result[i].second+1<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/