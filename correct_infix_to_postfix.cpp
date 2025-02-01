#include<iostream>
#include<string.h>
#define MAX 100

using namespace std;

char st[MAX];
int top = -1;

void push(char c);
char pop();
void InfixPostfix(char source[], char target[]);
int getPriority(char c);

int main()
{
    char infix[100], postfix[100];
    cout << "Enter infix expression: ";
    cin >> infix;
    InfixPostfix(infix, postfix);
    cout << "Postfix expression: ";
    cout << postfix;
    return 0;
}

void InfixPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while (top != -1 && (st[top] != '('))
            {
                target[j++] = pop();
            }
            if (top != -1)
            {
                pop();
            }
            i++;
        }
        else if (getPriority(source[i]) == 0) // Operand
        {
            target[j++] = source[i++];
        }
        else
        {
            while (top != -1 && getPriority(source[i]) <= getPriority(st[top]))
            {
                target[j++] = pop();
            }
            push(source[i++]);
        }
    }
    while (top != -1)
    {
        target[j++] = pop();
    }
    target[j] = '\0';
}

int getPriority(char c)
{
    if (c == '(')
    {
        return 0;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '^')
    {
        return 3;
    }
    return 0;
}

void push(char c)
{
    if (top < MAX - 1)
    {
        st[++top] = c;
    }
    else
    {
        cout << "Stack overflow\n";
    }
}

char pop()
{
    if (top >= 0)
    {
        return st[top--];
    }
    else
    {
        cout << "Stack underflow\n";
        return -1;
    }
}
