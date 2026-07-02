#include <iostream>
using namespace std;

// Global variables for the Queue
char Characters[10]; // Array changed to char
int headpointer = -1;
int tailpointer = 0;

void Enqueue(char ch) // Parameter changed to char
{
    if (tailpointer < 10)
    {
        Characters[tailpointer] = ch;
        tailpointer++;
        if (headpointer == -1)
        {
            headpointer = 0;
        }
    }
    else
    {
        cout << "Queue full";
    }
    cout << "New values of Queue: ";
    for (int i = 0; i < tailpointer; i++)
    {
        cout << Characters[i] << " ";
    }
    cout << "\n";
}

int Dequeue(void)
{
    if (headpointer == -1)
    {
        cout << "Queue empty";
    }
    else
    {
        cout << Characters[headpointer] << " was dequeued";
        headpointer++;
    }
    cout << "\nNew values of Queue: ";
    for (int i = headpointer; i < tailpointer; i++)
    {
        cout << Characters[i] << " ";
    }
    cout << "\n";
    return 0;
}

int main()
{
    int choice;
    char value; // Variable changed to char
    while (true)
    {
        while (true)
        {
            cout << "            |QUEUE menu|            " << "\n";
            cout << "Enter 1 if you want to ENQUEUE " << "\n";
            cout << "Enter 2 if you want to DEQUEUE " << "\n";
            cout << "Enter 3 if you want to view QUEUE " << "\n";
            cout << "Enter 4 if you want to terminate program" << "\n";
            cout << "\n";
            cin >> choice;
            if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
            {
                break;
            }
            else
            {
                cout << "Invalid characters entered" << "\n";
                continue;
            }
        }
        if (choice == 1)
        {
            cout << "Enter value you want to ENQUEUE" << "\n";
            cin >> value;
            Enqueue(value);
            continue;
        }
        else if (choice == 2)
        {
            Dequeue();
            continue;
        }
        else if (choice == 3)
        {
            for (int i = headpointer; i < tailpointer; i++)
            {
                cout << Characters[i] << " ";
            }
            cout << "\n";
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}