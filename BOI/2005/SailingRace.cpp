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
typedef pair<long long,long long> pi;

#define maxL 205
#define INF 100000000
long long L;
vector<long long> arr;
//first=total value second= total distance                	
pair<long long,long long> dp[maxL][maxL][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>L;
	long long cn;
	for(long long i=0;i<L;i++){
		cin>>cn;
		arr.push_back(cn);
	}
	arr.push_back(0);
	sort(arr.begin(),arr.end());
	L++;
	for(long long i=0;i<L;i++){
		for(long long j=0;i+j<=L;j++){
			dp[i][j][0].first=INF;
			dp[i][j][0].second=INF;
			dp[i][j][1].first=INF;
			dp[i][j][1].second=INF;
		}
	}
	for(long long i=0;i<arr.size();i++){
		if(arr[i]==0){
			dp[i][1][0].first=0;
			dp[i][1][0].second=0;
			dp[i][1][1].first=0;
			dp[i][1][1].second=0;
		}
	}
	for(long long len=1;len<L;len++){
		for(long long i=0;i+len<=L;i++){
			//added to the left dp[i-1][len+1][0]
			long long ll=dp[i][len][0].first+dp[i][len][0].second+(arr[i]-arr[i-1]);
			long long rl=dp[i][len][1].first+dp[i][len][1].second+(arr[i+len-1]-arr[i-1]);
			if(i>0&&dp[i-1][len+1][0].first>min(ll,rl)){
				cout<<"left check:" <<ll<<" "<<rl<<'\n';
				if(ll<rl){
					cout<<"check1"<<'\n';
					dp[i-1][len+1][0].first=ll;
					dp[i-1][len+1][0].second=dp[i][len][0].second+(arr[i]-arr[i-1]);
				}else{
					cout<<"check2"<<'\n';
					dp[i-1][len+1][0].first=rl;
					dp[i-1][len+1][0].second=dp[i][len][1].second+(arr[i+len-1]-arr[i-1]);
				}
			}
			//added to the right dp[i][len+1][1]
			long long lr=dp[i][len][0].first+dp[i][len][0].second+(arr[i+len]-arr[i]);
			long long rr=dp[i][len][1].first+dp[i][len][1].second+(arr[i+len]-arr[i+len-1]);
			if(dp[i][len+1][1].first>min(lr,rr)){
				if(lr<rr){
					dp[i][len+1][1].first=lr;
					dp[i][len+1][1].second=dp[i][len][0].second+(arr[i+len]-arr[i]);
				}else{
					dp[i][len+1][1].first=rr;
					dp[i][len+1][1].second=dp[i][len][1].second+(arr[i+len]-arr[i+len-1]);
				}
			}
			cout<<i<<" to "<<i+len<<" has left values "<<dp[i][len+1][0].first<<" "<<dp[i][len+1][0].second<<'\n';
			cout<<i<<" to "<<i+len<<" has right values "<<dp[i][len+1][1].first<<" "<<dp[i][len+1][1].second<<'\n';
		}
	}	
	//cout<<dp[0][8][0].first<<endl;
	cout<<min(dp[0][L][0].first,dp[0][L][1].first)<<'\n';

    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/