// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	cout << 1;
	for (int i = m; i!= 1; i=(i+m-1)%n){
		if (i == 0) {
			i = n;
		}
		cout << i;
	}
	return 0;
}
