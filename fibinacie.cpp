#include<iostream>
using namespace std;

struct node {
    int data;
    node *next,*prev;
};

int main() {
    int n,a=0,b=1,c;
    cout<<"Enter n: ";
    cin>>n;

    node *head=NULL,*temp;

    for(int i=0;i<n;i++) {
        node* newnode=new node{a,NULL,NULL};

        if(!head) {
            head=temp=newnode;
            head->next=head->prev=head;
        } else {
            newnode->prev=temp;
            newnode->next=head;
            temp->next=newnode;
            head->prev=newnode;
            temp=newnode;
        }

        c=a+b; a=b; b=c;
    }

    temp=head;
    for(int i=0;i<n;i++) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}