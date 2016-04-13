System Squeeze
==============

### Purpose

I developed it on an Arduino platform, an Uno with an ATMega328 on it. The actual data structure code is not Arduino specific. However, the `ino` sketches serve as tests for the data structures.

Why did I choose a little Arduino and simple C? They provide constraints. C forces effective memory management, and only 2K of RAM enforces this even more.
Now, I have heard many embedded software developers say that using `malloc()` and `free()` is not a good practice on a microcontroller at run time, beause of the risk of memory leaks. But I went ahead and used dynamic memory anyway, because this is a programming exercise.

For the first round of simplicity, the data structures store only integers.

The code could have more robust error checks. BUt my main concern was watching the sketch output

### Directory structure

`shared`: The shared source code, among all Arduino sketches that test them.

`uno`: Arduino sketches that run the source code.

Each of these projects includes an Arduino sketch to test a plain C library.

Also, each of the directories in the the `shared/` directory will need to be copied into or symlinked into the Arduino libraries directory, whereever you have that on your system.

## Miscellaneous  functionality

`shared/MemoryMeter`: On an ATMega328, this code determines the amount of free heap space. I use it to print messages in the output of the sketches to inspect for memory leaks.

## Queue functionality

This operates a queue on top of a doubly linked list. The list has only functionality for operating the queue.

`shared/Queue` The queue code.

`uno/QueueUp` The Arduino code to test the queue. Watch the serial output log to check memory usage and operation.

## Stack functionality

`shared/Stack` The stack code.

`uno/StackOfNumbers`: The Arduino code to test the stack. Watch the serial output log to check memory usage and operation.

## Heap functionality

`shared/Heap` The stack code.

`uno/CompostHeap`: The Arduino code to test the heap. Watch the serial output log to check memory usage and operation.

