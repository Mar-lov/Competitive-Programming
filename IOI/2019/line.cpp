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
typedef pair<int,int> pi;

#define maxN 100005

int N;
set< pi > xs;
set< pi > ys;
vector< pi > ans;

pi rev(pi a){ return make_pair(a.second,a.first); }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	int cx,cy;
	for(int i=0;i<N;i++){
		cin>>cx>>cy;
		xs.insert(make_pair(cx,cy));
		ys.insert(make_pair(cy,cx));
	}
	ans.push_back(make_pair(0,0));
	int ci=0;
	bool set=false;
	pi lastn;
	while(xs.size()>0&&ys.size()>0){
		if(ci%4==0){
			pi nx=(*xs.rbegin());
			ans.push_back(make_pair(nx.first,ans.back().second));
			if(set||rev(nx)!=*ys.rbegin()){
				ys.erase(rev(nx));
				set=false;
			}else{
				set=true;
			}
			lastn=nx;
			xs.erase(nx);
		}else if(ci%4==1){
			pi ny=(*ys.rbegin());
			ans.push_back(make_pair(ans.back().first,ny.first));
			if(set||rev(ny)!=*xs.begin()){
				xs.erase(rev(ny));
				set=false;
			}else{
				set=true;
			}
			lastn=rev(ny);
			ys.erase(ny);
		}else if(ci%4==2){
			pi nx=(*xs.begin());
			ans.push_back(make_pair(nx.first,ans.back().second));
			if(set||rev(nx)!=*ys.begin()){
				ys.erase(rev(nx));
				set=false;
			}else{
				set=true;
			}
			lastn=nx;
			xs.erase(nx);
		}else if(ci%4==3){
			pi ny=(*ys.begin());
			ans.push_back(make_pair(ans.back().first,ny.first));
			if(set||rev(ny)!=*xs.rbegin()){
				xs.erase(rev(ny));
				set=false;
			}else{
				set=true;
			}
			lastn=rev(ny);
			ys.erase(ny);
		}
		ci++;
	}
	ans.push_back(lastn);
	cout<<ans.size()-1<<'\n';
	for(int i=1;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/