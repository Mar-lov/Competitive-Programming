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
typedef pair<int,int> pi;

#define maxN 1005


int A,B,N;
int cost[maxN];
set<int> adj[maxN];
vector<int> unit[maxN];
int dist[maxN];

struct loc{
	int n;
	int cg;
	int cc;
	int tf;

	loc(int s,int g){
		n=s;
		cg=g;
		cc=cost[g];
		tf=0;
	}

};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>A>>B>>N;
	int cn;
	for(int i=0;i<N;i++){
		cin>>cost[i]>>cn;
		int cl;
		vector<int> vals;
		for(int j=0;j<cn;j++){
			cin>>cl;
			unit[cl].push_back(i);
			vals.push_back(cl);
		}
		for(int i=0;i<vals.size();i++){
			int v2=vals[i];
			int v1=vals[(i+vals.size()-1)%vals.size()];
			int v3=vals[(i+1)%vals.size()];
			adj[v2].insert(v1);
			adj[v2].insert(v3);
		}
	}
	//bfs
	queue<loc> q;
	for(int i=0;i<unit[A].size();i++){
		q.push(loc(A,unit[A][i]));
	}
	while(!q.empty()){
		loc cur=q.front();
		q.pop();
		
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/