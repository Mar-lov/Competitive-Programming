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
typedef int ll;
typedef pair<int,int> pi;

#define maxN 100001

int N,M;
int salary[maxN];
int leadership[maxN];
vector<int> adj[maxN];
//all the salary values
multiset<int> vals[maxN];
//min sum for all nodes
long long mins[maxN];
long long result=0;
//root node
int root=0;

//merge small to large
void dfs(int n){
	int big_index=n;
	for(int c:adj[n]){
		dfs(c);
		//doing by size instead
		if(vals[c].size()>vals[big_index].size()){
			big_index=c;
		}
	}
	swap(vals[n],vals[big_index]);
	swap(mins[n],mins[big_index]);

	for(int c:adj[n]){
			for(int a:vals[c]){
				//possible placement location
				multiset<int>::iterator loc=vals[n].upper_bound(a);
				//largest value of this list
				int back=*(vals[n].rbegin());
				//if can add value add it
				if(mins[n]+a<=M){
					mins[n]+=(a);
					//maybe add loc
					vals[n].insert(a);
					//if new value is less than current largesrt add it and remove others
				}else if(loc!=vals[n].end()){
					mins[n]+=(a-back);
					vals[n].insert(a);
					//maybe switch to vals[n].rbegin()
					vals[n].erase(vals[n].find(back));
					//if doesnt give any benefit to current list move on
				}else{
					break;
				}
			}
	}

	//cout<<n<<" "<<tm<<" yeilds: "<<tm*leadership[n]<<'\n';
	//cout<<tm<<" and "<<leadership[n]<<'\n';

	//current list size * leadership
	result=max(result,(long long)vals[n].size()*(long long)leadership[n]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M;
	int cnp;
	//reads in values 
	for(int i=1;i<=N;i++){
		cin>>cnp>>salary[i]>>leadership[i];
		adj[cnp].push_back(i);
		vals[i].insert(salary[i]);
		mins[i]=salary[i];
		if(cnp==0) root=i;
	}
	dfs(root);
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/