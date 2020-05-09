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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxN 100002

int N;
int arr[maxN];
vector<int> adj[maxN];
int start[maxN];
int stop[maxN];
stack<int> sim;

int solve(){
	int mN=0;
	for(int i=0;i<N;i++){
		if(start[i]!=0) sim.push(start[i]);
		mN=max(mN,(int)sim.size());
		if(stop[i]!=0){
			if(sim.top()!=stop[i]){
				return -1;
			}else{
				sim.pop();
			}
		}
	}

	return mN;
}

int main() {
	ifstream cin("art2.in");
	ofstream cout("art2.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		adj[arr[i]].push_back(i);
	}
	for(int i=1;i<=N;i++){
		if(adj[i].size()>0){
			start[adj[i].front()]=i;
			stop[adj[i].back()]=i;
		}
	}
	/*
	for(int i=0;i<N;i++){
		cout<<start[i]<<" "<<stop[i]<<'\n';
	}
	*/
	cout<<solve()<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/