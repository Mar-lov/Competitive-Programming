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

#define maxN 100005

long long N;
long long arr[maxN];
long long result=0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("poker.in");
    ofstream cout("poker.out");
	cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    long long cv=0;
    for(int i=0;i<N;i++){
        if(arr[i]>cv){
            result+=arr[i]-cv;
            cv=arr[i];
        }else if(arr[i]<=cv){
            cv=arr[i];
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