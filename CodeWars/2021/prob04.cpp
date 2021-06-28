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

#define maxN 100

int N;
string input[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	cin.ignore();
	for(int i=0;i<N;i++){
		getline(cin,input[i]);
	}
	reverse(input,input+N);
	for(int i=0;i<N;i++){
		cout<<input[i]<<endl;
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