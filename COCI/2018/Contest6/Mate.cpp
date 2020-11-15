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

#define maxV 2005
#define MOD 1000000007

string s;
long long Q;
long long pc[maxV][maxV];
long long dp[maxV][26];
vector<int> cnts[26];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>s;
	cin>>Q;
	//precomute pc[n][m] which is the nCm
	for(long long i=0;i<maxV;i++){
		pc[i][0]=1;
		for(long long j=1;j<i;j++){
			pc[i][j]=pc[i-1][j]+pc[i-1][j-1];
			pc[i][j]%=MOD;
		}
		pc[i][i]=1;
	}
	for(int i=0;i<s.length();i++){
		cnts[s[i]-'a'].push_back(i);
	}
	for(long long i=0;i<26;i++){
		for(long long j=s.length()-1;j>=0;j--){
			if(s[j]=='a'+i){
				dp[j][i]++;
			}
			if(j<s.length()-1){
				dp[j][i]+=dp[j+1][i];
			}
		}
	}
	long long tl;
	char fc,sc;
	for(long long i=0;i<Q;i++){
		long long result=0;
		cin>>tl>>fc>>sc;
		for(long long j=0;j<cnts[fc-'a'].size();j++){
			if(cnts[fc-'a'][j]>=tl-2&&cnts[fc-'a'][j]<s.length()-1){
				result+=pc[cnts[fc-'a'][j]][tl-2]*(dp[cnts[fc-'a'][j]+1][sc-'a']);
				result%=MOD;
			}
		}
		cout<<result<<'\n';
	}
    return 0;
}
/*
malimateodmameitate
3
10 ot
7 aa
3 me
*/
/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/