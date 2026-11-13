#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};
Node* head=NULL,*temp=NULL,*curr=NULL,*nxt=NULL,*prv=NULL;
void create()
{
    int val,n;
    cout<<"how many nodes you want:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Node* newNode=new Node();
        cout<<"Enter Data For Node "<<i+1<<endl;
        cin>>val;
        newNode->data=val;
        if(head==NULL)
        {
            head=temp=newNode;
        }
        else
        {
            temp=head;
            newNode->next=NULL;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
void reverse()
{
    curr=head;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prv;
        prv=curr;
        curr=nxt;
    }
    head=prv;
}
int main()
{
    create();
    display();
    reverse();
    display();
}