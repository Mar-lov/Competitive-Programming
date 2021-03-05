#include "rail.h"
using namespace std;
void findLocation(int N, int first, int location[], int stype[]){
	//location=vector<int>(N,0);
	//stype=vector<int>(N,2);
	for(int i=0;i<N;i++){
		location[i]=first+getDistance(0,i);
		stype[i]=2;
	}	
	stype[0]=1;
	return;
}