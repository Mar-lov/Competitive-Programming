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

#define maxN 100005
#define INF 1000000000

int N,Q;
int bl[maxN][18];
bool hasB[maxN];
int root;
//tree setup
vector<int> adj[maxN];
int stmin[maxN];
int ordering[maxN];
int layer[maxN];

bool cmp(int a,int b){
	return stmin[a]<stmin[b];
}

void dfs1(int n){
	if(adj[n].size()==0){
		stmin[n]=n;
		return;
	}
	for(int a:adj[n]){
		layer[a]=layer[n]+1;
		dfs1(a);
	}
	sort(adj[n].begin(),adj[n].end(),cmp);
	stmin[n]=min(n,stmin[adj[n][0]]);
}

int cno=0;

void dfs2(int n){
	for(int i=0;i<adj[n].size();i++){
		dfs2(adj[n][i]);
	}
	ordering[cno]=n;
	cno++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>Q;
	int cnp;
	for(int i=0;i<N;i++){
		cin>>cnp;
		cnp--;
		if(cnp==-1){
			root=i;
			bl[i][0]=i;
		}else{
			adj[cnp].push_back(i);
			bl[i][0]=cnp;
		}
		stmin[i]=INF;
		//adj[i].push_back(cnp);
	}
	for(int j=1;j<18;j++){
		for(int i=0;i<N;i++){
			bl[i][j]=bl[bl[i][j-1]][j-1];
		}
	}
	//order-processing
	layer[root]=0;
	dfs1(root);
	dfs2(root);	
	int t,v;
	for(int z=0;z<Q;z++){
		cin>>t>>v;
		if(t==1){
			for(int i=0;i<N;i++){
				if(hasB[ordering[i]]==false){
					hasB[ordering[i]]=true;
					v--;
				}
				if(v==0||i==N-1){
					cout<<ordering[i]+1<<'\n';
					break;
				}
			}
		}else if(t==2){
			int cn=v-1;
			int tl=0;
			for(int j=17;j>=0;j--){
				if(hasB[bl[cn][j]]==true){
					//cout<<"HERE: "<<layer[bl[cn][j]]<<" and "<<layer[cn]<<'\n';
					tl+=layer[cn]-layer[bl[cn][j]];
					cn=bl[cn][j];
				}
			}
				cout<<tl<<'\n';
				hasB[cn]=false; 
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/