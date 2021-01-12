int main()
{
    int a[]={1,2,3,4,5,6};
    int n1,num,i,p,c=0;
    int n=sizeof(a)/sizeof(a[0]);
    printf("num");
    scanf("%d",&n1);
    num=5;
    for(i=0;i<n;i++){
        if(a[i]==num){p=i;
        a[p+1]=n1;
        c=1;
        for(i=0;i<n;i++){
   
        printf("%d",a[i]);
        }
    }
}
   
}
