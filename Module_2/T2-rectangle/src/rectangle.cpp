/*
**Objective:** Practice use of I/O streams.

Implement function **Rectangle** that asks two values from standard
input, for the width and height of the rectangle (in floating point
format, double), and outputs the area and circumference of the rectangle.
Input and output should look exactly like the following:

Please enter width and height
2.5
3
Area: 7.5
Circumference: 11

In above, the second and third lines are entered by user, and other lines
are output by the system. User input can be any floating point numbers.
You should use the C++ **iostream** functions, not the traditional
C-style I/O. In the tests, the user inputs are randomly selected, so you
will need to actually calculate the area and circumference.
*/
#include "rectangle.hpp"

#include <iostream>

using namespace std;

void Rectangle() {
  double a = 0.0, b = 0.0;
  cout << "Please enter width and height" << endl;
  cin >> a >> b;
  cout << "Area: " << a * b << endl;
  cout << "Circumference: " << 2 * (a + b) << endl;
}
