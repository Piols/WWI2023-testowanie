#include<bits/stdc++.h>
using namespace std;

int main() {
    int seed;
    cin >> seed;
    /// Deklaracja generatorki losowych liczb.
    /// mt19937 to typ, gen to nazwa (zmiennej) a seed w nawiasie inicjuje generatorke z tym ziarnem.
    /// mt19937 generuje losowe liczby 32-bitowe. Dla 64-bitow uzyc tak samo mt19937_64.
    mt19937 gen(seed);
    /// Aby wylosowac liczbe wystarczy napisac [nazwa]().
    int a = gen() % 50000 + 1, b = gen() % 50000 + 1;
    cout << a << " " << b;
}
