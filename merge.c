#include<stdio.h>
void merge(int a[],int l,int mid,int h){
  int i=l;
  int j=mid+1;
  int temp[10];
  int k=l;
  while(i<=mid && j<=h){
    if(a[i]<=a[j]){
        temp[k]=a[i];
        i++;
        k++;
    }
    else{
        temp[k]=a[j];
        k++;
        j++;
    }
  }
  while (i<=mid)
  {
   temp[k]=a[i];
   i++;
   k++;
  }
  while (j<=h)
  {
    temp[k]=a[j];
    j++;
    k++;
  }
for(int i=l;i<=h;i++){
    a[i]=temp[i];
}    
}
void mergesort(int a[],int l,int h){
    if(l>=h){
        return ;
    }
int mid=(l+h)/2;
mergesort(a,l,mid);
mergesort(a,mid+1,h);
merge(a,l,mid,h);
}
int main(){
    int a[10]={4,5,7,8,2,9,1,0,4,2};
    int l=0;
    int h=9;
mergesort(a,l,h);
for (int i = 0; i < 10; i++)
{
  printf("%d\n",a[i]);
}
return 0;
}