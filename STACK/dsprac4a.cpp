#include <iostream>
using namespace std;

#define S 20

char stack[S];
int tos = -1;

int Empty()
{
    return (tos == -1);
}

int Full()
{
    return (tos == S - 1);
}

void push(char ch)
{
    if (!Full())
        stack[++tos] = ch;
    else
        cout << "Stack is Full";
}

char pop()
{
    if (!Empty())
        return stack[tos--];
    else
        return '\0';
}

char peek()
{
    if (!Empty())
        return stack[tos];
    else
        return '\0';
}

int priority(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i = 0, j = 0;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    while (infix[i] != '\0')
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= 'a' && infix[i] <= 'z') ||
            (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (peek() != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while (!Empty() && priority(peek()) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while (!Empty())
        postfix[j++] = pop();

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}