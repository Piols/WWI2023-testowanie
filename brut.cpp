#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    // int64_t to 64-bitowy int, czyli long long.
    int64_t wyn = 0;
    cin >> a >> b;
    /// b razy dodajemy do wyniku a.
    while(b--) {
        wyn += a;
    }
    cout << wyn;
}
