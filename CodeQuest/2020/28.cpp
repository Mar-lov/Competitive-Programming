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
typedef pair<int,int> ii;
double R(double n){ return round(n); }

struct state{
	int tx,ty;
	int mx,my;
};

int dx[5]={0,0,-1,1,0};
int dy[5]={-1,1,0,0,0};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	for(int z=0;z<T;z++){
		int X,Y;
		cin>>Y>>X;
		cin.ignore();
		string grid[X];
		for(int i=0;i<X;i++){
			getline(cin,grid[i]);
		}
		int sMX,sMY;
		int sTX,sTY;
		int EX,EY;
		bool visited[X][Y][X][Y];
		for(int i=0;i<X;i++){
			for(int j=0;j<Y;j++){
				for(int w=0;w<X;w++){
					for(int y=0;y<Y;y++){
						visited[i][j][w][y]=false;
					}
				}
				if(grid[i][j]=='T'){
					sTX=i;
					sTY=j;
				}else if(grid[i][j]=='M'){
					sMX=i;
					sMY=j;
				}else if(grid[i][j]=='E'){
					EX=i;
					EY=j;
				}
			}
		}

		queue< pair<int,state> > q;
		state st;
		st.tx=sTX;
		st.ty=sTY;
		st.mx=sMX;
		st.my=sMY;
		q.push(make_pair(0,st));
		while(!q.empty()){
			int steps=q.front().first;
			state cur=q.front().second;
			q.pop();
			int tx=cur.tx;
			int ty=cur.ty;
			int mx=cur.mx;
			int my=cur.my;
			if(visited[tx][ty][mx][my]) continue;
			visited[tx][ty][mx][my]=true;
			if(tx==EX&&ty==EY){
				cout<<steps<<endl;
				//cout<<tx<<" "<<ty<<" and "<<mx<<" "<<my<<endl;
				break;
			}
			for(int nc=0;nc<5;nc++){
					int nx=tx+dx[nc];
					int ny=ty+dy[nc];
					if(nx<0||nx>=X||ny<0||ny>=Y||grid[nx][ny]=='X') continue;
					vector< pair<double,int> > vec;
					for(int k=0;k<5;k++){
							int nmx=mx+dx[k];
							int nmy=my+dy[k];
							if(nmx<0||nmx>=X||nmy<0||nmy>=Y||grid[nmx][nmy]=='X') continue;
							vec.push_back( make_pair(sqrt(pow(nx-nmx,2)+pow(ny-nmy,2)) ,k ) );
					}
					sort(vec.begin(),vec.end());
					state ns;
					ns.mx=mx+dx[vec[0].second];
					ns.my=my+dy[vec[0].second];
					ns.tx=nx;
					ns.ty=ny;
					if(ns.mx==ns.tx&&ns.my==ns.ty) continue;
					q.push(make_pair(steps+1,ns));
				}
			
		}
	}
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/