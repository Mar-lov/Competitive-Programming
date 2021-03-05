#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int N;
map<string,int> toVal;
int ci=1;
map<string,int> name;
map<int,int> type;
int distToBessie[100005];

int main() {

  //Sets map for all values
  toVal["Ox"]=0;
  toVal["Tiger"]=1;
  toVal["Rabbit"]=2;
  toVal["Dragon"]=3;
  toVal["Snake"]=4;
  toVal["Horse"]=5;
  toVal["Goat"]=6;
  toVal["Monkey"]=7;
  toVal["Rooster"]=8;
  toVal["Dog"]=9;
  toVal["Pig"]=10;
  toVal["Rat"]=11;
  
  cin>>N;
  name["Bessie"]=0;
  distToBessie[0]=0;

  string intputStr[8];
  for(int i=0;i<N;i++){
    //read in input string
    for(int j=0;j<8;j++){
      cin>>intputStr[j];
    }

    name[intputStr[0]]=ci;
    type[ci]=toVal[intputStr[4]]; 
    int cp=name[intputStr[7]];
    //if statements check for previous vs next
    //then inside the if statements set the current cows location to bessie.
    if(intputStr[3]=="next"){
        if(type[ci]==type[cp]){
          //if same type of cow and next then 12 years ahead
          distToBessie[ci]=(12)+distToBessie[cp];
        }else if(type[ci]>type[cp]){
          //if a greater type and next then just add type difference
          distToBessie[ci]=(type[ci]-type[cp])+distToBessie[cp];
        }else if(type[ci]<type[cp]){
          //if a lesser type and next then 12-type difference
          distToBessie[ci]=(12-(type[cp]-type[ci]))+distToBessie[cp];
        }
    }else if(intputStr[3]=="previous"){
        if(type[ci]==type[cp]){
          distToBessie[ci]=-(12)+distToBessie[cp];
        }else if(type[ci]>type[cp]){
          distToBessie[ci]=-(12-(type[ci]-type[cp]))+distToBessie[cp];
        }else if(type[ci]<type[cp]){
          distToBessie[ci]=-(type[cp]-type[ci])+distToBessie[cp];
        }
    }
    //cout<<distToBessie[ci]<<'\n';
    ci++;
  }
  cout<<abs(distToBessie[name["Elsie"]])<<'\n';
  return 0;
}