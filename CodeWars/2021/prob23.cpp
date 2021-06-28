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

int N;
vector<int> arr;
int maxV=0;
void output(int s,int c){
	int nv=(s+1)/2;
	for(int i=-nv;i<=nv;i++){
		for(int z=0;z<c-s;z++){
			cout<<" ";
		}
		for(int z=0;z<abs(i);z++){
			cout<<" ";
		}
		if(nv==abs(i)){
			for(int z=0;z<s;z++){
				cout<<"#";
			}
			cout<<endl;
		}else{
			cout<<"#";
			for(int z=0;z<s+2*(nv-abs(i)-1);z++){
				cout<<" ";
			}
			cout<<"#";
			cout<<endl;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	int val;
	for(int i=0;i<N;i++){
		cin>>val;
		arr.push_back(val);
		maxV=max(maxV,val);
	}
	for(int i=0;i<N;i++){
		output(arr[i],maxV);
	}
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/