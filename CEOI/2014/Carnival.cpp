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
typedef pair<int,int> ii;

#define maxN 155

int N;

int p[maxN];
int r[maxN];
int ts=0;
map<int,int> toG;

int findP(int n){
	if(n==p[n]) return n;
	int np=findP(p[n]);
	p[n]=np;
	return np;
}

void combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(r[p1]<r[p2]) swap(p1,p2);
	r[p1]=max(r[p1],r[p2]+1);
	p[p2]=p1;
}


int query(int a,int b,int x=0){
	if(a==b&&x==0) return 1;
	int sv=(b-a)+1;
	if(x!=0) sv++;
	cout<<sv<<" ";
	for(int i=a;i<=b;i++){
		cout<<i<<" ";
	}
	if(x!=0) cout<<x<<" ";
	cout<<endl;
	int res;
	cin>>res;
	return res;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		p[i]=i;
		r[i]=0;
	}

	for(int i=1;i<N;i++){
		int toI=query(i+1,N,i);
		int toE=query(i+1,N);
		if(toI==toE+1) continue;
		int a=i+1;
		int b=N;
		while(a<b){
			int mid=(a+b)/2;
			toI=query(a,mid,i);
			toE=query(a,mid);
			if(toI==toE) b=mid;
			else a=mid+1;
		}
		//cout<<"SET: "<<i<<" "<<a<<endl;
		combine(i,a);
	}

	cout<<"0 ";
	for(int i=1;i<=N;i++){
		int cp=findP(i);
		if(toG.count(cp)==0){
			toG[cp]=ts;
			ts++;
		}
		cout<<toG[cp]+1<<" ";
	}
	cout<<endl;
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/