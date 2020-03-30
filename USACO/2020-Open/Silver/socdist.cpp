/*
ID: marlovk
TASK: socdist
LANG: C++14               
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair< int, pair<int,int> > pii;
#define f first
#define s second

ll N,M;
vector< pair<ll,ll> > vals;
ll maxB=0;
bool pos(ll K){
    ll tsc=0;
    ll ci=0;
    ll cl=-1;
    while(tsc<N&&ci<vals.size()&&cl<=maxB){
        if(cl<=vals[ci].f){
            cl=vals[ci].f;
            tsc++;
            cl+=K;
        }
    while(cl<=vals[ci].s&&cl<maxB){
        cl+=K;
        tsc++;
    }
    ci++;
    }
    return (tsc>=N?true:false);
}

int main() {
    //input setup
    ofstream cout ("socdist.out");
    ifstream cin ("socdist.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    //program
    cin>>N>>M;
    ll a,b;
    for(ll i=0;i<M;i++){
        cin>>a>>b;
        vals.push_back({a,b});
        maxB=max(maxB,b);
    }
    sort(vals.begin(),vals.end());
    ll lb=1;
    ll ub=1000000000000000000;
    while(lb<=ub){
        //cout<<lb<<" "<<ub<<'\n';
        ll mid=(lb+ub)/2;
        if(pos(mid)){
            lb=mid+1;
        }else{
            ub=mid-1;
        }
    }
    cout<<ub<<'\n';
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1,n=0?)
    * do smth instead of nothing and stay organized
*/