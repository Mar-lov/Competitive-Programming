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

#define maxN 1005
#define maxM 505
int N,M,K;
int adj[maxN][2];
int dir[maxM];
int bl[maxN][30];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("cruise.in");
	ofstream cout("cruise.out");
	cin>>N>>M>>K;

	for(int i=0;i<N;i++){
		cin>>adj[i][0]>>adj[i][1];
		adj[i][0]--;
		adj[i][1]--;
		bl[i][0]=i;
	}
	char cc;
	for(int i=0;i<M;i++){
		cin>>cc;
		if(cc=='L') dir[i]=0;
		else dir[i]=1;

		for(int j=0;j<N;j++){
			bl[j][0]=adj[bl[j][0]][dir[i]];
		}
	}
	for(int i=1;i<30;i++){
		for(int j=0;j<N;j++){
			bl[j][i]=bl[bl[j][i-1]][i-1];
		}
	}
	int result=0;
	for(int i=0;i<30;i++){
		if(K&(1<<i)){
			result=bl[result][i];
		}
	}
	cout<<result+1<<'\n';


    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/