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
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 1, 5}}, matrix1 = {{1, 1, 1},
                                                            {1, 0, 1},
                                                            {1, 1, 1}};
    Solution s;
    s.setZeroes(matrix1);

    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[0].size(); j++) {
            cout << matrix1[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}