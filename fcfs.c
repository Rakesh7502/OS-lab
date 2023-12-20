#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
      int at,bt,tat,ct,wt,rt;
};
int main(){
    int n,i,min_index,j,t1,t2;
    printf("enter the no of processess : ");
    scanf("%d",&n);
    printf("enter the arrival and burst times : ");
    struct fcfs s[n];
    for(i=0;i<n;i++){
        scanf("%d%d",&s[i].at,&s[i].bt);
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if(s[j].at<s[i].at)
            {
                t1=s[j].at;
                t2=s[j].bt;
                s[j].at=s[i].at;
                s[j].bt=s[i].bt;
                s[i].at=t1;
                s[i].bt=t2;
            }
        } 
    }
    s[0].ct=s[0].at+s[0].bt;
    for ( i = 1; i < n; i++)
    {
        s[i].ct=s[i-1].ct+s[i].bt;
        if(s[i-1].ct<s[i].at){
            s[i].ct+=(s[i].at-s[i-1].ct);
        }
    } 
    for(i=0;i<n;i++){
        printf("\n%d - %d - %d - %d",i+1,s[i].at,s[i].bt,s[i].ct);
    }

    
}
