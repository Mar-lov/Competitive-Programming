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
typedef pair<long long,long long> pi;

#define maxN 16
#define maxD 51
#define INF 10000000

long long R,C;
long long tg=0;
long long grid[maxD][maxD];
bool visited[maxD][maxD];
bool visited2[maxD][maxD];
long long dist[maxN][maxN];

long long dp[(1<<maxN)][maxN];

long long dx[4]={0,-1,0,1};
long long dy[4]={-1,0,1,0};

//for finding specific groups
void groupFill(long long x,long long y,long long cg){
	if(visited[x][y]) return;
	grid[x][y]=cg;
	visited[x][y]=true;
	for(long long i=0;i<4;i++){
		if(x+dx[i]>=0&&x+dx[i]<R&&y+dy[i]>=0&&y+dy[i]<C&&grid[x+dx[i]][y+dy[i]]==-1){
			groupFill(x+dx[i],y+dy[i],cg);
		}
	}
}

//does bfs on the paths
void bfs(long long x,long long y,long long sg){
	bool seen[maxD][maxD];
	queue< pair< pair<long long,long long>,long long> > q;
	for(long long i=0;i<maxD;i++){
		fill(seen[i],seen[i]+maxD,false);
	}
	q.push(make_pair( make_pair(x,y),1 ));
	seen[x][y]=true;
	while(!q.empty()){
		long long cx=q.front().first.first;
		long long cy=q.front().first.second;
		long long cd=q.front().second;
		q.pop();

		for(long long i=0;i<4;i++){
			if(cx+dx[i]>=0&&cx+dx[i]<R&&cy+dy[i]>=0&&cy+dy[i]<C&&!seen[cx+dx[i]][cy+dy[i]]){
				if(grid[cx+dx[i]][cy+dy[i]]==-2){
					seen[cx+dx[i]][cy+dy[i]]=true;
					q.push(make_pair( make_pair(cx+dx[i],cy+dy[i]),cd+1));
				}else if(grid[cx+dx[i]][cy+dy[i]]>=0&&grid[cx+dx[i]][cy+dy[i]]<=tg&&grid[cx+dx[i]][cy+dy[i]]!=sg){
					dist[sg][grid[cx+dx[i]][cy+dy[i]]]=min(cd,dist[sg][grid[cx+dx[i]][cy+dy[i]]]);
				}
			}
		}
	}
}

//check around a group for possible paths to other island
void groupCheck(long long x,long long y,long long cg){
	if(visited2[x][y]) return;
	if(grid[x][y]==100) return;
	if(grid[x][y]==-2){
		//cout<<"checking :"<<x<<" "<<y<<'\n';
		bfs(x,y,cg);
		
		return;
	}

	visited2[x][y]=true;
	for(long long i=0;i<4;i++){
		if(x+dx[i]>=0&&x+dx[i]<R&&y+dy[i]>=0&&y+dy[i]<C){
			groupCheck(x+dx[i],y+dy[i],cg);
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("island.in");
	ofstream cout("island.out");
	cin>>R>>C;
	for(long long i=0;i<R;i++){
		for(long long j=0;j<C;j++){
			char cur;
			cin>>cur;
			if(cur=='X'){
				grid[i][j]=-1;
			}else if(cur=='S'){
				grid[i][j]=-2;
			}else{
				grid[i][j]=100;
			}
		}
	}

//finds all groups
	for(long long i=0;i<R;i++){
		for(long long j=0;j<C;j++){
			if(grid[i][j]==-1&&!visited[i][j]){
				groupFill(i,j,tg);
				tg++;
			}
		}
	}

//sets values to INF
	for(long long i=0;i<maxN;i++){
		for(long long j=0;j<maxN;j++){
			dist[i][j]=INF;
		}
	}


//goes through each group and does bfs from all shallow portions
	for(long long i=0;i<R;i++){
		for(long long j=0;j<C;j++){
			if(!visited2[i][j]&&grid[i][j]>=0&&grid[i][j]<=tg){
				dist[grid[i][j]][grid[i][j]]=0;
				groupCheck(i,j,grid[i][j]);
			}
		}
	}
//FLOYD WARSHALLS
for(int k=0;k<tg;k++){
	for(int i=0;i<tg;i++){
		for(int j=0;j<tg;j++){
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
}

//DO DP
//possible tg problem
	for(long long i=0;i<(1<<tg);i++){
		for(long long j=0;j<tg;j++){
			dp[i][j]=INF;
		}
	}

	for(long long i=0;i<tg;i++){
		dp[(1<<i)][i]=0;
	}

	for(long long i=0;i<(1<<tg);i++){
		for(long long j=0;j<tg;j++){
			if((i&(1<<j))==0) continue;
			if(dp[i][j]==INF) continue;
			for(long long k=0;k<tg;k++) if((i&(1<<k))==0&&dist[j][k]<INF){
				dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+dist[j][k]);
			}
		}
	}
	long long result=INF;
	for(long long i=0;i<tg;i++){
		result=min(result,dp[(1<<tg)-1][i]);
		//cout<<dp[(1<<tg)-1][i]<<'\n';
	}
		cout<<result<<'\n';
    return 0;
}
/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/