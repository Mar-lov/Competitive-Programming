#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int values[500][500];
long long result=0;


int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>values[i][j];
    }
  }
  for(int c=0;c<N;c++){
    //from that column onwards
    int trm[500][500];
    //first till
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        trm[i][j]=1000000000;
      }
    }

    //find mins
    for(int i=c;i<N;i++){
      for(int j=0;j<N;j++){
        trm[j][i]=min(trm[j][(i-1<0?0:i-1)],values[j][i]);
       // cout<<trm[j][i]<<" ";
      }
      //cout<<endl;
    }

    for(int i=0;i<N;i++){
      vector<int> crm(500,1000000000);
      for(int j=i;j<N;j++){
        //cout<<c<<":"<<i<<" to "<<j<<":";
        int val=N;
        bool see100=false;
        int lvnsee=c;
        for(int z=c;z<N;z++){
        crm[z]=min(crm[z],trm[j][z]);
        if(val==N&&crm[z]<100) val=z;
        if(!see100&&crm[z]==100){
          see100=true;
          lvnsee=z-1;
        }
        //cout<<crm[z]<<" ";
        }
        /*
        cout<<endl;
        if(crm[c]>=100&&see100) cout<<"result:"<<(val-c)-(lvnsee-c+1)<<endl;
        */
        if(crm[c]>=100&&see100) result+=(val-c)-(lvnsee-c+1);
      }
    }

  }
  cout<<result<<'\n';
  return 0;
}