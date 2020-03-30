#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector< pair<int,int> > arr;

int main() {
  ifstream cin("socdist2.in");
  ofstream cout("socdist2.out");
  cin>>n;
  int fv,sv;
  for(int i=0;i<n;i++){
    cin>>fv>>sv;
    arr.push_back({fv,sv});
  }
  sort(arr.begin(),arr.end());
  int mhd=10000000;
  for(int i=0;i<n;i++){
    if(arr[i].second==0){
      if(i>0&&arr[i-1].second==1){
        mhd=min(mhd,arr[i].first-arr[i-1].first);
      }
      if(i<n-1&&arr[i+1].second==1){
        mhd=min(mhd,arr[i+1].first-arr[i].first);
      }
    }
  }
  int tgc=0;

  for(int i=0;i<n;i++){
    if(arr[i].second==1){
      tgc++;
    }
    int j=i;
    while(j<n&&arr[j].second==1&&(j==n-1?mhd:arr[j+1].first-arr[j].first)<mhd){
      j++;
    }
    i=j;
  }
  cout<<tgc<<'\n';
}