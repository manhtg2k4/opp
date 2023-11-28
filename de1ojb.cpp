#include <iostream>
using namespace std;
class tinhtoan {
private:
    string chuoi;
public:
    tinhtoan(string& s) : chuoi(s) {}
    // nap chong tt ()
    int operator()() {
        int cost = 0;
        size_t i = 0, j = chuoi.length() - 1;

        while (i < j) {
            if (chuoi[i] != chuoi[j]) {
                cost++;
            }
            i++;
            j--;
        }
        return cost;
    }
};
int main() {
    string inputString;
    cout << "Nhap xau ban dau: ";
    cin >> inputString;
    tinhtoan calculator(inputString);
    int result = calculator();
    cout << "Chi phi toi uu de bien doi thanh xau doi xung: " << result +1 << endl;
    return 0;
}

