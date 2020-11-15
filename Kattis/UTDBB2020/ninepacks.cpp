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

#define maxO 105
#define maxB 100000
#define INF 1000000000
int H,B;
int dogs[maxO];
int buns[maxO];
int dp0[maxO][maxB];
int dp1[maxO][maxB];
int result=INF;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>H;
	fill(dp0[0],dp0[0]+maxB,INF);
	fill(dp1[0],dp1[0]+maxB,INF);
	for(int i=1;i<=H;i++){
		cin>>dogs[i];
		fill(dp0[i],dp0[i]+maxB,INF);
	}
	cin>>B;
	for(int i=1;i<=B;i++){
		cin>>buns[i];
		fill(dp1[i],dp1[i]+maxB,INF);
	}
	dp0[0][0]=0;
	dp1[0][0]=0;
	for(int i=1;i<=H;i++){
		for(int j=0;j<maxB;j++){
			if(j<dogs[i]){
				dp0[i][j]=dp0[i-1][j];
			}else{
				dp0[i][j]=min(dp0[i-1][j],dp0[i-1][j-dogs[i]]+1);
			}
		}
	}
	for(int i=1;i<=B;i++){
		for(int j=0;j<maxB;j++){
			if(j<buns[i]){
				dp1[i][j]=dp1[i-1][j];
			}else{
				dp1[i][j]=min(dp1[i-1][j],dp1[i-1][j-buns[i]]+1);
			}
		}
	}
	
	for(int i=1;i<maxB;i++){
		result=min(result,dp0[H][i]+dp1[B][i]);
	}
	if(result==INF){
		cout<<"impossible"<<'\n';
	}else{
		cout<<result<<'\n';
	}

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/