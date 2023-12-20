#include<stdio.h>
int make(int a[],int i,int n,int f[],int m,int b[]){
    for(int k=0;k<m;k++){
        for(int j=i+1;j<n;j++){
            if(f[k]==a[j])
            {
                b[k]=j;
                break;
            }
            else b[k]=999;
        }
    }
}
int min(int b[],int m){
    int index=-1,num=-1;
    for(int i=0;i<m;i++){
        if(num<b[i]||num==-1){
        num=b[i];
        index=i;
        }
    }
    return index;
}
int isin(int f[],int m,int k){
    for(int i=0;i<m;i++){
        if(f[i]==k)
        return i;
    }
    return -1;
}
void print(int f[],int m){
    int i;
    for(i=0;i<m;i++){
        printf("%d ",f[i]);
    }
}
int main(){
    int n;
    printf("enter the no of : ");
    scanf("%d",&n);
    int a[n];
    printf("enter the sequence : ");
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int m;
    printf("enter the no of frames : ");
    scanf("%d",&m);
    int f[m],b[m];
    for(i=0;i<m;i++){
        f[i]=-1;
        b[i]=999;
    }
    int kk=0;
    for(i=0;i<n;i++){
        int index=isin(f,m,a[i]);
        if(index==-1){
            if(f[kk]==-1 && kk<m) {f[kk++]=a[i];}
            else{
            make(a,i,n,f,m,b);
            index=min(b,m);
            f[index]=a[i];}
        }
        print(f,m);
        printf("\n");
    } 
}