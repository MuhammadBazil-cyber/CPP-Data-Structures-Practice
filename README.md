# CPP-Data-Structures-Practice

# 📌 Project Overview
A custom C++ implementation of a dynamic array class that prioritizes Memory Safety and Robustness. Unlike standard C-style arrays, SafeArray includes built-in bound checking and handles manual memory management on the Heap using the RAII (Resource Acquisition Is Initialization) pattern.

# 🚀 Key Features
Bound Checking: Overloaded [] operator to prevent buffer overflows and segmentation faults.
Deep Copying: Custom Copy Constructor and Assignment Operator to ensure memory independence and prevent "Dangling Pointers."
Mathematical Support: Overloaded + and == operators for intuitive array manipulation.
Stream Integration: Friend function implementation for the << operator, allowing seamless cout printing.

# 🛠️ Technical Concepts Applied
Manual Memory Management: Utilization of new and delete[] keywords.
Operator Overloading: Customizing C++ syntax for user-defined classes.
Friend Functions: Managing private data access for external stream objects.
The 'this' Pointer: Ensuring precise object-level data manipulation.
