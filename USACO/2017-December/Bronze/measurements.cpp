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

#define maxD 101

int N;
//B=0 E=1 M=2
int change[maxD][3];
int score[3]={7,7,7};
bool winners[3]={true,true,true};
int result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("measurement.in");
	ofstream cout("measurement.out");
	cin>>N;
	int day;
	string name;
	int delta;
	for(int i=0;i<N;i++){
		cin>>day>>name>>delta;
		if(name=="Bessie"){
			change[day][0]+=delta;
		}else if(name=="Elsie"){
			change[day][1]+=delta;
		}else if(name=="Mildred"){
			change[day][2]+=delta;
		}
	}

	for(int d=1;d<101;d++){
		score[0]+=change[d][0];
		score[1]+=change[d][1];
		score[2]+=change[d][2];
		bool today[3];
		fill(today,today+3,false);
		int maxScore=max(score[0],max(score[1],score[2]));
		for(int j=0;j<3;j++){
			if(score[j]==maxScore) today[j]=true;
		}
		bool notEqual=false;
		for(int j=0;j<3;j++){
			if(winners[j]!=today[j]){
				notEqual=true;
			}
		}
		if(notEqual) result++;
		for(int j=0;j<3;j++){
			winners[j]=today[j];
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/