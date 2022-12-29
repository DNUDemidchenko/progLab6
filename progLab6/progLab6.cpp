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

double S(double x, int n)
{
    double sum = 0, num = 1, denom = 1;
    for (int i = 1; i <= n; i++)
    {
        num = 1; denom = 1;
        for (int j = 1; j <= i; j++)
        {
            num *= 2 * j - 1;
            denom *= 2 * j;
        }
        num *= pow(x, 2 * i + 1);
        denom *= 2 * i + 1;
        sum += num / denom;
    }
    return x + sum;
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

    cout << "\nPart 2:\n";

    double x, e;
    cout << "Input x from range (-1; 1)\n";
    cout << "x = ";
    cin >> x;
    cout << "Input accuracy\n";
    cout << "E = ";
    cin >> e;

    cout << "Sum of first 5 elements:\nS = " << S(x, 5) << endl;

    double s1 = S(x, 1);
    double s2 = S(x, 2);
    int count = 2;
    while (abs(s1 - s2) > e)
    {
        count++;
        s1 = s2;
        s2 = S(x, count);
    }
    cout << "Sum with accuracy " << e << ":\n";
    cout << "S = " << s2 << endl;
    cout << "Iterations made: " << count << endl;
    cout << "Using built in function:\narcsin(" << x << ") = " << asin(x) << endl;;
}