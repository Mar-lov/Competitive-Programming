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

#define maxN 100005

int N;
int input[maxN];
int elsie[maxN];
int bessie[maxN];
set<int> E;
set<int> B;
int dph[maxN];
int dpl[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//ifstream cin("cardgame.in");
	//ofstream cout("cardgame.out");
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>input[i];
		E.insert(input[i]);
	}
	for(int i=1;i<=2*N;i++){
		if(E.find(i)==E.end()){
			B.insert(i);
		}
	}
	int ci=1;
	for(int a:E){
		elsie[ci]=a;
		ci++;
	}
	ci=1;
	for(int a:B){
		bessie[ci]=a;
		ci++;
	}
//for larger
	ci=1;
	for(int i=1;i<=N;i++){
		while(ci<=N&&elsie[i]>bessie[ci]){
			ci++;
		}
		if(ci>N) break;
		dph[N]++;
		ci++;
	}
	set<int> e1=E;
	for(int i=N-1;i>=0;i--){
		int ei=i+1;
		e1.erase(e1.find(elsie[ei]));
		
	}
//for smaller
	ci=N;
	for(int i=N;i>=1;i--){
		while(ci>=1&&bessie[ci]>elsie[i]){
			ci--;
		}
		if(ci<1) break;
		dpl[N]++;
		ci--;
	}
	for(int i=N-1;i>=0;i--){

	}
	cout<<dpl[N]<<" "<<dph[N]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/