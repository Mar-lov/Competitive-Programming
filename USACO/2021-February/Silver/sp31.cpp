#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

long long N;
long long original[510][510];
long long aboveH[510][510];
long long totalH[510][510];
long long result=0;

long long pA(long long sr,long long sc,long long er,long long ec){
  return aboveH[er][ec]-aboveH[er][sc-1]-aboveH[sr-1][ec]+aboveH[sr-1][sc-1];
}
long long pH(long long sr,long long sc,long long er,long long ec){
  return totalH[er][ec]-totalH[er][sc-1]-totalH[sr-1][ec]+totalH[sr-1][sc-1];
}

int main() {
  cin>>N;
  for(long long i=1;i<=N;i++){
    for(long long j=1;j<=N;j++){
      cin>>original[i][j];
      if(original[i][j]>=100){
        aboveH[i][j]=1;
      }
      if(original[i][j]==100){
        totalH[i][j]=1;
      }
    }
  }
  //built the psums
  for(long long i=2;i<=N;i++){
    aboveH[i][1]+=aboveH[i-1][1];
    totalH[i][1]+=totalH[i-1][1];
  }
  for(long long i=2;i<=N;i++){
    aboveH[1][i]+=aboveH[1][i-1];
    totalH[1][i]+=totalH[1][i-1];
  }
  for(long long i=2;i<=N;i++){
    for(long long j=2;j<=N;j++){
      aboveH[i][j]+=aboveH[i-1][j]+aboveH[i][j-1]-aboveH[i-1][j-1];
      totalH[i][j]+=totalH[i-1][j]+totalH[i][j-1]-totalH[i-1][j-1];
    }
  }
  //to calc
  long long tval[510];
  long long tH[510];
  for(long long a=1;a<=N;a++){
    for(long long b=a;b<=N;b++){
      //find vals;
      for(long long i=1;i<=N;i++){
        tval[i]=pA(a,i,b,i);
        tH[i]=pH(a,i,b,i);
      }
      long long V=(b-a+1);
      long long curTotal=0;
      //calc all vals
      long long cl=0;
      for(long long i=1;i<=N+1;i++){
        if(tval[i]==V){
          cl++;
        }else{
          curTotal+=(cl*(cl+1))/2;
          cl=0;
        }
      }
      //remove notworking vals
      cl=0;
      for(long long i=1;i<=N+1;i++){
          if(tH[i]==0&&tval[i]==V){
            cl++;
          }else{
            curTotal-=(cl*(cl+1))/2;
            cl=0;
          }
      }
      
      result+=curTotal;
    }
  }
  cout<<result<<'\n';
  return 0;
}