#include <iostream>
#include <math.h>

using namespace std;

double F(double x)
{
    if (x > 3 && x < 5)
        return asin(log10(x) / (x * x + 5 * x + 1)) - (pow(x, 3.2) / 28);

    if (x > -5 && x <= 3)
        return pow(x, -25);

    return pow(x, 2 / 3);
}

int main(int argc, char* argv[])
{
    cout << "Part 1\n";
    double a, b, h;

    if (argc < 3)
    {
        cout << "Not enough arguments. Please input values:/n";
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "h = ";
        cin >> h;
    }
    else
    {
        a = atof(argv[1]);
        b = atof(argv[2]);
        h = atof(argv[3]);
        cout << "a = " << a << "\nb = " << b << "\nh = " << h << endl;
    }

    cout << "\nResult:\n";

    for (double i = a; i <= b; i += h)
    {
        cout << "x = " << i << "\ty = " << F(i) << endl;
    }
}