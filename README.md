# C++ Utility Library

## Overview

This library is a comprehensive collection of C++ classes designed to provide ready-to-use and efficient solutions for a wide range of common programming tasks. The library focuses on simplifying complex operations such as date manipulation, string processing, and the management of fundamental and advanced data structures.

The library is designed for easy integration and use, consisting of header-only files that can be directly included in your projects.

## Importance and Benefits

The significance of this library lies in the following points:

1.  **Accelerated Development:** Provides ready-made and tested classes for handling repetitive tasks (such as input validation or date operations), reducing the need to rewrite boilerplate code.
2.  **Code Organization:** Encapsulates complex functionalities within organized classes, which improves code readability and maintainability.
3.  **Custom Data Structures:** Offers implementations of essential data structures (like doubly linked lists and dynamic arrays) alongside specialized applications (such as queues and stacks), giving the developer flexibility in choosing the right tool.
4.  **Advanced Utilities:** Presents classes with unique functionalities, such as managing change history (Undo/Redo) and simulating a ticket queue system (`Queue Line`).

## Key Classes and Features

The library includes a set of core classes. The following table summarizes their importance and key features:

| Class | Description and Importance | Key Features |
| :--- | :--- | :--- |
| **`clsDate`** | A comprehensive class for date and time management. It allows for date calculations, validation, and formatting. | - Leap year check (`IsLeapYear`).<br>- Calculate number of days in a year/month.<br>- Date comparison (`IsDate1BeforeDate2`).<br>- Add days/weeks/months/years to a date.<br>- Print month and year calendars (`PrintMonthCalendar`, `PrintYearCalendar`). |
| **`clsString`** | A powerful class for string and text manipulation. It provides a wide range of functions for text processing and analysis. | - Case conversion (upper/lower, invert case).<br>- Splitting and joining strings (`Split`, `Join`).<br>- Trimming whitespace from ends (`TrimLeft`, `TrimRight`, `TrimString`).<br>- Counting capital letters, small letters, vowels, and words. |
| **`clsDblLinkedList`** | A template implementation of a Doubly Linked List. | - Insert and delete elements from the beginning and end.<br>- Search for an element (`Find`).<br>- Reverse the list order (`Reverse`).<br>- Get the list size (`Size`). |
| **`clsDynamicArray`** | A template implementation of a Dynamic Array. It allows for efficient resizing and element management. | - Array resizing (`ReSize`).<br>- Insert and delete elements at any position.<br>- Search for a value (`Find`).<br>- Reverse the order of elements (`Reverse`). |
| **`clsInputValidate`** | A static class for safely validating and reading user input. | - Read numbers and validate that they are within a specified range (`ReadNumberBetween`).<br>- Check if a date falls within a specified range (`IsDateBetween`).<br>- Safe reading of numbers and strings with input error handling. |
| **`clsMyQueue` / `clsMyStack`** | Implementations of the fundamental data structures (Queue and Stack) using the Doubly Linked List. | - Basic Queue operations: `push`, `pop`, `front`, `back`.<br>- Basic Stack operations: `push`, `pop`, `Top`, `Bottom`. |
| **`clsMyString`** | A specialized class for string management with support for Undo/Redo functionality. | - Stores current and previous values in stacks.<br>- `Undo` function to revert the last change.<br>- `Redo` function to reapply a change after undoing. |
| **`clsQueueLine`** | A class simulating a ticket queue system (e.g., for a bank or hospital). | - Issue a new ticket (`IssueTicket`).<br>- Serve the next client (`ServeNextClient`).<br>- Calculate the estimated waiting time.<br>- Display queue and ticket information. |

## Usage (Installation)

Since the library is header-only, it does not require a complex compilation process.

1.  **Copy Files:** Copy all `.h` files into your project folder.
2.  **Include:** Include the class you need in your source code files using the `#include` directive.

### Example Usage

```cpp
#include <iostream>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

int main() {
    // Example of clsDate usage
    clsDate Today = clsDate::GetSystemDate();
    cout << "Today's Date: " << Today.DateToString() << endl;
    cout << "Is Leap Year: " << (Today.IsLeapYear() ? "Yes" : "No") << endl;

    // Example of clsString usage
    clsString Text("hello world from cpp library");
    Text.UpperFirstLetterOfEachWord();
    cout << "Modified Text: " << Text.Value << endl; // Output: Hello World From Cpp Library

    return 0;
}
```

## Contribution

We welcome any contributions or suggestions to improve this library. Feel free to open a Pull Request or report an Issue on the GitHub repository.

---
