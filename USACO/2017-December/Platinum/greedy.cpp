/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxN 100005

int N;
int arr[maxN];

int num[maxN];
bool recieve(int k){
	fill(num,num+N,0);
	for(int i=0;i<k;i++){
		num[arr[i]]++;
	}
	int total=0;
	for(int i=1;i<=N;i++){
		total+=num[i];
		if(total>=i) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("greedy.in");
	ofstream cout("greedy.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		arr[i]=N-arr[i];
	}
	int lo=1;
	int hi=N;
	while(lo<hi){
		int mid=(lo+hi)/2;
		if(recieve(mid)){
			lo=mid+1;
		}else{
			hi=mid;
		}
	}
	cout<<N-lo<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/