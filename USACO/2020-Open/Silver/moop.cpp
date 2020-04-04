
/*
ID: marlovk
TASK: moop
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
typedef pair< pair<int,int>,int > pii;
#define f first
#define s second

#define maxN 100000

int N;
vector< pi > pts;
int ans=0;

int main() {
    //input setup
    //ofstream cout ("moop.out");
    //ifstream cin ("moop.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    //program
    cin>>N;
    int a,b;
    for(int i=0;i<N;i++){
      cin>>a>>b;
      pts.push_back({a,b});
    }
    sort(pts.begin(),pts.end());
    int cm=-1000000000;
    for(int i=pts.size()-1;i>=0;i--){
      if(pts[i].second>cm){
        cm=pts[i].second;
      }
    }
    cout<<ans<<'\n';
    return 0;
}

/* stuff you should look for
  * int overflow, array bounds
  * special cases (n=1,n=0?)
  * do smth instead of nothing and stay organized
*/


