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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int tY,N;
vector< pair<int,string> > arr;

int main() {
	cin>>tY>>N;
	string name;
	int cost;
	for(int i=0;i<N;i++){
		cin>>name>>cost;
		arr.push_back(make_pair(cost,name));
	}
	sort(arr.begin(),arr.end());
	int itemb=0;
	for(int i=0;i<N;i++){
		if(tY>=arr[i].first){
			tY-=arr[i].first;
			cout<<"I can afford "<<arr[i].second<<'\n';
			itemb++;
		}else{
			cout<<"I can't afford "<<arr[i].second<<'\n';
		}
	}
	if(itemb==0) cout<<"I need more Yen!"<<'\n';
	cout<<tY<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/