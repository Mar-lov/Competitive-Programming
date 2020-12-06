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

int N;
vector<int> adj[maxN];
string result="";
int root=0;

bool work=true;
int dp[maxN];
int pathl=0;

void dfs(int n,int p){
	dp[n]=0;
	multiset<int> cs;
	set<int> vals;
	for(int a:adj[n]) if(a!=p){
		dfs(a,n);
		if(work==false) return;
		cs.insert(dp[a]+1);
		vals.insert(dp[a]+1);
	}
	if(work==false) return;
	cs.erase(pathl);
	for(int a:vals){
		if(a>pathl/2) break;
		int i=a;
			if(i==pathl-i){
			if(cs.count(i)%2==1){
				cs.erase(i);
				cs.insert(i);
			}else{
				cs.erase(i);
			}
		}else{
			int tf=cs.count(i);
			int ts=cs.count(pathl-i);
			int df=max(0,tf-ts);
			int ds=max(0,ts-tf);
			cs.erase(i);cs.erase(pathl-i);
			if(df>1||ds>1){
				work=false;
				return;
			}else{
				if(df==1) cs.insert(i);
				if(ds==1) cs.insert(pathl-i);
			}
		}
	}
	if(cs.size()==0) dp[n]=0;
	if(cs.size()==1) dp[n]=*cs.begin();
	if(cs.size()>1){
		work=false;
		return;
	}
}

bool pos(int v){
	pathl=v;
	work=true;
	dfs(root,root);
	if(work&&dp[root]==0) return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("deleg.in");
	ofstream cout("deleg.out");
	cin>>N;
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<N;i++){
		if((N-1)%i==0){
			if(pos(i)){
				result+="1";
			}else{
				result+="0";
			}
		}else{
			result+="0";
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/