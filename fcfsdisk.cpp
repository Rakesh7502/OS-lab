//7
//50
//82 170 43 140 24 16 190
//208
#include<bits/stdc++.h>
using namespace std;
int main()//fcfs
{
   int n;
   cout<<"enter queue size"<<endl;
   cin>>n;
   vector<int>v(n);
   cout<<"enter address how they arrived"<<endl;
   for(int i=0;i<n;i++)
   {
    cin>>v[i];
   }
   int headpos;
   cout<<"enter head position "<<endl;
   cin>>headpos;
   int total=0;
   total=total+(abs(headpos-v[0]));
   cout<<headpos<<" - "<<v[0]<<endl;
   for(int i=0;i<n;i++)
   {
    if(i==n-1) break;
    else
    {
       cout<<v[i]<<" - "<<v[i+1]<<endl;
       total=total+(abs(v[i]-v[i+1]));
    }
   }
   cout<<"total head movements"<<endl;
   cout<<total;
}