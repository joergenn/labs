#include <iostream>
using namespace std;

void mltp(int f1, int f2, int mlt);
int length(int a);

int main(){
    int f1, f2, mlt;
    cin >> f1 >> f2 >> mlt;

    mltp(f1, f2, mlt);
    return 0;
}

void mltp(int f1, int f2, int mlt){
    int res1, res2, tmp, ten1 = 1, a, i, number = 0;
    
    int len_2 = length(f2);
    res1 = f1 * mlt;
    res2 = f2 * mlt;
    tmp = length(res2);

    // len_after = len_2;
    // len_before = length(tmp) - len_after;
    if(length(res2) != len_2){
        int *array = new int[tmp];

        for (i = 0; i < tmp; i++){
            a = res2 % 10;
            res2 /= 10;
            array[i] = a;
        }
        cout << endl;
        for (i = 0; i < tmp; i++){
            cout << array[i] << " ";
        }

        for (i = 0; i < len_2; i++){
            number += array[i] * ten1;
            ten1 *= 10;
        }
        res2 = number;
        
        ten1 = 1;
        number = 0;

        for (i = len_2; i < tmp; i++){
            number += array[i] * ten1;
            ten1 *= 10;
        }

        res1 += number;
        
        delete[] array; 
        array = nullptr;
    }
    cout << endl << "Res = " << res1 << "," << res2 << endl;
}

int length(int a){
    int i = 0;
    while (a > 0){
        a /= 10;
        i++;
    }
    return i;
}