#include<iostream>
using namespace std;
#define S 20
int queue[S];
int front=-1;
int rear=-1;
int full()
{
    if(rear==S-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int empty()
{
    if(front==-1 && rear==-1 || front>rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int x)
{
    if(full())
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
       if(front==-1 && rear==-1)
        front=0;
        queue[++rear]=x;
    }
}
int dequeue()
{
    int x;  
    if (empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        x =queue[front];
        front++;
    }
    return x;
}
void display()
{
    if(empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int choice,x;
    do
    {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the element to be insterted:"<<endl;
                cin>>x;
                enqueue(x);
                break;
            case 2:
                 x=dequeue();
                 if(x!=-1)
                 {
                    cout<<"The deleted element is:"<<x<<endl;
                 }                
                 break;
            case 3:
                display();
                break;
            case 4:
                 cout<<"Program is ended"<<endl;
                 break;
            default:
                 cout<<"Invalid choice"<<endl;
        
        }
   }while(choice!=4);
   
   return 0;
}
    