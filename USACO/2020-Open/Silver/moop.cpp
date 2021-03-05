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
typedef pair<int,int> pi;

#define maxN 100005
#define INF 1000000007

int N;
pair<int,int> arr[maxN];

int p[maxN];
int r[maxN];
int groups;

int findP(int n){
    if(n==p[n]) return n;
    int np=findP(p[n]);
    p[n]=np;
    return np;
}

void combine(int a,int b){
    int p1=findP(a);
    int p2=findP(b);
    if(p1==p2) return;
    groups--;
    if(r[p1]<r[p2]) swap(p1,p2);
    p[p2]=p1;
    r[p1]=max(r[p1],r[p2]+1);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("moop.in");
    ofstream cout("moop.out");
	cin>>N;
    groups=N;
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++){
        p[i]=i;
        r[i]=1;
    }
    vector<pi> ys;
    for(int i=0;i<N;i++){
        int cy=arr[i].second;
        if(ys.size()==0||cy<ys.back().first){
            ys.push_back(make_pair(cy,i));
        }
        else{
            pi bv=ys.back();
            while(ys.size()>0&&ys.back().first<=cy){
                combine(ys.back().second,i);
                ys.pop_back();
            }
            ys.push_back(bv);
        }
       // cout<<i<<endl;
    }
    cout<<groups<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/