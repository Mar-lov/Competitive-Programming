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

#define maxV 100005

int T;
int arr[maxV];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	for(int z=0;z<T;z++){
		int N,M;
		cin>>N>>M;
		int u,v;
		fill(arr,arr+N,0);
		for(int i=0;i<M;i++){
			cin>>u>>v;
			arr[u]++;
			arr[v+1]--;
		}
		int cs=0;
		for(int i=0;i<N;i++){
			cs+=arr[i];
			arr[i]=cs;
		}
		int result=0;
		int cv=0;
		for(int i=0;i<N;i++){
        if(arr[i]>cv){
            result+=arr[i]-cv;
            cv=arr[i];
        }else if(arr[i]<=cv){
            cv=arr[i];
        }
    	}
		cout<<result<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/