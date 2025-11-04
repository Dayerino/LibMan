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
    /*~BOOK(){

    }*/
};