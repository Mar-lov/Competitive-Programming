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

#define maxN 100005

ll N;
ll arr[maxN];
ll psum[maxN];
ll ts=0;
int nv;
int dv;
vector<int> ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("homework.in");
    ofstream cout("homework.out");
    cin>>N;
    for(ll i=1;i<=N;i++){
        cin>>arr[i];
        ts+=arr[i];
        psum[i]=arr[i];
        psum[i]+=psum[i-1];
    }

    nv=0;
    dv=1;
    ll mv=arr[N];

    for(ll i=N-2;i>=1;i--){

        mv=min(arr[i+1],mv);
        if((ts-psum[i]-mv)*dv>nv*(N-i-1)){
            nv=ts-psum[i]-mv;
            dv=N-i-1;
            ans.clear();
            //ans.push_back(i);
        }
        if((ts-psum[i]-mv)*dv==nv*(N-i-1)){
            ans.push_back(i);
        }

    }
    sort(ans.begin(),ans.end());
    for(int v:ans){
        cout<<v<<'\n';
    }
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/