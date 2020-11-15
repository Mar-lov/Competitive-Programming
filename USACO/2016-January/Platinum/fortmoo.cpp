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

#define maxV 205

int N,M;
char graph[maxV][maxV];
int psum[maxV][maxV];
int ans=-100;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("fortmoo.in");
    ofstream cout("fortmoo.out");
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            psum[j][i]=psum[j][i-1]+(graph[i][j]=='X'?1:0);
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            int ms=0;
            bool on=false;
            for(int k=1;k<=M;k++){
                if(psum[k][j]-psum[k][i-1]==0){
                    ms+=(j-i+1);
                    ans=max(ans,ms);
                    on=true;
                }else if(graph[i][k]=='.'&&graph[j][k]=='.'&&on==true){
                    ms+=(j-i+1);
                }else{
                    ms=0;
                    on=false;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/