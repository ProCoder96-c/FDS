#include<iostream>
using namespace std;
int visited[100];
class Queue
{
    public:
    int front=-1,rear=-1;
    int arr[100];
    void enque(int n)
    {
        arr[++rear]=n;
        if(rear==0)
        {
            front=0;
        }
    }
    int deque()
    {
        return arr[front++];
    }
    int empty()
    {
        if(front==-1 || front>rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
void bfs(Queue q,int arr[100][100],int n)
{
    if(q.empty())
    {
        return;
    }
    int cn=q.deque();
    for(int i=1;i<=n;i++)
    {
        if(arr[cn][i]==1 && visited[i]==0)
        {
            cout<<i;
            visited[i]=1;
            q.enque(i);
        }
    }
    bfs(q,arr,n);
}
int main()
{
    int arr[100][100],n,start;
    cout<<"Enter Number of vertices you want:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"Enter value of row of "<<i<<" of column "<<j<<" :";
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    cout<<"Enter Starting Vertex:";
    cin>>start;
    Queue q;
    q.enque(start);
    visited[start]=1;
    cout<<start<<"->";
    bfs(q,arr,n);
}