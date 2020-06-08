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

#define maxD 365

int N;
int arr[maxD];
int result=0;

int main() {
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	sort(arr,arr+N);
	int ci=0;
	int dp=0;
	int inc=0;
	for(int d=0;d<=maxD+20;d++){
		dp+=inc;
		if(ci<N&&arr[ci]==d){
			ci++;
			inc++;
		}
		if(dp+inc>=20){
			//if(arr[ci]==d) ci++;
			result++;
			dp=0;
			inc=0;
			//cout<<d<<'\n';
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/