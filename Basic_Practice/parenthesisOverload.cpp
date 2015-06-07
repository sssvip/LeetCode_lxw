// File: parenthesisOverload.cpp
// Author: lxw
// Date: 2015-06-07
// Usage: Operator Overload.

#include <iostream>
using namespace std;

class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h=0, int m=0, int s=0) {
        operator()(h, m, s);
    }

    //版本0，返回时间表示的秒数
    int operator()() {
        return hour*3600+minute*60+second;
    }

    //版本1，设置为整点
    void operator()(int h) {
        operator()(h, 0, 0);
    }

    //版本2，设置整小时和分钟
    void operator()(int h, int m) {
        operator()(h, m, 0);
    }

    //版本3，设置时分秒
    void operator()(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    friend ostream& operator<<(ostream& os, const Time& ct) {
        if(ct.hour < 10)
            os << '0';
        os << ct.hour << ':';

        if(ct.minute < 10)
            os << '0';
        os << ct.minute << ':';

        if(ct.second < 10)
            os << '0';
        os << ct.second;;
        return os;
    }
};

int main() {
    Time t;
    cout << t << endl;  //00:00:00
    t(9);           //09:00:00
    cout << t << endl;

    t(7, 30);       //07:30:00
    cout << t << endl;

    t(0, 10, 20);   //00:10:20
    cout << t << endl;

    cout << t() << endl;    // 0 * 3600 + 10 * 60 + 20
    return 0;
}
