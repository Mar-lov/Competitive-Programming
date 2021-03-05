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
typedef pair<long long,long long> ii;

#define maxN 100005
#define maxW 1000005

long long N;
long long arr[maxN];
bool dp[maxW];
long long numV[maxW];
long long pnum[maxW];
long long mW=0;
long long result=0;

long long numN(long long a,long long b){
	return pnum[a]-(b+1<maxW?pnum[b+1]:0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	fill(numV,numV+maxW,0);
	fill(pnum,pnum+maxW,0);
	fill(dp,dp+maxW,false);
	for(long long i=0;i<N;i++){
		cin>>arr[i];
		numV[arr[i]]++;
		mW=max(arr[i],mW);
	}
	for(long long i=mW;i>=0;i--){
		pnum[i]=pnum[i+1]+numV[i];
	}

	for(long long w=mW;w>0;w--){
		//first determine if cval is a win o
		long long totalV=numN(w,2*w-1);
		if(totalV%2==0){
			dp[w]=false;
			continue;
		}
		int numWin=0;
		int lw=1;
		for(long long k=2;w*k<=mW;k++){
			if(dp[k*w]){
				numWin++;
				lw=k;
			}
		}
		if(numWin==0){
			dp[w]=true;
			result+=totalV;
		}else if(numWin==1&&lw==2){
			dp[w]=true;
			result+=numN(2*w,3*w-1);
		}
	}

	cout<<result<<'\n';
    return 0;
}

/* IF STUCK LOOK HERE
	* long long overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/