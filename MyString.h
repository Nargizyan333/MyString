#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>
#include <iostream>
#include <fstream>

class MyString {
private:
    char* mBuf;
    int mSize;
public:
    MyString();
    MyString(const char* rhs);
    MyString(const std::string& rhs);
    MyString(const MyString& rhs);
    MyString(MyString&& rhs);
    MyString& operator=(const char* rhs);
    MyString& operator=(const std::string& rhs);
    MyString& operator=(const MyString& rhs);
    MyString& operator=(MyString&& rhs);
    ~MyString();
    int getSize() const;
    char* getBuf() const;
    void setBuf(const char* rhs);
    void setBuf(const std::string& rhs);
    char operator[](int index) const;
};

std::ostream& operator<<(std::ostream& os, const MyString& mStr);
std::ofstream& operator<<(std::ofstream& ofs, const MyString& mStr);
std::string operator+(std::string& str, const MyString& mStr);
char* operator+(char* cPtr, const MyString& mStr);

#endif