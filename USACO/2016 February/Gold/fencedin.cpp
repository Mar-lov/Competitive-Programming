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
typedef pair< int, pair<int,int> > pii;

int A,B,n,m;
int VF[2005];
int HF[2005];
pii lg[2002*2002];
int tcc;
int p[2002*2002];
int r[2002*2002];

int toI(int a,int b){
	return a*(m+1)+b;
}

int fP(int v){
	if(p[v]==v) return v;
	p[v]=fP(p[v]);
	return p[v];
}

bool merge(int a,int b){
	int p1=fP(a);
	int p2=fP(b);
	if(p1==p2) return false;
	if(r[p1]<r[p2]) swap(p1,p2);
	r[p1]=max(r[p1],r[p2]+1);
	p[p2]=p1;
	tcc--;
	return true;
}

int main() {
	ifstream cin("fencedin.in");
	ofstream cout("fencedin.out");
	cin>>A>>B>>n>>m;
	tcc=(n+1)*(m+1);
	for(int i=1;i<=n;i++){
		cin>>VF[i];
	}
	for(int j=1;j<=m;j++){
		cin>>HF[j];
	}
	VF[n+1]=B;
	HF[m+1]=A;
	sort(VF,VF+n+2);
	sort(HF,HF+m+2);
	for(int i=0;i<=n;i++){
		VF[i]=VF[i+1]-VF[i];
	}
	for(int i=0;i<=m;i++){
		HF[i]=HF[i+1]-HF[i];
	}
	for(int i=0;i<2002*2002;i++){
		p[i]=i;
		r[i]=0;
	}
	int ci=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			lg[ci]=make_pair(HF[j],make_pair(toI(i,j),toI(i+1,j)));
			ci++;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<m;j++){
			lg[ci]=make_pair(VF[i],make_pair(toI(i,j),toI(i,j+1)));
			ci++;
		}
	}
	sort(lg,lg+ci);
	//cout<<ci<<'\n';
	ll answer=0;
	ci=0;
	while(tcc>1){
		if(merge(lg[ci].second.first,lg[ci].second.second)){
			answer+=lg[ci].first;
		}
		//cout<<ci<<" "<<tcc<<'\n';
		ci++;
	}
	cout<<answer<<'\n';

	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/