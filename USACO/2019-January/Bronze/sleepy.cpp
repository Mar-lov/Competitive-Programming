#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream cin("sleepy.in");
  ofstream cout("sleepy.out");
  int N;
  cin>>N;
  int arr[N];
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  int sortedLength=1;
  for(int i=N-2;i>=0;i--){
    if(arr[i]<arr[i+1]){
      sortedLength++;
    }else{
      break;
    }
  }
  cout<<N-sortedLength<<'\n';
}