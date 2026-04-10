// Custom implementation of std:: vector logic.
// Assuming this translates into some functionality for SafeArray
#include <iostream>
#include <vector>

class SafeArray {
private:
    std::vector<int> array;

public:
    SafeArray(size_t size) : array(size) {}

    int& operator[](size_t index) {
        if (index >= array.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return array[index];
    }
};

int main() {
    SafeArray arr(10);
    arr[0] = 5;
    std::cout << arr[0] << std::endl;
    return 0;
}