

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
        ifstream input("file.txt");
        float ch;
        int Count = 0;
        while (input >> ch)
            Count++;
        cout << "Чисел в файле : " << Count << endl;
        input.close();

        float* mass = new float[Count];
        ifstream file("file.txt");
        int summ = 0;
        for (int i = 0; i < Count; i++) {
            file >> mass[i];
            summ += mass[i];
            //cout << mass[i] << endl;
        }
        summ /= Count;
        //cout << summ;
        int skolko_sprava=0;
        int skolko_sleva=0;
        for (int i = 0; i < Count; i++) {
            if (mass[i] > summ) {
                skolko_sprava++;
            }
            else {
                skolko_sleva++;
            }
        }
        
        if (skolko_sleva == skolko_sprava) {
            cout << summ;
        }
        else {
            while (skolko_sleva!= skolko_sprava) {
                
                if (skolko_sleva > skolko_sprava) {
                    summ--;
                    skolko_sleva = 0;
                    skolko_sprava = 0;
                    for (int i = 0; i < Count; i++) {
                        if (mass[i] > summ) {
                            skolko_sprava++;
                        }
                        else {
                            skolko_sleva++;
                        }
                    }
                    
                }
                else {
                    summ++;
                    //cout << summ;
                   // cout << summ<<endl;
                    skolko_sleva = 0;
                    skolko_sprava = 0;
                    for (int i = 0; i < Count; i++) {
                        if (mass[i] > summ) {
                            skolko_sprava++;
                        }
                        if(mass[i] < summ) {
                            skolko_sleva++;
                        }
                    }
                }
            }
            
        }
        int o = 0;
        for (int i = 0; i < Count; i++) {
            o = o + abs(mass[i] - summ);
        }
        cout <<endl<<summ<<endl<< o;


        delete[]  mass;
        system("pause");
        return 0;
    
}
