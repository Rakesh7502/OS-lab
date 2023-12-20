#include<stdio.h>
int min(int b[],int m){
    int i,max=999,index;
    for(i=0;i<m;i++){
        if(max>b[i]){
            max=b[i];
            index=i;
        }
    }
    return index;
}
void print(int f[],int m){
    for(int i=0;i<m;i++)
    printf("%d ",f[i]);
}
int isin(int f[],int m,int k){
    for(int i=0;i<m;i++){
        if(f[i]==k)
        return i;
    }
    return -1;
}
int main(){
    printf("enter the no of : ");
    int n,m,i,j;
    scanf("%d",&n);
    printf("enter the pages : ");
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the frame size : ");
    scanf("%d",&m);
    int f[m],b[m];
    for(i=0;i<m;i++){
        f[i]=-1;
        b[i]=i;
    }
    int k=i,c=0;
    for(i=0;i<n;i++){
        int index=isin(f,m,a[i]);
        if(index!=-1){
            // printf("done");
            b[index]=k++;
        }
        else{
            c+=1;
            int in=min(b,m);
            f[in]=a[i];
            b[in]=k++;
        }
        print(f,m);
        printf("\n");
    }
            printf("total page faults : %d\n and hits : %d\n",c,(n-c));


}