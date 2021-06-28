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

#define maxN 200005

int p[maxN];
int r[maxN];
int findP(int n){
	if(n==p[n]) return n;
	int pn=findP(p[n]);
	p[n]=pn;
	return pn;
}

bool combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1==p2) return false;
	if(r[p1]<r[p2]) swap(p1,p2);
	p[p2]=p1;
	r[p1]=max(r[p1],r[p2]+1);
	return true;
}

int N;
pair< ii,ii > arr[maxN];
int c[maxN];
vector< ii > order;
int result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<=2*N;i++){
		p[i]=i;
		r[i]=1;
	}
	for(int i=0;i<N;i++){
		cin>>c[i];
		cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
		order.push_back(make_pair(c[i],i));
		combine(arr[i].first.first,arr[i].first.second);
		combine(arr[i].second.first,arr[i].second.second);
	}
	sort(order.begin(),order.end());
	for(int i=0;i<order.size();i++){
		int ci=order[i].second;
		if(combine(arr[ci].first.first,arr[ci].second.first)){
			result+=order[i].first;
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/