#include <iostream>

using namespace std;

int main() {
    freopen("DATA01.txt", "r", stdin);

    int a,b,c,d,e;
    for (int i = 0; i < 5; i++)
    {
	cin >> a >> b >> c >> d >> e;
	cout << (200*a+100*b+25*c+10*d+5*e) << endl;
    }
}
