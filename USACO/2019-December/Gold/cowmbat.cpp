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

#define maxN 100005
#define INF 1000000000
int N,M,K;
string s;
int matrix[26][26];
int psum[maxN][26];
int dp[maxN][26];
int mn[maxN];
int main() {
	ifstream cin("cowmbat.in");
	ofstream cout("cowmbat.out");
	cin>>N>>M>>K;
	cin>>s;
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			cin>>matrix[i][j];
		}
	}
	for(int k=0;k<M;k++){
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++){
				matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			psum[i][j]=psum[i-1][j]+matrix[s[i-1]-'a'][j];
			dp[i][j]=INF;
		}
		mn[i]=INF;
	}
	//very important to have this. Pretty much first K values are set.
	fill(dp[0],dp[0]+26,INF);
	mn[0]=0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			dp[i][j]=min(dp[i][j],dp[i-1][j]+matrix[s[i-1]-'a'][j]);
			if(i>=K) dp[i][j]=min(dp[i][j],mn[i-K]+psum[i][j]-psum[i-K][j]);
			mn[i]=min(mn[i],dp[i][j]);
		}
	}
	cout<<mn[N]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/