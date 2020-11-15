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

#define maxN 100005
#define maxB 18
#define maxO 50005

int N,M,K;
unordered_map< int , unordered_map<int,int> > edge;
vector<int> adj[maxN];
int bl[maxN][maxB];
int level[maxN];
vector<int> dep[maxO];
set<int> on[maxN];
set<int> off[maxN];
vector<int> result;

void dfsbl(int n,int p){
    bl[n][0]=p;
    for(int a:adj[n])if(a!=p){
        level[a]=level[n]+1;
        dfsbl(a,n);
    }
}

int LCA(int a,int b){
    if(level[a]<level[b]) swap(a,b);
    int dt=level[a]-level[b];
    for(int i=maxB-1;i>=0;i--){
        if((1<<i)&dt){
            a=bl[a][i];
        }
    }
    if(a==b) return a;
    for(int i=maxB-1;i>=0;i--){
        while(bl[a][i]!=bl[b][i]){
            a=bl[a][i];
            b=bl[b][i];
        }
    }
    return bl[a][0];
}

void dfs(int n,int p){
    int big_index=n;
    for(int a:adj[n]) if(a!=p){
        dfs(a,n);
        if(on[a].size()>on[big_index].size()){
            big_index=a;
        }
    }

    for(int a:adj[n]) if(a!=p){
        if(on[a].size()>=K){
            if(a<n){
                result.push_back(edge[a][n]);
            }else{
                result.push_back(edge[n][a]);
            }
        }
    }

    swap(on[n],on[big_index]);

    for(int a:adj[n]) if(a!=p){
        on[n].insert(on[a].begin(),on[a].end());
    }

    //remove values at end
    for(int a:off[n]){
        on[n].erase(a);
    }

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
    int u,v;
    for(int i=0;i<N-1;i++){
        cin>>u>>v;
        if(u>v) swap(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[u][v]=i+1;
    }

    int tv;
    for(int i=0;i<M;i++){
        cin>>tv;
        int nv;
        for(int j=0;j<tv;j++){
            cin>>nv;
            dep[i].push_back(nv);
        }
    }

    //set 0 as root
    adj[0].push_back(1);
    adj[1].push_back(0);
    level[0]=0;
    dfsbl(0,0);
    for(int j=1;j<maxB;j++){
        for(int i=0;i<=N;i++){
            bl[i][j]=bl[bl[i][j-1]][j-1];
        }
    }
    for(int i=0;i<M;i++){
        int cv=dep[i][0];
        for(int j=0;j<dep[i].size();j++){
            cv=LCA(cv,dep[i][j]);
            on[dep[i][j]].insert(i);
        }
        off[cv].insert(i);
    }

    dfs(0,0);

    sort(result.begin(),result.end());
    cout<<result.size()<<'\n';
    for(int a:result){
        cout<<a<<" ";
    }

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/