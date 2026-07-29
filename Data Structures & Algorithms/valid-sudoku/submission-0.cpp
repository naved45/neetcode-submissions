#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use sets to track seen numbers
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];
                if (num == '.') continue;

                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check row, column, and box
                if (rows[r].count(num) || cols[c].count(num) || boxes[boxIndex].count(num)) {
                    return false;
                }

                // Insert into sets
                rows[r].insert(num);
                cols[c].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        return true;
    }
};
