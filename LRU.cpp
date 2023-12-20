#include<bits/stdc++.h>
using namespace std;
void print(vector<int>m)
{
  for(int i=0;i<m.size();i++)
  {
    cout<<m[i]<<" ";
  }
  cout<<endl;

}
int check(vector<int>v,vector<int>m,int ind,int f)
{
   vector<int>a(f,-1);
   for(int i=0;i<ind;i++)
   {
      for(int k=0;k<f;k++)
      {
         if(v[i]==m[k])
         {
            a[k]=i;
         }
      }
   }
   int min=*min_element(a.begin(),a.end());
   for(int i=0;i<f;i++)
   {
    if(a[i]==min)
    return i;
   }
   
}
int main()
{
  int n,x,f,j=0,c=0;
  cout<<"enter n"<<endl;
  cin>>n;
  vector<int>v;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    v.push_back(x);
  }
  cout<<"enter the number of frames"<<endl;
  cin>>f;
  vector<int>m(f,-1);
  int page_fault=0;
  for(int i=0;i<n;i++)
  { 
    if((*min_element(m.begin(),m.end()))==-1)
    {
      auto it=find(m.begin(),m.end(),v[i]);
      if(it==m.end())
      {
          m[j]=v[i];
          j++;
          page_fault++;
      }
    }
     else
    {
      auto it=find(m.begin(),m.end(),v[i]);
      if(it==m.end())
      {
        page_fault++;
        int k=i;
        cout<<v[i]<<endl;
        int ind=check(v,m,i,f);
        m[ind]=v[k];
      }
      else
      cout<<v[i]<<endl;
    }
    print(m);
     
  }
  cout<<"Page faults"<<endl;
  cout<<page_fault<<endl;
   
  }