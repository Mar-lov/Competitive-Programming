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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxV 100005

int N,B;
pair<int,int> arr[maxV];
int minD[maxV];

int p[maxV];
int s[maxV];

int findP(int n){
	if(p[n]==n) return n;
	int par=findP(p[n]);
	p[n]=par;
	return par;
}

int combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1!=p2&&s[p1]>0&&s[p2]>0){
		if(s[p1]<s[p2]) swap(p1,p2);
		p[p2]=p1;
		s[p1]+=s[p2];
		return s[p1];
	}
	return s[p1];
}

int main() {
	ifstream cin("snowboots.in");
	ofstream cout("snowboots.out");
	cin>>N>>B;
	int cv;
	for(int i=0;i<N;i++){
		cin>>cv;
		arr[i]=make_pair(cv,i);
		p[i]=i;
		s[i]=0;
	}
	sort(arr,arr+N);

	minD[N]=1;
	int cmd=1;
	for(int i=N-1;i>0;i--){
		int ci=arr[i].second;
		s[ci]=1;
		if(ci>0) cmd=max(cmd,combine(ci,ci-1)+1);
		if(ci<N-1) cmd=max(cmd,combine(ci,ci+1)+1);
		minD[i]=min(N-1,cmd);
	}

	int s,d;
	for(int i=0;i<B;i++){
		cin>>s>>d;
		int lo=0;
		int hi=N;
		while(lo<hi){
			int mid=(lo+hi)/2;
			if(arr[mid].first<=s){
				lo=mid+1;
			}else{
				hi=mid;
			}
		}
		//cout<<hi<<" ";
		if(minD[hi]<=d) cout<<1<<'\n';
		else cout<<0<<'\n';
	}

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/