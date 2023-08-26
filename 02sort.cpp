
#include <iostream>

using namespace std;
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
