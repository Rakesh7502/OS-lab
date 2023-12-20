#include<bits/stdc++.h> 
using namespace std; 

void BankingAlgo(){
          
    int m,n;
   cout<<"Enter number of Procesess and number of Resorcsess: ";
   cin>>m>>n;
   int alloc[m][n];
   int max[m][n];
   cout<<"Enter your Allocated Procesess: ";
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
            cin>>alloc[i][j];
   }
   cout<<"Enter your Max Procesess: ";
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++) 
           cin>>max[i][j];
   }
   int need[m][n];
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++)
             need[i][j]=max[i][j]-alloc[i][j];
      }
   
   vector<int>aval(n),work(n);
   cout<<"Enter Available Resorcess: ";
   for(int i=0;i<n;i++)cin>>aval[i];
   work=aval;
   vector<bool>bul(m,false);
   vector<int>ans;
   cout<<"Allocation Matrix: "<<endl;
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
          cout<<alloc[i][j]<<" ";
       cout<<endl;
   }
    cout<<"Max Matrix: "<<endl;
   
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
          cout<<max[i][j]<<" ";
       cout<<endl;
   }
    cout<<"Need Matrix: "<<endl;
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
          cout<<need[i][j]<<" ";
       cout<<endl;
   }
   
while(true){
    int f=1;
    int ind=0;
     for(int i=0;i<m;i++){
         if(bul[i]==false){
            int fnd=1;
            for(int j=0;j<n;j++){
               if(need[i][j]>aval[j]){
                  fnd=0;
                  break;
               }
            }
            if(fnd==1){
               bul[i]=true;
               for(int j=0;j<n;j++)
                   aval[j]+=alloc[i][j];
               f=0;
               ans.push_back(i+1);
            }    
         }
         
      }
    if(f==1){
       int s=1;
       for(int i=0;i<m;i++){
           if(bul[i]==false){
             s=0;
             break;
           }
       }
       if(s==1){
          cout<<endl;
          cout<<"Safety Sequence Is: ";
          for(int i=0;i<ans.size();i++)cout<<"P"<<ans[i]<<"-> ";
          cout<<endl;
       }
       else cout<<"Safety Sequence Is Does not exist: "<<endl;
       break;
    }
}
 //End of Block  
      
}

int main(){ 
   BankingAlgo();
   
}

//OUTPUT FILE 
/* 
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ g++ Bankers.cpp
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ ./a.out
Enter number of Procesess and number of Resorcsess: 4 3
Enter your Allocated Procesess: 2 1 0 1 2 2 0 2 0 3 0 1
Enter your Max Procesess: 8 6 3 9 4 3 5 3 3 4 2 3
Enter Available Resorcess: 4 3 2
Allocation Matrix: 
2 1 0 
1 2 2 
0 2 0 
3 0 1 
Max Matrix: 
8 6 3 
9 4 3 
5 3 3 
4 2 3 
Need Matrix: 
6 5 3 
8 2 1 
5 1 3 
1 2 2 

Safety Sequence Is: P->4, P->3, P->1, P->2, 
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ g++ Bankers.cpp
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ ./a.out
Enter number of Procesess and number of Resorcsess: 5 3
Enter your Allocated Procesess: 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
Enter your Max Procesess: 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 
Enter Available Resorcess: 3 3 2
Allocation Matrix: 
0 1 0 
2 0 0 
3 0 2 
2 1 1 
0 0 2 
Max Matrix: 
7 5 3 
3 2 2 
9 0 2 
2 2 2 
4 3 3 
Need Matrix: 
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 

Safety Sequence Is: P->2, P->4, P->5, P->1, P->3, 
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ g++ Bankers.cpp
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ ./a.out
Enter number of Procesess and number of Resorcsess: 5 3
Enter your Allocated Procesess: 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
Enter your Max Procesess:  7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
Enter Available Resorcess: 3 3 2
Allocation Matrix: 
0 1 0 
2 0 0 
3 0 2 
2 1 1 
0 0 2 
Max Matrix: 
7 5 3 
3 2 2 
9 0 2 
2 2 2 
4 3 3 
Need Matrix: 
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 

Safety Sequence Is: P2-> P4-> P5-> P1-> P3-> 
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ g++ Bankers.cpp
student@ student-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ ./a.out
Enter number of Procesess and number of Resorcsess: 5 3
Enter your Allocated Procesess: 1 1 2 2 1 2 3 0 1 0 2 0 1 1 2 
Enter your Max Procesess: 5 4 4 4 3 3 9 1 3 8 6 4 2 2 3 
Enter Available Resorcess: 3 2 1
Allocation Matrix: 
1 1 2 
2 1 2 
3 0 1 
0 2 0 
1 1 2 
Max Matrix: 
5 4 4 
4 3 3 
9 1 3 
8 6 4 
2 2 3 
Need Matrix: 
4 3 2 
2 2 1 
6 1 2 
8 4 4 
1 1 1 

Safety Sequence Is: P2-> P5-> P1-> P3-> P4-> 
student@ student-HP -348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ g++ Bankers.cpp
student@ student-HP-348 -G4: ~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ ./a.out
Enter number of Procesess and number of Resorcsess: 5 3
Enter your Allocated Procesess: 0 3 0 3 0 2 3 0 2 2 1 1 0 0 2
Enter your Max Procesess: 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 
Enter Available Resorcess: 2 1 0
Allocation Matrix: 
0 3 0 
3 0 2 
3 0 2 
2 1 1 
0 0 2 
Max Matrix: 
7 5 3 
3 2 2 
9 0 2 
2 2 2 
4 3 3 
Need Matrix: 
7 2 3 
0 2 0 
6 0 0 
0 1 1 
4 3 1 
Safety Sequence Is Does not exist: 
student@ s tudent-HP-348-G4:~/Desktop/ALL IN ONE/E3SEM1/OS/OSEXTERNAL$ 
 
*/
