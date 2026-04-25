#include<iostream>
using namespace std;

struct node {
    int data, pri;
    node* next;
};

node* head=NULL;

int main() {
    int ch,d,p;

    do {
        cout<<"\n1.Insert 2.Display 3.Exit\n";
        cin>>ch;

        if(ch==1) {
            cout<<"Enter data and priority: ";
            cin>>d>>p;

            node* newnode=new node{d,p,NULL};

            if(!head || p>head->pri) {
                newnode->next=head;
                head=newnode;
            } else {
                node* temp=head;
                while(temp->next && temp->next->pri>=p)
                    temp=temp->next;

                newnode->next=temp->next;
                temp->next=newnode;
            }
        }

        else if(ch==2) {
            node* temp=head;
            while(temp) {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }

    } while(ch!=3);
}