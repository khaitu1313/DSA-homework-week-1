#include <bits/stdc++.h> 
using namespace std;

class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
         this->title=nullptr;
         this->authors=nullptr;
         this->publishingYear=0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */

        int n = strlen(title);
        this->title = new char[n];
        for(int i=0;i<n;i++){
            this->title[i] = title[i];
        }

        int m = strlen(authors);
        this->authors = new char[m];
        for(int i=0;i<m;i++){
            this->authors[i] = authors[i];
        }

        this->publishingYear = publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] this->title;
        delete[] this->authors;
        this->publishingYear = 0;
    }

    friend class Printer;
};

class Printer
{
public:
    static void printBook(const Book book)
    {
        /*
         * STUDENT ANSWER
         */
        cout << book.title << endl;
        for(int i=0;i<strlen(book.authors);i++){
            if(book.authors[i] == ','){
                cout << endl;
                i+=2;
            }
            cout << book.authors[i];
        }
        cout << endl;
        cout << book.publishingYear;
    }
};

int main(){
    Book book1("Giai tich 1", "Nguyen Dinh Huy, Nguyen Thi Xuan Anh", 2000);
    Printer::printBook(book1);
    return 0;
}