#include <iostream>
#include <memory> // For smart pointers

// Base class
class Animal {
public:
    // Virtual function to be overridden in derived classes
    virtual void make_sound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }

    // Virtual destructor to allow proper cleanup of derived objects
    virtual ~Animal() {}
};

// Derived class Dog
class Dog : public Animal {
public:
    // Override make_sound() for Dog
    void make_sound() const override {
        std::cout << "Woof Woof!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Override make_sound() for Cat
    void make_sound() const override {
        std::cout << "Meow Meow!" << std::endl;
    }
};

int main() {
    std::unique_ptr<Animal> animal;  // Smart pointer for automatic memory management
    int choice;

    std::cout << "Choose an animal:\n";
    std::cout << "1. Dog\n";
    std::cout << "2. Cat\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Based on the user input, create the appropriate animal object
    switch (choice) {
        case 1:
            animal = std::make_unique<Dog>();
            break;
        case 2:
            animal = std::make_unique<Cat>();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            return 1;
    }

    // Call the make_sound method for the chosen animal
    animal->make_sound();

    return 0;
}
