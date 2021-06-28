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
typedef pair<long long,long long> ii;

#define INF 1000000000

long long n;
long double l,w;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>n>>l>>w){
        long double x,r;
        vector< pair<long double,long double> > seg;
        for(long long i=0;i<n;i++){
            cin>>x>>r;
			if(r<w/2.0) continue;
            long double span=sqrt(pow(r,2)-pow(w/2.0,2));
            seg.push_back(make_pair( max((long double)0.0,x-span) , min((long double)l,x+span) ));
        }

        long long dp[n+5];
        fill(dp,dp+n+5,INF);
        seg.push_back(make_pair((long double)0.0,(long double)0.0));
		n++;
        sort(seg.begin(),seg.end());
        dp[0]=0;
        long long ans=INF;

        for(long long i=1;i<n+1;i++){
            for(long long j=0;j<i;j++){
                if(seg[i].first<=seg[j].second){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
            if(seg[i].second==l){
                ans=min(ans,dp[i]);
            }
        }
/*
        for(long long i=0;i<n+1;i++){
            cout<<seg[i].first<<" "<<seg[i].second<<":"<<dp[i]<<endl;
        }
*/
        if(ans>=INF){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}

/* IF STUCK LOOK HERE
    * long long overflow, use long long
    * array bounds
    * edge cases (n=0,n=1)
    * values not distinct?
    * do smth instead of nothing and stay organized
*/