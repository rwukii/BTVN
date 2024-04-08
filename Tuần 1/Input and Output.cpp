#include <iostream>
#include <vector>
using namespace std;

string balancedsum(const std::vector<int>& arr)
{
    int totalSum = 0;
    int leftSum = 0;

    for (int num : arr) {
        totalSum += num;
    }

    for (int num : arr) {
        if (leftSum == totalSum - leftSum - num) {
            return "YES";
        }
        leftSum += num;
    }

    return "NO";
}
int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int length;
        cin >> length;
        vector <int> a(length);
        for (int j = 0; j < length; j++)
        {
            cin >> a[j];
        }
        cout << balancedsum(a) << "\n";
    }
}
