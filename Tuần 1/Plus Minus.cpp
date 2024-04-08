#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(6);
    int n; 
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    double pos = 0;
    double neg = 0;
    double zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0) pos++;
        else if (arr[i] < 0) neg++;
        else zero++;
    }
    cout << pos / n << "\n" << neg / n << "\n" << zero / n;
}
