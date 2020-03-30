#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int mD(int n){
  return (n-1)/2;
}


int N;
string loc;
vector<int> td;
int lsd=0;
int rsd=0;
int maxD=0;
int ald=1000000;

int main() {
  ifstream cin("socdist1.in");
  ofstream cout("socdist1.out");
  cin>>N;
  cin.ignore();
  getline(cin,loc);
    int li=0;
    while(loc[li]=='0'){
      li++;
    }
    lsd=li;
    int ri=N-1;
    while(loc[ri]=='0'){
      ri--;
    }
    rsd=N-ri-1;
    int pv=li;
    for(int i=li+1;i<N;i++){
      if(loc[i]=='1'){
        ald=min(ald,i-pv);
        pv=i;
      }
    }
  int cl=0;
  for(int i=li+1;i<=ri;i++){
    if(loc[i]=='0'){
      cl++;
    }else if(loc[i]=='1'&&loc[i-1]=='0'){
      td.push_back(cl);
      cl=0;
    }
  }
  sort(td.begin(),td.end());
    maxD=max(maxD,min(lsd-1,rsd-1));
    maxD=max(maxD,mD(lsd-1));
    maxD=max(maxD,mD(rsd-1));    
    if(td.size()>=1){
    maxD=max(maxD,((td[td.size()-1]-2)/3));
    maxD=max(maxD,min(lsd-1,mD(td[td.size()-1])));
    maxD=max(maxD,min(rsd-1,mD(td[td.size()-1])));
    }
    if(td.size()>=2){
    maxD=max(maxD,min(mD(td[td.size()-1]),mD(td[td.size()-2])));
    }
    cout<<min(ald,maxD+(ri<li?0:1))<<'\n';
  return 0;
}