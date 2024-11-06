#include <iostream>

using namespace std;

void Countdown(int i) {
    cout << i;
    if (i <= 1) {
        cout << endl;
        return;
    } else {
        cout << "..."sv;
        Countdown(i - 1);
    }
}

int main() {
    Countdown(1000);
}