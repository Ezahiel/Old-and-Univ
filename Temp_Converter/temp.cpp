#include <cstdlib>
#include <iostream>


using namespace std;
float t,b,c,d;
int s;
int main(int argc, char *argv[])
{

    cout<<"If you want to convert from Celsjus to Fahrenheit press 1"<<endl;
    cout<<"If you want to convert from Celsjus to Kelvin press 2"<<endl;
    cout<<"If you want to convert from Fahrenheit to Celsjus press 3"<<endl;
    cout<<"If you want to convert from Fahrenheit to Kelvin press 4"<<endl;
    cout<<"If you want to convert from Kelvin to Celsjus press 5"<<endl;
	cin>>s;
    cout<<"give temp"<<endl;
    cin>>t;
    switch(s)
    {   case 1:
        b=(t/5)*9+32;
        cout<<b"?F";
        break;
	case 2:
	d=t+273.15;
	cout<<d"?K";
	break;
		case 3:
		c=(t-32)/9*5;
		cout<<c"?C";
		break;
	case 4:
	d=(t-32)*5/9+273.15;
	cout<<d"?K";
	break;
			case 5:
			c=t-273.15;
			cout<<c"?C";
			break;
    }
    system("PAUSE");
return EXIT_SUCCESS;
}
