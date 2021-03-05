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
typedef pair<long long,long long> ii;

#define maxN 100005

struct pts{
	long long x,y;
	long long index;
};

struct seg{
	pts l;
	pts r;
};


long long N;
seg arr[maxN];
vector<pts> vals;
long long ti[maxN];
int p1=maxN,p2=maxN;

bool ccw(pts A,pts B,pts C){
    return (C.y-A.y) * (B.x-A.x) > (B.y-A.y) * (C.x-A.x);
}
bool intersect(long long i1,long long i2){
	//cout<<i1<<" "<<i2<<'\n';
	pts A=arr[i1].l;
	pts B=arr[i1].r;
	pts C=arr[i2].l;
	pts D=arr[i2].r;
	return ccw(A,C,D) != ccw(B,C,D) && ccw(A,B,C) != ccw(A,B,D);
}

bool cmp(pts a,pts b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("cowjump.in");
	ofstream cout("cowjump.out");
	cin>>N;
	pts a,b;
	for(long long i=0;i<N;i++){
		cin>>a.x>>a.y>>b.x>>b.y;
		a.index=i;
		b.index=i;
		if(a.x>b.x) swap(a,b);
		arr[i].l=a;
		arr[i].r=b;
		vals.push_back(a);
		vals.push_back(b);
	}

	sort(vals.begin(),vals.end(),cmp);
	set< ii > cnt;
	for(int i=0;i<2*N;i++){
		int li=vals[i].index;
		set< ii >::iterator loc=cnt.find(make_pair(arr[li].l.y,li));
		if(loc!=cnt.end()){
			set< ii >::iterator before=loc;
			set<ii>::iterator after=loc;
			if(after!=cnt.end()) after++;
			if(before!=cnt.begin()&&after!=cnt.end()){
				before--;
				if( intersect( (*before).second,(*after).second ) ){
					p1=(*before).second; p2=(*after).second;
					break;
				}
			}
			cnt.erase(loc);
		}else{
			cnt.insert(make_pair(arr[li].l.y,li));
			loc=cnt.find(make_pair(arr[li].l.y,li));
			set< ii >::iterator before=loc;
			set<ii>::iterator after=loc; 
			if(after!=cnt.end()) after++;
			if(before!=cnt.begin()){
				before--;
				if( intersect( (*before).second,(*loc).second ) ){
					p1=(*before).second; p2=(*loc).second;
					break;
				}
			}
			if(after!=cnt.end()){
				if( intersect( (*loc).second,(*after).second ) ){
					p1=(*loc).second; p2=(*after).second;
					break;
				}
			}
		}
	}
	if(p1>p2) swap(p1,p2);
	int ni1=0;
	int ni2=0;
	for(int i=0;i<N;i++){
		if(intersect(p1,i)) ni1++;
		if(intersect(p2,i)) ni2++;
	}
	if(ni1>=ni2) cout<<p1+1<<'\n';
	else cout<<p2+1<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/