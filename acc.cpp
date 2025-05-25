#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    // Constructor to initialize title, author, and price
    Book(const string& book_title, const string& book_author, double book_price) 
        : title(book_title), author(book_author), price(book_price) {
        cout << "Book \"" << title << "\" by " << author << " created with price $" << price << endl;
    }

    // Destructor to display a message when a Book object is deleted
    ~Book() {
        cout << "Book \"" << title << "\" by " << author << " is being deleted." << endl;
    }

    // Method to display book details
    void display_info() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    // Creating a Book object
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", 10.99);
    
    // Displaying the book details
    myBook.display_info();

    // The destructor will automatically be called when the object goes out of scope
    return 0;
}

