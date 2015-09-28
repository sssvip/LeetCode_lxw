// File: paraList.cpp
// Author: lxw
// Date: 2015-09-28
// Reference: http://www.douban.com/note/294704511/

/*
   构造函数初始化时必须采用初始化列表一共有三种情况，
   1.需要初始化的数据成员是对象(继承时调用基类构造函数)
   2.需要初始化const修饰的类成员
   3.需要初始化引用成员数据
   此例实现第一种情况！
   */
#include <iostream>
using namespace std;

class Point
{
    protected:
        int m_x, m_y;
    public:
        Point(int m = 0,int n = 0)	//此处设默认值比较好
        {
            m_x = m;
            m_y = n;
            printf("point constructor called\n");
        }
        Point(Point& p)	//拷贝构造
        {
            m_x = p.GetX();
            m_y = p.GetY();
            printf("point copy constructor called\n");
        }
        int GetX()
        {
            return m_x;
        }
        int GetY()
        {
            return m_y;
        }
};

class Point3d
{
    private:
        Point m_p;
        int m_z;

    public:
        Point3d(Point p,int k)
        {    	
            //m_p = p;
            m_z = k;
            cout<<"Point3d constructor called"<<endl;
        }
        Point3d(int i,int j,int k):m_p(i,j)
	    {
	        m_z = k;
	    }
        void Print()
        {
            printf("%d,%d,%d\n",m_p.GetX(),m_p.GetY(),m_z);
        }
};

int main()
{
    Point p(1,2);
    Point3d p3d(1,2,3);
    p3d.Print();

    Point3d p3d2(p,3);
    p3d2.Print();
    return 0;
}
