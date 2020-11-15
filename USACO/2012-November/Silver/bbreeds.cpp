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

#define maxN 1005

string s;
long long dp[maxN][maxN];
int psum[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("bbreeds.in");
	ofstream cout("bbreeds.out");
	getline(cin,s);
	s=" "+s;
	for(int i=1;i<s.length();i++){
		if(s[i]=='('){
			psum[i]=psum[i-1]+1; 
		}else{
			psum[i]=psum[i-1]-1;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<s.length();i++){
		for(int j=0;j<=psum[i];j++){
			if(s[i]=='('){
				dp[i][j]+=dp[i-1][j-1];
				dp[i][j]+=dp[i-1][psum[i]-j-1];
			}else{
				dp[i][j]+=dp[i-1][j+1];
				dp[i][j]+=dp[i-1][psum[i]-j+1];
			}
			dp[i][j]%=2012;
		}
	}
	cout<<dp[s.length()-1][0]<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/