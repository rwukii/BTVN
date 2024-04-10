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
    sort(vector.begin(), vector.end());
    for (int x : vector)
    {
        cout << x << " ";
    }
    return 0;
}
