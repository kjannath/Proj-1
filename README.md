# CISC 2200 Programming Project #1

In this project assignment, we practice **using `std::vector`**, **designing and implementing a class**, and **solving a real-world problem**.

## Provided code

From your terminal (mac or WSL/Ubunto) window, you can use the following command to download the repo:

```
git clone https://github.com/CISC2200-Fall-24-Fordham/Proj-1.git
```

## Programming Environment Setup

If you haven't done so already, please set up programming environment our our own computer, by following [Setup Tutorial](https://eecs280staff.github.io/tutorials/).

- The _Commannd Line Tools_ are required.

- The _C++ Dev Environment_ (VSCode) is highly recommened.

**Please follow these tutorials closely and carefully.**

## Requirements

Implement the methods outlined with `TODO` markings in the code comments:

1. The **BigInt** class represents a potential very large integer values, by storing its decimal digits in a list (using **`std::vector`**).
2. Implement a **output** member function for **BigInt**, for displaying the big integer in the terminal
3. Implement the **static** member function named **add** for adding two **BigInt**.
4. Implement the static member function named **subtract** for subtracting one **BigInt** from another **BigInt**
5. Implement the `*` operator for extra credit.

## Hints

 1. Note that **BigInt** uses **`std::vector`**'s public methods to manipulate the digits of the big integer.
 2. It's much easier to implement **add** and **subtract** if you store the ones digit in 0th position of the **`std::vector`**, and the 10th digit in 1th position...
    So that if you call **get(i)** on the **`std::vector`** object, you retrieve the i-th digit (from the right) for the number.
 4. When implementing **output**, you can first output the last digit in the **`std::vector`** (which is the most significant digits), and then the second last digit, ... and output the first digit in the list last.
 5. Pseudocode for **add**:

```c++
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

**BigInt.h** has some template code to get you started to make working with the autograder as easy as possible. Feel free to make any modifications you see fit.

**main.cpp** is provided as a simple set of tests to you can verify your code works with:

```bash
make clean
make main.out
./main.out
```

The **test.cpp** provides another more flexbile way to test your **BigInt** class.
Make sure to type in some example testcases from `testcases.txt` to verify your code works.

Run the code in **test.cpp** with:

```bash
make clean
make test.out
./test.out
```

> [!NOTE]
> Your code may appear to hang / not output anything. This is because it is waiting for your input!

## Style

The coding style part is worth 20 points. The rubrics for the style requirement is as follows:

- Insufficient or no comments: -1 point (-2 max)
- Code not indented correctly: -1 point (-2 max)
- Redundant code: -1 point (-2 max)
- Overly complicated code: -1 point (-2 max)

### `make check`

In your `Makefile`, I have added support for `make check` which helps give you friendly suggestions.

Feel free to ignore them, however I find that these suggestions help simplify and clarify my code, so I suggest you run this as you are developing as well.

## Submission

Submit your **BigInt.h** file at the following link:

[Project1 submission link](https://storm.cis.fordham.edu:8443/web/project/1949)

The autograder compiles and tests your programs using the testcases listed in **testcases.txt**. You can find the expected output for each case in this file.
