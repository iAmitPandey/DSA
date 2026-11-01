// class Solution {
//    public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for (int i = 0; i < 9; i++) {
//             unordered_set<char> seen;
//             for (int j = 0; j < 9; j++) {
//                 char digit = board[i][j];
//                 if (digit == '.') continue;
//                 if (seen.count(digit)) return false;
//                 seen.insert(digit);
//             }
//         }

//         for (int i = 0; i < 9; i++) {
//             unordered_set<char> seen;
//             for (int j = 0; j < 9; j++) {
//                 char digit = board[j][i];
//                 if (digit == '.') continue;
//                 if (seen.count(digit)) return false;
//                 seen.insert(digit);
//             }
//         }

//         for (int bi = 0; bi < 9; bi += 3) {
//             for (int bj = 0; bj < 9; bj += 3) {
//                 unordered_set<char> seen;
//                 for (int i = bi; i < bi + 3; i++) {
//                     for (int j = bj; j < bj + 3; j++) {
//                         char digit = board[i][j];
//                         if (digit == '.') continue;
//                         if (seen.count(digit)) return false;
//                         seen.insert(digit);
//                     }
//                 }
//             }
//         }
//         // for (int square = 0; square < 9; square++) {
//         //     unordered_set<char> seen;
//         //     for (int i = 0; i < 3; i++) {
//         //         for (int j = 0; j < 3; j++) {
//         //             int row = (square / 3) * 3 + i;
//         //             int col = (square % 3) * 3 + j;
//         //             if (board[row][col] == '.') continue;
//         //             if (seen.count(board[row][col])) return false;
//         //             seen.insert(board[row][col]);
//         //         }
//         //     }
//         // }
//         return true;
//     }
// };

// we know the size is fixed 9 so we can directly use fixed size array 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int d = board[r][c] - '1';
                int b = (r / 3) * 3 + (c / 3);   // the "box formula" from the thread

                if (row[r][d] || col[c][d] || box[b][d]) return false;
                row[r][d] = col[c][d] = box[b][d] = true;
            }
        }
        return true;
    }
};