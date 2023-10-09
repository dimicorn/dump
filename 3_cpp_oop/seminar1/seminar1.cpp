#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class StaticMap{
    public:
        vector<pair<int, int>> a;
    int Get(int key, int default_value){
        sort(a.begin(), a.end());
        int f, l, mid;
        f = 0;
        l = a.size() - 1;
        mid = (f + l)/2;
        while(f <= l){
            if(a[mid].first < key){
                f = mid + 1;
                mid = (f + l)/2;
            }
            else if(a[mid].first == key){
                return a[mid].second;
                break;
            }
            else{
                l = mid - 1;
                mid = (f + l)/2;
            }
        }
        if(f > l){
            return default_value;
        }
    }
    bool FindKey(int key){
        sort(a.begin(), a.end());
        int f, l, mid;
        f = 0;
        l = a.size() - 1;
        mid = (f + l)/2;
        while(f <= l){
            if(a[mid].first < key){
                f = mid + 1;
                mid = (f + l)/2;
            }
            else if(a[mid].first == key){
                return true;
                break;
            }
            else{
                l = mid - 1;
                mid = (f + l)/2;

            }
        }
        if(f > l){
            return false;
        }
    }
    };
int main(){
    StaticMap myObj;
    vector<pair<int, int>> vect;
    int arr1[] = {10, 20, 5, 40};
    int arr2[] = {30, 60, 20, 50};
    for (int i = 0; i < 4; ++i){
        myObj.a.push_back( make_pair(arr1[i],arr2[i]) );
    }
    cout << myObj.FindKey(69);
    cout << endl;
    cout << myObj.Get(69, 69);
    return 0;
}
