# Blood Type Inheritance Simulator

## Description
This C program simulates the inheritance of blood types across three generations of a family tree. It demonstrates how blood type alleles are passed down from grandparents to parents to children, following biological inheritance patterns.

## Features
- Creates a family tree data structure using dynamic memory allocation
- Simulates random inheritance of blood type alleles (A, B, O)
- Visualizes family relationships across three generations
- Implements recursive algorithms for tree creation and traversal
- Properly manages memory to prevent leaks

## How It Works
The program:
1. Creates a family tree with three generations
2. Randomly assigns blood types to grandparents
3. Simulates inheritance for subsequent generations
4. Prints the family tree with blood types
5. Frees all allocated memory

## Usage
```
$ make inheritance
$ ./inheritance
```
## Example Output
Child (Generation 0): blood type AO
Parent (Generation 1): blood type AB
Grandparent (Generation 2): blood type OA
Grandparent (Generation 2): blood type BB
Parent (Generation 1): blood type AO
Grandparent (Generation 2): blood type AA
Grandparent (Generation 2): blood type OA

## Dependencies
### #include <stdio.h>
### #include <stdlib.h>
### #include <time.h>

## Academic Honesty
This project is part of Harvard's CS50 coursework. Please follow the course's academic honesty guidelines.

