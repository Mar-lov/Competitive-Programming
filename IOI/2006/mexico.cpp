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

#define maxN 1005

int N,M;
bool adj[maxN][maxN];
bool dp[maxN][maxN][2];
int from[maxN][maxN][2];

vector<int> path(int a,int b,int c){
	vector<int> ans;
	while(a!=b&&from[a][b][c]!=-1){
		if(c==0){
			ans.push_back(a);
			if(from[a][b][c]==(a+1)%N){
				a=(a+1)%N;
				c=0;
			}else if(from[a][b][c]==b){
				a=(a+1)%N;
				c=1;
			}
		}else if(c==1){
			ans.push_back(b);
			if(from[a][b][c]==(b+N-1)%N){
				b=(b+N-1)%N;
				c=1;
			}else if(from[a][b][c]==a){
				b=(b+N-1)%N;
				c=0;
			}
		}
		//cout<<a<<" "<<b<<" "<<c<<" "<<from[a][b][c]<<endl;
	}
	ans.push_back(a);
	reverse(ans.begin(),ans.end());
	return ans;
}

void ans(vector<int> a,vector<int> b){
	reverse(b.begin(),b.end());
	for(int x:a) cout<<x+1<<'\n';
	for(int x:b) cout<<x+1<<'\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("mexico.in");
	ofstream cout("mexico.out");
	cin>>N>>M;
	int u,v;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u][v]=true;
		adj[v][u]=true;
	}
	for(int i=0;i<N;i++){
		dp[i][i][0]=true;
		dp[i][i][1]=true;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			from[i][j][0]=-1;
			from[i][j][1]=-1;
		}
	}
	for(int len=0;len<N;len++){
		for(int i=0;i<N;i++){
				int sl=(i+len)%N;
				int lv=(i+N-1)%N;
				int rv=(i+len+1)%N;
				//check if possible
				if(dp[i][sl][0]&&dp[rv][lv][0]&&adj[i][rv]){
					ans(path(i,sl,0),path(rv,lv,0));
					return 0;
				}
				if(dp[i][sl][0]&&dp[rv][lv][1]&&adj[i][lv]){
					ans(path(i,sl,0),path(rv,lv,1));
					return 0;
				}
				if(dp[i][sl][1]&&dp[rv][lv][0]&&adj[sl][rv]){
					ans(path(i,sl,1),path(rv,lv,0));
					return 0;
				}
				if(dp[i][sl][1]&&dp[rv][lv][1]&&adj[sl][lv]){
					ans(path(i,sl,1),path(rv,lv,1));
					return 0;
				}
				//propagate
				if(dp[i][sl][0]&&adj[lv][i]){
					dp[lv][sl][0]=true;
					from[lv][sl][0]=i;
				}
				if(dp[i][sl][0]&&adj[i][rv]){
					dp[i][rv][1]=true;
					from[i][rv][1]=i;
				}
				if(dp[i][sl][1]&&adj[lv][sl]){
					dp[lv][sl][0]=true;
					from[lv][sl][0]=sl;
				}
				if(dp[i][sl][1]&&adj[sl][rv]){
					dp[i][rv][1]=true;
					from[i][rv][1]=sl;
				}
		}
	}

	cout<<-1<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/