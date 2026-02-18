#include <iostream>
#include <vector>
#include <algorithm>

// Book class
class Book {
private:
    std::string title;
    std::string author;
    int pageCount;

public:
    Book(const std::string& title, const std::string& author, int pageCount)
        : title(title), author(author), pageCount(pageCount) {}

    // Getters
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPageCount() const { return pageCount; }

    // Setters
    void setTitle(const std::string& title) { this->title = title; }
    void setAuthor(const std::string& author) { this->author = author; }
    void setPageCount(int pageCount) { this->pageCount = pageCount; }

    // Display book information
    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Page count: " << pageCount << std::endl;
    }
};

// Bookshop class
class Bookshop {
private:
    std::vector<Book> books;

public:
    // Add a book to the bookshop
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Display all books in the bookshop
    void displayAllBooks() const {
        std::cout << "Books in the bookshop:" << std::endl;
        for (const auto& book : books) {
            book.displayBookInfo();
            std::cout << std::endl;
        }
    }

    // Modify a book's information
    void modifyBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(),
            [&](const Book& book) { return book.getTitle() == title; });

        if (it != books.end()) {
            std::cout << "Enter new title: ";
            std::string newTitle;
            std::getline(std::cin >> std::ws, newTitle);
            it->setTitle(newTitle);

            std::cout << "Enter new author: ";
            std::string newAuthor;
            std::getline(std::cin >> std::ws, newAuthor);
            it->setAuthor(newAuthor);

            std::cout << "Enter new page count: ";
            int newPageCount;
            std::cin >> newPageCount;
            it->setPageCount(newPageCount);

            std::cout << "Book modified successfully!" << std::endl;
        }
        else {
            std::cout << "Book not found!" << std::endl;
        }
    }

    // Delete a book from the bookshop
    void deleteBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(),
            [&](const Book& book) { return book.getTitle() == title; });

        if (it != books.end()) {
            books.erase(it);
            std::cout << "Book deleted successfully!" << std::endl;
        }
        else {
            std::cout << "Book not found!" << std::endl;
        }
    }
};

int main() {
    Bookshop bookshop;

    // Adding sample books
    Book book1("Book 1", "Author 1", 200);
    Book book2("Book 2", "Author 2", 300);
    Book book3("Book 3", "Author 3", 250);
    bookshop.addBook(book1);
    bookshop.addBook(book2);
    bookshop.addBook(book3);

    int choice;
    std::string title;

    while (true) {
        std::cout << "Bookshop Management System" << std::endl;
        std::cout << "1. Display all books" << std::endl;
        std::cout << "2. Add a book" << std::endl;
        std::cout << "3. Modify a book" << std::endl;
        std::cout << "4. Delete a book" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bookshop.displayAllBooks();
                break;
            case 2:
                {
                    std::cout << "Enter title: ";
                    std::cin.ignore();
                    std::getline(std::cin >> std::ws, title);

                    std::cout << "Enter author: ";
                    std::string author;
                    std::getline(std::cin >> std::ws, author);

                    std::cout << "Enter page count: ";
                    int pageCount;
                    std::cin >> pageCount;

                    Book newBook(title, author, pageCount);
                    bookshop.addBook(newBook);
                    std::cout << "Book added successfully!" << std::endl;
                }
                break;
            case 3:
                {
                    std::cout << "Enter title of the book to modify: ";
                    std::cin.ignore();
                    std::getline(std::cin >> std::ws, title);
                    bookshop.modifyBook(title);
                }
                break;
            case 4:
                {
                    std::cout << "Enter title of the book to delete: ";
                    std::cin.ignore();
                    std::getline(std::cin >> std::ws, title);
                    bookshop.deleteBook(title);
                }
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}