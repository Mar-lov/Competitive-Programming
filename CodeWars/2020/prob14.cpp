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

bool doable(int n){
	int os=0;
	int es=0;
	int i=1;
	while(n>0){
		if(i%2==0){
			es+=n%10;
		}else{
			os+=n%10;
		}
		n/=10;
		i++;
	}
	return os==es;
}


int main() {
	int X,Y;
	cin>>X>>Y;
	int found=0;
	for(int i=X+1;i<Y;i++){
		if(doable(i)){
			 cout<<i<<" ";
			found++;
		}
	}
	if(found==0) cout<<"No Numbers found with Equal Sum in the given range!!"<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/