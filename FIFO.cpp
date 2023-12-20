#include<bits/stdc++.h>
using namespace std;

void print(vector<int>f)
{
    for(int i=0;i<f.size();i++)
    {
        cout<<f[i]<<" ";
    }
    cout<<endl;
}
int main()
{
 int l,n,x;
 cout<<"length of the reference string: ";
 cin>>l;
 vector<int>v;
 for(int i=0;i<l;i++)
 {
    cin>>x;
    v.push_back(x);   
 }
 cout<<"No of frmames: ";
 cin>>n;
 vector<int>f(n,-1);
 int c=0;
 int j=0;
 for(int i=0;i<l;i++)
 {
   auto it=find(f.begin(),f.end(),v[i]);
   if(it!=f.end())
   {
      c++;     
     print(f);
   }
   else
   {
      f[j]=v[i];
      j=(j+1)%n;
      print(f);
   }
 }
 cout<<endl;
 cout<<"No of hits: "<<c<<endl;
 cout<<"Page faults: "<<v.size()-c<<endl;

}
