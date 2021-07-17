#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));

    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A.at(i).at(j);
        }
    }

    vector<int> row_sum(H);
    vector<int> column_sum(W);

    for(int i = 0; i < H; ++i) {
        int sum = 0;

        for(int j = 0; j < W; ++j) {
            sum += A.at(i).at(j);
        }

        row_sum.at(i) = sum;
    }

    for(int i = 0; i < W; ++i) {
        int sum = 0;

        for(int j = 0; j < H; ++j) {
            sum += A.at(j).at(i);
        }

        column_sum.at(i) = sum;
    }

    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cout << row_sum.at(i) + column_sum.at(j) - A.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}
