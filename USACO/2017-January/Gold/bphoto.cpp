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

#define maxN 100000

int N;
int arr[maxN];
int L[maxN];
int R[maxN];
int ans=0;
int main() {
	ifstream cin("bphoto.in");
	ofstream cout("bphoto.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	vector<int> oL;
	vector<int> oR;
	for(int i=0;i<N;i++){
		int locL=upper_bound(oL.begin(),oL.end(),arr[i])-oL.begin();
		int locR=upper_bound(oR.begin(),oR.end(),arr[N-i-1])-oR.begin();
		L[i]=i-(locL);
		R[N-i-1]=i-locR;
		oL.insert(oL.begin()+locL,arr[i]);
		oR.insert(oR.begin()+locR,arr[N-i-1]);
	}
	for(int i=0;i<N;i++){
		if(min(L[i],R[i])==0){
			if(L[i]!=R[i]) ans++;
		}else if(((double)max(L[i],R[i])/(double)(min(L[i],R[i])))>2.0){
			ans++;
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