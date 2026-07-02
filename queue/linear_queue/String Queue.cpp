#include <iostream>
#include <string> // Added string header
using namespace std;

// Global variables for the Queue
string Strings[10]; // Array changed to string
int headpointer = -1;
int tailpointer = 0;

void Enqueue(string str) // Parameter changed to string
{
    if (tailpointer < 10)
    {
        Strings[tailpointer] = str;
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
        cout << Strings[i] << " ";
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
        cout << Strings[headpointer] << " was dequeued";
        headpointer++;
    }
    cout << "\nNew values of Queue: ";
    for (int i = headpointer; i < tailpointer; i++)
    {
        cout << Strings[i] << " ";
    }
    cout << "\n";
    return 0;
}

int main()
{
    int choice;
    string value; // Variable changed to string
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
                cout << Strings[i] << " ";
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