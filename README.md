# CISC 2200 Programming Project #1

In this project assignment, we practice **using ADT list**, **designing and implementing a class**, 
and **solving a real-world problem**.

## Provided code

The **ADTList** that we developed in class and lab2 are provided. You need to design and write the 
rest of the code. 

From your terminal (mac or WSL/Ubunto) window, you can use the following command to download it:
```
git clone https://github.com/CISC2200-Spring2024/proj1.git
```

## Programming Environment Setup
If you haven't done so already, please set up programming environment our our own computer, by following [Setup Tutorial](https://eecs280staff.github.io/tutorials/). 

- The _Commannd Line Tools_ are required. 

- The _C++ Dev Environment_ (VSCode) is highly recommened.

**Please follow these tutorials closely and carefully.**

## Requirements

Design a class named **BigInt** in a file named **BigInt.h**, implement the class methods in a file named **BigInt.cpp**,
and test the class in a file named **main.cpp**. 

Detailed requirements: 

1. The **BigInt** class represents a potential very large integer values, by storing its decimal digits in a list (using **SLList**). 
2. Implement  **output** member function for **BigInt**, for displaying the big integer in the terminal
3. Implement **add** static member function for adding two **BigInt** objects and returning the resulting value as a **BigInt**.
4. Implement **substract**  member function for substracting one **BigInt** from another, and return the result as a **BigInt**.

   
## Hints

The **main.cpp** provided in this repository tests the above member functions ...



## Submission 

Submit your **BigInt.h**, **BigInt.cpp** file at the following link by xxxxx midnight (11:59pm). The autograder compiles and tests your programs using 
some testcases that are different from those in **main.cpp**. If your program fails some testcases, go back to review your code, and test your member functions
with different inputs.
