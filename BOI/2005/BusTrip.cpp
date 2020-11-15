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
 
#define INF 2000000000
#define maxN 50000
#define maxM 100000
 
struct trip{
    int u,v;
    int a,b,c,d;
};
 
bool cmp(trip a,trip b){
    if(a.d==b.d) return a.a<b.a;
    return a.d<b.d;
}
 
int N,M,P,T;
trip bus[maxM];
//first value is destination time secone is min wait time
vector< pair<int,int> > dp[maxN];
 
 
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>P>>T;
    P--;
    for(int i=0;i<M;i++){
        cin>>bus[i].u>>bus[i].v>>bus[i].a>>bus[i].b>>bus[i].c>>bus[i].d;
        bus[i].u--;
        bus[i].v--;
    }
    sort(bus,bus+M,cmp);
 
    dp[0].push_back(make_pair(0,0));
    for(int k=0;k<M;k++){
        trip cur=bus[k];
        int f=cur.u;
        int s=cur.v;
        if(cur.d>T) break;
        int pt=-1;
        int dt=0;
        for(int i=dp[f].size()-1;i>=0;i--){
            if(dp[f][i].first<=cur.a){
                pt=dp[f][i].second;
                dt=cur.b-dp[f][i].first+cur.d-cur.c;
                break;
            }
        }
        if(pt==-1) continue;
        //add to destination
        if(dp[s].size()==0){
            dp[s].push_back(make_pair(cur.d,pt+dt));
        }else if(((dp[s].back().second+(cur.d-dp[s].back().first))>(pt+dt))){
            dp[s].push_back(make_pair(cur.d,pt+dt));
        }
        //cout<<k<<'\n';
    }
    int result=INF;
    if(dp[P].size()==0){
        cout<<-1<<'\n';
    }else{
        for(int i=0;i<dp[P].size();i++){
            result=min(result,(T-dp[P][i].first)+dp[P][i].second);
        }
        cout<<result<<'\n';
    }
    return 0;
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/