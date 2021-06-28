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

#define INF 1000000000


struct loc{
	int cx,cy;
	int vx,vy;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	for(int z=0;z<T;z++){
		int X,Y;
		cin>>Y>>X;
		cin.ignore();
		string grid[Y];
		string cur;
		for(int i=0;i<Y;i++){
			getline(cin,grid[i]);
		}

		bool dist[Y][X][7][7];
		int startX,startY;

		for(int i=0;i<Y;i++){
			for(int j=0;j<X;j++){
				for(int w=0;w<7;w++){
					for(int y=0;y<7;y++){
						dist[i][j][w][y]=false;
					}
				}
				
				if(grid[i][j]=='C'){
					startX=j;
					startY=i;
				}
			}
		}

		//priority_queue< pair<int,loc> , vector< pair<int,loc> > , greater< pair<int,loc> > > pq;
		queue< pair<int,loc> > pq;
			loc curl;
			curl.cx=startX;
			curl.cy=startY;
			curl.vx=0;
			curl.vy=0;
			pq.push(make_pair(0,curl));


		while(!pq.empty()){
			//int steps=pq.top().first;
			int steps=pq.front().first;
			//loc c=pq.top().second;
			loc c=pq.front().second;
			pq.pop();
			int cx=c.cx;
			int cy=c.cy;
			int vx=c.vx;
			int vy=c.vy;
			//cout<<cx<<" "<<cy<<endl;
			if(dist[cy][cx][vx+3][vy+3]){
				continue;
			}
			if(grid[cy][cx]=='$'){
				cout<<steps+1<<endl;
				break;
			}
			dist[cy][cx][vx+3][vy+3]=true;
			for(int dy=-1;dy<=1;dy++){
				for(int dx=-1;dx<=1;dx++){
					if(abs(vx+dx)<=3&&abs(vy+dy)<=3){
					int nx=cx+vx+dx;
					int ny=cy+vy+dy;
					if(nx>=0&&nx<X&&ny>=0&&ny<Y&&grid[ny][nx]!='#'){
						loc cur;
						cur.cx=nx;
						cur.cy=ny;
						cur.vx=vx+dx;
						cur.vy=vy+dy;
						pq.push(make_pair(steps+1,cur));
					}
					}
				}
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