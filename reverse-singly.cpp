#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};
Node* head=NULL,*temp=NULL,*curr=NULL,*next=NULL,*prev=NULL;
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
            if(temp->next!=NULL)
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
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
}
int main()
{
    create();
    display();
}