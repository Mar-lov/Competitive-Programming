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
#define maxB 1000005
#define INF 1000000000

struct val{
	int ts;
	//vector<int> len;
	//vector<int> wx;
	val(){
		ts=0;
		//len=vector<int> (0);
		//wx=vector<int> (0);
	}
};

int X,Y;
int N;
vector< ii > nr[maxB];
//first value is current y
//switching map to set an arr
//map<int,val> arr;
set<int> arr;
val mat[2000001];

vector<int> ny;
vector<val> nv;

/*
void answer(int ey,val ev){
	cout<<ev.ts+X<<'\n';
	vector< ii > travel;
	for(int i=0;i<(int)ev.len.size()-1;i++){
		travel.push_back(make_pair(abs(ev.wx[i+1]-ev.wx[i]),0));
		if(ev.len[i]!=0) travel.push_back(make_pair(0,ev.len[i]));
	}
	cout<<travel.size()<<'\n';
	for(int i=0;i<(int)travel.size();i++){
		cout<<travel[i].first<< " "<<travel[i].second<<'\n';
	}
}*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>X>>Y;
	Y+=1000000;
	cin>>N;
	int x1,y1,x2,y2;
	for(int i=0;i<N;i++){
		cin>>x1>>y1>>x2>>y2;
		y1+=1000000;
		y2+=1000000;
		nr[x1].push_back(make_pair(y1,y2));
	}	

	arr.insert(1000000);
	mat[1000000]=val();

	for(int i=0;i<X;i++){
		//first look at all rectangles and add their corners
		ny.clear();
		nv.clear();
		//cout<<i<<":";
		for(int j=0;j<(int)nr[i+1].size();j++){
			int ly=nr[i+1][j].first; ly--;
			int uy=nr[i+1][j].second; uy++;
			//for lower
			if(arr.count(ly)==0){
				set<int>::iterator below= arr.lower_bound(ly);
				if(below!=arr.begin()) below--;
				set<int>::iterator above=arr.upper_bound(ly);
				int cb=mat[*below].ts+abs(ly-*below);
				int ca;
				if(above==arr.end()) ca=INF;
				else ca=(mat[*above]).ts+abs((*above)-ly);
				if(cb<=ca){
					ny.push_back(ly);
					val nyv=(mat[*below]);
					nyv.ts+=abs(ly-(*below));
					//nyv.len.push_back(-1*abs(ly-(*below)));
					//nyv.wx.push_back(i+1);
					nv.push_back(nyv);
				}else{
					ny.push_back(ly);
					val nyv=(mat[*above]);
					nyv.ts+=abs(ly-(*above));
					//nyv.len.push_back(abs((*above)-ly));
					//nyv.wx.push_back(i+1);
					nv.push_back(nyv);
				}
			}

			//for upper
			if(arr.count(uy)==0){
				set<int>::iterator below= arr.lower_bound(uy);
				if(below!=arr.begin()) below--;
				set<int>::iterator above=arr.upper_bound(uy);
				int cb=(mat[*below]).ts+abs(uy-(*below));
				int ca;
				if(above==arr.end()) ca=INF;
				else ca=(mat[*above]).ts+abs((*above)-uy);
				if(cb<=ca){
					ny.push_back(uy);
					val nyv=(mat[*below]);
					nyv.ts+=abs(uy-(*below));
					//nyv.len.push_back(-1*abs(uy-((*below))));
					//nyv.wx.push_back(i+1);
					nv.push_back(nyv);
				}else{
					ny.push_back(uy);
					val nyv=(mat[*above]);
					nyv.ts+=abs(uy-(*above));
					//nyv.len.push_back(abs((*above)-uy));
					//nyv.wx.push_back(i+1);
					nv.push_back(nyv);
				}
			}
		}
		
		//now remove bad values
		for(int j=0;j<(int)nr[i+1].size();j++){
			int ly=nr[i+1][j].first;
			int uy=nr[i+1][j].second;
			set<int>::iterator lb=arr.lower_bound(ly);
			set<int>::iterator up=arr.upper_bound(uy);
			if(lb!=up&&up!=arr.begin()){
				//up--;
				//cout<<i<<" is removing from "<<ly<<":"<<(lb->first)<<" to "<<uy<<":"<<((up)->first)<<'\n';
				arr.erase(lb,up);
			}
		}
		//add new valuyes
		for(int j=0;j<(int)ny.size();j++){
			//cout<<ny[j]<<" ";
			arr.insert(ny[j]);
			mat[ny[j]]=nv[j];
		}
		//cout<<'\n';
		//if(i==50000) return 0;
		//cout<<i<<": "<<arr.size()<<'\n';
	}
	//know find answer
	
	int ay=Y;
	val av=val();
	av.ts=INF;
	if(arr.count(Y)==1){ 
		av=mat[Y];
		//av.wx.push_back(Y);
		//av.len.push_back(0);
	}
		set<int>::iterator lv=arr.lower_bound(Y);
		if(lv!=arr.begin()) lv--;
		set<int>::iterator uv=arr.lower_bound(Y);
		int lc=(mat[*lv]).ts+abs((*lv)-Y);
		int uc=(mat[*uv]).ts+abs((*uv)-Y);
		if(lc<av.ts){
			ay=*lv;
			av=mat[*lv];
			av.ts+=abs((*lv)-Y);
			//av.wx.push_back(X);
			//av.len.push_back(-1*abs((*lv)-Y));
		}
		if(uc<av.ts){
			ay=*uv;
			av=mat[*uv];
			av.ts+=abs((*uv)-Y);
			//av.wx.push_back(X);
			//av.len.push_back(abs((*uv)-Y));
		}
	
	cout<<av.ts+X<<'\n';
	//answer(ay,av);
	
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/