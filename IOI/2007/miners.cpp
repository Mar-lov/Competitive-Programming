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

int dp[maxN][4][4][4][4];
int N;
int arr[maxN];
int result=0;
int add(int n,int p1,int p2){
	if(p1==0&&p2==0) return 1;
	if(p1==0) return 0;
	if(p2==0){
		if(n!=p1) return 2;
		return 1;
	}
	if(n==p1&&p1==p2) return 1;
	if(n==p1&&p1!=p2) return 2;
	if(n==p2&&p1!=p2) return 2;
	if(p1==p2&&n!=p1) return 2;
	return 3;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	char cur;
	for(int i=0;i<N;i++){
		cin>>cur;
		if(cur=='M') arr[i]=1;
		else if(cur=='F') arr[i]=2;
		else if(cur=='B') arr[i]=3;
	}
	for(int i=0;i<N;i++){
		for(int f1=0;f1<4;f1++){
			for(int s1=0;s1<4;s1++){
				for(int f2=0;f2<4;f2++){
					for(int s2=0;s2<4;s2++){
						//if(i==0&&!(f1==0&&f2==0&&s1==0&&s2==0)) continue;
						//if(i==1&&!(f2==0&&s2==0)) continue;
						//cout<<arr[i]<<" "<<f1<<" "<<f2<<" : "<<add(arr[i],f1,f2)<<'\n';
						//cout<<arr[i]<<" "<<s1<<" "<<s2<<" : "<<add(arr[i],s1,s2)<<'\n';
						dp[i+1][arr[i]][f1][s1][s2]=max(dp[i+1][arr[i]][f1][s1][s2],dp[i][f1][f2][s1][s2]+add(arr[i],f1,f2));
						dp[i+1][f1][f2][arr[i]][s1]=max(dp[i+1][f1][f2][arr[i]][s1],dp[i][f1][f2][s1][s2]+add(arr[i],s1,s2));
						result=max(result,max(dp[i+1][arr[i]][f1][s1][s2],dp[i+1][f1][f2][arr[i]][s1]));
					}
				}
			}
		}
	}
	cout<<result-6<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/