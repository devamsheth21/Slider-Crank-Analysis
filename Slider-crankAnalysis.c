#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using std::showpoint;
int main() {
	double a, b, e, w1, theta, beta,acc1,accs,acc2,w2,vs,d, c1,c2,c3,c4,pi = 3.14159, incr;
	int cont = 1, choice1;
	cout << "Slider-Crank Analysis\n";
	//cout << "by Tony Scarcia (2019)\n";
	cout << "Given the input angle, the output position, angular velocities and accelerations are calculated\n\n";
	while (cont) {
		cout << fixed;
		cout << "Slider-Crank Geometry" << endl;
		// define geometry here
		e = 0;
		a = 5;
		b = 10;
		w1 = -2;
		cout << "e = " << setprecision(1) << e << endl;
		cout << "a = " << setprecision(1) << a << endl;
		cout << "b = " << setprecision(1) << b << endl;
		cout << "w1 = " << setprecision(1) << w1 << endl;
		cout << "Change geometry?" << endl;
		cout << "Press 1 to change, 0 to to continue with these values :";
		cin >> choice1;
		while (choice1) {
			cout << "e: "; cin >> e;
			cout << "a: "; cin >> a;
			cout << "b: "; cin >> b;
			cout << "w1: "; cin >> w1;
			choice1 = 0;
		}
		cout << "Enter increment for theta: ";
		cin >> incr;
		while (incr < 0.1) {
			cout << "Enter value greater than or equal to 0.1" << endl;
			cin >> incr;
		}
		cout << "theta increment = " << setprecision(1) << incr << endl;
		cout << endl;
		// output the table headings here
		cout << "theta	beta	  d	omega2	 ddot	  a2	ddotdot" << endl;
		cout << "------	------	------	------	------	------	--------" << endl;
		for (theta = 0; theta <= 360; theta += incr) {
			// here are the kinematic equations
			beta = asin((a - e * sin(theta * pi / 180)) / b) * 180 / pi;
			d = a * cos(theta * pi / 180) + b * cos(beta * pi / 180);
			w2 = -(w1 * a * cos(theta * pi / 180)) / (b * cos(beta * pi / 180));
			vs = -a * w1 * sin((theta - beta)*pi / 180) / (cos(beta * pi/180) * 1000 )
			c1 = a * acc1 * sin((beta - theta)*pi/180) - b * pow(w2,2);
			c2 = a * pow(w1,2) * cos(beta - theta);
			c3 = a * acc1 * cos(teta) - a * pow(w1,2) * sin(theta);
			c4 = b * pow(w2,2) * sin(beta)
			//ddot = (w1 * a * sin((beta - theta) * pi / 180))/(b * cos(beta * pi / 180));
			acc2 = -(c3 - c4) / b * cos(beta * pi / 180) ;
			accs =
			ddotdot = -(a2 * b * sin(beta * pi / 180) + pow(w1, 2) * a * cos(theta * pi / 180) + pow(w2, 2) * b * cos(theta * pi / 180));
			// output the table data here
			cout << setw(6) << setprecision(1) << theta << setw(8) << setprecision(2) << beta << setw(8) << setprecision(2) << d << setw(8) << setprecision(2) << w2 << setw(8) << setprecision(2) << ddot << setw(8) << setprecision(2) << a2 << setw(10) << setprecision(2) << ddotdot << endl;
		}
	cout << endl << "Press 1 to Continue, 0 to to Quit" << endl;
	cin >> cont;
	}
}
