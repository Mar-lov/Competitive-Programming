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
typedef pair< pair<int,int> , int > piii;
typedef pair<piii,piii> State;
#define maxN 20

int N;
char grid[maxN][maxN];
int dp[maxN][maxN][4][maxN][maxN][4];

int X1(State a){return a.first.first.first;}
int Y1(State a){return a.first.first.second;}
int D1(State a){return a.first.second;}
int X2(State a){return a.second.first.first;}
int Y2(State a){return a.second.first.second;}
int D2(State a){return a.second.second;}
 
State createS(int a,int b,int c,int d,int e,int f){
	return  make_pair( make_pair(make_pair(a,b),c),make_pair(make_pair(d,e),f) );
}
State turnLeft(State c){
	return createS(X1(c),Y1(c),(D1(c)+3)%4,X2(c),Y2(c),(D2(c)+3)%4);
}
State turnRight(State c){
	return createS(X1(c),Y1(c),(D1(c)+1)%4,X2(c),Y2(c),(D2(c)+1)%4);
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
State forward(State c){
	int ax=X1(c);
	int ay=Y1(c);
	int ad=D1(c);
	int bx=X2(c);
	int by=Y2(c);
	int bd=D2(c);
	if(ax!=0||ay!=N-1){
	if(ax+dx[ad]>=0&&ax+dx[ad]<N){
		ax+=dx[ad];
	}
	if(ay+dy[ad]>=0&&ay+dy[ad]<N){
		ay+=dy[ad];
	}
	if(grid[ax][ay]=='H'){
		ax=X1(c);
		ay=Y1(c);
	}
	}
	if(bx!=0||by!=N-1){
	if(bx+dx[bd]>=0&&bx+dx[bd]<N){
		bx+=dx[bd];
	}
	if(by+dy[bd]>=0&&by+dy[bd]<N){
		by+=dy[bd];
	}
	if(grid[bx][by]=='H'){
		bx=X2(c);
		by=Y2(c);
	}
	}
	return createS(ax,ay,ad,bx,by,bd);
}

bool reachedEnd(State a){
	return X1(a)==0&&X2(a)==0&&Y1(a)==N-1&&Y2(a)==N-1;
}
int dpVal(State a){
	return dp[X1(a)][Y1(a)][D1(a)][X2(a)][Y2(a)][D2(a)];
}
void setDp(State a,int val){
	dp[X1(a)][Y1(a)][D1(a)][X2(a)][Y2(a)][D2(a)]=val;
}

int main() {
	ifstream cin("cownav.in");
	ofstream cout("cownav.out");
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>grid[i][j];
		}
	}
	dp[N-1][0][0][N-1][0][1]=1;
	queue<State> q;
	q.push(createS(N-1,0,0,N-1,0,1));
	while(!q.empty()){
		State cur=q.front();
		//cout<<X1(cur)<<" "<<Y1(cur)<<" "<<D1(cur)<<'\n';
		q.pop();
		if(reachedEnd(cur)){
			cout<<dpVal(cur)-1<<'\n';
			break;
		}
		State left=turnLeft(cur);
		State right=turnRight(cur);
		State adv=forward(cur);
		if(dpVal(left)==0){
			setDp(left,dpVal(cur)+1);
			q.push(left);
		}
		if(dpVal(right)==0){
			setDp(right,dpVal(cur)+1);
			q.push(right);
		}
		if(dpVal(adv)==0){
			setDp(adv,dpVal(cur)+1);
			q.push(adv);
		}
	}

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/