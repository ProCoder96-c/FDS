#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int prime(int n) {
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return 0;
    return 1;
}

int main() {
    node *head=NULL,*temp;

    for(int i=1;i<=500;i++) {
        if(prime(i)) {
            node* newnode=new node{i,NULL};
            if(!head) head=temp=newnode;
            else {
                temp->next=newnode;
                temp=newnode;
            }
        }
    }

    temp=head;
    while(temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}