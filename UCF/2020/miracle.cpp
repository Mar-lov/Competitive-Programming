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

int T;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		double cur=100.0;
		for(int i=0;i<N;i++){
			cur*=(100+arr[i])/100.0;
		}
		cout<<fixed;
		cout<<setprecision(3)<<cur-100.0<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/