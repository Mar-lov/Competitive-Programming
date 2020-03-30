#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define maxN 105
int N,T;
string inf;
vector< pair< int, pair<int,int> > > shakes;
vector<int> cow[maxN];

//answers
int pI=0;
int minK=-1,maxK=1000000;

int main() {
  ifstream cin("tracing.in");
  ofstream cout("tracing.out");
  cin>>N>>T;
  cin.ignore();
  getline(cin,inf);
  int t,x,y;
  for(int i=0;i<T;i++){
    cin>>t>>x>>y;
    x--;
    y--;
    shakes.push_back({t,{x,y}});
  }
  sort(shakes.begin(),shakes.end());
  for(int i=0;i<shakes.size();i++){
    cow[x].push_back(y);
    cow[y].push_back(x);
  }
  int fmv=1000000;
  for(int i=0;i<N;i++){
    if(inf[i]=='1'){
      int j=0;
      while(j<cow[i].size()&&inf[cow[i][j]]!='0'){
        j++;
      }
      if(j!=cow[i].size()&&j!=0){
        fmv=min(fmv,j+1);
      }
    }
  }
  maxK=fmv;
  for(int p=0;p<N;p++){
    if(inf[p]=='1'){
      bool pos=true;
      vector<int> seen(N,0);
      seen[p]++;
      for(int i=0;i<shakes.size()&&pos;i++){
        int fc=shakes[i].second.first;
        int sc=shakes[i].second.second;
        if(seen[fc]>0&&seen[fc]<maxK+(fc==p?1:0)&&seen[sc]<maxK+(sc==p?1:0)){
          seen[fc]++;
          seen[sc]++;
          if(inf[sc]=='0') pos=false;
        }else if(seen[sc]>0&&seen[sc]<maxK+(sc==p?1:0)&&seen[fc]<maxK+(fc==p?1:0)){
          seen[fc]++;
          seen[sc]++;
          if(inf[sc]=='0') pos=false;
        }
      }
      seen[p]--;
      if(pos){
        pI++;
      }
      int gm=seen[p];
      for(int j=0;j<seen.size();j++){
        if(seen[j]>0){
          gm=min(gm,seen[j]);
        }
      }
      if(minK==-1){
        minK=gm;
      }
      minK=min(gm,minK);

    }

  }
  cout<<pI<<" ";
  if(maxK==1000000){
    cout<<minK<<" "<<"Infinity";
  }else{
    cout<<maxK<<" "<<maxK;
  }
  cout<<'\n';
    return 0;
}