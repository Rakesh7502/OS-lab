#include<bits/stdc++.h>
using namespace std;
//7
//50
//82 170 43 140 24 16 190
//right 200 ans:391
int main(){
    int  n;
    cout<<"enter size"<<endl;
    cin>>n;
    vector<int>req;
    cout<<"enter track or queue elements"<<endl;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        req.push_back(x);
    }
    cout<<"enter head position"<<endl;
    int head;
    cin>>head;
    cout<<"enter highest point"<<endl;
    int track;
    cin>>track;
    cout<<"enter side left or right"<<endl;
    string side;
    cin>>side;

    vector<int>v;
    v.push_back(head);

    if(side.length()==5){
      sort(req.begin(),req.end());
      for(int i=0;i<n;i++){
        if(req[i]>head)
        v.push_back(req[i]);
      }
      v.push_back(track-1);
      v.push_back(0);
      //reverse(req.begin(),req.end());
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
    else{
     sort(req.begin(),req.end());
     reverse(req.begin(),req.end());
     for(int i=0;i<req.size();i++){
      if(req[i]<head)
      v.push_back(req[i]);
     }
     v.push_back(0);
     v.push_back(track-1);
     //reverse(req.begin(),req.end());
     for(int i=0;i<req.size();i++){
      if(req[i]>head)
      v.push_back(req[i]);
     }
     cout<<"Sequence:";
     for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
     }
     int sum=0;
     for(int i=0;i<v.size()-1;i++){
      sum=sum+abs(v[i]-v[i+1]);
     }
     cout<<"\nTotal heads:"<<sum;
    }

    
}