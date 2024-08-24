#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
    set<char> validate;

    // horizontal
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char num = board[row][col];
            if (num != '.') {
                if (validate.find(num) != validate.end()) {
                    return false;
                }
                validate.insert(num);
            }
        }
        validate.clear();
    }

    // vertical
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char num = board[col][row];
            if (num != '.') {
                if (validate.find(num) != validate.end()) {
                    return false;
                }
                validate.insert(num);
            }
        }
        validate.clear();
    }

    // 3x3
    int n = 9;
    int begin = 0;
    int end = 3;
    int rowBegin = 0;
    int rowEnd = 3;
    while (n > 0) {
        if (n == 6) {
            rowBegin = 3;
            rowEnd = 6;
            begin = 0;
            end = 3;
        } else if (n == 3) {
            rowBegin = 6;
            rowEnd = 9;
            begin = 0;
            end = 3;
        }
        for (int row = rowBegin; row < rowEnd; row++) {
            for (int col = begin; col < end; col++) {
                char num = board[row][col];
                if (num != '.') {
                    if (validate.find(num) != validate.end()) {
                        return false;
                    }
                    validate.insert(num);
                }
            }
        }
        validate.clear();
        begin += 3;
        end += 3;
        n--;
    }

    return true;
}

int main() {
    vector<vector<char> > board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << isValidSudoku(board) << endl;

    return 0;
}
