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
2. Implement a **output** member function for **BigInt**, for displaying the big integer in the terminal
3. Implement a static member function named **add** for adding two **BigInt**.
4. Implement a static member function named **substract** for substracting one **BigInt** from another **BigInt**.

   
## Hints

The **main.cpp** provided in this repository tests the above member functions ...

```
 ds::BigInt a("1234567890123");
  ds::BigInt b("1567890123");

  a.output(); //this should display a's value: 1234567890123

  ds:BigInt r;
  ds::BigInt::add (a, b, r);

  r.output ();  //This should display 1236135780246

  ds:BigInt r2;
  ds::BigInt::subtract (a,b,r2);

  r2.output (); //This should display 123000000000
```

## Submission 

Submit your **BigInt.h**, **BigInt.cpp** file at the following link by March 8th, Friday, midnight (11:59pm). 

[Project1 submission link](https://storm.cis.fordham.edu:8443/web/project/1764)

The autograder compiles and tests your programs using some testcases that are different from those in **main.cpp**. If your program fails some testcases, go back to review your code, and test your member functions
with different inputs.
