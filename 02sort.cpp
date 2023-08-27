
#include <iostream>

using namespace std;
void merge(int arr[], int l, int m, int r);
 void mergeSort(int arr[], int l, int r);
void selection(int a[],int n)
{
    int j,k;
    for(int i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
            {
                k=j;swap(a[k],a[i]);
            }
        }
    }
}
void insertion(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;int x=a[i];
        while(j>-1&&a[j]>x)
        {
            a[j+1]=a[j];j--;
        }
        a[j+1]=x;
    }
}

int main()
{
    // cout<<"Hello World";
 int a[]={2,5,3,100,9};
//  selection(a,5);
 insertion(a,5);
 for(int i=0;i<5;i++)
 {
     cout<<a[i]<<" ";
 }
    return 0;
}
void merge(int arr[], int l, int m, int r)
    {
         // Your code here
        int i=l,j=m+1;int b[l+r];int k=0;
        while(i<=m&&j<=r)
        {
            if(arr[i]<=arr[j])
            {
              b[k++]=arr[i++];
            }
            else b[k++]=arr[j++];
        }
        for(;i<=m;i++) b[k++]=arr[i];
        
        for(;j<=r;j++) b[k++]=arr[j];
        for(i=l;i<r+1;i++)
        {
            arr[i]=b[i-l];
        }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
         if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        // merge(arr,l,r/2,r);
    }
