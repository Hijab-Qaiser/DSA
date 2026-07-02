# Circular Queue Implementation Notes

A beginner-friendly C++ project that demonstrates the **circular queue data structure** using fixed-size arrays.

The repository contains three separate circular queue programs:

* Integer Circular Queue
* Character Circular Queue
* String Circular Queue

Each program follows the **FIFO** principle:

> First In, First Out

This means the first value added to the queue is the first value removed.

## Features

Each program provides a menu for the following operations:

1. **Enqueue** — add a value to the back of the queue
2. **Dequeue** — remove a value from the front of the queue
3. **View** — display all values currently stored in the queue
4. **Exit** — terminate the program

The programs also check for:

* **Queue overflow** when all ten array positions are occupied
* **Queue underflow** when the queue is empty

## Project Files

| File                           | Data type stored  |
| ------------------------------ | ----------------- |
| `Integer Circular Queue.cpp`   | Integers          |
| `Character Circular Queue.cpp` | Single characters |
| `String Circular Queue.cpp`    | Strings           |

## How the Circular Queue Works

Each circular queue has a fixed capacity of ten elements.

Three variables are used:

```cpp
int headpointer = -1;
int tailpointer = 0;
int Count = 0;
```

* `headpointer` points to the element at the front of the queue.
* `tailpointer` points to the next empty position at the back.
* `Count` stores the number of elements currently in the queue.

The queue is empty when:

```cpp
Count == 0
```

The queue is full when:

```cpp
Count == 10
```

When the queue is initially empty:

```cpp
headpointer = -1;
```

After the first element is added, the head pointer is set to position `0`.

```cpp
if (headpointer == -1)
{
    headpointer = 0;
}
```

### Enqueue

A new value is stored at the position indicated by `tailpointer`.

```cpp
Queue[tailpointer] = value;
```

The tail pointer then moves to the next position:

```cpp
tailpointer = (tailpointer + 1) % 10;
Count++;
```

The modulo operator `%` allows the tail pointer to return to position `0` after reaching position `9`.

For example:

```text
Current tail position: 9
Next tail position: (9 + 1) % 10 = 0
```

This allows the queue to reuse empty positions at the beginning of the array.

### Dequeue

The value at the position indicated by `headpointer` is removed.

The head pointer then moves to the next position:

```cpp
headpointer = (headpointer + 1) % 10;
Count--;
```

The modulo operator also allows the head pointer to return to the beginning of the array after reaching the final position.

Unlike a stack, a queue removes values from the front rather than from the back.

### View Queue

The current queue values are displayed starting from the head position.

```cpp
for (int i = 0; i < Count; i++)
{
    int index = (headpointer + i) % 10;
    cout << Queue[index] << " ";
}
```

The position of each element is calculated using:

```cpp
int index = (headpointer + i) % 10;
```

This allows the display loop to correctly show the queue even when its values are stored across the end and beginning of the array.

## Circular Queue Behaviour

A circular queue reuses positions that become available after dequeue operations.

Suppose the queue contains:

```text
10 20 30 40
```

After two dequeue operations:

```text
30 40
```

The positions previously occupied by `10` and `20` become available.

When the tail pointer reaches the end of the array, it returns to the beginning and stores new values in those available positions.

For example:

```text
Array positions:

[60] [70] [30] [40] [50] [ ] [ ] [ ] [ ] [ ]
```

Although the values wrap around inside the array, the queue is displayed in the correct FIFO order:

```text
30 40 50 60 70
```

This prevents the wasted-space problem found in a linear queue.

## Compile and Run

Use a C++ compiler such as `g++`.

### Integer Circular Queue

```bash
g++ "Integer Circular Queue.cpp" -o integer_circular_queue
./integer_circular_queue
```

### Character Circular Queue

```bash
g++ "Character Circular Queue.cpp" -o character_circular_queue
./character_circular_queue
```

### String Circular Queue

```bash
g++ "String Circular Queue.cpp" -o string_circular_queue
./string_circular_queue
```

On Windows PowerShell, run the compiled program with:

```powershell
.\integer_circular_queue.exe
```

Replace the filename as needed for the other programs.

## Example

```text
|QUEUE menu|
Enter 1 if you want to ENQUEUE
Enter 2 if you want to DEQUEUE
Enter 3 if you want to view QUEUE
Enter 4 if you want to terminate program

1
Enter value you want to ENQUEUE
25

New values of Queue:
25
```

After adding more values:

```text
New values of Queue:
25 40 70
```

After one dequeue:

```text
25 was dequeued

New values of Queue:
40 70
```

When the tail reaches the end of the array, it returns to the beginning and continues using available positions.

## Time Complexity

| Operation  | Time complexity |
| ---------- | --------------- |
| Enqueue    | (O(1))          |
| Dequeue    | (O(1))          |
| View queue | (O(n))          |

Enqueue and dequeue update one array position, one pointer, and the element count.

Viewing the complete queue requires visiting every currently stored element.

## Current Limitations

* The queue capacity is fixed at ten elements.
* Similar code is repeated in the three programs.
* Menu input validation can be improved.
* The implementation uses global arrays and variables.

## Possible Future Improvements

* allow the user to select the queue size at runtime
* create a reusable circular queue class
* use C++ templates to support multiple data types
* improve invalid-input handling
* avoid using global variables
* compare the manual implementation with C++ STL containers

