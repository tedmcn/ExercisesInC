## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

A common feature in interpreted lanuages that is rare in compiled languages
is the support for dynamic variable typing.

2) Name two advantages of static typing over dynamic typing.

Using static typing helps ensure there are no bugs in the program regarding
typing because a staticly typed language will find the errors at compile time
rather than runtime. This means you don't need to enumerate the possible
patterns the code can follow to find the errors.

This also helps save space because you don't need to save the variable names
during runtime, the compiler abstracts them away when compiling.

3) Give an example of a static semantic error.

You would get a static semantic error if you try to pass a int to a function
that takes in a char*.

4) What are two reasons you might want to turn off code optimization?

You might want to turn it off because it will make your compiliation take a 
longer amount of time which is inifficient if you just want to test your code
while you are writing it. It also has the potential to change your bugs making
them harder to troubleshoot (if they exist).

5) When you run `gcc` with `-S`, why might the results look different on different computers?

The result will look different because the flag outputs the code into assembly.
Assembly code is machine specific so when C compiles into assembly it is
creating code specific to the hardware specs of the machine compiling it.

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?

The Linking stage of the compilation process is responsible for the names
and values of both functions and variables and therefor throws similar errors.

7) What is a segmentation fault?

This is an error you get when you attempt to read or write at an incorrect
location in memory.

## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

Banks create the illusion that they are currently holding all assets given to
them by investors and that any and everyone can withdraw all money they put
in the bank. In truth, the money isn't always there, it's moving through the
economy and will (hopefully) be there when someone wants to withdraw.

2) What is the difference between a program and a process?

A processes is a virtualized program. The two have a many-to-many relationship
where a program can have many processes and vice-versa, but the main difference
is the way that the OS treats the processes. They are given virtualized memory,
storage and hardware access. Processes think they are alone and have full
access to all resources. The main goal is to keep the isolated moving parts,
isolated.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

The goal of process abstraction is to keep multiple processes from accessing
the same resource at once. This would otherwise cause issues where process a
asks the wifi card (for example) a question, and the response is then sent to 
process b when they ask a question at the same time. The abstraction creates
the illusion, to the processes, that they have full access to all resources.

4) What is the kernel?

The kernel is responsible for very core OS operations such as creating threads,
memory management, device management, as well as system calls.

5) What is a daemon?
 
A daemon is a kind of background process that is waiting for a trigger to be
activated.

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

You would need 6 bits since 5 bits can represent 32 different letters and we need
one extra, so 6 bits of information.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

With 32 bits you can represent 1024*1024*1024*4 characters which calculates to
be 4,294,967,296

3) What is the difference between "memory" and "storage" as defined in Think OS?

Memory refers to volitle information storage such as in ram (as it loses all
information when it loses power). Storage is used to refer to more stable forms
of storage such as a Hard Disk or SSD.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB is a number with base 2. GB is base 10. GiB is a bit more accurate since in
computers we deal with binary frequently.

The percent difference between the two is about 7%.

5) How does the virtual memory system help isolate processes from each other?

The virtual memory helps keep processes isolated by adding a layer of abstraction
between the physical harware and the virtual hardware (ie virtual memory). The 
system keeps track of which processes can access which pieces of hardware or
memory, and it makes sure that no process can access a resource of another process
unless specifically instructed otherwise.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

This is because the stack and heap both need to grow dynamically. If they were in
the middle of the structure they would not be able to grow out if need be, this
way the stack or heap can expand if more memory is needed to be saved.

7) What Python data structure would you use to represent a sparse array?

I don't know python specifically, but it sounds like you can implement a sparse
array with a hashmap. With a hashmap, all values are 0 by default and all keys
are already "added" since it hashes the key to find the value. This would be 
efficient because all the hashmap wouldn't have to actually save all the 0's
for each value since it's the default value.

8) What is a context switch?

A context switch is when a given process is frozen, and then another process
is run in it's place. The first process can finished.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.
  
    Address of main is 0x40057d
    Address of global is 0x60104c
    Address of local is 0x7fff6a673ce4
    Address of p is 0x145b010
  
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  


    Address of main is 0x40057d
    Address of global is 0x60104c
    Address of local is 0x7ffd8e6b30ac
    Address of p is 0x1e47010
    Address of q is 0x1e470a0

    When running the code a second time I found the 2nd varible had a larger
    address.


2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

    5
    Address of main is 0x40057d
    Address of global is 0x60104c
    Address of local is 0x7ffcda4d4b2c
    Address of p is 0xc28010
    Address of q is 0xc280a0

    Accessing the value of a local variable make the stack grow downward.


3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

    Address of main is 0x40057d
    Address of global is 0x60104c
    Address of local is 0x7ffeec44c52c
    Address of p is 0x19d1010
    Address of q is 0x19d10a0
    Address of a is 0x19d11b0
    Address of b is 0x19d11d0

There are 32 bits between them or 2^(n+1)

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

File systems abstract away the fact that files are constructed of thousands of
tiny spaces in memory, not necisarrily all next to one another, and only show
to us the file neatly together, ready to read or write.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

OpenFileTableEntry would most likely have a portion of the file's text stored in
it, who has access to it, the file position, and perhaps a pointer to the
original file.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Caching is the process of keeping a memory of the most frequently
accessed queries and saving the solution instead of recalculating it. You can buffer
which is the process of waiting for the final change of a file to commit any changes.
The computer can also prefetch data it predicts it might need and finally it can
only transfer blocks of memory at a time as the time difference from writing
1 byte and 8KiB is negligible.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

An advantage of using FAT over an inode might be that the size of files can be 
more dynamic, because if a file only needs one block, the inode would still use
12 blocks, while the FAT system only needs one. 

However, it is more expensive to read the next block on a FAT system as you have
to follow a pointer instead of continuing down the physical memory.

6) What is overhead?  What is fragmentation?

Overhead is the cost of running, in this case, its the cost of an empty block.
We want the size of an empty block to be as near 0 as possible without sacrificing
any functionality.

Fragmentation is when you've allocated more blocks then necisarry and arn't using
the total. You have empty blocks.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

This is a good idea because it is technically true. There is nothing magical
about any given range of values in memory that happens to be a file, other than
the fact that somewhere else it has been defined to be "a file". The more you
can abstract away concepts like "files", the more all the different pieces of a
computer can work together.

It might be a bad way to think like this though because there are a lot of other
notions that come with the idea of a file, such as "a file has an owner", which 
does not necisarrily have to be true. It's not good because the meaning in the 
expression might get lost in the semantics of the word "file".

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
