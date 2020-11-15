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
typedef pair<ll,ll> pi;

#define maxN 200000
#define INF 1000000000

ll N,Q;
ll lazy[4*maxN+1];
ll trees[4*maxN+1];
ll treem[4*maxN+1];
ll arr[maxN];

void push(ll index,ll L,ll R){
    trees[index]+=(R-L+1)*lazy[index];
    treem[index]+=lazy[index];
    if(L!=R){
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
    }
    lazy[index]=0;
}

void build(ll index,ll L,ll R){
    if(L==R){
        trees[index]=arr[L];
        treem[index]=arr[L];
        return;
    }
    build(2*index,L,(L+R)/2);
    build(2*index+1,(L+R)/2+1,R);
    trees[index]=trees[2*index]+trees[2*index+1];
    treem[index]=min(treem[2*index],treem[2*index+1]);
}

ll querys(ll index,ll qL,ll qR,ll L,ll R){
    if(R<qL||qR<L) return 0;
    push(index,L,R);
    if(qL<=L&&R<=qR) return trees[index];

    return querys(2*index,qL,qR,L,(L+R)/2)+querys(2*index+1,qL,qR,(L+R)/2+1,R);
}

ll querym(ll index,ll qL,ll qR,ll L,ll R){
    if(R<qL||qR<L) return INF;
    push(index,L,R);
    //Push must come before this statement
    if(qL<=L&&R<=qR) return treem[index];
    return min(querym(2*index,qL,qR,L,(L+R)/2),querym(2*index+1,qL,qR,(L+R)/2+1,R));
}

void update(ll index,ll qL,ll qR,ll L,ll R,ll delta){
    push(index,L,R);
    if(R<qL||qR<L) return;
    if(qL<=L&&R<=qR){
        lazy[index]+=delta;
        push(index,L,R);
        return;
    }
    update(2*index,qL,qR,L,(L+R)/2,delta);
    update(2*index+1,qL,qR,(L+R)/2+1,R,delta);
    trees[index]=trees[2*index]+trees[2*index+1];
    treem[index]=min(treem[2*index],treem[2*index+1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");
	cin>>N>>Q;
    for(ll i=1;i<=N;i++){
        cin>>arr[i];
    }
    build(1,1,N);
    char v;
    ll a,b,c;
    for(ll i=0;i<Q;i++){
        cin>>v;
        cin>>a>>b;
        if(v=='M'){
            cout<<querym(1,a,b,1,N)<<'\n';
        }else if(v=='S'){
            cout<<querys(1,a,b,1,N)<<'\n';
        }else{
            cin>>c;
            update(1,a,b,1,N,c);
        }
    }
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/