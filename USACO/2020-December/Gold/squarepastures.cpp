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

#define maxN 205
#define INF 2000000000
int N;
pair<int,int> arr[maxN];
int result=0;
int eql=0;              


void solve(){
    sort(arr,arr+N);
    for(int i=0;i<N;i++){
        set<int> cys;
        //cys.insert(arr[i].second);
        for(int j=i+1;j<N;j++){
            if(i<j-1) cys.insert(arr[j-1].second);
            int len=arr[j].first-arr[i].first;
            int lo=max(arr[i].second,arr[j].second)-len;
            int hi=min(arr[i].second,arr[j].second);
            if(lo>hi) continue;
            vector<int> y(cys.begin(),cys.end());
            int b=0;
            int t=-1;//y.size()-1;
            while(b<y.size()&&y[b]<lo) b++;
            //while(t>0&&y[t]>lo+len) t--;
            while(t+1<y.size()&&y[t+1]-len<=lo) t++; 
            while(1){
                result++;
                int yl=min(arr[i].second,arr[j].second);
                int yu=max(arr[i].second,arr[j].second);
                if(b<=t){
                    yl=min(yl,y[b]);
                    yu=max(yu,y[t]);
                }

                if(yu-yl==len) eql++;
                int removeB=(b<y.size()?y[b]+1:INF);
                int addU=(t+1<y.size()?y[t+1]-len:INF);
                int closest=min(removeB,addU);
                if(closest>hi) break;
                if(removeB==closest) b++;
                if(addU==closest) t++;               
            }
        }
    }
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    result=N+1;

    solve();
    for(int i=0;i<N;i++){
        swap(arr[i].first,arr[i].second);
    }
    solve();
    //cout<<result<<'\n';
    cout<<result-(eql/2)<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/