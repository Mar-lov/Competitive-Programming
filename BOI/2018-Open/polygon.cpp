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
unordered_map<string,int> toNum;
int p[maxN];
set<int> children[maxN];
bool visited[maxN];
int loner=0;
int result=0;

int dfs(int s){
	int cl=0;
	int cn=s;
	do{
		visited[cn]=true;
		cn=p[cn];
		cl++;
	}while(cn!=s);
	if(cl<3) return -1; 
	return cl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	if(N%2==1){
		cout<<-1<<"\n";
		return 0;
	}
	string a,b;
	int TC=0;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		if(toNum.count(a)==0){
			toNum[a]=TC;
			TC++;
		}
		if(toNum.count(b)==0){
			toNum[b]=TC;
			TC++;
		}
		p[toNum[a]]=toNum[b];
		if(toNum[a]!=toNum[b]) children[toNum[b]].insert(toNum[a]);
	}

	for(int i=0;i<N;i++){
		if(!visited[i]){
			if(i!=p[i]&&i==p[p[i]]){
				visited[i]=true;
				visited[p[i]]=true;
			}
		}
	}

	queue<int> leafs;
	for(int i=0;i<N;i++){
		if(children[i].size()==0){
			leafs.push(i);
		}
	}

	while(!leafs.empty()){
		int cn=leafs.front();
		int cp=p[cn];
		leafs.pop();
		visited[cn]=true;
		if(visited[cp]){
			loner++;
			continue;
		}
		result++;
		visited[cp]=true;
		children[p[cp]].erase(cp);
		if(children[p[cp]].size()==0){
			leafs.push(p[cp]);
		}
	}

	for(int i=0;i<N;i++){
		if(visited[i]==false){
			result+=((dfs(i)+1)/2);
		}
	}

	cout<<result+loner<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/