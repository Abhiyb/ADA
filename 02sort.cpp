
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
                k=j;
            }
        }
             swap(a[k],a[i]);
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
//===============================QUICK SORT=================================
int partition(int arr[],int l,int h)
{
    int piote=arr[h];int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<piote)
        {
            i++;swap(arr[i],arr[j]);
        }
    }
    i++;swap(arr[i],arr[h]);
    return i;
}
void quick_sort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p=partition(arr,l,h);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,h);
        
    }
}
//==============================================================================================================
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
int linear_search(int arr[],int n,int key){
    if(n<0)
        return -1;
    if(arr[n]==key)
        return n;
    return linear_search(arr,n-1,key);
}

int binary_search(int arr[],int l,int h,int key){
    if(l<=h){
        int mid = (l+h)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binary_search(arr,l,mid-1,key);
        return binary_search(arr,mid+1,h,key);
    }
    return -1;
}
