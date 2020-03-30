/*
ID: marlovk
TASK: cereal
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

int N,M;
vector< pi > arr;
vector<int> ans;
unordered_set<int> psv[100005];
unordered_set<int> ccv;

int main() {
    //input setup
    ofstream cout ("cereal.out");
    ifstream cin ("cereal.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    //program
    cin>>N>>M;
    int a,b;
    for(int i=0;i<N;i++){
      cin>>a>>b;
      arr.push_back({a,b});
    }

    for(int i=N-1;i>=0;i--){
      int fv=arr[i].first;
      int sv=arr[i].second;
      if(ccv.count(fv)){
        ccv.insert(psv[fv].begin(),psv[fv].end());
        psv[fv].clear();
      }
      ccv.insert(fv);
      psv[fv].insert(sv);
      ans.push_back(ccv.size());
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<'\n';
    }
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1,n=0?)
    * do smth instead of nothing and stay organized
*/