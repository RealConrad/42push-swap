<div align="center">
<h1>
    <p>
        📗 Push Swap
    </p>
</h1>
<p>
    <b><i>A simple sorting algorithm that sorts stacks in ascending order.</i></b>
</p>
<p>
    Coded in&nbsp&nbsp
    <a href="https://skillicons.dev">
        <img src="https://skillicons.dev/icons?i=c,vscode,git" />
    </a>
</p>
</div>
<br />

## Table Of Contents
- [Features](#features)
- [Rules](#rules)
- [Installation](#installation)
- [Examples](#examples)
- [Tools](#tools)
- [License](#license)

## Features
> Disclaimer: While my implementation of push_swap is functional, it will not achieve 100% for the project
- **Sorting Capability:** The program is capable of sorting stacks in ascending order.
- **Scalability:** It can handle an unlimited number of inputs, making it adaptable to various use cases and data sizes. However it does become slower/more inefficent with more numbers.
- **Error Handling:** The program is designed to manage errors and incorrect inputs effectively. It also frees up resources accordingly to prevent memory leaks.
- **Memory Management:** The program is careful in its memory management, ensuring that all allocated memory is correctly freed, thereby preventing any potential memory leaks.
- **Documentation:** All functions are thoroughly documented using Doxygen comments. Additionally, the code is supplemented with comments to enhance readability and facilitate easier understanding of the underlying logic.

## Rules
1. You have 2 stacks named a and b.
    - At the beginning:
        - The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
        - The stack b is empty.
2. The following operations at your disposal:

| Operation | Description |
| --- | --- |
| `sa` (swap a) | Swap the first 2 elements at the top of stack a. Does nothing if there is only one or no elements. |
| `sb` (swap b) | Swap the first 2 elements at the top of stack b. Does nothing if there is only one or no elements. |
| `ss` | Executes `sa` and `sb` at the same time. |
| `pa` (push a) | Takes the first element at the top of stack b and puts it at the top of stack a. Does nothing if stack b is empty. |
| `pb` (push b) | Takes the first element at the top of stack a and puts it at the top of stack b. Does nothing if stack a is empty. |
| `ra` (rotate a) | Shifts up all elements of stack a by 1. The first element becomes the last one. |
| `rb` (rotate b) | Shifts up all elements of stack b by 1. The first element becomes the last one. |
| `rr` | Executes `ra` and `rb` at the same time. |
| `rra` (reverse rotate a) | Shifts down all elements of stack a by 1. The last element becomes the first one. |
| `rrb` (reverse rotate b) | Shifts down all elements of stack b by 1. The last element becomes the first one. |
| `rrr` | Executes `rra` and `rrb` at the same time. |

## Installation
1. Clone the repository:
```shell
git clone https://github.com/RealConrad/42push-swap.git
```
2. Enter the directory:
```shell
cd 42push-swap
```
3. Build the library
> NOTE: This will clone the following directory automatically (https://github.com/RealConrad/42c-library.git)
```shell
make
```

## Examples
Once the 
