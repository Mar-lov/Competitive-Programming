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
typedef pair<long long,long long> pi;

#define maxN 3000000

long long N,K;
long long stall[maxN];
bool filled[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("empty.in");
	ofstream cout("empty.out");
	cin>>N>>K;
	long long X,Y,A,B;
	for(long long i=0;i<K;i++){
		cin>>X>>Y>>A>>B;
		for(long long j=1;j<=Y;j++){
			stall[(A*j+B)%N]+=X;
		}
	}
	long long ct=0;
	for(long long i=0;i<N;i++){
		ct+=stall[i];
		if(ct>0&&!filled[i]){
			filled[i]=true;
			ct--;
		}
	}
	long long ci=0;
	while(ct>0){
		if(ct>0&&!filled[ci]){
			filled[ci]=true;
			ct--;
		}
		ci++;
	}
	for(long long i=0;i<N;i++){
		if(!filled[i]){
			cout<<i<<'\n';
			return 0;
		}
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/