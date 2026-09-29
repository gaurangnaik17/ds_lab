#include<iostream>
#include<malloc.h>
using namespace std;

#define MAX 20

struct node
{
    int info;
    struct node *next;
};

struct node *start=NULL;
int count=0;

struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    temp->info=x;
    temp->next=NULL;

    return temp;
}

void insert_first(int x)
{
    struct node *t,*p;

    if(count==MAX)
    {
        cout<<"Maximum position reached"<<endl;
        return;
    }

    t=create_node(x);

    if(start==NULL)
    {
        start=t;
        t->next=start;
    }
    else
    {
        p=start;

        while(p->next!=start)
            p=p->next;

        t->next=start;
        p->next=t;
        start=t;
    }

    count++;
}

void insert_last(int x)
{
    struct node *t,*p;

    if(count==MAX)
    {
        cout<<"Maximum position reached"<<endl;
        return;
    }

    t=create_node(x);

    if(start==NULL)
    {
        start=t;
        t->next=start;
    }
    else
    {
        p=start;

        while(p->next!=start)
            p=p->next;

        p->next=t;
        t->next=start;
    }

    count++;
}

void insert_after(int value,int x)
{
    struct node *t,*p;

    if(count==MAX)
    {
        cout<<"Maximum position reached"<<endl;
        return;
    }

    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    p=start;

    do
    {
        if(p->info==value)
        {
            t=create_node(x);

            t->next=p->next;
            p->next=t;

            count++;
            return;
        }

        p=p->next;

    }while(p!=start);

    cout<<"Given node not found"<<endl;
}

void delete_first()
{
    struct node *t,*p;

    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(start->next==start)
    {
        t=start;
        start=NULL;
        free(t);
        count--;
    }
    else
    {
        p=start;

        while(p->next!=start)
            p=p->next;

        t=start;
        start=start->next;
        p->next=start;

        free(t);
        count--;
    }
}

void delete_last()
{
    struct node *t,*p;

    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(start->next==start)
    {
        t=start;
        start=NULL;
        free(t);
        count--;
    }
    else
    {
        p=start;

        while(p->next->next!=start)
            p=p->next;

        t=p->next;
        p->next=start;

        free(t);
        count--;
    }
}

void delete_after(int value)
{
    struct node *t,*p;

    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    p=start;

    do
    {
        if(p->info==value)
        {
            t=p->next;

            if(t==start)
            {
                cout<<"No node after the given node"<<endl;
                return;
            }

            p->next=t->next;
            free(t);

            count--;
            return;
        }

        p=p->next;

    }while(p!=start);

    cout<<"Given node not found"<<endl;
}

void display()
{
    struct node *t;

    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    t=start;

    do
    {
        cout<<t->info<<" ";
        t=t->next;
    }while(t!=start);

    cout<<endl;
}

int main()
{
    int ch,x,value;

    while(1)
    {
        cout<<"\n1.Insert at first";
        cout<<"\n2.Insert at last";
        cout<<"\n3.Insert after a given node";
        cout<<"\n4.Delete first";
        cout<<"\n5.Delete last";
        cout<<"\n6.Delete node after a given node";
        cout<<"\n7.Display";
        cout<<"\n8.Exit";

        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter the element to be inserted:";
                cin>>x;
                insert_first(x);
                break;

            case 2:
                cout<<"Enter the element to be inserted:";
                cin>>x;
                insert_last(x);
                break;

            case 3:
                cout<<"Enter the given node and element:";
                cin>>value>>x;
                insert_after(value,x);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                cout<<"Enter the given node:";
                cin>>value;
                delete_after(value);
                break;

            case 7:
                display();
                break;

            case 8:
                cout<<"Program is ended"<<endl;
                return 0;
        }
    }

    return 0;
}