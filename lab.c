#include <iostream>
#include <string>
#include <iomanip>

double extractNumeric(const std::string& input) {
    bool hasDecimal = false;
    bool hasSign = false;
    int length = input.length();

    double result = 0.0;
    double fraction = 0.1;
    bool isNegative = false;
    int i = 0;

    if (input[i] == '+' || input[i] == '-') {
        hasSign = true;
        isNegative = (input[i] == '-');
        i++;
    }

    if (i >= length) return -999999.99;

    for (; i < length; ++i) {
        char ch = input[i];
        if (ch >= '0' && ch <= '9') {
            if (!hasDecimal) {
                result = result * 10 + (ch - '0');
            } else {
                result += (ch - '0') * fraction;
                fraction *= 0.1;
            }
        } else if (ch == '.' && !hasDecimal) {
            hasDecimal = true;
        } else {
            return -999999.99;
        }
    }

    if (isNegative) result = -result;
    return result;
}

// Main function
int main() {
    std::string input;
    while (true) {
        std::cout << "Enter a string (or 'X' to quit): ";
        std::getline(std::cin, input);

        if (input == "X") break;

        double value = extractNumeric(input);
        if (value == -999999.99) {
            std::cout << "The input is invalid.\n";
        } else {
            std::cout << "The input is: " << std::fixed << std::setprecision(4) << value << "\n";
        }
    }
    return 0;
}
