#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
int num_of_queries, rows, cols;
    cin >> num_of_queries >> rows;
    vector <vector<int>> two_dimen_vector(rows);
    for (int i = 0; i < rows; i++)
    {
        std::cin >> cols;
        two_dimen_vector[i].resize(cols);
        for (int j = 0; j < cols; j++)
        {
            cin >> two_dimen_vector[i][j];
        }
    }
    int row_i, col_i;
    for (int i = 0; i < num_of_queries; i++)
    {
        cin >> row_i >> col_i;
        cout << two_dimen_vector[row_i][col_i] << "\n";
    } 
    return 0;
}
