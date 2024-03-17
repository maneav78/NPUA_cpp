#include <iostream>
using namespace std;


class Point
{
public:
    Point();
    Point(double, double);
    Point(const Point& ob);
    ~Point();
    double getX() const;
    double getY() const;
    void setXY(double, double);
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);
    int getQuater() const;
    bool operator==(const Point&) const;
    bool operator!=(const Point&);
    double distance(const Point&) const;
    double distanceFromZero() const;
    Point& xParallelMoveing(double);
    Point& yParallelMoveing(double);
    Point& operator=(const Point&);
private:
    double x;
    double y;
};