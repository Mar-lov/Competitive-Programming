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

#define maxN 605
#define maxK 51
int N,K;
int tp=0;
//how many passengers rightafter(ra) station j that started at i
int ra[maxN][maxN];
int dp[maxN][maxK];
int from[maxN][maxK];
vector<int> result;
int maxv=0;
int iom=0;

void getAns(int n,int k){
	if(k==0) return;
	getAns(from[n][k],k-1);
	result.push_back(n);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	int cv;

	for(int i=1;i<N;i++){
		for(int j=i+1;j<=N;j++){
			cin>>cv;
			tp+=cv;
			ra[i][j-1]=cv;
		}
		for(int j=N-1;j>=i;j--){
			ra[i][j]+=ra[i][j+1];
		}
	}

	//SOLVE;);)
	for(int i=1;i<=N;i++){
		int cpn=0;
		for(int j=1;j<=i;j++){
			cpn+=ra[j][i];
		}
		//cout<<cpn<<'\n';
		dp[i][1]=cpn;
		for(int j=2;j<=min(i,K);j++){
			int tempa=cpn;
			for(int k=1;k<i;k++){
				tempa-=ra[k][i];
				if(dp[i][j]<dp[k][j-1]+tempa){
					dp[i][j]=dp[k][j-1]+tempa;
					from[i][j]=k;
				}
			}
		}
		if(maxv<dp[i][K]){
			maxv=dp[i][K];
			iom=i;
		}
	}
	getAns(iom,K);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/