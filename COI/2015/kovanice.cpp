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

#define maxN 300005
#define INF 1000000000

int N,M,V;
int p[maxN];
int r[maxN];
vector< pair<int,int> > grps;

//graphs
vector<int> ls,gs;
vector<int> adjl[maxN];
vector<int> adjg[maxN];
//dp
int dpmin[maxN];
int dpmax[maxN];



int findP(int n){
    if(n==p[n]) return n;
    int pn=findP(p[n]);
    p[n]=pn;
    return pn;
}

void combine(int a,int b){
    int p1=findP(a);
    int p2=findP(b);
    if(r[p1]<r[p2]) swap(p1,p2);
    p[p2]=p1;
    r[p1]=max(r[p1],r[p2]+1);
}   

void dfsmin(int n){
    if(dpmin[n]!=0) return;
    if(adjg[n].size()==0){
        dpmin[n]=1;
        return;
    }
    for(int a:adjg[n]){
        dfsmin(a);
        dpmin[n]=max(dpmin[n],dpmin[a]+1);
    }
}

void dfsmax(int n){
    if(dpmax[n]!=INF) return;
    if(adjl[n].size()==0){
        dpmax[n]=N;
        return;
    }
    for(int a:adjl[n]){
        dfsmax(a);
        dpmax[n]=min(dpmax[n],dpmax[a]-1);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>V;
    cin.ignore();
    for(int i=0;i<M;i++){
        p[i]=i;
        r[i]=1;
        dpmin[i]=0;
        dpmax[i]=INF;
    }
    string str;
    for(int i=0;i<V;i++){
        getline(cin,str);
        stringstream sin(str);
        int f,s;
        char c;
        sin>>f>>c>>s;
        f--;
        s--;
        if(c=='='){
            combine(f,s);
        }else if(c=='<'){
            grps.push_back(make_pair(f,s));
        }
    }
    for(int i=0;i<grps.size();i++){
        adjl[findP(grps[i].first)].push_back(findP(grps[i].second));
        adjg[findP(grps[i].second)].push_back(findP(grps[i].first));
    }
    //find starts
    for(int i=0;i<M;i++){
        if(p[i]==i&&adjg[i].size()==0) ls.push_back(i);
        if(p[i]==i&&adjl[i].size()==0) gs.push_back(i);
    }

    for(int i=0;i<M;i++){
        dfsmin(findP(i));
        dfsmax(findP(i));
    }
    for(int i=0;i<M;i++){
        //cout<<dpmin[findP(i)]<<" "<<dpmax[findP(i)]<<'\n';
        if(dpmin[findP(i)]==dpmax[findP(i)]){
            cout<<"K"<<dpmin[findP(i)]<<'\n';
        }else{
            cout<<"?"<<'\n';
        }
    }

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/