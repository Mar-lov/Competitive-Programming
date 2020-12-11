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

#define maxV 100005
#define maxQ 5005
#define maxB 17
int N,M,Q;
int shuf[maxV];
int query[maxQ];
int bl[maxV][maxB];
int loc[maxV];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("shuffle.in");
	ofstream cout("shuffle.out");
	cin>>N>>M>>Q;
	for(int i=1;i<=M;i++){
		cin>>shuf[i];
	}
	for(int i=0;i<Q;i++){
		cin>>query[i];
	}
	for(int i=1;i<=N;i++){
		if(i<=M){
			bl[i][0]=shuf[i]-1;
		}else{
			bl[i][0]=i-1;
		}
	}
	bl[0][0]=0;
	for(int j=1;j<maxB;j++){
		for(int i=0;i<=N;i++){
			bl[i][j]=bl[bl[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=N;i++){
		int ci=i;
		int turns=0;
		for(int j=maxB-1;j>=0;j--){
			if(bl[ci][j]!=0){
				ci=bl[ci][j];
				turns+=pow(2,j);
			}
		}
		//cout<<i<<endl;
		turns++;
		//cout<<i<<" has "<<turns<<endl;
		if(turns>(N-M)){
			ci=i;
			for(int j=0;j<maxB;j++){
				if((N-M+1)&(1<<j)){
					ci=bl[ci][j];
				}
			}
			loc[(N-M+1)+ci]=i;
		}else{
			loc[turns]=i;
		}
		//cout<<i<<" got "<<loc[i]<<" with "<<turns<<'\n';
	}
	for(int i=0;i<Q;i++){
		cout<<loc[N+1-query[i]]<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/