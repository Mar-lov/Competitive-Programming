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
typedef pair<int,int> pi;

#define maxN 100005
#define MOD 1000000007

string s;
int N;
int arr[maxN];
int dp[maxN][4];
int	psum[maxN][4][4];
int result=1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	getline(cin,s);
	N=s.length();
	for(int i=0;i<s.length();i++){
		if(s[i]=='A') arr[i+1]=1;
		else if(s[i]=='G') arr[i+1]=2;
		else if(s[i]=='C') arr[i+1]=3;
		else if(s[i]=='T') arr[i+1]=4;
		else if(s[i]=='?') arr[i+1]=5;
	}

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/