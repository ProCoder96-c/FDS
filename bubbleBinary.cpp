#include<iostream>
using namespace std;

int main() {
    int n, arr[50], key;
    cout<<"Enter n: ";
    cin>>n;

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);

    cout<<"Enter key: ";
    cin>>key;

    int l=0,r=n-1,mid;
    while(l<=r) {
        mid=(l+r)/2;
        if(arr[mid]==key) {
            cout<<"Found";
            return 0;
        }
        else if(arr[mid]<key) l=mid+1;
        else r=mid-1;
    }
    cout<<"Not Found";
}