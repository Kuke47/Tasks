#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int x, y, r;
    setlocale(LC_ALL, "Russian");
    ifstream input("файл1.txt");
    float ch;
    int Count = 0;
    while (input >> ch)
        Count++;
    //cout << "Чисел в файле : " << Count << endl;
    input.close();

    float* mass = new float[Count];
    ifstream file("файл1.txt");
    for (int i = 0; i < Count; i++) {
        file >> mass[i];
        //out << mass[i] << endl;
    }

    file.close();
    x = mass[0];
    y = mass[1];
    r = mass[2];

    ifstream input1("файл2.txt");
    string linn;
    Count = 0;
    while (getline(input1,linn))
        Count++;
    input1.close();

    int* xx = new int[Count];
    int* yy = new int[Count];
    ifstream file1("файл2.txt");
    for (int i = 0; i < Count; i++) {
        file1 >> xx[i];
        file1 >> yy[i];
        if (sqrt(pow(xx[i] - x, 2) + pow(yy[i] - y, 2)) == r) {
            cout << 0<<endl;
        }
        if (sqrt(pow(xx[i] - x, 2) + pow(yy[i] - y, 2)) > r) {
            cout << 2<<endl;
        }
        if (sqrt(pow(xx[i] - x, 2) + pow(yy[i] - y, 2)) < r) {
            cout << 1<<endl;
        }

       // cout << xx[i] << "      " << yy[i]<<endl;
    }
    file1.close();
    delete[] xx; delete[] yy;
    delete[]  mass;
    system("pause");
    return 0;
}