#include <iostream>
#include "bit.h"

using namespace std;
int main(){
    bit_array a(100000);
    cout<< a.test_bit(10000) << endl;
    a.set_bit(10000);
    cout << a.test_bit(10000)  << endl;
    return 0;
}