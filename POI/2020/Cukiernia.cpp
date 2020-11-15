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

#define maxN 300000

int N;
int arr[maxN][3];
int dp[maxN][3];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            dp[i][j]
        }
    }
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/