#include <iostream>
using namespace std;

#define S 20

int stack[S];
int tos = -1;

int Empty()
{
    if(tos == -1)
        return 1;
    else
        return 0;
}

int Full()
{
    if(tos == S - 1)
        return 1;
    else
        return 0;
}

void Push(int x)
{
    if(!Full())
    {
        tos++;
        stack[tos] = x;
        cout << "Element inserted successfully" << endl;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}

int Pop()
{
	int x;
    if(!Empty())
    {
        
        x=stack[tos];
        tos--;
        return x;
    }
    else
    {
        cout << "Stack is not empty" << endl;
        return -1;
    }
}

void Peek()
{
    if(Empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Top element of stack is: " << stack[tos] << endl;
    }
}

void Display()
{
    if(Empty())
    {
        cout << "Stack is Empty" << endl;	
    }
    else
    {
        cout << "Stack elements are: ";
        for(int i = tos; i >= 0; i--)
        {
            cout << stack[i]<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int choice, num, x;

    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter the element: ";
                cin >> num;
                Push(num);
                break;

            case 2:
                x = Pop();
                if(x != -1)
                    cout << "Deleted element: " << x << endl;
                break;

            case 3:
                Peek();
                break;

            case 4:
                Display();
                break;

            case 5:
                cout << "Program Ended" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}
