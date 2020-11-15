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

#define maxN 20

int N,L;
int len[maxN];
vector<int> show[maxN];
pair<int,int> dp[(1<<maxN)];
int result=100;
int main() {
	ifstream cin("movie.in");
	ofstream cout("movie.out");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>L;
	int st;
	for(int i=0;i<N;i++){
		cin>>len[i]>>st;
		int cst;
		for(int j=0;j<st;j++){
			cin>>cst;
			show[i].push_back(cst);
		}
	}	
	for(int i=0;i<(1<<maxN);i++){
		dp[i].first=-1;
		dp[i].second=-1;
	}
	for(int i=0;i<N;i++){
		if(show[i].front()==0){
			dp[(1<<i)].second=len[i];
			dp[(1<<i)].first=0;
		}
	}

	for(int i=1;i<(1<<N);i++){
		if(dp[i].first==-1||dp[i].second==-1) continue;
		int tc=0;
		for(int j=0;j<N;j++){
			if(i&(1<<j)) tc++;
		}
		if(dp[i].second>=L){
			result=min(result,tc);
		}
		for(int j=0;j<N;j++){
			if(i&(1<<j)) continue;
			int cl=(upper_bound(show[j].begin(),show[j].end(),dp[i].second)-show[j].begin())-1;
			//remove second >=?? also maybe if len is same chose one with most length essentially
			if(cl>=0&&show[j][cl]<=dp[i].second&&show[j][cl]>=dp[i].first&&dp[i|(1<<j)].second<show[j][cl]+len[j]){
				dp[i|(1<<j)].first=show[j][cl];
				dp[i|(1<<j)].second=show[j][cl]+len[j];
			}
		}

	}
	if(result==100){
		cout<<-1<<'\n';
	}else{
		cout<<result<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/