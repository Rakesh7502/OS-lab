#include<bits/stdc++.h>
using namespace std;
void firstfit(int blocksize[],int n,int processsize[],int m){
   int allocation[m];
   fill(allocation,allocation+m,-1);

    int copy[n];
    for(int i=0;i<n;i++){
        copy[i]=blocksize[i];
    }
   int external=0;
   int internal=0;
   int ans=0;
   
    //processes
    for(int i=0;i<m;i++){
        int min=INT_MAX;
       int index=0;
        //blocksize
        for(int j=0;j<n;j++){
            if(blocksize[j]>=processsize[i]){
               ans= blocksize[j]-processsize[i];
             
            }
            if(min>ans && blocksize[j]>=processsize[i]){
                min=ans;
                index=j;
            }
        }
        allocation[i]=index;
        blocksize[index]-=processsize[i];
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
    cout<<"total internal fragmentation:"<<internal<<endl;
    cout<<"total external fragmentation:"<<external<<endl;
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