#include <bits/stdc++.h>
using namespace std;

int z = 7;
int x;
int sum(){
    x = 5;
    return x + z;
}

int main(){
    x = 4;
    cout << sum() << '\n';
    cout << x;
}