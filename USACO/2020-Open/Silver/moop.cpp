
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
int p[maxN];
int r[maxN];
int tgc;

int parent(int n){
  if(n==p[n])return n;
  return parent(p[n]);
}

void combine(int a,int b){
  int pa=parent(a);
  int pb=parent(b);
  if(pa!=pb){
    if(r[pa]<=r[pb]){
      r[pa]=max(r[pa],r[pb]+1);
      p[pb]=pa;
    }else{
      r[pb]=max(r[pb],r[pa]+1);
      p[pa]=pb;
    }
    tgc--;
  }
}

bool inG(pi a,pi b){
  if(a.f>=b.f&&a.s>=b.s) return true;
  if(a.f<=b.f&&a.s<=b.s) return true;
  return false;
}

int main() {
    //input setup
    ofstream cout ("moop.out");
    ifstream cin ("moop.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    //program
    cin>>N;
    tgc=N;
    for(int i=0;i<N;i++){
      p[i]=i;
    }
    int a,b;
    for(int i=0;i<N;i++){
      cin>>a>>b;
      pts.push_back({a,b});
    }
    for(int i=0;i<N;i++){
      for(int j=1;j<N;j++){
        if(inG(pts[i],pts[j])){
          combine(i,j);
          //cout<<i<<" "<<j<<'\n';
        }
      }
    }
    cout<<tgc<<'\n';
    return 0;
}

/* stuff you should look for
  * int overflow, array bounds
  * special cases (n=1,n=0?)
  * do smth instead of nothing and stay organized
*/


