#include<bits/stdc++.h>
using namespace std;
//7
//50
//82 170 43 140 24 16 190
//314 right highest:200
int main(){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    vector<int>req;
    cout<<"enter queue elements"<<endl;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        req.push_back(x);
    }
    int head;
    cout<<"enter head position"<<endl;
    cin>>head;
    cout<<"enter highest value"<<endl;
    int track;
    cin>>track;
    cout<<"enter right or left"<<endl;
    string side;
    cin>>side;

    vector<int>v;
    v.push_back(head);
    if(side.length()==5){         //right
        sort(req.begin(),req.end());
        for(int i=0;i<n;i++){
            if(req[i]>head)
            v.push_back(req[i]);
        }
        reverse(req.begin(),req.end());
        for(int i=0;i<req.size();i++){
            if(req[i]<head)
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
    else{    //left
        sort(req.begin(),req.end(),greater<int>());
        for(int i=0;i<n;i++){
            if(req[i]<head)
            v.push_back(req[i]);
        }
        reverse(req.begin(),req.end());
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