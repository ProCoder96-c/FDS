#include<iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
    int pivot=arr[end],indx=start-1;
    for(int j=start;j<end;j++)
    {
        if(arr[j]<=pivot)
        {
            indx++;
            swap(arr[j],arr[indx]);
        }
    }
    indx++;
    swap(arr[indx],arr[end]);
    return indx;
}
void quick(int arr[],int start,int end)
{
    if(start<end)
    {
        int indx=partition(arr,start,end);
        quick(arr,start,indx-1);
        quick(arr,indx+1,end);
    }
}
int main()
{
    int arr[]={5,3,2,1,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    quick(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}