#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int N,K;
vector<int> arr;
vector<int> rM;
int result=0;

//Greedy solution is to take all intervals between 12 year intervals that done have any cows
//
int main() {
  cin>>N>>K;
  int in;
  for(int i=0;i<N;i++){
    cin>>in;
    arr.push_back(-1*in);
  }
  sort(arr.begin(),arr.end());
  arr.push_back(0);
  int leaveYear=-1*arr[0]/12;
  result=leaveYear+1;
  for(int i=0;i<arr.size();i++){
    int cly=-1*arr[i]/12;
    if(cly!=leaveYear){
    rM.push_back(leaveYear-(cly+(arr[i]!=0?1:0)));
    leaveYear=cly;
    }
  }
  sort(rM.begin(),rM.end());
  K--;
  for(int i=0;i<K;i++){
    result-=rM.back();
    rM.pop_back();
  }
  cout<<12*result<<'\n';
}