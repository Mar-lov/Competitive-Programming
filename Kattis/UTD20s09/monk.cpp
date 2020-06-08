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

#define maxV 5002

int a,d;

double th=0;
vector<double> ascs;
vector<double> dess;
double ch1=0,ch2=0;
int main() {
	cin>>a>>d;
	int h,t;
	for(int i=0;i<a;i++){
		cin>>h>>t;
		for(int j=0;j<t;j++){
			ascs.push_back((double)h/(double)t);
		}
		th+=h;
	}
	for(int i=0;i<d;i++){
		cin>>h>>t;
		for(int j=0;j<t;j++){
			dess.push_back((double)h/(double)t);
		}
	}
	ch2=th;
	int ci=0;
	cout<<fixed<<'\n';
	while(ch1+ascs[ci]<(ch2-dess[ci])){
		ch1+=ascs[ci];
		ch2-=dess[ci];
		 ci++;
	}
	cout<<ci<<'\n';
	//if(ch1+ascs[ci]==th-(ch2+dess[ci])){
	//	cout<<setprecision(5)<<ci<<'\n';
	//}else{
		cout<<ch1<<" "<<ch2<<" "<<ascs[ci]<<" "<<dess[ci]<<" "<<(th-ch1-ch2-dess[ci])/(ascs[ci]-dess[ci])<<" "<<(th-ch1-ch2-dess[ci])<<" / "<<(ascs[ci]-dess[ci])<<'\n';
		cout<<setprecision(5)<<(double)ci+(1-((ch1-ch2-dess[ci])/(-1*dess[ci]-ascs[ci])))<<'\n';
	//}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/