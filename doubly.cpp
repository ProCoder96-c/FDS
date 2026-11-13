#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* prev;
        Node* next;
};
Node* head=NULL,*temp=NULL,*pre=NULL;
class Doubly
{
    public:
    Node* head;
    Node* tail;
    public:
    Doubly()
    {
        head=tail=NULL;
    }
    void insertAtbeg()
    {
        int val;
        cout<<"Enter Data to new Node:"<<endl;
        cin>>val;
        Node* newNode =new Node();
        newNode->data=val;
        if(head==NULL)
        {
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            newNode->prev=NULL;
        }
    }
    void insertAtpos()
    {
        Node* newNode=new Node();
        int n;
        int pos;
        cout<<"Enter data that add in particular location:"<<endl;
        cin>>n;
        cout<<"Enter Position to add:"<<endl;
        cin>>pos;
        newNode->data=n;
        if(pos==1)
        {
            newNode->next=head;
            if(head!=NULL)
            {
                head->prev=newNode;
            }
            head=newNode;
            newNode->prev=NULL;
            return;
        }
        else{
            temp=head;
            for(int i=1;i<pos-1 && temp!=NULL;i++)
            {
                temp=temp->next;
            }
            if(temp==NULL)
            {
                cout<<"Position out of Range"<<endl;
                return;
            }
            newNode->next=temp->next;
            temp->next=newNode;
            newNode->prev=temp;
            temp=temp->next;
            temp->prev=newNode;
        }
    }
    void insertAtEnd()
    {
        int n;
        Node* newNode=new Node();
        cout<<"Enter Data To add at the end:"<<endl;
        cin>>n;
        newNode->data=n;
        temp=head;
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=NULL;
    }
    void deleteFirst()
    {
        if(head==NULL)
        {
            cout<<"Linked List is Empty";
            return;
        }
        temp=head;
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        delete temp;
        cout<<"\nDeleted Successfully"<<endl;
    }
    void deleteAtpos()
    {
        int pos;
        cout<<"Enter Position that Delete:"<<endl;
        cin>>pos;
        temp=head;
        if(head==NULL)
        {
            cout<<"Linked List is Empty";
            return;
        }
        if(pos==1)
        {
            head=head->next;
            if(head!=NULL)
            {
                head->prev=NULL;
            }
            delete temp;
            cout<<"\nDeleted Successfully"<<endl;
            return;
        }
        for(int i=1;i<pos && temp!=NULL;i++)
        {
            pre=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"Position is out of Range"<<endl;
            return;
        }
        pre->next=temp->next;
        if(temp->next!=NULL)
        {
            temp->next->prev=pre;
        }
        delete temp;
        cout<<"Deleted.....";

    }
    void deleteLast()
    {
        if(head==NULL)
        {
            cout<<"Linked List is Empty";
            return;
        }
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
            cout<<"Deleted.....";
            return;
        }
        temp=head;
        while(temp->next!=NULL)
        {
            pre=temp;
            temp=temp->next;
        }
        pre->next=NULL;
        delete temp;
        cout<<"Deleted....."<<endl;
    }
    void print()
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};

int main()
{
    Doubly db;
    // db.insertAtbeg();
    // db.print();
    // db.insertAtbeg();
    // db.print();
    db.insertAtbeg();
    db.print();
    db.insertAtEnd();
    db.print();
    db.insertAtEnd();
    db.print();
    //db.insertAtpos();
    // db.print();
    //db.deleteAtpos();
    db.deleteLast();
    db.print();

}