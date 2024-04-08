#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; 
    cin >> n;
    int num;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    reverse(begin(arr), end(arr));
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

