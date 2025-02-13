# C++ Module 06 - Type Casting

This module explores the various type casting mechanisms available in C++98, focusing on their proper usage, safety features, and specific use cases. Understanding type casting is crucial for managing data type conversions and ensuring type safety in C++ programs.

## Overview

Type casting in C++ provides several mechanisms to convert data between different types:

1. **Static Cast (`static_cast`)**: The most straightforward casting mechanism, used for conversions between related types (like int to float, or up/down a class hierarchy).

2. **Reinterpret Cast (`reinterpret_cast`)**: Used for low-level reinterpreting of bit patterns, typically for converting between pointer types. This is the most dangerous form of casting.

3. **Dynamic Cast (`dynamic_cast`)**: Used for safe downcasting in inheritance hierarchies, with runtime type checking.

4. **Const Cast (`const_cast`)**: Used to remove or add const qualification from variables.

## Module Exercises

### Exercise 00: Scalar Type Conversion
- Implementation of a `ScalarConverter` class
- Static method for converting between fundamental data types
- Handling of special cases (inf, nan)
- Focus on proper type detection and conversion

### Exercise 01: Serialization
- Implementation of a `Serializer` class
- Converting pointers to integers and back
- Understanding memory representation
- Safe pointer handling

### Exercise 02: Real Type Identification
- Runtime type identification without RTTI
- Implementation of base and derived classes
- Dynamic type checking
- Pointer vs Reference behavior

## Technical Requirements

- Compile with C++98 standard
- Compile flags: `-Wall -Wextra -Werror`
- Each exercise must include a Makefile with the following rules:
  - `all`: Builds the program
  - `clean`: Removes object files
  - `fclean`: Removes object files and executable
  - `re`: Rebuilds the program

## Code Style Guidelines

- Follow Orthodox Canonical Class Form
- Proper header guards
- No using namespace declarations
- No external libraries except the Standard Library
- Memory leak-free code

## Learning Objectives

Upon completing this module, students will understand:
- The differences between C++ casting operators
- When to use each type of cast
- Type safety in C++
- Runtime type identification techniques
- Proper memory handling with pointers
- Serialization concepts

## Testing

Each exercise includes specific test cases to verify proper implementation. Students should:
- Test edge cases
- Verify proper memory management
- Ensure type safety
- Handle error cases gracefully

## References

- C++98 Standard Documentation
- Stroustrup, Bjarne. "The C++ Programming Language"
- School 42 Coding Standards

## Author

This module is part of the C++ modules created by School 42.