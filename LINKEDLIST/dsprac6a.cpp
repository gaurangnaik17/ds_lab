#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int info;
    struct node *next;
};

struct node *start=NULL;

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
    struct node *t;
    t=create_node(x);

    if(start==NULL)
        start=t;
    else
    {
        t->next=start;
        start=t;
    }
}

void insert_last(int x)
{
    struct node *t,*p;
    t=create_node(x);

    if(start==NULL)
        start=t;
    else
    {
        p=start;
        while(p->next!=NULL)
            p=p->next;

        p->next=t;
    }
}

void insert(int pos,int x)
{
    struct node *t,*p;
    t=create_node(x);

    if(start==NULL)
        start=t;
    else
    {
        p=start;

        for(int i=1;i<pos-1;i++)
            p=p->next;

        t->next=p->next;
        p->next=t;
    }
}

void delete_first()
{
    struct node *t;

    if(start==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        t=start;
        cout<<"Deleted element: "<<t->info<<endl;
        start=start->next;
        free(t);
    }
}

void delete_last()
{
    struct node *t,*p;

    if(start==NULL)
        cout<<"List is empty"<<endl;
    else if(start->next==NULL)
    {
        t=start;
        cout<<"Deleted element: "<<t->info<<endl;
        start=NULL;
        free(t);
    }
    else
    {
        p=start;

        while(p->next->next!=NULL)
            p=p->next;

        t=p->next;
        cout<<"Deleted element: "<<t->info<<endl;
        p->next=NULL;
        free(t);
    }
}

void delete_pos(int pos)
{
    struct node *t,*p;

    if(start==NULL)
        cout<<"List is empty"<<endl;
    else if(pos==1)
    {
        t=start;
        cout<<"Deleted element: "<<t->info<<endl;
        start=start->next;
        free(t);
    }
    else
    {
        p=start;

        for(int i=1;i<pos-1;i++)
            p=p->next;

        t=p->next;

        if(t==NULL)
            cout<<"Invalid position"<<endl;
        else
        {
            cout<<"Deleted element: "<<t->info<<endl;
            p->next=t->next;
            free(t);
        }
    }
}

void display()
{
    struct node *t;
    t=start;

    while(t!=NULL)
    {
        cout<<t->info<<" ";
        t=t->next;
    }
}

int main()
{
    int ch,x,pos;

    while(1)
    {
        cout<<"\n1.Insert at first";
        cout<<"\n2.Insert at last";
        cout<<"\n3.Insert at position";
        cout<<"\n4.Delete first";
        cout<<"\n5.Delete last";
        cout<<"\n6.Delete at position";
        cout<<"\n7.Display";
        cout<<"\n8.Exit";

        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter the element to be inserted:"<<endl;
                cin>>x;
                insert_first(x);
                break;

            case 2:
                cout<<"Enter the element to be inserted:"<<endl;
                cin>>x;
                insert_last(x);
                break;

            case 3:
                cout<<"Enter the position and element to be inserted:"<<endl;
                cin>>pos>>x;
                insert(pos,x);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                cout<<"Enter the position to be deleted:"<<endl;
                cin>>pos;
                delete_pos(pos);
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
