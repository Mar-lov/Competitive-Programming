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

#define maxN 1000000

int len;
char arr[maxN];
ll result=0;
int goTo[maxN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>len;
	for(int i=0;i<len;i++){
		cin>>arr[i];
	}

	goTo[0] = 0;
	int j=0;
	for(int i=1;i<len;i++){
		    j = goTo[i-1];
		    while (true) {
                	if (arr[i] == arr[j]) {
                	    goTo[i] = j+1;
                	    break;
                	}
                	if (j == 0) {
                	    goTo[i] = 0;
                	    break;
                	}
                	j = goTo[j-1];
		    }
	}
	int cm=0;
	for(int i=len-1;i>=0;i--){
		if(i<cm) cm=0;
		int cv=goTo[i];
		int ci=i;
		while(goTo[ci]!=0){
			cv=max(cv,i+1-goTo[ci]);
			ci=goTo[ci];
		}
		cm=max(cm,cv);
		if(cm==0||cm>i) continue;
		//cout<<i<<" "<<cm<<'\n';
		cout<<i<<" "<<cm<<'\n';
		result+=cm;
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/