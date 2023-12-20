#include<stdio.h>
int abss(int a,int b){
    return a>b?(a-b):(b-a);
}
int min(int head,int a[],int i,int n){
    int ss=99999,k;
    for(int j=i;j<n;j++){
        int c=abss(head,a[j]);
        if(ss>c){
            k=j;
            ss=c;
        }
    }
    return k;
}
int main(){
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int a[n],i;
    printf("enter the sequence : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the head : ");
    int head;
    scanf("%d",&head);
    int sum=0;
    int k=head,temp;
    for(i=0;i<n;i++){
        int index=min(k,a,i,n);
        temp=a[i];
        a[i]=a[index];
        a[index]=temp;
        k=a[i];
    }
    sum=abss(head,a[0]);
    printf("%d ",head);
    for(i=0;i<n;i++){
        if(i<n-1)
        sum+=abss(a[i],a[i+1]);
        printf("%d ",a[i]);
    }
        printf("\n%d",sum);


}