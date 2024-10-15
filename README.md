# Mark and Sweep Garbage Collection

## Overview

This project implements a simple virtual machine (VM) with a mark-and-sweep garbage collection (GC) mechanism. The aim is to manage memory efficiently by automatically freeing objects that are no longer reachable or needed by the program.

## Garbage Collection Approach

Our approach in this VM is inspired by the tricolor marking concepts used in languages like Golang, though in a more simplified form. This implementation draws inspiration from the article: [Exploring the Inner Workings of Garbage Collection in Golang: Tricolor Mark and Sweep](https://medium.com/@souravchoudhary0306/exploring-the-inner-workings-of-garbage-collection-in-golang-tricolor-mark-and-sweep-e10eae164a12).

### Inspiration from Go's Tricolor GC

The Go language uses a sophisticated tricolor garbage collection strategy, which helps manage memory with minimal pause times. Our project reflects some core principles of this tricolor method:

1. **Mark Phase**: Detect potentially reachable objects and mark them.
2. **Trace using a gray stack**: Process objects queued for checking, which marks all referenced objects.
3. **Sweep Phase**: Remove objects not marked as reachable.

While Go's GC is concurrent and minimizes pause times, this implementation serves as a foundational step towards understanding such systems by focusing on basic reachability analysis and cleaning up.

## How It Works

### Mark Phase

1. **Initialization**: Objects are initially unmarked (akin to being "white").
2. **Root Identification**: All objects directly referenced by the VM are marked and pushed onto a gray stack, marking them as reachable.
3. **Mark All Reachables**: Recursively mark all objects reachable by the currently marked objects.

### Trace Phase

- Objects marked and pushed onto the gray stack are processed. As each object is popped, all references it holds are marked as well, simulating the transition from "gray" to "black."

### Sweep Phase

- Any objects that remain unmarked after tracing are considered unreachable and are collected.

## Project Structure

- **`vm.c`**: Contains functions that manage the VM lifecycle and GC process. It includes `vm_collect_garbage` which orchestrates the entire GC flow.
- **`snekobject.c`**: Defines the structure of objects and provides utility functions for object management.
- **`stack.c`**: Implements a simple stack used in maintaining our gray lists during the tracing process.

## Key Functions

- `mark()`: Identifies root objects in the VM's stack frames.
- `trace()`: Recursively marks all reachable objects.
- `sweep()`: Frees unmarked objects and resets marks on live objects.
- `vm_collect_garbage()`:

### Why Use C to Learn About Go's GC?

1. **Fundamental Concepts**: C allows us to implement the core concepts of garbage collection from scratch, providing a deep understanding of the underlying principles that Go's GC builds upon.

2. **Low-level Control**: By implementing GC in C, we gain insight into memory management at a lower level, which helps in appreciating Go's abstraction of these complex operations.

3. **Performance Implications**: Manually implementing GC helps us understand the performance trade-offs, which is crucial for optimizing Go programs.

## What We Learn

1. **Memory Management**: Understanding how automatic memory management works in programming languages, which is fundamental to both our C implementation and Go's GC.

2. **Garbage Collection Algorithms**: Deep dive into mark-and-sweep, one of the most common GC algorithms, providing insight into the foundations of Go's more advanced GC.

3. **Generational Hypothesis**: While our C implementation is simpler, it introduces the concept of tracking object lifetimes, which is key to Go's generational GC approach.

4. **Concurrent Collection**: Our implementation stops the world to collect garbage. This helps us appreciate Go's concurrent GC, which minimizes pause times.

5. **Root Finding**: The process of identifying root objects in our VM is similar to how Go identifies roots in goroutines and global variables.

6. **Memory Allocation**: Understanding object allocation in our VM provides insight into Go's allocation patterns and escape analysis.

7. **Write Barriers**: While not implemented in our basic version, understanding the need for write barriers in more advanced GC systems (like Go's) becomes clearer.

8. **GC Tuning**: The simple knobs in our implementation give a taste of the more advanced tuning options available in Go.

9. **C Programming**: Advanced use of structs, pointers, and memory allocation in C, which deepens our understanding of low-level memory management that Go abstracts away.

10. **Data Structures**: Implementation and use of stacks for managing objects and frames, similar to how Go manages its runtime structures.

11. **Algorithm Implementation**: Translating a conceptual algorithm into working code, a skill applicable to understanding Go's runtime implementation.

12. **Runtime Systems**: Insight into how language runtimes manage object lifecycles, which is crucial for efficient Go programming.

13. **Performance Considerations**: Understanding the trade-offs in garbage collection (like pause times vs. memory usage), which helps in optimizing Go applications.

By implementing this simpler GC in C, we gain a foundational understanding that makes it easier to grasp the more advanced concepts in Go's garbage collector. This knowledge ultimately leads to more efficient Go programming practices and a deeper appreciation of Go's runtime behavior.

