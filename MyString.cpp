#include "MyString.h"
#include <cstring>

MyString::MyString() : mBuf(nullptr), mSize(0) {}

MyString::MyString(const char *rhs) : mBuf(new char[strlen(rhs) + 1]), mSize(strlen(rhs)) {
    for (int i = 0; i < strlen(rhs); ++i) {
        mBuf[i] = rhs[i];
    }
}

MyString::MyString(const std::string &rhs) : mBuf(new char[rhs.size() + 1]), mSize(rhs.size()) {
    for (int i = 0; i < mSize; ++i) {
        mBuf[i] = rhs[i];
    }
}

MyString::MyString(const MyString &rhs) : mBuf(new char[rhs.mSize + 1]), mSize(rhs.mSize) {
    memcpy(mBuf, rhs.mBuf, mSize);
}

MyString::MyString(MyString &&rhs) : mBuf(std::move(rhs.mBuf)), mSize(std::move(rhs.mSize)) {}

MyString &MyString::operator=(const char *rhs) {
    delete[] mBuf;
    mSize = strlen(rhs);
    mBuf = new char[mSize + 1];
    strcpy(mBuf, rhs);
    return *this;
}

MyString &MyString::operator=(const std::string &rhs) {
    delete[] mBuf;
    mSize = rhs.size();
    mBuf = new char[mSize + 1];
    for (int i = 0; i < mSize; ++i) {
        mBuf[i] = rhs[i];
    }
    return *this;
}

MyString &MyString::operator=(const MyString &rhs) {
    if (this != &rhs) {
        delete[] mBuf;
        mSize = rhs.mSize;
        mBuf = new char[mSize + 1];
        strcpy(mBuf, rhs.mBuf);
    }
    return *this;
}

MyString &MyString::operator=(MyString &&rhs) {
    if (this != &rhs) {
        delete[] mBuf;
        mBuf = std::move(rhs.mBuf);
        mSize = std::move(rhs.mSize);
    }
    return *this;
}

MyString::~MyString() {
    delete[] mBuf;
    mBuf = nullptr;
}

int MyString::getSize() const {
    return mSize;
}

char *MyString::getBuf() const {
    return mBuf;
}

void MyString::setBuf(const char *rhs) {
    delete[] mBuf;
    mSize = strlen(rhs);
    mBuf = new char[mSize + 1];
    strcpy(mBuf, rhs);
}

void MyString::setBuf(const std::string &rhs) {
    delete[] mBuf;
    mSize = rhs.size();
    mBuf = new char[mSize + 1];
    for (int i = 0; i < mSize; ++i) {
        mBuf[i] = rhs[i];
    }
}

char MyString::operator[](int index) const {
    return mBuf[index];
}

std::ostream& operator<<(std::ostream &os, const MyString &mStr) {
    os << mStr.getBuf();
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const MyString& mStr) {
    for (int i = 0; i < mStr.getSize(); ++i) {
        ofs << mStr[i];
    }
    return ofs;
}

std::string operator+(std::string& str, const MyString& mStr) {
    std::string tmp = str;
    for (int i = 0; i < mStr.getSize(); ++i) {
        tmp.push_back(mStr[i]);
    }
    return tmp;
}

char* operator+(char* cPtr, const MyString& mStr) {
    std::size_t size1 = strlen(cPtr);
    std::size_t size2 = strlen(mStr.getBuf());
    char* result = new char[size1 + size2 + 1];
    strcpy(result, cPtr);
    strcat(result, mStr.getBuf());
    return result;
}