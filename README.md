# Data Structures and Algorithms in C++

This repository documents my learning journey through **Data Structures and Algorithms (DSA)** using C++. Created as part of my personal learning journey in C++.
The goal is not only to write working programs, but also to understand how each data structure works, practise problem-solving, improve code quality, and keep a clear record of my progress.

## Current Progress

### Stack — Completed

I started my DSA journey by implementing the **Stack** data structure using fixed-size arrays.

I created separate stack programs for:

* Integer values
* Character values
* String values

Each stack program supports:

* Push
* Pop
* Peek
* View stack
* Stack overflow checking
* Stack underflow checking
* Menu-based user interaction

These programs follow the **LIFO** principle:

> Last In, First Out

This means the most recently added value is the first value removed.

---

### Linear Queue — Completed

After Stack, I implemented a basic **linear queue** using fixed-size arrays.

I created separate queue programs for:

* Integer values
* Character values
* String values

Each queue program supports:

* Enqueue
* Dequeue
* View queue
* Queue full checking
* Queue empty checking
* Menu-based user interaction

The queue uses two variables:

* `headpointer` to track the front element
* `tailpointer` to track the next empty position at the back

These programs follow the **FIFO** principle:

> First In, First Out

This means the first value added to the queue is the first value removed.

The current implementation is a **linear queue**, not a circular queue. Once the tail reaches the end of the array, previously emptied positions cannot be reused.

### Next Step

My next goal is to implement a **circular queue**, where empty positions created after dequeue operations can be reused.


## Repository Structure

```text
DSA/
├── stack/
│   ├── integer_stack.cpp
│   ├── character_stack.cpp
│   ├── string_stack.cpp
│   └── README.md
├── queue/
├── linked-list/
├── trees/
├── graphs/
├── LICENSE
└── README.md
```


## Learning Roadmap

| Topic              | Status              |
| ------------------ | ------------------- |
| Stack              | Completed           |
| Linear Queue       | Completed           |
| Circular Queue     |  Next               |
| Linked List        | Planned             |
| Trees              | Planned             |
| Graphs             | Planned             |
| Hashing            | Planned             |


## What I Am Learning

Through this repository, I am practising:

* arrays and pointers
* functions
* loops and conditional statements
* menu-driven programs
* stack overflow and underflow
* debugging and testing
* code organisation
* Git and GitHub workflow
