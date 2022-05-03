#pragma once

#include <string>
#include <map>
#include <vector>

class Roman {
public:
    Roman() = default;
    explicit Roman(const std::string &value);

    explicit Roman(int value);

    std::string ToString() const;

    Roman& operator+=(const Roman& other);

    Roman& operator=(const Roman& other);

private:
    const std::map<char, int> kRomanArabic{{'I', 1},
                                           {'V', 5},
                                           {'X', 10},
                                           {'L', 50},
                                           {'C', 100}};

    const std::map<int, std::string> kArabicRoman{{100, "C"},
                                                  {90,  "XC"},
                                                  {50,  "L"},
                                                  {40,  "XL"},
                                                  {10,  "X"},
                                                  {9,   "IX"},
                                                  {5,   "V"},
                                                  {4,   "IV"},
                                                  {1,   "I"}};

    const std::vector<int> kValues{100, 90, 50, 40, 10, 9, 5, 4, 1};

private:
    std::string ConvertArabicToRoman(int arabic);

private:
    std::string roman_number_;
    int arabic_number_ = 0;
};


std::ostream& operator<<(std::ostream& output, const Roman& roman);

Roman::Roman(const std::string &value) : roman_number_(value) {
    int temp = 0;
    int res = 0;
    for (char c : value){
        int number = kRomanArabic.at(c);
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
    arabic_number_ = res + temp;
}

Roman::Roman(int value) : Roman(ConvertArabicToRoman(value)) {
    // Implement me
}

std::string Roman::ToString() const{
    return roman_number_;
}

std::string Roman::ConvertArabicToRoman(int arabic) {
    std::string result= std::string();
    for (const int &value: kValues) {
        if (arabic >= value){
            while (arabic >= value){
                result += kArabicRoman.at(value);
                arabic -= value;
            }

        }
    }
    return result;
}

Roman& Roman::operator+=(const Roman& other) {
    arabic_number_ += other.arabic_number_;
    roman_number_ = ConvertArabicToRoman(arabic_number_);
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Roman& roman) {
    return output << roman.ToString();
}

std::istream& operator>>(std::istream& input, Roman& roman) {
    std::string number;
    input >> number;
    roman = Roman{number};
    return input;
}

Roman& Roman::operator=(const Roman& other) {
    arabic_number_ = other.arabic_number_;
    return *this;
}

Roman operator+(Roman left, Roman right) {
    return left += right;
}
