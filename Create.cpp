#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node *head=NULL,*temp=NULL,*newNode;
void create()
{
    int n;
    cout<<"Number of Nodes in Linked List:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value;
        cout<<"Enter Data for "<<i+1<<"Node"<<endl;
        cin>>value;
        newNode = new Node();
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
    cout<<"Linked List Created Successfully"<<endl;
}
void insertAtbeginning()
{
    int value;
    cout<<"Enter Data for New Node:"<<endl;
    cin>>value;
    newNode=new Node();
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    cout<<"New Node Added Successfully"<<endl;
}

void insertAtpos()
{
    int value,pos;
    cout<<"Enter Value for New Node:"<<endl;
    cin>>value;
    cout<<"Enter Position To add a node(start form 1):"<<endl;
    cin>>pos;
    newNode=new Node();
    newNode->data=value;
    if(pos==1)
    {
        newNode->next=head;
        head=newNode;
        return;
    }
    temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++)
    {
       temp=temp->next;
    }
    if (temp == NULL)        
    {
        cout << "Position out of range!" << endl;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    cout<<"Added Successfully"<<endl;
}
void insertAtend()
{
    int value;
    cout<<"Enter Data for New Node:"<<endl;
    cin>>value;
    newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;
   if(head==NULL)
   {
        head=newNode;
   }
   else{
        temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
   }
   cout<<"New Node Added SuccessFully at end"<<endl;
}
void deleteFirst()
{
    if(head==NULL)
    {
        cout<<"List Is empty";
        return;
    }
    temp=head;
    head=head->next;
    delete temp;
    cout<<"Deleted Successfully"<<endl;
}

void deleteAtPosition()
{
    int pos;
    cout << "Enter position to delete (starting from 1): ";
    cin >> pos;

    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // If deleting the first node
    if (pos == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted from position 1 successfully!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Traverse to the position
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL)
    {
        cout << "Position out of range!" << endl;
        return;
    }

    // Bypass the node to delete
    prev->next = temp->next;
    delete temp;

    cout << "Node deleted from position " << pos << " successfully!" << endl;
}


void deleteEnd()
{
    if(head==NULL)
    {
        cout<<"List Empty Already";
        return;
    }
    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        cout<<"deleted Successfully"<<endl;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
    cout << "Node deleted from end successfully" << endl;
}
void display()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    create();
    display();
    ///insertAtbeginning();
    //display();
    //insertAtend();
    //display();
    //insertAtpos();
    //display();
    deleteFirst();
    display();
    deleteEnd();
    display();
    deleteAtPosition();
    display();
}