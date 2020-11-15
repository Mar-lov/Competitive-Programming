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

#define maxV 405

int R,C;
char arr[maxV][maxV];
int dp[maxV][maxV];
int result=0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
        }
    }
    //to the right
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int ci=j;
            while(ci<C&&arr[i][ci]=='.'){
               dp[i][j]++; 
               ci++;
            }
        }
    }
    //down 
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int ci=i;
            int mw=1000000;
            while(ci<R&&dp[ci][j]>0){
                mw=min(mw,dp[ci][j]);
                result=max(result,2*mw+2*(ci-i+1));
                ci++;
            }
        }
    }
    cout<<result-1<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/