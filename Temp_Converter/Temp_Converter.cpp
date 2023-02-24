#include <cstdlib>
#include <iostream>
#include <cmath>

// b = Fahrenheit
// c = Celsjus
// d = Kelvin
// "\370" = degree char

using namespace std;
float t, b, c, d;
int s;
int main(int argc, char* argv[])
{

    cout << "If you want to convert from Celsjus to Fahrenheit press 1" << "\n";
    cout << "If you want to convert from Celsjus to Kelvin press 2" << "\n";
    cout << "If you want to convert from Fahrenheit to Celsjus press 3" << "\n";
    cout << "If you want to convert from Fahrenheit to Kelvin press 4" << "\n";
    cout << "If you want to convert from Kelvin to Celsjus press 5" << "\n";
    cout << "If you want to convert from Kelvin to Fahrenheit press 6" << "\n\n";
    cout << "Select option:: ";
    cin >> s; // option number
    cout << "\n";
    cout << "Give temperature:: " ;
    cin >> t; // temp number
    cout << "\n";
    switch (s)
    {
    case 1:
        b = (t / 5) * 9 + 32;
        cout << b <<"\370F"<<"\n\n"; //b is Fahrenheit temp
        break;
            case 2:
                d = t + 273.15;
                cout << d <<"\370K"<<"\n\n"; //d is Kelvin temp
                break;
                    case 3:
                        c = (t - 32) / 9 * 5;
                        cout << c <<"\370C"<<"\n\n"; //c is Celsjus temp
                        break;
                            case 4:
                                d = (t - 32) * 5 / 9 + 273.15;
                                cout << d <<"\370K"<<"\n\n";
                                break;
                                    case 5:
                                        c = t - 273.15;
                                        cout << c <<"\370C"<<"\n\n";
                                        break;
                                            case 6:
                                                b = (t - 273.15) * 9 / 5 + 32;
                                                cout << b <<"\370F"<<"\n\n";
                                                break;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}