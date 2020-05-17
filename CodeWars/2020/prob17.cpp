/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
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
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int N;
vector<string> arr;
unordered_map<string, vector<string> > adj;

int main() {
	cin>>N;
	string cur;
	for(int i=0;i<N;i++){
		cin>>cur;
		arr.push_back(cur);
	}
	string l;
	cin.ignore();
	while(getline(cin,l)){
		stringstream ss(l);
		string word[9];
		for(int i=0;i<9;i++){
			ss>>word[i];
		}
		string c1=word[1];
		string c2=word[6];
		string ct=word[8];
		if(ct!="air"){
			adj[c1].push_back(c2);
			adj[c2].push_back(c1);
		}
	}
	for(int i=0;i<N;i++){
		if(adj[arr[i]].size()==0){
			cout<<"City "<<arr[i]<<" is remote and has no neighbours!"<<'\n';
		}else{
			cout<<"City "<<arr[i]<<" is neighbour to Cities ";
			
			//bfs
			queue<string> q;
			unordered_set<string> visited;
			vector<string> ans;
			q.push(arr[i]);
			visited.insert(arr[i]);
			while(!q.empty()){
				string cur=q.front();q.pop();
				for(int i=0;i<adj[cur].size();i++){
					if(visited.count(adj[cur][i])==0){
						q.push(adj[cur][i]);
						visited.insert(adj[cur][i]);
						ans.push_back(adj[cur][i]);
					}
				}
			}
			//end bfs
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<(i<ans.size()-1?",":"\n");
			}

		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/