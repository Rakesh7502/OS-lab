#include<bits/stdc++.h>
using namespace std;
//7
//50
//82 170 43 140 24 16 190
//track side right 200
//ans 334 if right most 200 else 332 track-1
int main(){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    vector<int>req;
    cout<<"enter queue"<<endl;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x>=0)
        req.push_back(x);
    }
    cout<<"enter head position"<<endl;
    int head;
    cin>>head;
    cout<<"enter highest value"<<endl;
    int track;
    cin>>track;
    cout<<"enter right or left"<<endl;
    string side;
    cin>>side;
    string str="right";   
    vector<int>v;
    v.push_back(head);//head inserting into sequence
     
     //right
    if(str.compare(side)==0){  
       sort(req.begin(),req.end());
       for(int i=0;i<req.size();i++){
        if(req[i]>head)
        v.push_back(req[i]);
       }
        
        v.push_back(track-1);
        reverse(req.begin(),req.end());
        for(int i=0;i<req.size();i++){
        if(req[i]<head)
        v.push_back(req[i]);
        }
        cout<<"sequence:";
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        int sum=0;
        for(int i=0;i<v.size()-1;i++){
            sum=sum+abs(v[i]-v[i+1]);
        }
        cout<<"\nTotal Heads:"<<sum;
    }
     //left
    else{    
       sort(req.begin(),req.end());
       reverse(req.begin(),req.end());
       for(int i=0;i<req.size();i++){
        if(req[i]<head)
        v.push_back(req[i]);
       }
       v.push_back(0);
       for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
       reverse(req.begin(),req.end());
       for(int i=0;i<req.size();i++){
        if(req[i]>head)
        v.push_back(req[i]);
       }
       cout<<"sequence:";
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        int summ=0;
        for(int i=0;i<v.size()-1;i++){
            summ=summ+abs(v[i]-v[i+1]);
        }
        cout<<"\nTotal Heads:"<<summ;
    }
    
}