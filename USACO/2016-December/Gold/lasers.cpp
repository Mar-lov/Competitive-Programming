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
#define MP make_pair
#define maxN 100005

int N,lx,ly,bx,by;
pi pts[maxN];
unordered_map<int, vector<int> > xs;
unordered_map<int, vector<int> > ys;
unordered_map< int , unordered_map<int,bool> > visited;
//sortes dist node and type of exntions
//type=0 means vert type=1 means horz
typedef pair<pi,pi> State;

State createS(int x,int y,int dist,int type){
	return MP( MP(x,y),MP(dist,type) );
}

int bfs(int sxv,int syv){
	queue<State> q;
	q.push(createS(sxv,syv,0,-1));
	visited[sxv][syv]=true;
	while(!q.empty()){
		State cur=q.front();
		int x=cur.first.first;
		int y=cur.first.second;
		int dist=cur.second.first;
		int type=cur.second.second;
		q.pop();
		if(x==bx&&y==by) return dist; 
		if(type!=1){
			for(int i=0;i<ys[y].size();i++){
				if(visited[ys[y][i]][y]==false){
					visited[ys[y][i]][y]=true;
					q.push(createS(ys[y][i],y,dist+1,1));
				}
			}
		}
		if(type!=0){
			for(int i=0;i<xs[x].size();i++){
				if(visited[x][xs[x][i]]==false){
					visited[x][xs[x][i]]=true;
					q.push(createS(x,xs[x][i],dist+1,0));
				}
			}
		}
	}
	return -1;
}



int main() {
	ifstream cin("lasers.in");
	ofstream cout("lasers.out");
	cin>>N>>lx>>ly>>bx>>by;
	pts[0]=MP(lx,ly);
	pts[N+1]=MP(bx,by);
	xs[lx].push_back(ly);
	ys[ly].push_back(lx);
	xs[bx].push_back(by);
	ys[by].push_back(bx);
	visited[lx][ly]=false;
	visited[bx][by]=false;
	for(int i=1;i<=N;i++){
		cin>>pts[i].first>>pts[i].second;

		xs[pts[i].first].push_back(pts[i].second);
		ys[pts[i].second].push_back(pts[i].first);
		visited[pts[i].first][pts[i].second]=false;
	}

	cout<<bfs(lx,ly)-1<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/