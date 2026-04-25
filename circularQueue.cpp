#include<iostream>
using namespace std;
const int MAX=5;
int queue[MAX];
int rear=-1,front=-1;
void enque()
{
    if(front==(rear+1)%MAX ||(front==0 && rear==MAX-1))
    {
        cout<<"Queue is Overflow";
    }
    else
    {
        cout<<"Enter Element that want to insert:"<<endl;
        int value;
        cin>>value;
        rear=(rear+1)%MAX;
        queue[rear]=value;
        if(rear==0)
        {
            front=0;
        }
    }
}
void deque()
{
    if(rear==-1 && front==-1)
    {
        cout<<"Queue IS Empty";
    }
    else{
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
        
    }
}
void display()
{
    int i=front;
    while(true)
    {
        if(rear==-1 && front==-1)
        {
            cout<<"Queue IS Empty";
            break;
        }

        cout<<queue[i]<<" ";
        if(i==rear)
        {
            break;
        }
        i=(i+1)%MAX;
    }
}
int main()
{
    int ch;
    do{
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeu"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter Choice:"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
                /* code */
                enque();
                break;
            case 2:
                /* code */
                deque();
                break;
            case 3:
                /* code */
                display();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Wrong Input"<<endl;
                break;
        }
    }while(ch!=4);
}