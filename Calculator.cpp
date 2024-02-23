#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> toBinary(int digit);
std::vector<int> toDecimal(int digit);
void showBinary(std::vector<int> ans);
void showDecimal(std::vector<int> ans);

std::vector<int> ans1;
std::vector<int> ans2;

int main() {

    std::cout << "Binary and Decimal conversion calculator" << std::endl;
    std::cout << "Select conversion: 1 Decimal to Binary / 2 Binary to Decimal"
            << ' ' << "[1/2]" << std::endl;

    char input;
    std::cin >> input;
    int digit;

    std::cout << "Enter a number" << std::endl;
    std::cin >> digit;

    if (input == '1') {
        ans1 = toBinary(digit);
        showBinary(ans1);

    } else if (input == '2') {
        ans2 = toDecimal(digit);
        showDecimal(ans2);

    } else 
        std::cout << "Error!";

    return 0;
}

std::vector<int> toBinary(int digit) {
    for (;digit > 0;) {
        ans1.push_back(digit % 2);
        digit /= 2;
    }

    return ans1;
}

std::vector<int> toDecimal(int digit) {
    int result = 0;
    int power = 0;

    for (;digit > 0;) {
        int remainder = digit % 10;
        result += remainder * pow(2, power);
        digit /= 10;
        ++power;
    }

    std::vector<int> ans;
    for (;result > 0;) {
        ans.insert(ans.begin(), result % 10);
        result /= 10;
    }

    return ans;
}

void showBinary(std::vector<int> ans){
    std::cout << "Binary representation: ";

    for(int i = ans.size() - 1; i >= 0; --i)
        std::cout << ans[i];

    std::cout << std::endl;
}

void showDecimal(std::vector<int> ans) {
    std::cout << "Decimal representation: ";

    for (size_t i = 0; i < ans.size(); ++i)
        std::cout << ans[i];

    std::cout << std::endl;
}