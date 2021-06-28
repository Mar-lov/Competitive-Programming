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

long long N;
long long arr[maxN];
vector<long long> breed[maxN];
long long pv[maxN];
long long result=0;

long long ft[maxN];
void update(long long x, long long v) {while(x<=N) ft[x]+=v, x+=(x&-x);}
long long query (long long x) {return (x>0 ? ft[x]+query(x-(x&-x)):0);}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string cre;
	getline(cin,cre);
	string rs="";
	for(int i=0;i<cre.length();i++){
		if(cre[i]!=rs.back()) rs+=cre[i];
	}
	for(int i=0;i<rs.length();i++){
		arr[i+1]=rs[i]-'a';
	}
	//cout<<rs<<endl;
	N=rs.length();
	for(long long i=1;i<=N;i++){
		//cout<<arr[i]<<endl;
		if(breed[arr[i]].size()>0){
			pv[i]=breed[arr[i]].back();
		}
		breed[arr[i]].push_back(i);
	}
	for(long long i=1;i<=N;i++){
		if(pv[i]!=0) update(pv[i],-1);
		int add=query(i)-(pv[i]==0?0:query(pv[i]));
		result+=(add>0?add:0);
		update(i,1);		
	}
	cout<<result<<'\n';
    return 0;
}


/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/