#include <iostream>
using namespace std;
class Rectangle {
private:
    double length;
    double width;
public:
    void setLength(double l) {
        if (l > 0)
            length = l;
        else
            cout << "Length must be positive." << endl;
    }
    void setWidth(double w) {
        if (w > 0)
            width = w;
        else
            cout << "Width must be positive." << endl;
    }
    double getLength() const {
        return length;
    }
   double getWidth() const {
        return width;
    }
    double calculateArea() const {
        return length * width;
    }
};
int main() {
    Rectangle rect;
    rect.setLength(15.5);
    rect.setWidth(3.25);
    cout << "Length: " << rect.getLength() << endl;
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Area: " << rect.calculateArea() << endl;
}
