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

#define maxN 100005
#define maxK 200005
#define maxB 17

int N,K;
long long M;
ii swapTo[maxK];
int goTo[maxN];
unordered_set<int> result[maxN];


int tg=0;
bool grpVisited[maxN];
vector<int> grp[maxN];
void dfs(int n){
	if(grpVisited[n]) return;
	grpVisited[n]=true;
	grp[tg-1].push_back(n);
	dfs(goTo[n]);
}

int bl[maxN][maxB];
unordered_set<int> bls[maxN][maxB];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K>>M;
	for(int i=0;i<K;i++){
		cin>>swapTo[i].first>>swapTo[i].second;
		swapTo[i].first--;
		swapTo[i].second--;
	}
	//run through once
	int qloc[maxN];
	for(int i=0;i<N;i++){
		qloc[i]=i;
		bls[i][0].insert(i);
	}
	for(int i=0;i<K;i++){
		bls[qloc[swapTo[i].first]][0].insert(swapTo[i].second);
		bls[qloc[swapTo[i].second]][0].insert(qloc[swapTo[i].first]);
		swap(qloc[swapTo[i].first],qloc[swapTo[i].second]);
	}
	for(int i=0;i<N;i++){
		goTo[qloc[i]]=i;
		bl[i][0]=goTo[i];
	}
	//figure out groups
	for(int i=0;i<N;i++){
		if(!grpVisited[i]){
			tg++;
			dfs(i);
		}
	}
	//quick check
	/*
	for(int i=0;i<tg;i++){
		for(int u:grp[i]) cout<<u<<" ";
		cout<<endl;
	}
	*/

	//setup binary lifiting
	/*
	for(int i=0;i<N;i++){
		cout<<i<<" ";
		for(int a:bls[i][0]) cout<<a<<" ";
		cout<<endl;
	}
	*/
	for(int j=1;j<maxB;j++){
		for(int i=0;i<N;i++){
			bl[i][j]=bl[bl[i][j-1]][j];
			bls[i][j]=bls[i][j-1];
			bls[i][j].insert(bls[bl[i][j-1]][j-1].begin(),bls[bl[i][j-1]][j-1].begin());
		}
	}
	
	//result finder
	int trn=M/K;
	for(int i=0;i<N;i++){
		int tv=i;
		for(int j=0;j<maxB;j++){
			if(trn&(1<<j)){
				if(result[i].size()==0){
					//result[i].insert(bls[tv][j].begin(),bls[tv][j].end());
					result[i]=bls[tv][j];
				}else{
					result[i].insert(bls[tv][j].begin(),bls[tv][j].end());
				}
				tv=bl[tv][j];
			} 
		}
		qloc[tv]=i;
	}

	
	for(int i=0;i<(M-K*trn);i++){
		result[qloc[swapTo[i].first]].insert(swapTo[i].second);
		result[qloc[swapTo[i].second]].insert(qloc[swapTo[i].first]);
		swap(qloc[swapTo[i].first],qloc[swapTo[i].second]);
	}

	for(int i=0;i<N;i++){
		cout<<result[i].size()<<'\n';
	}

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/