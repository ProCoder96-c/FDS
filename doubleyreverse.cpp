//4 create a doubly linked list to store any integer digit by digit and reverse the same
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *prev=NULL;
};
Node *head=NULL,*temp=NULL;
void create()
{
    int n,value;
    cout<<"Enter Number of Nodes you want in linked list:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Node *newNode=new Node();
        cout<<"Enter Data For "<<i+1<<endl;
        cin>>value;
        newNode->data=value;
        if(head==NULL)
        {
            head=temp=newNode;
            newNode->prev=NULL;
        }
        else
        {
            temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;
            newNode->prev=temp;
        }
    }
    cout<<"Linked List Created Successfully"<<endl;
}
void display(){
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void display_reverse()
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"<-";
        temp=temp->prev;
    }
    cout<<"head";
}
int main()
{
    create();
    //display();
    display_reverse();
    return 0;
}