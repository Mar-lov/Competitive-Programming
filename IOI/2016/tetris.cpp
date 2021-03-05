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

int type;
int rot=0;
int loc=0;
int state=1;
/*
1: ---
2: *--
3: -*-
4: --*
5: **-
6: -**

   *__
7: **_

   **_
8: **-
*/

int get_position(){
	return loc;
}

int get_rotation(){
	return rot;
}

void new_figure(int figure_type){
	int x=figure_type;
	if(x==1){
		type=1;
		rot=0;
		loc=0;
	}else if(x==2){
		if(state==1){
			rot=0;
			loc=0;
			state=5;
		}else if(state==2){
			rot=0;
			loc=1;
			state=1;
		}else if(state==3){
			rot=3;
			loc=0;
			state=7;
		}else if(state==4){
			rot=0;
			loc=0;
			state=1;
		}else if(state==5){
			rot=3;
			loc=2;
			state=4;
		}else if(state==6){
			rot=3;
			loc=0;
			state=2;
		}else if(state==7){
			rot=0;
			loc=1;
			state=5;
		}else if(state==8){
			rot=3;
			loc=2;
			state=1;
		}
	}else if(x==3){
		if(state==1){
			rot=0;
			loc=0;
			state=7;
		}else if(state==2){
			rot=1;
			loc=1;
			state=4;
		}else if(state==3){
			rot=3;
			loc=0;
			state=8;
		}else if(state==4){
			rot=0;
			loc=0;
			state=2;
		}else if(state==5){
			rot=2;
			loc=1;
			state=6;
		}else if(state==6){
			rot=3;
			loc=0;
			state=5;
		}else if(state==7){
			rot=2;
			loc=1;
			state=1;
		}else if(state==8){
			rot=2;
			loc=1;
			state=3;
		}
	}
}

void init(int n){
	return;
}

