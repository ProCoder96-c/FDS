#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main() {
    int n, bin[8]={0};
    cout<<"Enter number: ";
    cin>>n;

    for(int i=7;i>=0;i--) {
        bin[i]=n%2;
        n/=2;
    }

    node *head=NULL,*temp;

    for(int i=0;i<8;i++) {
        node* newnode=new node{bin[i],NULL};
        if(!head) head=temp=newnode;
        else {
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp->next=head;

    temp=head;
    for(int i=0;i<8;i++) {
        cout<<temp->data;
        temp=temp->next;
    }
}