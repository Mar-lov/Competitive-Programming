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
typedef pair<int,int> ii;

#define maxN 505
#define maxT 5005
int T,N;
int arr[maxN];
bool dp[maxN][2*maxT];
int from[maxN][2*maxT];
set<int> fg;
void recur(int cw,int tv){
	int index=from[tv][cw];
	//cout<<index<<'\n';
	if(index==0) return;
	fg.insert(index);
	//cout<<"recur:"<<cw-arr[index]<<'\n';
	recur(cw-arr[index],index-1);
}
//may have error if break time is 0
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T>>N;
	for(int i=1;i<=N;i++){
		cin>>arr[i];
	}
	dp[0][0]=true;
	from[0][0]=0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<2*maxT;j++){
			if(j>=arr[i]&&dp[i-1][j-arr[i]]){
				dp[i][j]=true;
				from[i][j]=i;
			}else{
				dp[i][j]=dp[i-1][j];
				from[i][j]=from[i-1][j];
			}
		}
	}
	int mt=T;
	while(!dp[N][mt]) mt--;
	//cout<<mt<<'\n';
	recur(mt,N);
	int g1=0;
	int g2=0;
	//for(int a:fg) cout<<a<<'\n';
	for(int i=1;i<=N;i++){
		if(fg.count(i)){
			cout<<g1;
			g1+=arr[i];
		}else{
			cout<<g2;
			g2+=arr[i];
		}
		cout<<" ";
	}
	cout<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/