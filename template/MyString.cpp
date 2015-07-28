#include <iostream>
#include <cstring>
using namespace std;

class MyString{
public:
    MyString(char * data = NULL);
    MyString(const MyString & ms);
    ~MyString();
    MyString & operator=(const MyString & ms);
    //Accessors
    size_t size() const;
    const char * c_str() const;
    void print();
private:
    char * data_;
};

size_t MyString::size() const{
    return strlen(this->data_);
}

const char * MyString::c_str() const{
    return this->data_;
}

MyString::MyString(char * data){
    if(data == NULL){
        this->data_ = new char[1];
        this->data_[0] = '\0';
    }
    else{
        this->data_ = new char[strlen(data) + 1];
        strcpy(this->data_, data);
    }
}

MyString::MyString(const MyString & ms){
    this->data_ = new char[strlen(ms.data_) + 1];
    strcpy(this->data_, ms.data_);
}

MyString::~MyString(){
    delete[] this->data_;
}

MyString & MyString::operator=(const MyString & ms){
    /*
    //Method 1:
    if(this == &ms)
        return *this;
    delete[] this->data_;
    this->data_ = new char[strlen(ms.data_) + 1];
    strcpy(this->data_, ms.data_);
    return *this;
    */

    //Method 2:
    if(this != &ms){
        MyString tempStr(ms);   //copy constructor
        char * str = this->data_;
        this->data_ = tempStr.data_;
        tempStr.data_ = str;
    }
    return *this;
}

void MyString::print(){
    cout << this->data_;
}

// ====================测试代码====================
void Test1() {
    cout << "Test1 begins:" << endl;

    MyString str1("Hello world");
    MyString str2;
    str2 = str1;

    cout << "The expected result is: Hello world.\nThe actual result is: ";
    str2.print();
    cout << "." << endl;
}

// 赋值给自己
void Test2(){
    cout << "Test2 begins:" << endl;

    MyString str1("Hello world");
    str1 = str1;

    cout << "The expected result is: Hello world." << endl << "The actual result is: ";
    str1.print();
    cout << "." << endl;
}

// 连续赋值
void Test3(){
    cout << "Test3 begins:\n";
    char text[] = "Hello world";

    //MyString str1("Hello world");
    MyString str1(text);
    MyString str2, str3;
    str3 = str2 = str1;

    cout << "The expected result is: Hello world." << endl << "The actual result is: ";
    str2.print();
    cout << ".\n";

    cout << "The expected result is: Hello world.\nThe actual result is: ";
    str3.print();
    cout << ".\n";
}

int main(void){
    /*
    char * str = NULL;
    delete[] str;   //OK
    */
    Test1();
    cout << endl;
    Test2();
    cout << endl;
    Test3();
    return 0;
}

/*
lxw Desktop$ ./a.out 
Test1 begins:
The expected result is: Hello world.
The actual result is: Hello world.

Test2 begins:
The expected result is: Hello world.
The actual result is: Hello world.

Test3 begins:
The expected result is: Hello world.
The actual result is: Hello world.
The expected result is: Hello world.
The actual result is: Hello world.
*/
