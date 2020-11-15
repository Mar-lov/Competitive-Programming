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

int N,Q;
int tree[4*maxN];
int input[maxN];
void build(int index,int L,int R){

	if(L==R){ tree[index]=input[L]; return;}
	build(2*index,L,(L+R)/2);
	build(2*index+1,((L+R)/2)+1,R);
	tree[index]=tree[2*index]+tree[2*index+1];
}

void update(int index,int L,int R,int value){
	if(L==R){ tree[index]=value; return;}
	update(2*index,L,(L+R)/2,value);
	update(2*index+1,((L+R)/2)+1,R,value);
	tree[index]=tree[2*index]+tree[2*index+1];
}

int query(int qL,int qR,int index,int L, int R){
	if(qR<L||qL>R) return 0;
	if(qL<=L&&R<=qR) return tree[index];
	return query(qL,qR,2*index,L,(L+R)/2)+query(qL,qR,2*index+1,((L+R)/2)+1,R);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	int cn;
	for(int i=0;i<N;i++){
		cin>>input[i];
	}
	build(1,0,N-1);
	cin>>Q;
	int u,v;
	for(int i=0;i<Q;i++){
		cin>>u>>v;
		cout<<query(u,v,1,0,N-1)<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/