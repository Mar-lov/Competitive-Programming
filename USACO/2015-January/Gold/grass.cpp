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

#define maxV 100005

int N,M;
int el[maxV][2];
vector<int> ccadj[maxV];
vector<int> ccradj[maxV];
vector<int> adj[maxV];
vector<int> radj[maxV];
int cg=0;
map<int,int> tg;
int gs[maxV];

stack<int> s;
bool visited1[maxV];
void cc1(int n){
    visited1[n]=true;
    for(int a:ccradj[n]) if(!visited1[a]){
        cc1(a);
    }
    s.push(n);
}
bool visited2[maxV];
void cc2(int n){
    visited2[n]=true;
    for(int a:ccadj[n]) if(!visited2[a]){
        cc2(a);
    }
    tg[n]=cg;
    gs[cg]++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M;
    int u,v;
    for(int i=0;i<M;i++){
        cin>>u>>v;
        u--;
        v--;
        el[i][0]=u;
        el[i][1]=v;
        ccadj[u].push_back(v);
        ccradj[v].push_back(u);
    }

    //run Korasaju's
    for(int i=0;i<N;i++){
        if(!visited1[i]) cc1(i);
    }
    /*while(!s.empty()){
        cout<<s.top()+1<<" "; s.pop();
    }*/
    while(!s.empty()){
        if(!visited2[s.top()]) cc2(s.top());
        s.pop();
        cg++;  
    }

    for(int i=0;i<M;i++){
        u=el[i][0];
        v=el[i][1];
        int gu=tg[u];
        int gv=tg[v];
        if(gu!=gv){
            adj[gu].push_back(gv);
            radj[gv].push_back(gu);
        }
    }



    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/