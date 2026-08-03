#include <iostream>
using namespace std;

#define S 20

float stack[S];
int tos = -1;
int Empty()
{
    if(tos == -1)
        return 1;
    else
        return 0;
}

int full()
{
    if(tos == S - 1)
        return 1;
    else
        return 0;
}
void push(float x)
{
    if(!full())
    {
        tos++;
        stack[tos] = x;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}
float pop()
{
	float x;
    if(!Empty())
    {
        
        x=stack[tos];
        tos--;
        return x;
    }
    else
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
}
float cal(char op,float p1,float p2)
{
	switch(op)
	{
        case '+': 
		return p1 + p2;
        case '-':
		 return p1 - p2;
        case '*':
		 return p1 * p2;
        case '/':
		 return p1 / p2;
    }
    return 0;
}
int main()
{
	char post[50];
	float p1,p2,r;
	int i=0;
	cout<<"Enter postfix expression:";
	cin>>post;
	while(post[i]!='\0')
	{
		if(post[i]>='0' && post[i]<='9')
		{
			push(post[i]-'0');
		}
		else
		{
			p2=pop();
			p1=pop();
			r=cal(post[i],p1,p2);
			push(r);
		}
		i++;
	}
	cout<<"Result:"<<pop()<<endl;
	return 0;
}

