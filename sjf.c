#include<stdio.h>
struct sjf{
    int at,bt,tat,ct,wt,rt,com;
};
int main(){
    int n,i,min_index,j;
    printf("enter the no of processess : ");
    scanf("%d",&n);
    printf("enter the arrival and burst times : ");
    struct sjf s[n];
    for(i=0;i<n;i++){
        scanf("%d%d",&s[i].at,&s[i].bt);
        s[i].com=0;
    }
    int t=0;
    int com_count=0;
    while(1)
    { 
        int b=0;
        for(j=0;j<n;j++){
            if(s[j].com==0){
                if(s[j].at<=t && (s[j].bt<b || b==0)){
                min_index=j;
                b=s[j].bt;}
            }
        }
        if(b==0) t++;
        else{
        s[min_index].ct=t+s[min_index].bt;
        s[min_index].com=1;
        com_count+=1;
        t+=s[min_index].bt;
        }
        if(com_count==n)
        break;
    }
    // for (i = 0; i < n; i++)
    // {
    //     s[i].
    // }
    
    for(i=0;i<n;i++){
        printf("\n%d - %d - %d - %d",i+1,s[i].at,s[i].bt,s[i].ct);
    }



}