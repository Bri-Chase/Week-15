// Brianna Chase
// CIS 1202 501
// Prof. Melissa Goodall
// December 8th, 2024

#include <iostream>
#include <cmath>
#include <type_traits>

// Templated function for half
template <typename T>
T half(T value) {
    if constexpr (std::is_floating_point<T>::value) {
        return value / 2.0;
    } else if constexpr (std::is_integral<T>::value) {
        return static_cast<T>(std::round(value / 2.0));
    } else {
        static_assert(std::is_arithmetic<T>::value, "Unsupported type for half function");
    }
}

// Driver function
int main() {
    // Test with integers
    int intVal = 5;
    std::cout << "Half of " << intVal << " is " << half(intVal) << std::endl;

    // Test with float
    float floatVal = 5.5f;
    std::cout << "Half of " << floatVal << " is " << half(floatVal) << std::endl;

    // Test with double
    double doubleVal = 10.25;
    std::cout << "Half of " << doubleVal << " is " << half(doubleVal) << std::endl;

    return 0;
}

