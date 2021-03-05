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

#define maxN 300005

int N,K;
string s;
int dp[maxN];
int psum[maxN];

struct cmp{
    bool operator() (int a,int b) const{
        if(dp[a]==dp[b]){
            return psum[a]<psum[b];
        }
        return dp[a]<dp[b];
    }
};
multiset<int,cmp> vals;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("redistricting.in");
    ofstream cout("redistricting.out");
    cin>>N>>K;
    char cc;
    for(int i=1;i<=N;i++){
        cin>>cc;
        psum[i]=psum[i-1];
        if(cc=='H'){
            psum[i]++;
        }else if(cc=='G'){
            psum[i]--;
        }
    }
    dp[0]=0;
    vals.insert(0);
    for(int i=1;i<=N;i++){
        if(i>K){
            while((*vals.begin())<(i-K)){
                vals.erase(vals.begin());
            }
        }
        int cl=*vals.begin();
        dp[i]=dp[cl]+(psum[i]>psum[cl]?0:1);
        vals.insert(i);
    }
    cout<<dp[N];

    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/