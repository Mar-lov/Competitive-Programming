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
typedef pair<long long,long long> pi;

#define maxV 100005

long long N,K;
vector<long long> arr[maxV];
long long baseS=0;
//current total cows on current recursion
long long tc=0;
//current total sum on current recursion
long long cs=0;

//recusive function
//maxc=max cost
//cc=current cost
//li=last index(dont want to change before last changed index otherwise will get overlap)
//cv=list of index of current value that its on
vector<int> cv=vector<int>(maxV,0);

void check(long long maxc , long long cc , long long li){
    if(cc>maxc) return;
    tc++;
    cs+=cc;
    //recurses onto the next value
    for(long long i=li;i<N;i++){
        if(tc>=K) return;
        if(cv[i]+1<arr[i].size()&&cc+(arr[i][cv[i]+1])<=maxc){
        cv[i]++;
        check(maxc,cc+(arr[i][cv[i]]),i);
        cv[i]--;
        }else if(i!=li&&arr[i].size()!=1){
            return;
        }
    }
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("roboherd.in");
    ofstream cout("roboherd.out");
    //reads in input
    cin>>N>>K;
    for(long long i=0;i<N;i++){
        long long cs;
        cin>>cs;
        for(long long j=0;j<cs;j++){
            long long cv;
            cin>>cv;
            arr[i].push_back(cv);    
        }
        sort(arr[i].begin(),arr[i].end());
        for(int j=arr[i].size()-1;j>0;j--){
            arr[i][j]-=arr[i][j-1];
        }
        baseS+=arr[i].front();
        arr[i][0]=0;
    }
    sort(arr,arr+N);
    //binary search
    long long a=baseS;
    long long b=(long long)1e13;
    while(a<=b){
        long long mid=(a+b)/2;
        tc=0;
        cs=0;
        check( mid , baseS , 0 ); 
        if(tc>=K){
            b=mid-1;
        }else{
            a=mid+1;
        }
    }

    //set iniitals and checks for a-1 values. Then adds on rest
    tc=0;
    cs=0;
    check(a-1,baseS,0);
    cout<<a*(K-tc)+cs<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/