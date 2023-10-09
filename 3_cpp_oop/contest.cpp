#include <iostream>
#include <string>
#include <vector>

std::string min_date(const std::vector<std::pair<std::string, int>>& vector){
    int min_year = 10001;
    int min_month = 13;
    int min_day = 32;
    unsigned int n = vector.size();
    for (int i = 0; i < n; ++i){
        int year = std::stoi(vector[i].first.substr(6, 4));
        int month = std::stoi(vector[i].first.substr(3, 2));
        int day = std::stoi(vector[i].first.substr(0, 2));
        if (year < min_year){
            min_year = year;
            min_month = month;
            min_day = day;
        }
        else if (year == min_year){
            min_year = year;
            if (month < min_month){
                min_month = month;
                min_day = day;
            }
        }
        else if (year == min_year and month == min_month){
            min_year = year;
            min_month = month;
            if (day < min_day){
                min_day = day;
            }
        }
    }
    std::string min_day_s = std::to_string(min_day);
    std::string min_month_s = std::to_string(min_month);
    std::string min_year_s = std::to_string(min_year);
    if (min_month/10 == 0){
        min_month_s = "0" + min_month_s;
    }
    if (min_day/10 == 0){
        min_day_s = "0" + min_day_s;
    }
    std::string result = min_day_s + "." + min_month_s + "." + min_year_s;
    return result;
}
int main() {
    int n, m;
    std::string date;
    std::pair <std::string, int> p;
    std::vector<std::pair<std::string, int>> v1, v1_s;
    std::vector<std::string> v2;
    std::cin >> n;
    for (int i = 0; i < n; ++i){
        std::cin >> p.first >> p.second;
        v1.push_back(p);
    }
    std::cin >> m;
    for (int i = 0; i < m; ++i){
        std::cin >> date;
        v2.push_back(date);
    }
    for (int i = 0; i < n; ++i){
        std::string a = min_date(v1);
        for (int j = 0; j < n; ++j){
            if (v1[j].first == a){
                v1_s.push_back(v1[j]);
                v1.erase(v1.begin() + j);
            }
        }
    }
    for (int i = 0; i < m; ++i){
        int year2 = std::stoi(v2[i].substr(6, 4));
        int month2 = std::stoi(v2[i].substr(3, 2));
        int day2 = std::stoi(v2[i].substr(0, 2));
        int summ = 0;
        for (int j = 0; j < n; ++j){
            int year1 = std::stoi(v1_s[j].first.substr(6, 4));
            int month1 = std::stoi(v1_s[j].first.substr(3, 2));
            int day1 = std::stoi(v1_s[j].first.substr(0, 2));
            if ((year1 > year2) or (year1 == year2 and month1 > month2) or
            (year1 == year2 and month1 == month2 and day1 > day2) or
            (year1 == year2 and month1 == month2 and day1 == day2)){
                std::cout << summ << std::endl;
                break;
            }
            else{
                summ += v1_s[j].second;
            }
        }
    }
    return 0;
}
