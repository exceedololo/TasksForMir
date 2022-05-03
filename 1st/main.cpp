#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cmath>

int MinAlligmentCount(std::vector<int>& wall) {
    //std::sort(wall.begin(), wall.end());
    for (int a: wall){
        if(a < 1 || a >10){
            std::cout<<"\n";
            throw std::invalid_argument("exceeds the range of wall heights");
            break;}
    }
    const auto median_it = wall.begin() + wall.size() / 2;
    //std::nth_element(wall.begin(), median_it , wall.end());
    auto median = *median_it;

    int count = 0;
    for (size_t i = 0; i < wall.size(); ++i) {
        int delta = std::abs(median - wall[i]);
        count += delta;
        while (delta--) {
            std::cout << "[ ";
            std::copy(wall.begin(), wall.end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << "]" << std::endl;
            (wall[i] > median) ? wall[i]-- : wall[i]++;
        }
    }
    std::cout << "[ ";
    std::copy(wall.begin(), wall.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]";
    std::cout << std::endl;

    return count;
}

int main()
{
    std::vector<int> wall;
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(wall));
    std::cout << MinAlligmentCount(wall) << std::endl;
    return 0;
}
//на всякий случай хотел добавить что программа ожидает символ конца ввода "ctrl+d", но можно заставить ее работать введя, например, букву или символ 
