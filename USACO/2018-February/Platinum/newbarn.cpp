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

#define maxV 100005
#define maxB 17

long long Q;
long long cn=1;
//vector<long long> adj[maxV];
long long level[maxV];
long long bl[maxV][maxB];
int a[maxV];
int b[maxV];

long long lca(long long a,long long b){
	if(level[a]<level[b]) swap(a,b);
	long long dl=level[a]-level[b];
	for(long long j=maxB-1;j>=0;j--){
		if((1<<j)&dl) a=bl[a][j];
	}
	if(a==b) return a;
	for(long long j=maxB-1;j>=0;j--){
		if(bl[a][j]!=bl[b][j]){
			a=bl[a][j];
			b=bl[b][j];
		}
	}
	return bl[a][0];
}

long long dist(long long a,long long b){
	return level[a]+level[b]-2*level[lca(a,b)];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("newbarn.in");
	ofstream cout("newbarn.out");
	cin>>Q;
	char ch;
	long long val;
	for(long long i=0;i<Q;i++){
		cin>>ch>>val;
		if(ch=='B'){
			if(val==-1){
				level[cn]=0;
				bl[cn][0]=cn;
				a[cn]=cn;
				b[cn]=cn;
			}else{
				level[cn]=level[val]+1;
				bl[cn][0]=val;
			}

			for(long long j=1;j<maxB;j++){
				bl[cn][j]=bl[bl[cn][j-1]][j-1];
			}
			int pn=bl[cn][maxB-1];
			long long toA=dist(cn,a[pn]);
			long long toB=dist(cn,b[pn]);
			long long cd=dist(a[pn],b[pn]);
			if((toA>cd&&toB<=cd)||(toB>=cd&&toB<=toA)){
				b[pn]=cn;
			}else if((toA<=cd&&toB>cd)||(toA>=cd&&toA<=toB)){
				a[pn]=cn;
			}
			cn++;
		}else if(ch=='Q'){
			int pn=bl[val][maxB-1];
			cout<<max(dist(a[pn],val),dist(b[pn],val))<<'\n';//" "<<a<<" "<<b<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/