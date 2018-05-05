# Most Recently Used Cache and Circular Buffer

## I. Most Recently Used Cache

A generic implementation of the Most Recently Used Cache using C++ 14. The algorithm policy is FIFO using hash map as auxiliary data structure. Time complexity: O(1)

## II. Circular Buffer

A generic implementation of the circular buffer using C++ 14. Some requirments are:

+ The exact starting location does not matter in a circular buffer.
+ If you write to a FULL CicularBuffer, then it starts overwriting the OLDEST data.
+ When an element is overwritten, the start pointer is incremented to the next element.

The underline data structure is a raw array, very efficient. It's thread-safe and exception-safe. Time complexity: O(1)


Please feel free to ask me if you have any questions.


Have fun,

Jerry Sun

Email:    jerysun007@hotmail.com

Website:  https://sites.google.com/site/geekssmallworld
