
class Solution {
private:
    bool issafe(vector<vector<int>> &m, int n,
                vector<vector<int>> &visited, int x, int y) {

        return x >= 0 && x < n &&
               y >= 0 && y < n &&
               visited[x][y] == 0 &&
               m[x][y] == 1;
    }

    void solve(vector<vector<int>> &m, int n,
               vector<string> &ans, int x, int y,
               string &path, vector<vector<int>> &visited) {

        // Base case: destination reached
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        int newx = x + 1, newy = y;
        if (issafe(m, n, visited, newx, newy)) {
            path.push_back('D');
            solve(m, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (issafe(m, n, visited, newx, newy)) {
            path.push_back('L');
            solve(m, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        // Right
        newx = x;
        newy = y + 1;
        if (issafe(m, n, visited, newx, newy)) {
            path.push_back('R');
            solve(m, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (issafe(m, n, visited, newx, newy)) {
            path.push_back('U');
            solve(m, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        // Backtracking
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;

        if (n == 0 || m[0][0] == 0 || m[n - 1][n - 1] == 0) {
            return ans;
        }

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";

        solve(m, n, ans, 0, 0, path, visited);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
