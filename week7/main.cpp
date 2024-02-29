#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<int> nums_to_test;
    int input = 1;
    while(input > 0) {
        cout << "Enter a positive, non zero integer to test, or enter a negative number to stop input: ";
        cin >> input;
        if(input > 0) {
            nums_to_test.push_back(input);
        }
    }

    // perfect number algorithm described here: https://cplusplus.com/forum/general/35319/
    for_each(nums_to_test.begin(), nums_to_test.end(), [](int &n) { 
        int sum = 1;
        for (int i = 2; i <= sqrt((double)n); i++) {
            if (n % i == 0) {
                sum += i + n / i;
            }
        }
        if (sum == n) {
            cout << n << " is a perfect integer." << endl;
        } else {
            cout << n << " is not a perfect integer." << endl;
        }
    });

    return 0;
}