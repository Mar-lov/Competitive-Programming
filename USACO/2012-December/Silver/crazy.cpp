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

#define maxN 1005

struct Segment{
	int x1,y1,x2,y2;
	Segment(){}
	Segment(int a,int b,int c,int d){
		x1=a;
		y1=b;
		x2=c;
		y2=d;
	}
};

bool areConnected(Segment a,Segment b){
	if(a.x1==b.x1&&a.y1==b.y1) return true;
	if(a.x1==b.x2&&a.y1==b.y2) return true;
	if(a.x2==b.x1&&a.y2==b.y1) return true;
	if(a.x2==b.x2&&a.y2==b.y2) return true;
	return false;
}

int p[maxN];
int r[maxN];
int findP(int n){
	if(n==p[n])return n;
	int fp=findP(p[n]);
	p[n]=fp;
	return fp;
}

void combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1!=p2){
		if(r[p1]<r[p2]) swap(p1,p2);
		p[p2]=p1;
		r[p1]=max(r[p1],r[p2]+1);
	}
}
//doesnt incclue x1 x2
double intersect(int x,int y,Segment a){
	if(y<a.y2&&y>=a.y1){
		if(a.x1==a.x2) return a.x1-x;
		double m=(a.y2-a.y1)/(a.x2-a.x1);
		if(m==0) return a.x1-x;
		double ix=((double)(y-a.y1)/m)+a.x1;
		return ix-x;
	}
	return -1;
}

int N,C;
Segment segs[maxN];
vector< vector<Segment> > groups;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("crazy.in");
	ofstream cout("crazy.out");
	cin>>N>>C;
	for(int i=0;i<N;i++){
		p[i]=i;
		r[i]=0;
	}
	for(int i=0;i<N;i++){
		cin>>segs[i].x1>>segs[i].y1>>segs[i].x2>>segs[i].y2;
		if(segs[i].y1>segs[i].y2){
			swap(segs[i].y1,segs[i].y2);
			swap(segs[i].x1,segs[i].x2);
		}else if(segs[i].y1==segs[i].y2&&segs[i].x1<segs[i].x2){
			swap(segs[i].x1,segs[i].x2);
		}
		for(int j=0;j<i;j++){
			if(areConnected(segs[i],segs[j])){
				combine(i,j);
			}
		}
	}
	int tsg=-1;
	map<int,int> hasseen;
	for(int i=0;i<N;i++){
		if(hasseen.count(findP(i))){
			groups[hasseen[findP(i)]].push_back(segs[i]);
		}else{
			hasseen[findP(i)]=++tsg;
			groups.push_back(vector<Segment>());
			groups[tsg].push_back(segs[i]);
		}
	}
	vector<int> result(tsg+1,0);
	int x,y;
	for(int i=0;i<C;i++){
		cin>>x>>y;
		int cw=tsg;
		double ctm=100000000;
		for(int j=0;j<groups.size();j++){
			int ti=0;
			double cgm=100000000;
			for(int k=0;k<groups[j].size();k++){
				double cd=intersect(x,y,groups[j][k]);
				if(cd>0){
					ti++;
					cgm=min(cd,cd);
				}
			}
			if(cgm<ctm&&ti==1){
				ctm=cgm;
				cw=i;
			}
		}
		result[cw]++;
	}	
	int mx=0;
	for(int i=0;i<result.size();i++){
		mx=max(mx,result[i]);
	}
	cout<<mx<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/