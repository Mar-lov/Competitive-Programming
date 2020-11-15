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

#define maxV 1000005

int N;
int mx=maxV,my=maxV;
int result=0;
set<pair<int,int> > graph;
set<pair<int,int> > visited;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void flood(pair<int,int> loc){
	int x=loc.first;
	int y=loc.second;
	bool found=false;
	for(int cx=-1;cx<2;cx++){
		for(int cy=-1;cy<2;cy++){
			if(graph.count(make_pair(x+cx,y+cy))) found=true;
		}
	}
	if(!found) return;
	visited.insert(loc);
	for(int i=0;i<4;i++){
		if(visited.count(make_pair(x+dx[i],y+dy[i]))) continue;
		if(graph.count(make_pair(x+dx[i],y+dy[i]))){
			result++;
			continue;
		}
		flood(make_pair(x+dx[i],y+dy[i]));
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//ifstream cin("perimeter.in");
	//ofstream cout("perimeter.out");
	cin>>N;
	int x,y;
	for(int i=0;i<N;i++){
		cin>>x>>y;
		graph.insert(make_pair(x,y));
		if(x<mx){
			mx=x;
			my=y;
		}
		if(x==mx){
			my=min(my,y);
		}
	}
	flood(make_pair(mx-1,my));
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/