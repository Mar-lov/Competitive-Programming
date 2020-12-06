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

#define INF 1000000000

long long N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	long long x;
	for(long long i=0;i<N;i++){
		cin>>x;
		double ms=INF;
		for(long long i=0;i<sqrt((double)x);i++){
			double ps=x-pow((double)i,2);
			if(pow(floor(sqrt(ps)),2)==ps){
				ms=min(ms,sqrt(ps)+i);
			}
		}
		if(ms==INF){
			cout<<-1<<'\n';
		}else{
			cout<<ms<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/