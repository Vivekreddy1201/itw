#include<stdio.h>
void swap(int a,int b){
    int temp=b;
    b=a;
    a=temp;
}
int g(int a[],int l,int h){
    int p=a[l];
    int i=l;
    int j=h;
    while (i<j)
    {
        while (a[i]<=a[p]&&i<=h)
        {
           i++;
        }
        while (a[j]>a[p]&&j>=l)
        {
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
    }
        swap(a[l],a[j]);
  return i;
    }
void qs(int a,int l,int h){
if(l<h){
    int pi=g(a,l,h);
    qs(a,l,pi-1);
    qs(a,pi+1,h);
}
}

int main(){
    int a[10]={4,5,7,8,2,9,1,0,4,2};
    int l=0;
    int h=9;
    qs(a,l,h);
    for (int i = 0; i < 10; i++)
{
  printf("%d\n",a[i]);
}
return 0;
}