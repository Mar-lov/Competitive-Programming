/*
Code by @marlov       
*/
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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxN 205

int N;
int X[maxN];
int Y[maxN];
int DTE[maxN];
vector<int> arr(1,0);
int minD=0;
int main() {
	ifstream cin("lightsout.in");
	ofstream cout("lightsout.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>X[i]>>Y[i];
	}
	for(int i=0;i<N;i++){
		int j=(i+1)%N;
		int k=(i+2)%N;
		arr.push_back(abs(X[j]-X[i])+abs(Y[j]-Y[i]));
		//-1 clock -2 counter
		if((X[i] - X[j]) * (Y[k] - Y[j]) - (X[k] - X[j]) * (Y[i] - Y[j]) > 0) {
      		arr.push_back(-1);
    	}else{
      		arr.push_back(-2);
   		}
	}
	arr.back()=0;
	/*
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	*/
	for(int i=0;i<N;i++){
		DTE[i+1]=DTE[i]+arr[i*2+1];
	}
	DTE[N]=0;
	for(int i=N-1;i>=0;i--){
		DTE[i]=min(DTE[i],DTE[i+1]+arr[2*i+1]);
		//cout<<DTE[i]<<" ";
	}
	//cout<<'\n';
	//cout<<"BEFORE"<<'\n';
	multiset< vector<int> > ctn;
	for(int i=2;i+2<arr.size();i+=2){
		for(int len=1;i+len<=arr.size();len+=2){
			ctn.insert(vector<int>(arr.begin()+i,arr.begin()+i+len));
		}
	}
	for(int i=2;i+2<arr.size();i+=2){
		int ln;
		int cost=0;
		for(ln=1;i+ln<=arr.size();ln+=2){
			if(ctn.count(vector<int>(arr.begin()+i,arr.begin()+i+ln))==1){
				break;
			}
			//cout<<i<<" "<<ctn.count(vector<int>(arr.begin()+i,arr.begin()+i+ln))<<'\n';
			cost+=arr[i+ln];
		}
		minD = max(minD, cost + DTE[(i + ln) / 2] - DTE[i / 2]);
	}
	cout<<minD<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/