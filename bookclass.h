#include "header.h"
class BOOK{
    private:
    std::string bookTitle;
    std::string bookAuthor;
    int bookID;
    public:
    void setBookTitle(std::string arg){
        this->bookTitle = arg;
    }
    void setBookAuthor(std::string arg){
        this->bookAuthor = arg;
    }
    void setBookID(int arg){
        this->bookID = arg;
    }
    std::string getBookTitle(){
        return this->bookTitle;
    }
    std::string getBookAuthor(){
        return this->bookAuthor;
    }
    int getBookID(){
        return this->bookID;
    }
    BOOK(){};
    BOOK(std::string bookTitle,std::string bookAuthor,int bookID){
        setBookTitle(bookTitle);
        setBookAuthor(bookAuthor);
        setBookID(bookID);
    }
    //equality operator for comparison
    bool operator==(const BOOK&other)const{
        return this->bookID == other.bookID;
    }
    /*~BOOK(){

    }*/
};
/* ALTERNATE CLASS LAYOUT, internal data/state is hidden, users of the class interact using the behavior of the functions, not the data itself
class BOOK {
private:
    std::string bookTitle;
    std::string bookAuthor;
    int bookID;

public:
    BOOK(const std::string& title, const std::string& author, int id)
        : bookTitle(title), bookAuthor(author), bookID(id) {} << no need for setters

    BOOK() = default;

    void printDetails() const {
        std::cout << "Title: " << bookTitle << "\n"
                  << "Author: " << bookAuthor << "\n"
                  << "ID: " << bookID << std::endl;
    } this is an example of a function which removes the need for getters
    the following functions are examples of modifying private elements without exposing the data
    void changeName(const std::string& newTitle) {
        bookTitle = newTitle;
    }

    void changeAuthor(const std::string& newAuthor) {
        bookAuthor = newAuthor;
    }

    void changeID(int newID) {
        bookID = newID;
    }*/