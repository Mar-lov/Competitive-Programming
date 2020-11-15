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

#define maxV 21

int N,B;
vector< pair<int,int> > bonus[maxV];
int pts[maxV][maxV];
int dp[(1<<maxV)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("dec.in");
	ofstream cout("dec.out");
	cin>>N>>B;
	int K,P,A;
	for(int i=0;i<B;i++){
		cin>>K>>P>>A;
		bonus[K].push_back(make_pair(P,A));
	}	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>pts[i][j];
		}
	}
	for(int i=1;i<=N;i++){
		sort(bonus[i].begin(),bonus[i].end());
	}
	//solve
	for(int i=1;i<(1<<N);i++){
		int tc=0;
		for(int j=0;j<N;j++){
			if(i&(1<<j)) tc++;
		}
		for(int j=0;j<N;j++){
			if((i&(1<<j))==0) continue;
			int cval=dp[i^(1<<j)]+pts[j][tc-1];
			for(int k=0;k<bonus[tc].size();k++){
				if(cval>=bonus[tc][k].first) cval+=bonus[tc][k].second;
			}
			dp[i]=max(dp[i],cval);
		}	
		//cout<<i<<" "<<dp[i]<<'\n';
	}
	cout<<dp[(1<<N)-1]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/