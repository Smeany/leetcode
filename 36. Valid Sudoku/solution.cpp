class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> boxes(9);
        
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                char c = board[row][col];
                if(c == '.') continue;
                if(rows[row].find(c) != rows[row].end()) return false;
                if(cols[col].find(c) != cols[col].end()) return false;
                int box = row/3 + col/3*3;
                if(boxes[box].find(c) != boxes[box].end()) return false;
                rows[row].insert(c);
                cols[col].insert(c);
                boxes[box].insert(c);
            }
        }
        
        return true;
    }
};
