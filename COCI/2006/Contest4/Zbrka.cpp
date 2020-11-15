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
typedef pair<long long,long long> pi;

#define MOD 1000000007

long long M;

long long N, ft[100013];
void update(long long x, long long v) {while(x<=N) ft[x]+=v, x+=(x&-x);}
long long query (long long x) {return (x>0 ? ft[x]+query(x-(x&-x)):0);}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>M>>N;
	N++;
	update(1,1);
	update(2,-1);

	for(long long i=1;i<M;i++){
		for(long long j=N;j>=1;j--){
			long long cn=query(j)%MOD;
			update(j+1,cn);
			update(j+i+1,-cn);
		}
		/*
		for(int j=1;j<=N;j++){
			ft[j]%=MOD;

		}
		*/
	}
	cout<<query(N)%MOD;
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/