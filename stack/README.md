# Stack Implementation Notes

A beginner-friendly C++ project that demonstrates the **stack data structure** using fixed-size arrays.

The repository contains three separate stack programs:

* Integer Stack
* Character Stack
* String Stack

Each program follows the **LIFO** principle:

> Last In, First Out

This means the most recently added value is the first value removed.

## Features

Each program provides a menu for the following operations:

1. **Push** — add a value to the top of the stack
2. **Pop** — remove the most recently added value
3. **Peek** — display the value currently at the top
4. **View** — display all values stored in the stack
5. **Exit** — terminate the program

The programs also check for:

* **Stack overflow** when the stack is full
* **Stack underflow** when the stack is empty

## Project Files

| File                  | Data type stored  |
| --------------------- | ----------------- |
| `Integer Stack.cpp`   | Integers          |
| `Character Stack.cpp` | Single characters |
| `String Stack.cpp`    | Strings           |

## How the Stack Works

Each stack has a fixed capacity of five elements.

```cpp
int stackpointer = 0;
```

`stackpointer` points to the next empty position in the array.

### Push

A value is stored at the current position, and then the pointer moves forward.

```cpp
Stack[stackpointer] = value;
stackpointer++;
```

### Pop

The pointer moves back by one position, making the most recently added value the item that is removed.

```cpp
stackpointer--;
```

### Peek

The top value is found one position before the next empty slot.

```cpp
Stack[stackpointer - 1]
```

## Compile and Run

Use a C++ compiler such as `g++`.

### Integer Stack

```bash
g++ "Integer Stack.cpp" -o integer_stack
./integer_stack
```

### Character Stack

```bash
g++ "Character Stack.cpp" -o character_stack
./character_stack
```

### String Stack

```bash
g++ "String Stack.cpp" -o string_stack
./string_stack
```

On Windows, run the compiled program with:

```powershell
.\integer_stack.exe
```

Replace the filename as needed for the other programs.

## Example

```text
|STACK menu|
Enter 1 if you want to PUSH into stack
Enter 2 if you want to POP from stack
Enter 3 if you want to PEEK into stack
Enter 4 if you want to view the stack
Enter 5 if you want to terminate the program

1
Enter value you want to PUSH
25

New values of stack are:
25
```


## Current Limitations

* The stack capacity is fixed at five elements.
* Similar code is repeated in the three programs because each data type is implemented separately.

## Possible Future Improvements

* allow the user to choose the stack size at runtime
* create a reusable stack class
* use C++ templates to support multiple data types with one implementation


::: 
