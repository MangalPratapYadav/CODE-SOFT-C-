#include <bits/stdc++.h>
using namespace std;
// Book class
class Book 
{
    public:
        string title;
        string author;
        string ISBN;
        bool isAvailable;
        // Constructor to initialize a book
        Book(string t, string a, string i)
            : title(t), author(a), ISBN(i), isAvailable(true) {}
        // Default constructor
        Book() : title(""), author(""), ISBN(""), isAvailable(true) {}
};
// Borrower class
class Borrower 
{
    public:
        string name;
        unordered_map<string, string> borrowedBooks;
        // Constructor to initialize a borrower
        Borrower(string n) : name(n) {}
        // Default constructor
        Borrower() : name("") {}
};
// Function to parse date in YYYY-MM-DD format
time_t parseDate(const string& date) 
{
    struct tm tm = {0};
    tm.tm_year = stoi(date.substr(0, 4)) - 1900;
    tm.tm_mon = stoi(date.substr(5, 2)) - 1;
    tm.tm_mday = stoi(date.substr(8, 2));
    return mktime(&tm);
}
// Function to calculate the difference in days between two dates
int calculateDaysDifference(time_t startDate, time_t endDate) 
{
    double seconds = difftime(endDate, startDate);
    return seconds / (60 * 60 * 24);
}
// Library class
class Library 
{
    private:
        vector<Book> books;
        unordered_map<string, Borrower> borrowers;
    public:
        // Function to add a book
        void addBook(string title, string author, string ISBN) 
        {
            books.emplace_back(title, author, ISBN);
            cout << "Book added: " << title << " by " << author << " (ISBN: " << ISBN << ")" << endl;
        }
        // Function to add a borrower
        void addBorrower(string name) 
        {
            borrowers.emplace(name, Borrower(name));
            cout << "Borrower added: " << name << endl;
        }
        // Function to search for a book
        void searchBook(string query) 
        {
            for (const auto& book : books) 
            {
                if (book.title == query || book.author == query || book.ISBN == query) 
                {
                    cout << "Found Book: " << book.title << " by " << book.author << " (ISBN: " << book.ISBN << "), Available: " << (book.isAvailable ? "Yes" : "No") << endl;
                    return;
                }
            }
            cout << "Book not found." << endl;
        }
        // Function to checkout a book
        void checkoutBook(string borrowerName, string ISBN) 
        {
            if (borrowers.find(borrowerName) == borrowers.end()) 
            {
                cout << "Borrower not found." << endl;
                return;
            }
            for (auto& book : books) 
            {
                if (book.ISBN == ISBN) 
                {
                    if (book.isAvailable) 
                    {
                        book.isAvailable = false;
                        string checkoutDate;
                        cout << "Enter checkout date (YYYY-MM-DD): ";
                        cin >> checkoutDate;
                        borrowers[borrowerName].borrowedBooks[ISBN] = checkoutDate;
                        cout << "Book checked out successfully." << endl;
                    } 
                    else 
                    {
                        cout << "Book is not available." << endl;
                    }
                    return;
                }
            }
            cout << "Book not found." << endl;
        }
        // Function to return a book
        void returnBook(string borrowerName, string ISBN) 
        {
            if (borrowers.find(borrowerName) == borrowers.end()) 
            {
                cout << "Borrower not found." << endl;
                return;
            }
            if (borrowers[borrowerName].borrowedBooks.find(ISBN) == borrowers[borrowerName].borrowedBooks.end()) 
            {
                cout << "This book was not borrowed by the borrower." << endl;
                return;
            }
            string returnDate;
            cout << "Enter return date (YYYY-MM-DD): ";
            cin >> returnDate;
            time_t checkoutTime = parseDate(borrowers[borrowerName].borrowedBooks[ISBN]);
            time_t returnTime = parseDate(returnDate);
            int daysBorrowed = calculateDaysDifference(checkoutTime, returnTime);
            cout << "Book is being returned after " << daysBorrowed << " days." << endl;
            if (daysBorrowed > 15) 
            {
                double fine = (daysBorrowed - 15) * 2.0;
                cout << "Fine for " << (daysBorrowed - 15) << " days overdue is: " << fine << " rupees." << endl;
            }
            for (auto& book : books) 
            {
                if (book.ISBN == ISBN) 
                {
                    book.isAvailable = true;
                    borrowers[borrowerName].borrowedBooks.erase(ISBN);
                    cout << "Book returned successfully." << endl;
                    return;
                }
            }
            cout << "Book not found." << endl;
        }
        // Function to display the menu
        void displayMenu() 
        {
            cout << "=============================  LIBRARY MANAGEMENT SYSTEM  =============================" << endl;
            cout << "1. Add Book" << endl;
            cout << "2. Add Borrower" << endl;
            cout << "3. Search Book" << endl;
            cout << "4. Checkout Book" << endl;
            cout << "5. Return Book" << endl;
            cout << "6. Exit" << endl;
            cout << "========================================================================================" << endl;
        }
        // Function to handle user input
        void handleUserInput() 
        {
            char choice;
            do 
            {
                displayMenu();
                cout << "Enter your choice: ";
                cin >> choice;

                string title, author, ISBN, name;
                switch (choice) 
                {
                    case '1':
                        cout << "Enter book title: ";
                        cin.ignore();
                        getline(cin, title);
                        cout << "Enter book author: ";
                        getline(cin, author);
                        cout << "Enter book ISBN: ";
                        getline(cin, ISBN);
                        addBook(title, author, ISBN);
                        break;
                    case '2':
                        cout << "Enter borrower name: ";
                        cin.ignore();
                        getline(cin, name);
                        addBorrower(name);
                        break;
                    case '3':
                        cout << "Enter book title/author/ISBN to search: ";
                        cin.ignore();
                        getline(cin, title);
                        searchBook(title);
                        break;
                    case '4':
                        cout << "Enter borrower name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter book ISBN to checkout: ";
                        getline(cin, ISBN);
                        checkoutBook(name, ISBN);
                        break;
                    case '5':
                        cout << "Enter borrower name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter book ISBN to return: ";
                        getline(cin, ISBN);
                        returnBook(name, ISBN);
                        break;
                    case '6':
                        cout << "Exiting... Thank you for using the Library Management System!" << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice != '6');
        }
};
int main() {
    Library library;
    library.handleUserInput();
    return 0;
}
