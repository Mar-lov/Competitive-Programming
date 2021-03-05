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
typedef pair<int,int> pi;

#define maxN 2505

int N;
int tt[maxN];
vector<int> adj[maxN];
int result=0;

int timeC(int n){
	return ((n-1)%12)+1;
}

int dfs(int n,int p){
	int  sum=0;
	if(n!=p) sum++;
	int tc=0;
		for(int a:adj[n]) if(a!=p){
			sum+=dfs(a,n);
			tc++;
		}
		//cout<<n<<" "<<12-timeC(tt[n]+sum+tc)<<'\n';
	return 12-timeC(tt[n]+sum+tc);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("clocktree.in");
	ofstream cout("clocktree.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tt[i];
	}

	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	for(int i=0;i<N;i++){
		int ct=12-dfs(i,i);
		if(ct==1||ct==12) result++;
		//cout<<i<<" "<<nt<<'\n';
	}

	cout<<result<<'\n';
    return 0;

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/