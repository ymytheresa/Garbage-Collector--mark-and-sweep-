# Mark and Sweep Garbage Collection

## Overview

This project implements a mark and sweep garbage collection algorithm for a simple virtual machine (VM) in C. The mark and sweep algorithm is a fundamental technique used in memory management to automatically reclaim memory that is no longer in use by the program.

## How Mark and Sweep Works

The mark and sweep algorithm consists of three main phases:

1. **Mark**: Starting from the root objects (those directly accessible by the program), we traverse all reachable objects and mark them as "in use".

2. **Trace**: We follow references from the marked objects to find and mark all other reachable objects recursively.

3. **Sweep**: We iterate through all objects in memory, freeing those that are not marked and resetting the mark on the others for the next collection cycle.

## Key Components

- **Virtual Machine (VM)**: Represents our runtime environment, managing objects and stack frames.
- **Objects**: Various types (integers, floats, strings, vectors, arrays) that can be allocated in our VM.
- **Stack Frames**: Represent function calls or scopes, each containing references to objects.

## What We Learn

1. **Memory Management**: Understanding how automatic memory management works in programming languages.

2. **Garbage Collection Algorithms**: Deep dive into one of the most common GC algorithms.

3. **C Programming**: Advanced use of structs, pointers, and memory allocation in C.

4. **Data Structures**: Implementation and use of stacks for managing objects and frames.

5. **Algorithm Implementation**: Translating a conceptual algorithm into working code.

6. **Runtime Systems**: Insight into how language runtimes manage object lifecycles.

7. **Performance Considerations**: Understanding the trade-offs in garbage collection (like pause times vs. memory usage).

## Key Functions

- `mark()`: Identifies root objects in the VM's stack frames.
- `trace()`: Recursively marks all reachable objects.
- `sweep()`: Frees unmarked objects and resets marks on live objects.
- `vm_collect_garbage()`: