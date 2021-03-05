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
typedef pair<long long,long long> ii;
 
#define maxN 1000005
#define INF 1000000000
 
long long N;
bool visited[maxN];
vector<int> child;
long long root;
long long cg=-1;
long long td[maxN];
long long mr[maxN];
vector<vector<ll> > grps;
 
void dfs(long long n){
	if(visited[n]) return;
	visited[n]=true;
	grps.back().push_back(n);
	td[cg]+=abs(n-child[n]);
	long long tr=n-root;
	if(abs(tr)<abs(mr[cg])) mr[cg]=tr;
	dfs(child[n]);
}
 
int minimum_walk(vector<int> p, int s){
	N=p.size();
	child=p;
	root=s;
	fill(visited,visited+maxN,false);
	fill(mr,mr+maxN,INF);
	cg=-1;
	grps.clear();
	fill(td,td+maxN,0);
	//if(p==vector<int> {3,2,1,0}) return 8;
	for(long long i=0;i<N;i++){
		if(!visited[i]){
			cg++;
			grps.push_back(vector<ll>());
			dfs(i);
		}
	}
	long long result=0;
	long long reach=0;
	long long ld=0;
	long long rd=0;
	for(long long i=0;i<=cg;i++){
		if(grps[i].size()==1) continue;
		result+=td[i];
		reach+=mr[i];
		//if(mr[i]<0) ld=min(ld,mr[i]);
		//if(mr[i]>=0) rd=max(rd,mr[i]);
	}
	return result+2*reach;
}
/*
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<minimum_walk({0,2,3,1},0);
	//cout<<minimum_walk({0,1,2,3,4,6,5},0);
	vector<int> v = {0,1,2,3};
	do{
		cout<<minimum_walk(v,0)<<": ";
		for(int a:v) cout<<a<<" ";
		cout<<'\n';
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}
*/

 
/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/