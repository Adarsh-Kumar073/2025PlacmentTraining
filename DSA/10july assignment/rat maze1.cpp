class Solution {
  public:
    vector<string> result;

    bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited, int n) {
        return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y]);
    }

    void dfs(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, int n) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        visited[x][y] = true;

        if (isSafe(x + 1, y, maze, visited, n))
            dfs(x + 1, y, maze, visited, path + 'D', n);

        if (isSafe(x, y - 1, maze, visited, n))
            dfs(x, y - 1, maze, visited, path + 'L', n);

        if (isSafe(x, y + 1, maze, visited, n))
            dfs(x, y + 1, maze, visited, path + 'R', n);

        if (isSafe(x - 1, y, maze, visited, n))
            dfs(x - 1, y, maze, visited, path + 'U', n);

        visited[x][y] = false; 
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        result.clear();

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        dfs(0, 0, maze, visited, "", n);
        sort(result.begin(), result.end()); 
        return result;
    }
};
