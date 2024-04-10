#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector <int> vector;
    int length, num;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> num;
        vector.push_back(num);
    }
    cin >> num;
    vector.erase(vector.begin() + num - 1);
    int first, last;
    cin >> first >> last;
    vector.erase(vector.begin() + first - 1, vector.begin() + last - 1);
    cout << vector.size() << "\n";
    for (int x : vector)
    {
        cout << x << " ";
    }
    return 0;
}
