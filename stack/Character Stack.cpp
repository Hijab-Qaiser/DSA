#include <iostream>
using namespace std;

// Create an array of char type
char Characters[5];
int stackpointer = 0; // Points to next empty slot

// Push an element
void Push(char value)
{
    if (stackpointer > 4) // Stack is full
    {
        cout << "Stack full" << "\n";
        return;
    }
    Characters[stackpointer] = value; // add value
    stackpointer = stackpointer + 1;  // pointer points to next empty slot
    cout << "New values of stack are: " << "\n";
    for (int i = 0; i < stackpointer; i++)
    {
        cout << Characters[i] << " ";
    }
    cout << "\n";
}

// Pop an element
void Pop()
{
    if (stackpointer == 0) // Stack is empty
    {
        cout << "Stack empty" << "\n";
        return;
    }

    stackpointer = stackpointer - 1; // return pointer to taken slot
    cout << Characters[stackpointer] << " was popped from stack" << "\n";
    cout << "New values of stack are: " << "\n";
    for (int i = 0; i < stackpointer; i++)
    {
        cout << Characters[i] << " ";
    }
    cout << "\n";
}

void Peek()
{
    if (stackpointer == 0)
    {
        cout << "Stack empty" << "\n";
        return;
    }
    cout << Characters[stackpointer - 1] << "\n"; // look at the previous taken slot
    cout << "\n";
}

int main()
{
    string choice;
    char value; // String variable
    while (true)
    {
        while (true)
        {
            cout << "            |STACK menu|            " << "\n";
            cout << "Enter 1 if you want to PUSH into stack " << "\n";
            cout << "Enter 2 if you want to POP from stack " << "\n";
            cout << "Enter 3 if you want to PEEK into stack " << "\n";
            cout << "Enter 4 if you want to view the stack " << "\n";
            cout << "Enter 5 if you want to terminate the program " << "\n";
            cout << "\n";
            cin >> choice;
            if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
            {
                break;
            }
            else
            {
                cout << "Invalid characters entered" << "\n";
                continue;
            }
        }
        if (choice == "1")
        {
            cout << "Enter value you want to PUSH" << "\n";
            cin >> value;
            Push(value);
            continue;
        }
        else if (choice == "2")
        {
            Pop();
            continue;
        }
        else if (choice == "3")
        {
            cout << "Last entered value on the stack is: ";
            Peek();
            continue;
        }
        else if (choice == "4")
        {
            for (int i = 0; i < stackpointer; i++)
            {
                cout << Characters[i] << " ";
            }
            cout << "\n";
            continue;
        }
        else if (choice == "5")
        {
            break;
        }
    }
    return 0;
}