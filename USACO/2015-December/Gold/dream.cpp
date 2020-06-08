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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxV 1000
#define INF 1000000000

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int N,M;
int arr[maxV][maxV];
int dist[maxV][maxV][2];
int main() {
	ifstream cin("dream.in");
	ofstream cout("dream.out");
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>arr[i][j];
			dist[i][j][0]=INF;
			dist[i][j][1]=INF;
		}
	}
	queue< pair< pi , pi > > q;
	q.push(make_pair( make_pair(0,0) , make_pair(0,0) ));
	//start while
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int d=q.front().second.first;
		int smell=q.front().second.second;
		q.pop();
		int type=arr[x][y];
		
		if(d<dist[x][y][smell]&&!(smell==0&&type==3)){		
			dist[x][y][smell]=d;
			for(int j=0;j<4;j++){
				int cx=x+dx[j];
				int cy=y+dy[j];
				//start bound
				if(cx>=0&&cx<N&&cy>=0&&cy<M){
					//start ifs
					if(arr[cx][cy]==0){

					}else if(arr[cx][cy]==1){
						q.push(make_pair( make_pair(cx,cy) , make_pair(d+1,smell) ));
					}else if(arr[cx][cy]==2){
						q.push(make_pair( make_pair(cx,cy) , make_pair(d+1,1) ));
					}else if(arr[cx][cy]==3&&smell==1){
						q.push(make_pair( make_pair(cx,cy) , make_pair(d+1,smell) ));
					}else if(arr[cx][cy]==4){
						//start purple
						int cd=d+1;
						while(cx>=0&&cx<N&&cy>=0&&cy<M&&arr[cx][cy]==4){
							cx+=dx[j];
							cy+=dy[j];
							cd++;
						}
						if(!(cx>=0&&cx<N&&cy>=0&&cy<M)||arr[cx][cy]==0||arr[cx][cy]==3){
						cx-=dx[j];
						cy-=dy[j];
						cd--;
						}
						q.push(make_pair( make_pair(cx,cy) , make_pair(cd,0) ));
						//end purple
					}
					//end ifs
				}
				//endbounds
			}
		}
		//cout<<q.size()<<'\n';
	}
	//end while
	int ans=min(dist[N-1][M-1][0],dist[N-1][M-1][1]);
	if(ans==INF){
		cout<<-1<<'\n';
	}else{
		cout<<ans<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/