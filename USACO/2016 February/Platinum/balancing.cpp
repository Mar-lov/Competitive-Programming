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

#define maxN 100005
#define maxB 1000004
int N;
pi arr[maxN];
int result=maxN;
//psum for number of cows for their x and y components
int xsum[maxB];
int ysum[maxB];


vector<int> tree[4*maxN];
void build(int index,int L,int R){
	if(L==R){
		tree[index].push_back(arr[L].second);
		return;
	}
	build(2*index,L,(L+R)/2);
	build(2*index+1,((L+R)/2)+1,R);
	int p1=0;
	int p2=0;
	while(p1<tree[2*index].size()&&p2<tree[2*index+1].size()){
		if(tree[2*index][p1]<=tree[2*index+1][p2]){
			tree[index].push_back(tree[2*index][p1]);
			p1++;
		}else{
			tree[index].push_back(tree[2*index+1][p2]);
			p2++;
		}
	}
	while(p1<tree[2*index].size()){
		tree[index].push_back(tree[2*index][p1]);
		p1++;
	}
	while(p2<tree[2*index+1].size()){
		tree[index].push_back(tree[2*index+1][p2]);
		p2++;
	}
}

int query(int index,int qL,int qR,int L,int R,int val){
	if(R<qL||qR<L) return 0;
	if(qL<=L&&R<=qR) return upper_bound(tree[index].begin(),tree[index].end(),val)-tree[index].begin();
	return query(2*index,qL,qR,L,(L+R)/2,val)+query(2*index+1,qL,qR,((L+R)/2)+1,R,val);
}

void bs(int lo,int hi,int ci){
	if(hi-lo<=1) return;
	int mid=(lo+hi)/2;
	int x=arr[ci].first+1;
	int y=arr[mid].second+1;
	int ll=query(1,1,ci,1,N,y);
	int ul=xsum[x]-ll;
	int lr=ysum[y]-ll;
	int ur=N-ll-ul-lr;
	result=min(result,max(max(ll,lr),max(ul,ur)));
	if(ll+lr<ul+ur){
		bs(mid+1,hi,ci);
	}else if(ll+lr>ul+ur){
		bs(lo,mid-1,ci);
	}else{
		bs(mid,hi,ci);
		bs(lo,mid,ci);
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("balancing.in");
	ofstream cout("balancing.out");
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>arr[i].first>>arr[i].second;
		xsum[arr[i].first]++;
		ysum[arr[i].second]++;
	}
	for(int i=1;i<maxB;i++){
		xsum[i]+=xsum[i-1];
		ysum[i]+=ysum[i-1];
	}
	//sorts by increaing x then by increasing y
	sort(arr+1,arr+N+1);
	//builds the segment tree by yvalue
	build(1,1,N);
	for(int i=0;i<=N;i++){
		bs(0,N,i);
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/