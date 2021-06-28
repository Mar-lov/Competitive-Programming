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
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define maxN 105

int T;
int N;
int arr[maxN];
int order[maxN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--){
	cin>>N;
	for(int i=0;i<N;i++){
		int cur;
		cin>>cur;
		arr[i]=cur;
		order[i]=cur;
	}
	sort(arr,arr+N);
	int ele;
	if(arr[0]==arr[1]){
		ele=arr[N-1];
	}else{
		ele=arr[0];
	}
	for(int i=0;i<N;i++){
		if(order[i]==ele){
			cout<<i+1<<endl;
			break;
		}
	}
	}
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/