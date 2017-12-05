# Safe-String
Secure String class from CS 470

## completion time: 4 hours

## how does it work?
this program is a string class in C++ written from scratch, designed to be immune to memory injection.  This is accomplished by checking for
several corner cases.  The input buffer supports consumption of formatted input (just like regular cin) as well as support the getline() feature.

In order to ensure that no memory injection can occur from the input buffer, the string class automatically expands its buffer size by a factor
of 2 each time it runs out of space. This reduces the total amount of allocations to base2 log(n).
