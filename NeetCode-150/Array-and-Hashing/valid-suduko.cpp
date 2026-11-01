class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                char digit = board[i][j];
                if (digit == '.') continue;
                if (seen.count(digit)) return false;
                seen.insert(digit);
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                char digit = board[j][i];
                if (digit == '.') continue;
                if (seen.count(digit)) return false;
                seen.insert(digit);
            }
        }

        for (int bi = 0; bi < 9; bi += 3) {
            for (int bj = 0; bj < 9; bj += 3) {
                unordered_set<char> seen;
                for (int i = bi; i < bi + 3; i++) {
                    for (int j = bj; j < bj + 3; j++) {
                        char digit = board[i][j];
                        if (digit == '.') continue;
                        if (seen.count(digit)) return false;
                        seen.insert(digit);
                    }
                }
            }
        }
        // for (int square = 0; square < 9; square++) {
        //     unordered_set<char> seen;
        //     for (int i = 0; i < 3; i++) {
        //         for (int j = 0; j < 3; j++) {
        //             int row = (square / 3) * 3 + i;
        //             int col = (square % 3) * 3 + j;
        //             if (board[row][col] == '.') continue;
        //             if (seen.count(board[row][col])) return false;
        //             seen.insert(board[row][col]);
        //         }
        //     }
        // }
        return true;
    }
};
