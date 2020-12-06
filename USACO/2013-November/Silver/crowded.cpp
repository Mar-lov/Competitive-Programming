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

#define maxN 50005
#define maxB 17

int N,D;
pi arr[maxN];
vector<int> x;
vector<int> h;
int to[maxN][maxB];
int bl[maxN][maxB];
int result=0;

int mv(int a,int b){
    if(a>b) return 0;
    int val=0;
    int ct=b-a+1;
    int ci=a;
    for(int i=maxB-1;i>=0;i--){
        if(ct&(1<<i)){
            val=max(val,bl[ci][i]);
            ci=to[ci][i];
        }
    }
    return val;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("crowded.in");
    ofstream cout("crowded.out");
    cin>>N>>D;
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++){
        x.push_back(arr[i].first);
        h.push_back(arr[i].second);
    }
    for(int i=0;i<N;i++){
        bl[i][0]=h[i];
        to[i][0]=(i+1==N?i:i+1);
    }  
    for(int j=1;j<maxB;j++){
        for(int i=0;i<N;i++){
            bl[i][j]=max(bl[i][j-1],bl[to[i][j-1]][j-1]);
            to[i][j]=to[to[i][j-1]][j-1];
            //cout<<i<<" with "<<pow(2,j)<<" val is "<<bl[i][j]<<'\n';
        }
    }
    for(int i=0;i<N;i++){
        int li=lower_bound(x.begin(),x.end(),x[i]-D)-x.begin();
        int ui=lower_bound(x.begin(),x.end(),x[i]+D)-x.begin();
        int ms=min(mv(li,i-1),mv(i+1,ui));
        if(ms>=h[i]*2) result++;
    }
    cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/