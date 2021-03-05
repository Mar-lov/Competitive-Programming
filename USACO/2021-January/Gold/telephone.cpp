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

#define maxN 50005
#define maxK 55
#define INF 1000000000

int N,K;
int arr[maxN];
bool willT[maxK][maxK];
vector<int> type[maxN];

int travel(int a,int b){
	return abs(a-b);
}

bool visited[maxN];
int dist[maxN];
priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		arr[i]--;
	}
	char wTv=0;
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			cin>>wTv;
			if(wTv=='1'){
				willT[i][j]=true;
			}else if(wTv=='0'){
				willT[i][j]=false;
			}
		}
	}
	//puts same breed dues together
	for(int i=0;i<N;i++){
		type[arr[i]].push_back(i);
	}

	//setup for dijkstras
	for(int i=0;i<N;i++){
		dist[i]=INF;
		visited[i]=false;
	}
	dist[0]=0;
	pq.push(make_pair(0,0));

	while(!pq.empty()){
		int cd=pq.top().first;
		int cn=pq.top().second;
		pq.pop();
		//cout<<cn<<endl;
		if(visited[cn]) continue;
		visited[cn]=true;
		int breed=arr[cn];
		for(int k=0;k<K;k++){
			if(willT[breed][k]){
				for(int v:type[k]){
					if(dist[cn]+travel(cn,v)<dist[v]&&!visited[v]){
						dist[v]=dist[cn]+travel(cn,v);
						pq.push(make_pair(dist[v],v));
					}
				}
			}
		}
	}

	if(dist[N-1]==INF){
		cout<<-1<<'\n';
	}else{
		cout<<dist[N-1]<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/