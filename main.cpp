// Brianna Chase
// CIS 1202 501
// Prof. Melissa Goodall
// December 8th, 2024

#include <iostream>
#include <stdexcept>

// Custom exceptions
class invalidCharacterException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid start character. Start must be a letter (A-Z or a-z).";
    }
};

class invalidRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid range. Resulting character is not a valid letter.";
    }
};

// Function prototype
char character(char start, int offset) {
    // Check if the start character is a letter
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }

    // Calculate the target character
    char target = start + offset;

    // Validate that the target remains within the same case
    if ((start >= 'A' && start <= 'Z' && (target < 'A' || target > 'Z')) ||
        (start >= 'a' && start <= 'z' && (target < 'a' || target > 'z'))) {
        throw invalidRangeException();
    }

    return target;
}

// Driver function
int main() {
    // Test cases
    try {
        std::cout << "character('a', 1) = " << character('a', 1) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        std::cout << "character('a', -1) = ";
        std::cout << character('a', -1) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        std::cout << "character('Z', -1) = " << character('Z', -1) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        std::cout << "character('?', 5) = ";
        std::cout << character('?', 5) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        std::cout << "character('A', 32) = ";
        std::cout << character('A', 32) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
