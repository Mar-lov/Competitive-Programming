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
#define INF 1000000000

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int N,D;
char chart[maxN][maxN];
//all S values locations
vector< pi > start;
int result=0;

//distance to closest Wall
int distW[maxN][maxN];
//wall visited
bool wallV[maxN][maxN];
void bfsWall(){
	queue< pi > q;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			distW[i][j]=INF;
			if(chart[i][j]=='#'){
				q.push(make_pair(i,j));
				wallV[i][j]=true;
				distW[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		int cx=q.front().first;
		int cy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=cx+dx[i];
			int ny=cy+dy[i];
			if(!(nx>=0&&nx<N&&ny>=0&&ny<N)) continue;
			if(wallV[nx][ny]) continue;
			if(distW[nx][ny]>distW[cx][cy]+1){
				distW[nx][ny]=distW[cx][cy]+1;
				wallV[nx][ny]=true;
				q.push(make_pair(nx,ny));
			}
		}
	}
}

//distance from closest start location
int dist[maxN][maxN];
bool visited[maxN][maxN];
void bfsStarts(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dist[i][j]=INF;
		}
	}
	queue<pi> q;
	for(int i=0;i<start.size();i++){
		dist[start[i].first][start[i].second]=0;
		visited[start[i].first][start[i].second]=true;
		q.push(start[i]);
	}
	while(!q.empty()){
		int cx=q.front().first;
		int cy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=cx+dx[i];
			int ny=cy+dy[i];
			if(!(nx>=0&&nx<N&&ny>=0&&ny<N)) continue;
			if(visited[nx][ny]) continue;
			if(dist[nx][ny]>dist[cx][cy]+1&&distW[nx][ny]>=1+(dist[cx][cy]+1)/D){
				dist[nx][ny]=dist[cx][cy]+1;
				visited[nx][ny]=true;
				q.push(make_pair(nx,ny));
			}else if(distW[nx][ny]>=1+(dist[cx][cy])/D){
				visited[nx][ny]=true;
			}
		}
	}
}

//pv=propagation value so how much furthur our can it propagate
int pv[maxN][maxN];
//if we visited the values
bool seen[maxN][maxN];
priority_queue< pair<int, pair<int,int> > , vector< pair<int, pair<int,int> > > , less< pair<int, pair<int,int> > > > pq;

void prop(int cd,int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(chart[nx][ny]=='#') continue;
		if(pv[nx][ny]<cd){
			pv[nx][ny]=cd;
			pq.push(make_pair(cd,make_pair(nx,ny)));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>D;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>chart[i][j];
			if(chart[i][j]=='S') start.push_back(make_pair(i,j));
		}
	}

	//sets up walls and finds min distance to them
	bfsWall();
	//goes through start. So moves the 'centers' of robots as much as possible
	bfsStarts();

	//goes to all possible visited values and progagates from them if it will make a difference
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(visited[i][j]){
				pv[i][j]=distW[i][j];
				pq.push(make_pair(distW[i][j],make_pair(i,j)) );
				//cout<<distW[i][j]<<" "<<i<<" "<<j<<endl;
			}
		}
	}
	//cout<<"PQ"<<endl;
	while(!pq.empty()){
		int cd=pq.top().first;
		int cx=pq.top().second.first;
		int cy=pq.top().second.second;
		pq.pop();
		//cout<<cd<<" "<<cx<<" "<<cy<<endl;
		if(seen[cx][cy]) continue;
		prop(cd-1,cx,cy);
		seen[cx][cy]=true;
	}

	//see how many were visited
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(seen[i][j]) result++;
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
