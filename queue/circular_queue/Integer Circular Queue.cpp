#include <iostream>
using namespace std;

// Global variables for the Queue
int Numbers[10];      // Array to store queue elements with a max size of 10
int headpointer = -1; // Points to the front of the queue (the element to be removed)
int tailpointer = 0;  // Points to the next empty position at the back of the queue
int Count = 0;        // Number of elements currently in the queue

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
        cout << Numbers[index] << " ";
    }

    cout << "\n";
}
// Function to add an element to the back of the queue
void Enqueue(int num)
{
    // Check if there is space in the queue
    if (Count == 10)
    {
        cout << "Queue full\n";
        return;
    }
    Numbers[tailpointer] = num;           // Add the value to the tail position
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
        cout << Numbers[headpointer] << " was dequeued"; // Display the removed element
        headpointer = (headpointer + 1) % 10;            // Move the head pointer forward
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
    int value; // Variable to store input value for Enqueue

    // Infinite loop to keep the menu running
    while (true)
    {
        // Inner loop to handle menu input and validation
        while (true)
        {
            cout << "            |QUEUE menu|            " << "\n";
            cout << "Enter 1 if you want to ENQUEUE " << "\n";
            cout << "Enter 2 if you want to DEQUEUE " << "\n";
            cout << "Enter 3 if you want to view QUEUE " << "\n";
            cout << "Enter 4 if you want to terminate program" << "\n";
            cout << "\n";
            cin >> choice;

            // Check for valid menu selection
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

        // Execute based on user choice
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
            // Print all elements currently between head and tail
            ViewQueue();
            continue;
        }
        else
        {
            // Terminate the program
            break;
        }
    }

    return 0;
}