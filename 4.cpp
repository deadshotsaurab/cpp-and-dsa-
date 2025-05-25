#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h) {}

    // Method to calculate area
    double area() const {
        return width * height;
    }

    // Static method to compare areas of two rectangles
    static void compareArea(const Rectangle& r1, const Rectangle& r2) {
        if (r1.area() > r2.area()) {
            cout << "Rectangle 1 has a larger area." << endl;
        } else if (r1.area() < r2.area()) {
            cout << "Rectangle 2 has a larger area." << endl;
        } else {
            cout << "Both rectangles have the same area." << endl;
        }
    }
};

int main() {
	
    double width1, height1, width2, height2;

    // User input for first rectangle
    cout << "Enter dimensions of Rectangle 1 (width height): ";
    cin >> width1 >> height1;
    Rectangle rect1(width1, height1);

    // User input for second rectangle
    cout << "Enter dimensions of Rectangle 2 (width height): ";
    cin >> width2 >> height2;
    Rectangle rect2(width2, height2);

    // Compare the areas
    Rectangle::compareArea(rect1, rect2);
    return 0;
}

