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

int N,Q;
pair< int , pair<int,int> > edj[100005];
pair< pair<int,int> , int > que[100005];
int p[100005];
int s[100005];
int ans[100005];
int findP(int v){
	if(v==p[v]) return v;
	int result=findP(p[v]);
	p[v]=result;
	return result;
}

void merge(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1!=p2){
	if(s[p1]<s[p2]) swap(p1,p2);
	s[p1]+=s[p2];
	p[p2]=p1;
	}
}
int main() {
	ifstream cin("mootube.in");
	ofstream cout("mootube.out");
	cin>>N>>Q;
	int a,b,r;
	for(int i=0;i<N-1;i++){
		cin>>a>>b>>r;
		a--;b--;
		edj[i]=make_pair(r,make_pair(a,b));
	}
	int k,v;
	for(int i=0;i<Q;i++){
		cin>>k>>v;
		v--;
		que[i]=make_pair(make_pair(k,v),i);
	}
	for(int i=0;i<100005;i++){
		p[i]=i;
		s[i]=1;
	}
	sort(edj,edj+N-1);
	reverse(edj,edj+N-1);
	sort(que,que+Q);
	reverse(que,que+Q);
	int cei=0;
	for(int i=0;i<Q;i++){
		while(cei<N-1&&edj[cei].first>=que[i].first.first){
			merge(edj[cei].second.first,edj[cei].second.second);
			cei++;
		}
		ans[que[i].second]=s[findP(que[i].first.second)]-1;
	}
	/*
	for(int i=0;i<N;i++){
		cout<<s[i]<<' ';
	}
	cout<<'\n';
	*/
	for(int i=0;i<Q;i++){
		cout<<ans[i]<<'\n';
	}
    return 0;

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/