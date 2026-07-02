# Linear Queue Implementation Notes

A beginner-friendly C++ project that demonstrates the **linear queue data structure** using fixed-size arrays.

The repository contains three separate queue programs:

* Integer Queue
* Character Queue
* String Queue

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

* **Queue overflow** when the array has no more available positions
* **Queue underflow** when the queue is empty

## Project Files

| File                  | Data type stored  |
| --------------------- | ----------------- |
| `Integer Queue.cpp`   | Integers          |
| `Character Queue.cpp` | Single characters |
| `String Queue.cpp`    | Strings           |

## How the Linear Queue Works

Each queue has a fixed capacity of ten elements.

Two pointers are used:

```cpp
int headpointer = -1;
int tailpointer = 0;
```

* `headpointer` points to the element at the front of the queue.
* `tailpointer` points to the next empty position at the back of the queue.

When the queue is empty:

```cpp
headpointer = -1;
```

### Enqueue

A new value is stored at the position indicated by `tailpointer`.

```cpp
Queue[tailpointer] = value;
tailpointer++;
```

When the first value is added, the head pointer is changed from `-1` to `0`.

```cpp
if (headpointer == -1)
{
    headpointer = 0;
}
```

### Dequeue

The value at the position indicated by `headpointer` is removed.

The head pointer then moves forward to the next value.

```cpp
headpointer++;
```

Unlike a stack, a queue removes values from the front rather than from the back.

### View Queue

The current queue values are displayed from the head position up to the tail position.

```cpp
for (int i = headpointer; i < tailpointer; i++)
{
    cout << Queue[i] << " ";
}
```

## Linear Queue Behaviour

This implementation is a **linear queue**, not a circular queue.

Suppose the queue has ten positions. After the tail pointer reaches the end of the array, no new values can be added, even if some values were removed from the front.

Example:

```text
Initial queue:
10 20 30 40

After two dequeue operations:
30 40
```

The positions previously used by `10` and `20` are now empty, but a linear queue does not move the tail pointer back to reuse them.

A circular queue solves this limitation by allowing the pointers to return to the beginning of the array.

## Compile and Run

Use a C++ compiler such as `g++`.

### Integer Queue

```bash
g++ "Integer Queue.cpp" -o integer_queue
./integer_queue
```

### Character Queue

```bash
g++ "Character Queue.cpp" -o character_queue
./character_queue
```

### String Queue

```bash
g++ "String Queue.cpp" -o string_queue
./string_queue
```

On Windows PowerShell, run the compiled program with:

```powershell
.\integer_queue.exe
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

## Time Complexity

| Operation  | Time complexity |
| ---------- | --------------- |
| Enqueue    | (O(1))          |
| Dequeue    | (O(1))          |
| View queue | (O(n))          |

Enqueue and dequeue only update one array position and one pointer.

Viewing the complete queue requires visiting every remaining element.

## Current Limitations

* The queue capacity is fixed at ten elements.
* Empty positions at the beginning of the array cannot be reused.
* The implementation is linear rather than circular.
* Similar code is repeated in the three programs.
* The empty state should be reset carefully after the final element is dequeued.

## Possible Future Improvements

* implement a circular queue
* reuse empty positions created by dequeue operations
* reset the head and tail pointers when the queue becomes empty
* allow the user to select the queue size at runtime
* create a reusable queue class
* use C++ templates to support multiple data types
* compare the manual implementation with the C++ STL `queue`

:::
