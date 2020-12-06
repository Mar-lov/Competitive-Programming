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
typedef pair<double,double> pi;

double N;
vector<double> t;
vector<double> d;
double cs=1;
double ct=0;
double cd=0;
int p1=0;
int p2=0;
int R(double v){
    int td=((int)(v*10))%10;
    if(td<5){
        return (int)(v);
    }
    return (int)ceil(v);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("slowdown.in");
    ofstream cout("slowdown.out");
    cin>>N;
    char c;
    double val;
    for(int i=0;i<N;i++){
        cin>>c>>val;
        if(c=='T'){
            t.push_back(val);
        }else if(c=='D'){
            d.push_back(val);
        }
    }
    sort(t.begin(),t.end());
    sort(d.begin(),d.end());
    while(p1<t.size()&&p2<d.size()){
        //by time
        double nd=(d[p1]-cd)/(1.0/cs);
        double nt=t[p2]-ct;
        if(nt<nd){
            ct=t[p2];
            cd+=(1.0/cs)*nt;
            cs++;
            p2++;
        }else if(nd<nt){
            ct+=nd;
            cd=d[p1];
            cs++;
            p1++;
        }else if(nd==nt){
            ct+=nt;
            cd+=(1.0/cs)*nt;
            cs++;
            p2++;
            ct+=nd;
            cd=d[p1];
            cs++;
            p1++;
        }
    }
    /*
    while(p1<t.size()){
        double nd=(d[p1]-cd)/(1.0/cs);
        ct+=nd;
        cd=d[p1];
        cs++;
        p1++;
    }
    while(p2<d.size()){
        double nt=t[p2]-ct;
        ct+=nt;
        cd+=(1.0/cs)*nt;
        cs++;
        p2++;
    }
    */
    ct+=(1000.0-cd)/(1.0/cs);
    cout<<R(ct)<<'\n';
    return 0;
}

/* stuff you should look for
	* double overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/