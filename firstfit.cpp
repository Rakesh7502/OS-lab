#include<bits/stdc++.h>
using namespace std;
void firstfit(int blocksize[],int n,int processsize[],int m){
    int external=0,internal=0;
    int copy[n];
    for(int i=0;i<n;i++){
        copy[i]=blocksize[i];
    }
   int allocation[m];
   fill(allocation,allocation+m,-1);
    //processes
    for(int i=0;i<m;i++){
        //blocksize
        for(int j=0;j<n;j++){
            if(blocksize[j]>=processsize[i]){
                allocation[i]=j;
                blocksize[j]-=processsize[i];
               // internal+=blocksize[j];
                //blocksize[j]=-1;
                break;
            }
        }
    }
    //internal and external framentation
    for(int i=0;i<n;i++){
        if(blocksize[i]==copy[i])
        external+=blocksize[i];
        else{
            internal+=blocksize[i];
        }
    }

    
    cout<<"\nProcess No.\tProcess size\tBlock no.\n";
    for(int i=0;i<m;i++){
        cout<<i+1<<"\t\t"<<processsize[i]<<"\t\t";
        if(allocation[i]!=-1)
        cout<<allocation[i]+1;
        else{
       
            cout<<"Not allocated"; 
        }
        cout<<endl;
    }

    cout<<"external framentation: "<<external<<endl;
    cout<<"internal framentation: "<<internal<<endl;
}

int main(){
    // int n,m;
    // cout<<"enter no.of blocks"<<endl;
    // cin>>n;
    // int blocksize[n];
    // cout<<"enter sizes of block"<<endl;
    // for(int i=0;i<n;i++){
    //     int x=0;
    //     cin>>x;
    //    blocksize[i]=x;;
    // }
    // cout<<"enter no.of proceses:"<<endl;
    // cin>>m;
    // int processsize[m];
    // cout<<"enter processsizes"<<endl;
    // for(int i=0;i<m;i++){
    //     int x=0;
    //     cin>>x;
    //    processsize[i]=x;
    // }
    int blocksize[]={100,500,200,300,600};
    int processsize[]={212,417,112,426};
    int n=sizeof(blocksize)/sizeof(blocksize[0]);
    int m=sizeof(processsize)/sizeof(processsize[0]);
    firstfit(blocksize,n,processsize,m);

    return 0;
    

}