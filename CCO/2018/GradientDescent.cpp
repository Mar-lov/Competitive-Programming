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
//typedef long long ll;
typedef pair<int,int> ii;

#define INF 2100000000

int R,C,K;
int result=INF;

unordered_map< int , int > seen;

int query(int x,int y){
	int qick=x*C+y;
	if(seen.count(qick)>0) return seen[qick];
	cout<<"?"<<" "<<x<<" "<<y<<endl;
	K--;
	int ret;
	cin>>ret;
	seen[qick]=ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>R>>C>>K;
	int ra=1;
	int rb=R;
	int ca=1;
	int cb=C;
	while((ra<rb||ca<cb)){
		int midr=(ra+rb)/2;
		int midc=(ca+cb)/2;

		int ll=INF,ul=INF,lr=INF;

		if(K<2) break;
		ll=query(midr,midc);

		if(ra<rb){
		if(K<2) break;
		ul=query(midr+1,midc);
		if(ll<=ul){
			rb=midr;
		}else if(ul<ll){
			ra=midr+1;
		}
		}

		if(ca<cb){
		if(K<2) break;
		lr=query(midr,midc+1);
		if(ll<=lr){
			cb=midc;
		}else if(lr<ll){
			ca=midc+1;
		}
		}
		result=min(min(result,ll),min(lr,ul));
	}
	//cout<<ra<<" "<<ca<<endl;
	result=min(result,query(ra,ca));
	cout<<"!"<<" "<<result<<endl;
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/