#include<iostream>
using namespace std;
int main()
{
    int n,arr[100],key,p,i;
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
    for(p=1;p<=n;p++)
    {
        for(i=0;i<n-p;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    cout<<"Array Element are(After sorting):"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
}