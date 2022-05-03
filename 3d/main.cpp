#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

int ConvertRomanToArabic(const std::string &roman){
    const std::map<char, int> table {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100} };
    int temp = 0;
    int res = 0;
    for (char c : roman){
        int number = table.at(c);
        if (number < temp){
            res += temp;
            temp = number;
        }
        else if (number > temp){
            if (temp == 0)
                temp = number;
            else {
                res += number - temp;
                temp = 0;
            }
        }
        else if (number == temp){
            res += temp + number;
            temp = 0;
        }
    }
    return res + temp;
}

std::string ConvertArabicToRoman(int arabic){
    const std::map<int, std::string> table {{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    const std::vector<int> values {100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string result= std::string();
    for (const int &value: values){
        if (arabic >= value){
            while (arabic >= value){
                result += table.at(value);
                arabic -= value;
            }
 
        }
    }
    return result;
}

std::string PrintRomanAnswer(std::string a, std::string b){
    return ConvertArabicToRoman(ConvertRomanToArabic(a) + ConvertRomanToArabic(b));
}

int main() {
    std::string c, k;
    std::cin >> c >> k;
    if(c[0] == 'C' && c.size() > 1){
        std::cout<<"number can't exceed C";
        return (c[0] == 'C' && c.size() == 1);
    }
    if(k[0] == 'C'&& k.size() > 1){
        std::cout<<"number can't exceed C";
        return (k[0] == 'C' && k.size() == 1);
    }
    std::cout<<PrintRomanAnswer(c, k);
    return 0;
}
