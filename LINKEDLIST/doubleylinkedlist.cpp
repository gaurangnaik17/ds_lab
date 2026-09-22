#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *first=NULL;

struct node *create_node(int x){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=x;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void insert_first(int x)
{
    struct node *t;
    t=create_node(x);
    if(first==NULL)
       first=t;
    else{
        t->next=first;
        first->prev=t;
        first=t;
    } 
}
void insert_last(int x)
{
    struct node *t,*temp;
    t=create_node(x);
    if(first==NULL)
       first=t;
    else{
        temp=first;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=t;
        t->prev=temp;
    } 
}
void insert_after(int x,int y)
{
    struct node *t,*temp;
    t=create_node(x);
    if(first==NULL)
       first=t;
    else{
        temp=first;
        while(temp!=NULL && temp->info!=y)
            temp=temp->next;
        if(temp==NULL)
            cout<<"Element "<<y<<" not found\n";
        else{
            t->next=temp->next;
            t->prev=temp;
            if(temp->next!=NULL)
                temp->next->prev=t;
            temp->next=t;
        }
    } 
}
void delete_first()
{
    struct node *temp;
    if(first==NULL)
        cout<<"List is empty\n";
    else{
        temp=first;
        first=first->next;
        if(first!=NULL)
            first->prev=NULL;
        free(temp);
    }
}
void delete_last()
{
    struct node *temp;
    if(first==NULL)
        cout<<"List is empty\n";
    else{
        temp=first;
        while(temp->next!=NULL)
            temp=temp->next;
        if(temp->prev!=NULL)
            temp->prev->next=NULL;
        else
            first=NULL;
        free(temp);
    }
}
void delete_after(int y)
{
    struct node *temp;
    if(first==NULL)
        cout<<"List is empty\n";
    else{
        temp=first;
        while(temp!=NULL && temp->info!=y)
            temp=temp->next;
        if(temp==NULL)
            cout<<"Element "<<y<<" not found\n";
        else if(temp->next==NULL)
            cout<<"No element after "<<y<<"\n";
        else{
            struct node *t=temp->next;
            temp->next=t->next;
            if(t->next!=NULL)
                t->next->prev=temp;
            free(t);
        }
    } 
}
void display()
{
    struct node *temp;
    if(first==NULL)
        cout<<"List is empty\n";
    else{
        temp=first;
        while(temp!=NULL){
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}
int main()
{
    int choice,x,y;
    while(1){
        cout<<"1. Insert at first\n";
        cout<<"2. Insert at last\n";
        cout<<"3. Insert after\n"; 
        cout<<"4. Delete first\n";
        cout<<"5. Delete last\n";
        cout<<"6. Delete after\n";
        cout<<"7. Display\n";
        cout<<"8. Exit\n";

        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to insert: ";
                cin>>x;
                insert_first(x);
                break;
            case 2:
                cout<<"Enter element to insert: ";
                cin>>x;
                insert_last(x);
                break;
            case 3:
                cout<<"Enter element to insert: ";
                cin>>x;
                cout<<"Enter element after which to insert: ";
                cin>>y;
                insert_after(x,y);
                break;
            case 4:

                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                cout<<"Enter element after which to delete: ";
                cin>>y;
                delete_after(y);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
        
}



