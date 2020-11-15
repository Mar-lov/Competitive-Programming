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

//I usually just define global arrays because they are easier to access. Also this is commonly done by advanced programmers

#define maxN 105 // 100+ a little extra 

int N;
//moveTo to index array
int moveTo[maxN];
//2d array
int arr[maxN][4];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("shuffle.in");
    ofstream cout("shuffle.out");
    
    cin>>N;
    int cur;
    //swap the direction of swapping
    for(int i=0;i<N;i++){
        cin>>cur;
        cur--;
        moveTo[cur]=i;
    }

    for(int i=0;i<N;i++){
        cin>>arr[i][0];
    }
    //nested loops to do transistions!!!
    for(int j=0;j<3;j++){
        for(int i=0;i<N;i++){
            arr[moveTo[i]][j+1]=arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        cout<<arr[i][3]<<"\n";
    }
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/