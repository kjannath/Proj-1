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
3. Implement a **static** member function named **add** for adding two **BigInt**.
4. Implement a static member function named **subtract** for substracting one **BigInt** from another **BigInt**.

## Hints:
 1. Note that **BigInt** uses **SLList**'s public methods to manipulate the digits of the big integer. 
 2. It's much easier to implement **add** and **subtract** if you store the ones digit in 0th position of the **SLList**, and the 10th digit in 1th position...
    So that if you call **get(i)** on the **SLList** object, you retrieve the i-th digit (from the right) for the number. 
 4. When implementing **output**, you can first output the last digit in the **SLList** (which is the most significant digits), and then the second last digit, ... and output the first digit in the list last.
 5. Pseudocode for **add** as explained in class (March 5th) with more details:
    ```
    void add (const BigInt & a1, const BigInt & a2, BigInt & c)
    {
       //pseudocode for adding BigInt a, b, and save it to BigInt c 
       c = (a1.digits.size()>a2.digits.size())?a1:a2; //assign the one with more digits to c
    
       BigInt & d = (a1.digits.size()>a2.digits.size())?a2:a1;   //d is referring to the one with fewer digits,
           //no copy is being made here, d just referring to a2 or a1...
    
       carry=0
       int i=0; //pointing to which digit are we adding now

       while (i<d.length() || carry!=0) //This loop ends when we finish processing d's digits, and there is no carry any more
       {
          if (i<d.digits.size())  //not done with d yet ... 
              d1 = get i-th digit of d
          else
              d1 = 0 

          if (i<c.digits.size()) 
               d2 = get i-th digit of c
          else
               d2 = 0 
          sum = d1+d2+carry

          carry = sum/10
          sum = sum%10
          if (i < c.digits.size()) //c has i-th digit 
               set the i-th digit of c to sum //c.digits.get(i)=sum
          else
               add sum to the end of c.digits //using addBack member function of SLList

           i++  //move to the next digit 
       }
    

     }
    ```
   
## Requirement

Instead of specifying what constructors and member functions you need to implement, the **main.cpp** provided in this repository 
demonstrated how the **BigInt** class is used. **Please try your best to figure out what member functions are required, and what their
function signature should be from the user code. One example is commented below for a constructor:** 

```
  ds::BigInt a("1234567890123");
     //This implies that we should provide a constructor that takes a string as parameter
      //This constructor should initialize a to represent a big integer of value: 1234567890123
  ds::BigInt b("1567890123");

  a.output(); //this should display a's value: 1234567890123

  ds:BigInt r;
  ds::BigInt::add (a, b, r);

  r.output ();  //This should display 1236135780246

  ds:BigInt r2;
  ds::BigInt::subtract (a,b,r2);

  r2.output (); //This should display 123000000000
```

The **test.cpp** provides another more flexbile way to test your **BigInt** class: 
```
string input1,input2, op;

  cin >> op;
  cin >> input1;
  cin >> input2;

  ds::BigInt a(input1);
  ds::BigInt b(input2);

  if (op=="add")
  {
        ds::BigInt r;
        ds::BigInt::add (a, b, r);

        r.output ();
  }
  else if (op=="subtract")
  {
        //assume a>=b
        ds::BigInt r2;
        ds::BigInt::subtract (a,b,r2);

        r2.output ();
   }
```

## Style ##

The coding style part is worth 20 points. The rubrics for the style requirement is as follows: 

* Insufficient or no comments: -1 point (-2 max)
* Code not indented correctly: -1 point (-2 max)
* Redundant code: -1 point (-2 max)
* Overly complicated code: -1 point (-2 max)

## Submission 

Submit your **BigInt.h**, **BigInt.cpp** file at the following link by March 10th, Sunday, midnight (11:59pm). 

[Project1 submission link](https://storm.cis.fordham.edu:8443/web/project/1764)

The autograder compiles and tests your programs using the testcases listed in **testcases.txt**. You can find the expected output for each case in this file.



