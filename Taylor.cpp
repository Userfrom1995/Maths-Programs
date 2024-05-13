#include <iostream>
#include <cmath>
#include <vector>
#define e = 2.71828;
using namespace std;

double df(double x , double y) {
    return 2*y + 3*pow(2.71828,x);
}

double ddf(double x , double y) {
    return 3*pow(2.71828,x) + 2*df(x,y);
}

double dddf(double x , double y) {
    return 3*pow(2.71828,x) + 2*ddf(x,y);
}

double ddddf(double x , double y) {
    return 3*pow(2.71828,x) + 2*dddf(x,y);
}

double dddddf(double x , double y) {
    return 3*pow(2.71828,x) + 2*ddddf(x,y);
}

void taylor(double x, double h, double x1,double y) {
double n = abs((x1 - x) / h);
 vector<double> taylor(n);
 taylor[0] = y;
for(int i = 0; i < n; i++) {
    
taylor[i] = taylor[i] + ((df(x,taylor[i])) * (h)) + (ddf(x,taylor[i])) * pow((h),2) / 2 + (dddf(x,taylor[i])) * pow((h),3) / 6 + (ddddf(x,taylor[i])) * pow((h),4) / 24 + (dddddf(x,taylor[i])) * pow((h),5)/ 120;
  x= x + h;
  cout << "value of x: " << x << "value of y: " << taylor[i] << endl;





}
}


int main() {


double x;
cout << "Enter the value of x given: ";
cin >> x;

double y;
cout << "Enter the value of y given: ";
cin >> y;

double h ;
cout << "Enter the value of h given: ";
cin >> h;

double x1;
cout << "Enter the value of x1 you want to find : ";
cin >> x1;


taylor(x,h,x1,y);


return 0;
}
