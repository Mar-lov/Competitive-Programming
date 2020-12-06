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

#define maxK 17
#define maxN 100005
#define INF 1000000000

int K,N;
int coins[maxK];
int costs[maxN];
int pc[maxN];
//dp[2^16][last coin]=min lost
int dp[(1<<maxK)][maxK];
int result=-INF;
int tt=0;

int loss(int tv){
	int a=0;
	int b=N;
	while(a<b){
		int mid=(a+b+1)/2;
		if(pc[mid]>tv){
			b=mid-1;
		}else{
			a=mid;
		}
	}
	return tv-pc[a];
}

string toBinary(int N){
	if(N==0){
		return "0";
	}
	string s="";
	while(N>0){
		if(N%2==0){
			s="0"+s;
		}else{
			s="1"+s;
		}
		N/=2;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("nochange.in");
	ofstream cout("nochange.out");
	cin>>K>>N;
	for(int i=0;i<K;i++){
		cin>>coins[i];
		tt+=coins[i];
	}
	for(int i=1;i<=N;i++){
		cin>>costs[i];
		pc[i]=costs[i]+pc[i-1];	
	}
	//set values to INF
	for(int i=0;i<(1<<maxK);i++){
		for(int j=0;j<maxK;j++){
			dp[i][j]=INF;
		}
	}
	//base case setup
	for(int i=0;i<K;i++){
		dp[0][i]=0;
	}
	//do dp
	//cout<<pc[N]<<'\n';
	for(int j=0;j<(1<<K);j++){
		int mins=INF;
		int ts=0;
		for(int i=0;i<K;i++){
			if(((1<<i)&j)>0){
				mins=min(mins,dp[j][i]);
				ts+=coins[i];
			}
		}
		if(j==0) mins=0;
		//cout<<j<<" "<<mins<<" "<<ts<<'\n';
		for(int i=0;i<K;i++){
			if((1<<i)&j) continue;
			dp[(1<<i)|j][i]=min(dp[(1<<i)|j][i],mins+loss(ts+coins[i]-mins));
			//cout<<toBinary(((1<<i)|j))<<" "<<toBinary(1<<i)<<" has "<<ts+coins[i]<<" and "<<dp[(1<<i)|j][i]<<'\n';
			if((ts+coins[i])-dp[(1<<i)|j][i]>=pc[N]){
				result=max(result,tt-(ts+coins[i]));
			}
		}
	}

	if(result!=-INF){
		cout<<result<<'\n';
	}else{
		cout<<-1<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/