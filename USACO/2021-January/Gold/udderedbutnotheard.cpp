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

#define maxC 21
#define INF 1000000000

string S;
int tc=0;
unordered_map<char,int> toI;
int result=0;

int arr[maxC][maxC];
int ts[maxC];

int dp[(1<<maxC)][maxC];

bool after[maxC][maxC];

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	getline(cin,S);

	//maps each given character to an integer
	for(int i=0;i<(int)S.length();i++){
		if(toI.count(S[i])==0){
			tc++;
			toI[S[i]]=tc-1;
		}
	}

	//calculate intercep
	for(int i=(int)S.length()-1;i>=0;i--){
		arr[toI[S[i]]][toI[S[i+1]]]++;
	}
	/*
	for(int i=0;i<tc;i++){
		for(int j=0;j<tc;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	*/

	for(int i=0;i<tc;i++){
		for(int j=0;j<tc;j++){
			ts[i]+=arr[i][j];
		}
	}
	//setup 2^n
	for(int i=0;i<(1<<tc);i++){
		for(int j=0;j<tc;j++){
			dp[i][j]=INF;
		}
	}

	for(int i=0;i<tc;i++){
		dp[(1<<i)][i]=ts[i];
	}

	//2^N dp
	int cv[maxC];

	for(int i=1;i<(1<<tc);i++){
		for(int j=0;j<tc;j++){
			cv[j]=ts[j];
		}
		for(int j=0;j<tc;j++){
			for(int k=0;k<tc;k++){
				if(i&(1<<k)){
					//cout<<"did "<<cv[j]<<" - "<<arr[j][k]<<" = ";
					cv[j]-=arr[j][k];
					//cout<<cv[j]<<endl;
				}
			}
		}
		//cout<<i<<" ";
		//for(int j=0;j<tc;j++) cout<<cv[j]<<" ";
		//cout<<'\n';
		for(int j=0;j<tc;j++){
			if((i&(1<<j))==0){
				
				for(int k=0;k<tc;k++){
					//cout<<dp[i|(1<<j)][j]<<" with "<<k<<" "<<dp[i][k]+cv[j]<<" becomes ";
					if(i&(1<<k)) dp[i|(1<<j)][j]=min(dp[i|(1<<j)][j],dp[i][k]+cv[j]);
					//cout<<dp[i|(1<<j)][j]<<endl;
				}
			}
		}

	}
	
	/*
	for(int i=0;i<(1<<tc);i++){
		for(int j=0;j<tc;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
*/

	vector<int> ordering;
	int cvl=(1<<tc)-1;
	for(int r=0;r<tc;r++){
		int sv=INF;
		int ti=0;
		for(int j=0;j<tc;j++){
			if(cvl&(1<<j)){
				if(dp[cvl][j]<=sv){
					sv=dp[cvl][j];
					ti=j;
				}
			}
		}
		ordering.push_back(ti);
		//cout<<ti<<"\n";
		cvl=cvl&(~(1<<ti));
	}

	for(int i=0;i<tc;i++){
		for(int j=i+1;j<tc;j++){
			after[ordering[i]][ordering[j]]=true;
		}
	}
	for(int i=0;i<(int)S.length()-1;i++){
		int fv=toI[S[i]];
		int sv=toI[S[i+1]];
		if(!after[fv][sv]){
			result++;
			//cout<<S[i]<<" "<<S[i+1]<<'\n';
		}
	}

	cout<<result+1<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/