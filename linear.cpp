#include <iostream>

int main() {
    int n, target;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the target value to search: ";
    std::cin >> target;

    // Perform linear search
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            std::cout << "Element found at index " << i << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}

