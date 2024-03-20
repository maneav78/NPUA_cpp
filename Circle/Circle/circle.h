#include <iostream>
using namespace std;

struct Point
{
    double x;
    double y;
};

class Circle
{
public:
    Circle(double, double, double);
    Circle(Circle&);
    ~Circle();

    double getR() const;
    void getCenter() const;
    void setParametrs(double, double, double);
    friend ostream& operator<<(ostream&, const Circle&);
    friend istream& operator>>(istream&, Circle&);
    bool operator==(const Circle&);
    bool operator!=(const Circle&);
    bool operator>(const Circle&);
    bool operator<(const Circle&);
    bool isPointOn(double, double);
    int countOfHatums(const Circle&);
    void tangentEquation(Point);
    double length() const;
    double area() const;
    double distanceOfCenters(const Circle&) const;
    void xParallelMoveing(double);
    void yParallelMoveing(double);
    void changeAreaByK(double); 

private:
    Point p;
    double r;
    int gcd(int a, int b) {
        int temp;
        while (b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

};
