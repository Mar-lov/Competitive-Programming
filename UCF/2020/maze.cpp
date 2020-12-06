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


int T;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("maze.in");
	cin>>T;
	for(int z=0;z<T;z++){
		int N,M;
		cin>>N>>M;
		char arr[N+2][M+2];
		bool visited[N+2][M+2];
		queue< pi > q;

		for(int i=0;i<=N+1;i++){
			for(int j=0;j<=M+1;j++){
				visited[i][j]=false;
				if((i==0||j==0||i==N+1||j==M+1)){
					//arr[i][j]='G';
					visited[i][j]=true;
					continue;
				}
				cin>>arr[i][j];
				if(arr[i][j]=='*'){
					q.push(make_pair(i,j));
					arr[i][j]='9';
					visited[i][j]=true;
				}else if(arr[i][j]=='G'){
					visited[i][j]=true;
					for(int k=0;k<4;k++){
						visited[i+dx[k]][j+dy[k]]=true;
					}
				}
			}
		}

		bool found=false;
		while(!q.empty()){
			int cx=q.front().first;
			int cy=q.front().second;
			q.pop();
			//cout<<"start"<<cx<<","<<cy<<'\n';
			if((cx==1||cy==1||cx==N||cy==M)&&arr[cx][cy]=='1'){
				found=true;
				break;
			}
			for(int i=0;i<4;i++){
				int nx=cx+dx[i];
				int ny=cy+dy[i];
				//cout<<nx<<" "<<ny<<'\n';
				if(arr[nx][ny]=='E'){
					for(int j=0;j<4;j++){
						int fx=nx+dx[j];
						int fy=ny+dy[j];
						if(!visited[fx][fy]){
							visited[fx][fy]=true;
							q.push(make_pair(fx,fy));
						}
					}
				}else if(arr[nx][ny]=='F'){
					for(int j=0;j<4;j++){
						int fx=nx+dx[j];
						int fy=ny+dy[j];
						if(!visited[fx][fy]&&(arr[cx][cy]-arr[fx][fy])>0){
							visited[fx][fy]=true;
							q.push(make_pair(fx,fy));
						}
					}
				}else if(arr[nx][ny]=='P'){
					for(int j=0;j<4;j++){
						int fx=nx+dx[j];
						int fy=ny+dy[j];
						if(!visited[fx][fy]&&(arr[fx][fy]-arr[cx][cy])>0){
							visited[fx][fy]=true;
							q.push(make_pair(fx,fy));
						}
					}
				}else{
					if(!visited[nx][ny]&&abs(arr[nx][ny]-arr[cx][cy])<=1){
							visited[nx][ny]=true;
							q.push(make_pair(nx,ny));
					}
				}
			}
		}
		if(found==true){
			cout<<"You've got this!"<<'\n';
		}else{
			cout<<"Find another way"<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/