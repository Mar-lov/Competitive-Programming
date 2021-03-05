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

#define maxN 200005
#define INF 1000000000

vector<int> adj[maxN];
int maxC=0;
int has1child;
vector<int> order;
bool visitedS[maxN];
bool visitedE[maxN];

void bfsS(int n,int lb){
	queue<int> q;
	q.push(n);
	fill(visitedS,visitedS+maxN,false);
	while(!q.empty()){
		int cn=q.front();
		q.pop();
		if(cn<lb) continue;
		visitedS[cn]=true;
		for(int a:adj[cn])if(!visitedS[a]){
			q.push(a);
		}
	}
}
void bfsE(int n,int ub){
	queue<int> q;
	q.push(n);
	fill(visitedE,visitedE+maxN,false);
	while(!q.empty()){
		int cn=q.front();
		q.pop();
		if(cn>ub) continue;
		visitedE[cn]=true;
		for(int a:adj[cn])if(!visitedE[a]){
			q.push(a);
		}
	}
}

int treemax[4*maxN];
int treemin[4*maxN];
void buildmin(int index,int L,int R){
	if(L==R){
		treemin[index]=order[L];
		return;
	}
	buildmin(2*index,L,(L+R)/2);
	buildmin(2*index+1,((L+R)/2)+1,R);
	treemin[index]=min(treemin[2*index],treemin[2*index+1]);
}
void buildmax(int index,int L,int R){
	if(L==R){
		treemax[index]=order[L];
		return;
	}
	buildmax(2*index,L,(L+R)/2);
	buildmax(2*index+1,((L+R)/2)+1,R);
	treemax[index]=max(treemax[2*index],treemax[2*index+1]);
}
int querymin(int index,int qL,int qR,int L,int R){
		if(R<qL||qR<L) return INF;
		if(qL<=L&&R<=qR) return treemin[index];
		return min(querymin(2*index,qL,qR,L,(L+R)/2),querymin(2*index+1,qL,qR,((L+R)/2)+1,R));
}
int querymax(int index,int qL,int qR,int L,int R){
		if(R<qL||qR<L) return -1;
		if(qL<=L&&R<=qR) return treemax[index];
		return max(querymax(2*index,qL,qR,L,(L+R)/2),querymax(2*index+1,qL,qR,((L+R)/2)+1,R));
}

int loc[maxN];
int ci=0;
void dfs(int n,int p){
	order.push_back(n);
	loc[n]=ci;
	ci++;
	for(int a:adj[n]) if(a!=p){
		dfs(a,n);
	}
}

vector<int> check_validity(int N, vector<int> X, vector<int> Y, vector<int> S, vector<int> E, vector<int> L, vector<int> R){
	int M=X.size();
	int Q=S.size();
	vector<int> result;
	for(int i=0;i<M;i++){
		int u=X[i];
		int v=Y[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
		maxC=max(maxC,(int)max(adj[v].size(),adj[u].size()));
		if(adj[u].size()==1) has1child=u;
		if(adj[v].size()==1) has1child=v;
	}
	if(M==N-1&&maxC<=2){
		dfs(has1child,has1child);
		buildmin(1,0,N-1);
		buildmax(1,0,N-1);
		for(int i=0;i<Q;i++){
			//to left
			int si=loc[S[i]];
			int ei=loc[E[i]];
			if(si<=ei){
				int sa=si,se=ei;
				while(sa<se){
					int mid=(sa+se+1)/2;
					if(querymin(1,si,mid,0,N-1)>=L[i]){
						sa=mid;
					}else{
						se=mid-1;
					}
				}
				int ea=si,ee=ei;
				while(ea<ee){
					int mid=(ea+ee)/2;
					if(querymax(1,mid,ei,0,N-1)<=R[i]){
						ee=mid;
					}else{
						ea=mid+1;
					}
				}
				if(ea<=sa) result.push_back(1);
				else result.push_back(0);
			}else{
				int sa=si,se=ei;
				while(sa<se){
					int mid=(sa+se)/2;
					if(querymin(1,mid,si,0,N-1)>=L[i]){
						se=mid;
					}else{
						sa=mid+1;
					}
				}
				int ea=si,ee=ei;
				while(ea<ee){
					int mid=(ea+ee+1)/2;
					if(querymax(1,ei,mid,0,N-1)<=R[i]){
						ea=mid;
					}else{
						ee=mid-1;
					}
				}
				if(sa<=ea) result.push_back(1);
				else result.push_back(0);
			}
		}
	}else{
			for(int i=0;i<Q;i++){
				bfsS(S[i],L[i]);
				bfsE(E[i],R[i]);
				bool possible=false;
				for(int j=L[i];j<=R[i];j++){
					if(visitedS[j]&&visitedE[j]) possible=true;
				}
				if(possible) result.push_back(1);
				else result.push_back(0);
			}
	}

	return result;
}
/*
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> ans=check_validity(6,{5,1,1,3,3,5},{1,2,3,4,0,2},{4,4,5},{2,2,4},{1,2,3},{2,2,4});
	for(int a:ans) cout<<a<<" ";
    return 0;
}
*/

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/