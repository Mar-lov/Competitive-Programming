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

#define maxN 1005
#define maxN2 1000005
#define INF 1000000000
int N;
int arr[maxN][maxN];
bool visited[maxN2];
int numVis=0;
int miny[maxN2];
int maxy[maxN2];
int minx[maxN2];
int maxx[maxN2];
bool works[maxN2];
int result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("art.in");
	ofstream cout("art.out");
	cin>>N;
	fill(miny,miny+maxN2,INF);
	fill(minx,minx+maxN2,INF);
	fill(maxy,maxy+maxN2,-1);
	fill(maxx,maxx+maxN2,-1);
	fill(visited,visited+maxN2,false);
	fill(works,works+maxN2,true);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			if(visited[arr[i][j]]==false) numVis++;
			visited[arr[i][j]]=true;
			miny[arr[i][j]]=min(miny[arr[i][j]],j);
			minx[arr[i][j]]=min(minx[arr[i][j]],i);
			maxy[arr[i][j]]=max(maxy[arr[i][j]],j);
			maxx[arr[i][j]]=max(maxx[arr[i][j]],i);
		}
	}

	for(int i=1;i<=N*N;i++){
		if(!visited[i]) continue;
		for(int a=minx[i];a<=maxx[i];a++){
			for(int b=miny[i];b<=maxy[i];b++){
				if(arr[a][b]!=i) works[arr[a][b]]=false;
			}
		}
	}

	for(int i=1;i<=N*N;i++){
		if(works[i]) result++;
	}
		cout<<result+(numVis>2?0:-1)<<"\n";
	
	return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/