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

#define maxN 100000

int N;
int arr[maxN];
vector<int> adj[maxN];
int rb[maxN][2];
int cn=0;
vector<int> fl;
void dfs(int n){
	fl.push_back(arr[n]);
	rb[n][0]=cn;
	cn++;
	for(int a:adj[n]){
		dfs(a);
	}
	rb[n][1]=cn-1;
}

vector<int> tree[4*maxN+1];
//Apparently merge did work???? WHY
vector<int> merge(vector<int> a,vector<int> b){
	vector<int> fa;
	int p1=0;
	int p2=0;
	while(p1<a.size()&&p2<b.size()){
		if(a[p1]<b[p1]){
			fa.push_back(a[p1]);
			p1++;
		}else{
			fa.push_back(b[p2]);
			p2++;
		}
	}
	while(p1<a.size()){
		fa.push_back(a[p1]);
		p1++;
	}
	while(p2<b.size()){
		fa.push_back(b[p2]);
		p2++;
	}
	return fa;
}

void build(int index,int L,int R){
	if(L==R){
		tree[index].push_back(fl[L]);
		return;
	}
	build(2*index,L,(L+R)/2);
	build(2*index+1,(L+R)/2+1,R);
	tree[index]=merge(tree[2*index],tree[2*index+1]);
	sort(tree[index].begin(),tree[index].end());
}

int query(int index,int qL,int qR,int L,int R,int val){
	if(R<qL||qR<L) return 0;
	if(qL<=L&&R<=qR){
		/*
		cout<<"Searching for >"<<val<<" in:\n";
		for(int a:tree[index]) cout<<a<<" ";
		cout<<"\nanswer is:"<<tree[index].size()-(lower_bound(tree[index].begin(),tree[index].end(),val+1)-tree[index].begin())+1<<'\n';
		*/
		return tree[index].size()-(lower_bound(tree[index].begin(),tree[index].end(),val+1)-tree[index].begin());
	}
	return query(2*index,qL,qR,L,(L+R)/2,val)+query(2*index+1,qL,qR,(L+R)/2+1,R,val);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("promote.in");
	ofstream cout("promote.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	int p;
	for(int i=1;i<N;i++){
		cin>>p;
		p--;
		adj[p].push_back(i);
	}
	dfs(0);
	build(1,0,N-1);
	for(int i=0;i<N;i++){
		//cout<<i<<" "<<rb[i][0]<<" "<<rb[i][1]<<'\n';
		cout<<query(1,rb[i][0],rb[i][1],0,N-1,arr[i])<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/