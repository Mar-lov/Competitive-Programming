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

#define maxN 505

int N;
vector< pair< pair<int,int>, char > > pts;
vector<int> xs;
int maxh=1;
int mina=0;
bool cmpy( pair< pair<int,int>, char> a, pair< pair<int,int>, int> b){
	if(a.first.second==b.first.second){
		if(a.second=='G') return true;
		return false;
	}
	return a.first.second<b.first.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("cowrect.in");
	ofstream cout("cowrect.out");
	cin>>N;
	int px,py;
	char pct;
	for(int i=0;i<N;i++){
		cin>>px>>py>>pct;
		pts.push_back(make_pair( make_pair(px,py) , pct ));
		if(pct=='H'){
			xs.push_back(px);
		}
	}
	sort(xs.begin(),xs.end());
	sort(pts.begin(),pts.end(),cmpy);
	
	for(int i=0;i<xs.size();i++){
		for(int j=i+1;j<xs.size();j++){
			int sy=0;
			int ey=0;
			int cth=0;
			for(int k=0;k<pts.size();k++){
				if(pts[k].first.first>=xs[i]&&pts[k].first.first<=xs[j]&&pts[k].first.second>=sy){
					if(pts[k].second=='H'){
						cth++;
						if(cth==1) sy=pts[k].first.second;
						ey=pts[k].first.second;
						if(cth>maxh){
							maxh=cth;
							mina=(xs[j]-xs[i])*(ey-sy);
							//cout<<xs[i]<<" "<<xs[j]<<" "<<sy<<" "<<ey<<'\n';
						}else if(cth==maxh){
							mina=min((xs[j]-xs[i])*(ey-sy),mina);
						}
					}else{
						sy=pts[k].first.second+1;
						ey=sy;
						cth=0;
					}
				}
			}
		}
	}
	
	cout<<maxh<<'\n';
	cout<<mina<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/