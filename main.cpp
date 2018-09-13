#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int mSize = matrix.size();
        int zeroSize = 0;
        if (mSize < 1)
            return;
        int nSize = matrix[0].size();

        bool zeroPosM[mSize], zeroPosN[nSize];

        for (int i = 0; i < mSize; i++) {
            zeroPosM[i] = 1;
            for (int j = 0; j < nSize; j++) {
                zeroPosM[i] = zeroPosM[i] && matrix[i][j];
            }
        }
        for (int j = 0; j < nSize; j++) {
            zeroPosN[j] = 1;
            for (int i = 0; i < mSize; i++) {
                zeroPosN[j] = zeroPosN[j] && matrix[i][j];
            }
        }

        for (int i = 0; i < mSize; i++) {
            for (int j = 0; j < nSize; j++) {
                if (!(zeroPosM[i] && zeroPosN[j]))
                    matrix[i][j] = 0;
            }
        }
    }

    void betterSetZeroes(vector<vector<int>> &matrix) {

        bool ifFirstRowContain0 = false, ifCurrentRowContain0 = false;

        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                ifFirstRowContain0 = true;
                break;
            }
        }

        for (int j = 1; j < matrix.size(); ++j) {
            ifCurrentRowContain0 = false;
            for (int i = 0; i < matrix[j].size(); ++i) {
                if (matrix[j][i] == 0) {
                    ifCurrentRowContain0 = true;
                    matrix[0][i] = 0;
                }
            }
            if (ifCurrentRowContain0) {
                for (int i = 0; i < matrix[j].size(); ++i) {
                    matrix[j][i] = 0;
                }
            }
        }

        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] && ifFirstRowContain0) {
                matrix[0][i] = 0;
                continue;
            } else if (matrix[0][i] == 0) {
                for (int j = 1; j < matrix.size(); ++j) {
                    matrix[j][i] = 0;
                }
            }
        }

        return;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 1, 5}}, matrix1 = {{1, 1, 1},
                                                            {1, 0, 1},
                                                            {1, 1, 1}};
    Solution s;
    s.betterSetZeroes(matrix);

    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[0].size(); j++) {
            cout << matrix1[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}