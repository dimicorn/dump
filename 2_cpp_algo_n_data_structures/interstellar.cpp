#include <iostream>
using namespace std;

struct Data {
    int mst, tmp_pole, tmp_eq, ox_mpercent, co2_mpercent;
};

bool check(Data d, Data limit_min, Data limit_max) {
    if ((d.mst >= limit_min.mst) && (d.mst <= limit_max.mst) &&
    (d.tmp_pole >= limit_min.tmp_pole) && (d.tmp_pole <= limit_max.tmp_pole) &&
            (d.tmp_eq >= limit_min.tmp_eq) && (d.tmp_eq <= limit_max.tmp_eq) &&
            (d.ox_mpercent >= limit_min.ox_mpercent) && (d.ox_mpercent <= limit_max.ox_mpercent) &&
            (d.co2_mpercent >= limit_min.co2_mpercent) && (d.co2_mpercent <= limit_max.co2_mpercent)){
        return true;
    }
    else{
        return false;
    }
}

// Здесь ваша реализация функции

// Это минимально допустимые значения
const Data MIN = { 3000, 203, 283, 15000,  0};
// Это максимально допустимые значения
const Data MAX = {10000, 273, 333, 25000, 45};

int main() {
    // Это пара тестовых значений, первое из которых подходит, а второе нет
    Data test1 = {3000, 203, 283, 15000, 0};
    Data test2 = {10000, 210, 300, 20000, 50};

    cout << boolalpha;
    cout << "Check result for test1: " << check(test1, MIN, MAX) << endl;
    cout << "Check result for test2: " << check(test2, MIN, MAX) << endl;

    return 0;
}

