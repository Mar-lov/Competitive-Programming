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




int main() {
	int k;
	cin>>k;
	while(k!=0){
		int arr[k];
		for(int i=0;i<k;i++){
			cin>>arr[i];
		}
		for(int n1=0;n1<k-5;n1++){
			for(int n2=n1+1;n2<k-4;n2++){
				for(int n3=n2+1;n3<k-3;n3++){
					for(int n4=n3+1;n4<k-2;n4++){
						for(int n5=n4+1;n5<k-1;n5++){
							for(int n6=n5+1;n6<k;n6++){
								cout<<arr[n1]<<" "<<arr[n2]<<" "<<arr[n3]<<" "<<arr[n4]<<" "<<arr[n5]<<" "<<arr[n6]<<'\n';
							}
						}
					}
				}
			}
		}
		cin>>k;
		if(k!=0) cout<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/