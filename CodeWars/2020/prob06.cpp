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

string arr[3][11]={ {"","B","BB","BBB","BW","W","WB","WBB","WBBB","BK",""} , {"","Z","ZZ","ZZZ","ZP","P","PZ","PZZ","PZZZ","ZB",""} , {"","B","BB","BBB","BG","G","GB","GBB","GBBB","BR","R"} };

string convert(int N){
	return arr[2][N/100]+arr[1][(N/10)%10]+arr[0][N%10];
}


int main() {
	int N;
	while(cin>>N){
		cout<<convert(N)<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/