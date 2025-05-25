#include <iostream>
#include <memory>
using namespace std;

// Base class
class Animal {
public:
    virtual void make_sound() const = 0;  // Pure virtual function
};

// Derived class: Dog
class Dog : public Animal {
public:
    void make_sound() const override {
        cout << "Bark!" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    void make_sound() const override {
        cout << "Meow!" << endl;
    }
};

int main() {
    unique_ptr<Animal> animal;
    int choice;

    cout << "Choose an animal: (1) Dog, (2) Cat: ";
    cin >> choice;

    if (choice == 1) {
        animal = make_unique<Dog>();
    } else if (choice == 2) {
        animal = make_unique<Cat>();
    } else {
        cout << "Invalid choice!" << endl;
        return 1;  // Exit the program with an error
    }

    // Call the make_sound method based on user choice
    animal->make_sound();

    return 0;
}
