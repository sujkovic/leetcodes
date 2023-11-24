//  perform dfs from source pixel

//  solved in 4 minutes damn

//  Time - O(m * n)
//      worst case whole image needs to be changed
//  Space - O(m * n)
//      recursive call stack

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int r, int c, int &color, int &ogColor)
    {
        if (r >= image.size() || r < 0 || c >= image[0].size() || c < 0 || image[r][c] != ogColor || image[r][c] == color)
        {
            return;
        }

        image[r][c] = color;
        dfs(image, r + 1, c, color, ogColor);
        dfs(image, r, c + 1, color, ogColor);
        dfs(image, r - 1, c, color, ogColor);
        dfs(image, r, c - 1, color, ogColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int ogColor = image[sr][sc];
        dfs(image, sr, sc, color, ogColor);
        return image;
    }
};