#include <iostream>
#include <cstring>
using namespace std;

#define M 10
#define N 10

bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y]) {
        return false;
    }
    return true;
}
bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0) {
        return true;
    }
    return false;
}
void findLongestPath(int mat[M][N], int visited[M][N], int i, int j,int x, int y, int &max_dist, int dist)
{
    if (mat[i][j] == 0) {
        return;
    }
    if (i == x && j == y)
    {
        max_dist = max(dist, max_dist);
        return;
    }
    visited[i][j] = 1;

    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j)) {
        findLongestPath(mat, visited, i + 1, j, x, y, max_dist, dist + 1);
    }

    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1)) {
        findLongestPath(mat, visited, i, j + 1, x, y, max_dist, dist + 1);
    }

    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j)) {
        findLongestPath(mat, visited, i - 1, j, x, y, max_dist, dist + 1);
    }

    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1)) {
        findLongestPath(mat, visited, i, j - 1, x, y, max_dist, dist + 1);
    }
    visited[i][j] = 0;
}
 
int main()
{
    int mat[M][N] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };
    int visited[M][N];
    memset(visited, 0, sizeof visited);
    int max_dist = 0;
    findLongestPath(mat, visited, 0, 0, 5, 7, max_dist, 0);
    cout << "The Maximum length path is " << max_dist;
    return 0;
}
