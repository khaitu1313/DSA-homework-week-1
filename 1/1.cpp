#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        this->title = NULL;
        this->authors = NULL;
        this->publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        setTitle(title);
        setAuthors(authors);
        setPublishingYear(publishingYear);
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        setTitle(book.getTitle());
        setAuthors(book.getAuthors());
        setPublishingYear(book.getPublishingYear());
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
        int n = strlen(title);
        this->title = new char[n];
        for(int i=0;i<n;i++){
            this->title[i] = title[i];
        }
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
        int n = strlen(authors);
        this->authors = new char[n];
        for(int i=0;i<n;i++){
            this->authors[i] = authors[i];
        }
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->publishingYear;
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

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main(){
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    Book book2 = book1;
    book2.printBook();
    return 0;
}