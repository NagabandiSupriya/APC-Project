# Arbitrary Precision Calculator (APC)
📌 Overview

The Arbitrary Precision Calculator (APC) is a C-based application that performs arithmetic operations on very large integers that exceed the limits of standard C data types such as int and long long.
To overcome this limitation, the calculator uses doubly linked lists to represent numbers, allowing calculations on integers of any length, limited only by system memory.

This project demonstrates how fundamental data structures can be applied to solve real-world problems that are not possible using built-in data types alone.

✨ Features

🔢 Supports arbitrarily large integers

➕ Addition

➖ Subtraction

✖ Multiplication

➗ Division

🔗 Uses Doubly Linked Lists for number representation

⚠️ Validates command-line inputs

➖ Handles positive and negative numbers

🧹 Removes leading zeros automatically

🛠️ Technologies Used

Programming Language: C

Core Concepts:

Doubly Linked Lists

Dynamic Memory Allocation

Command Line Arguments

Modular Programming

🧠 How It Works

Numbers are provided as command-line arguments

Each digit of a number is stored in a node of a doubly linked list

Arithmetic operations are performed digit by digit

Results are stored in a separate linked list

Final output is displayed in a readable, color-coded format

▶️ Usage

Compile

gcc *.c -o apc

Run

./apc <operand1> <operator> <operand2>

Example

./apc 123456789123456789 + 987654321987654321

📂 Project Structure

APC/
 
├── main.c                          # Program entry point

├── addition.c                      # Addition logic

├── subtraction.c                   # Subtraction logic

├── multiplication.c                # Multiplication logic

├── division.c                      # Division logic

├── apc.h                           # Header file

