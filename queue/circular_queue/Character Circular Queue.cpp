#include <iostream>
using namespace std;

// Global variables for the Queue
char Characters[10]; // Array changed to char
int headpointer = -1;
int tailpointer = 0;
int Count = 0;

// Function to view
void ViewQueue(void)
{
    if (Count == 0)
    {
        cout << "Queue empty\n";
        return;
    }

    for (int i = 0; i < Count; i++)
    {
        int index = (headpointer + i) % 10;
        cout << Characters[index] << " ";
    }

    cout << "\n";
}
// Function to add an element to the back of the queue
void Enqueue(char ch)
{
    // Check if there is space in the queue
    if (Count == 10)
    {
        cout << "Queue full\n";
        return;
    }
    Characters[tailpointer] = ch;         // Add the value to the tail position
    tailpointer = (tailpointer + 1) % 10; // Move tail forward and return to 0 after position 9
    Count++;

    // If this is the first element added, set the head pointer to 0
    if (headpointer == -1)
    {
        headpointer = 0;
    }

    // Display the current state of the queue
    cout << "\nNew values of Queue: ";
    ViewQueue();
    return;
}

// Function to remove an element from the front of the queue
void Dequeue(void)
{
    // Check if the queue is empty
    if (Count == 0)
    {
        cout << "Queue empty\n";
        return;
    }

    else
    {
        cout << Characters[headpointer] << " was dequeued"; // Display the removed element
        headpointer = (headpointer + 1) % 10;               // Move the head pointer forward
        Count--;
    }

    // Display the remaining elements in the queue
    cout << "\nNew values of Queue: ";
    ViewQueue();
    return;
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