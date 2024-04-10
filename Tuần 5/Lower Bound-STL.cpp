#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int number, length;
    vector <int> vector;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> number;
        vector.push_back(number);
    }
    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        cin >> number;
        auto it = lower_bound(vector.begin(), vector.end(), number);
        if (it != vector.end() && *it == number)
        {
            cout << "Yes " << std::distance(vector.begin(), it) + 1 << "\n";
        }
        else if (it != vector.end())
        {
            cout << "No " << std::distance(vector.begin(), it) + 1 << "\n";
        }
    }  
    return 0;
}
