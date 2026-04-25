#include<iostream>
using namespace std;
int main()
{
    int n,arr[100],key;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter for "<<i+1<<" Element"<<endl;
        cin>>arr[i];
    }
    cout<<"Array Element are:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    cout<<"Enter Element That you want to find:"<<endl;
    cin>>key;
    int f=0;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
        {
            f=1;
            cout<<"Element Found At Location:"<<mid<<endl;
            break;
        }
        if(key<arr[mid])
        {
            high=mid-1;
        }
        if(key>arr[mid])
        {
            low=mid+1;
        }
    }
    if(f==0)
    {
        cout<<"Element are not found!!!"<<endl;
    }
    return 0;
}