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

#define maxN 100001
#define INF 2000000000

int N,D;
int A[2*maxN];
int B[2*maxN];
int dist[2*maxN];
queue<int> q;

struct cmpA
{
	bool operator()(int a,int b) const
	{
		return B[a]<B[b];
	}
};
 
struct cmpB
{
	bool operator()(int a,int b) const
	{
		return A[a]<A[b];
	}
};
 
multiset<int,cmpA> sA;
multiset<int,cmpB> sB;

int main() {
	ifstream cin("piepie.in");
	ofstream cout("piepie.out");
	cin>>N>>D;
	for(int i=0;i<2*N;i++){
		cin>>A[i]>>B[i];
		A[i]=-A[i];
		B[i]=-B[i];
		dist[i]=-1;
	}	
	for(int i=0;i<N;i++){
		if(B[i]==0){
			q.push(i);
			dist[i]=1;
		}else{
			sA.insert(i);
		}
		if(A[i+N]==0){
			q.push(i+N);
			dist[i+N]=1;
		}else{
			sB.insert(i+N);
		}
	}

	while(!q.empty()){
		int ci=q.front();q.pop();
		if(ci<N){
			multiset<int,cmpB>::iterator itB=sB.lower_bound(ci);
			while(itB!=sB.end()&&A[*itB]<=D+A[ci]){
				dist[*itB]=dist[ci]+1;
				q.push(*itB);
				sB.erase(itB);
				itB=sB.lower_bound(ci);
			}
		}else{
			multiset<int,cmpA>::iterator itA=sA.lower_bound(ci);
			while(itA!=sA.end()&&B[*itA]<=D+B[ci]){
				dist[*itA]=dist[ci]+1;
				q.push(*itA);
				sA.erase(itA);
				itA=sA.lower_bound(ci);
			}
		}
		//cout<<sA.size()<<" "<<sB.size()<<'\n';
	}
	for(int i=0;i<N;i++){
		cout<<dist[i]<<'\n';
	}

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/