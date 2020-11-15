#include "grader.h"
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
#define maxB 17

vector<int> adj[maxN];
int subtree[maxN];
int level[maxN];
int bl[maxN][maxB];
pair<int,int> loc[maxN];

/*
void setFarmLocation(int a,int x,int y){
	cout<<a<<" at "<<x<<","<<y<<'\n';
}

int getN(){return 6;}
*/

//all self made functions
int findS(int n,int p){
	bl[n][0]=p;
	level[n]=level[p]+1;
	subtree[n]=1;
	for(int a:adj[n])if(a!=p){
		subtree[n]+=findS(a,n);
	}
	return subtree[n];
}

void solve(int n,int p){
	if(subtree[n]==1) return;
	//has more than 1 child
	//start x and start y locations
	int sx=loc[n].first;
	int sy=loc[n].second+subtree[n];
	for(int a:adj[n]) if(a!=p){
		sy-=subtree[a];
		loc[a]=make_pair(sx,sy);
		sx+=subtree[a];
		assert(loc[a].second<=getN());
		setFarmLocation(a,loc[a].first,loc[a].second);
		solve(a,n);
	}
}

//all grader functions
void addRoad(int a, int b){
	// Fill in code here
	adj[a].push_back(b);
	adj[b].push_back(a);
}



//root 0
void buildFarms(){
	//subtree sizes
	findS(0,0);
	//setup binary lifitng
	for(int j=1;j<maxB;j++){
		for(int i=0;i<getN();i++){
			bl[i][j]=bl[bl[i][j-1]][j-1];
		}
	}
	//build tree
	loc[0]=make_pair(1,1);
	setFarmLocation(0,loc[0].first,loc[0].second);
	solve(0,0);
}

//essentially just LCA
void notifyFJ(int ia, int ib){
	// Fill in code here
	int a=ia;
	int b=ib;
	if(level[a]<level[b]){
		swap(a,b);
		swap(ia,ib);
	}
	int dt=level[a]-level[b];
	for(int i=maxB-1;i>=0;i--){
		if((1<<i)&dt){
			a=bl[a][i];
		}
	}
	if(a==b){
		addBox(loc[b].first,loc[b].second,loc[ia].first,loc[ia].second);
		return;
	}
	for(int i=maxB-1;i>=0;i--){
		while(bl[a][i]!=bl[b][i]){
			a=bl[a][i];
			b=bl[b][i];
		}
	}
	addBox(loc[a].first,loc[a].second,loc[ia].first,loc[ia].second);
	addBox(loc[bl[b][0]].first,loc[bl[b][0]].second,loc[ib].first,loc[ib].second);
	return;
}


/*
int main(){
	addRoad(0,1);
	addRoad(1,2);
	addRoad(0,3);
	addRoad(3,4);
	addRoad(3,5);
	buildFarms();

}
*/
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/