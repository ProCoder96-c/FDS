#include<iostream>
using namespace std;

int main() {
    char str[50], stack[50];
    int top=-1,i=0;

    cout<<"Enter string: ";
    cin>>str;

    while(str[i]) stack[++top]=str[i++];

    i=0;
    while(str[i]) {
        if(str[i++]!=stack[top--]) {
            cout<<"Not Palindrome";
            return 0;
        }
    }
    cout<<"Palindrome";
}