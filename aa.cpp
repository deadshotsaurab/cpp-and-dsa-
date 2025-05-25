#include <iostream>
using namespace std;
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal sound\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof\n";
    }
};

int main() {
    Animal* animals[2]; // Array of pointers to Animal

    Cat cat;
    Dog dog;

    animals[0] = &cat;
    animals[1] = &dog;

    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
    }

    return 0;
}
