#include <vector>
namespace N {
    vector<pair<int, int>> adj(int i, int j, int m, int n) {
        // i, j: current position
        // m, n: size of the grid
        // return vector[(x, y)]: x, y that are adjacent to i, j
        vector<pair<int, int>> out;
        out.reserve(4);
        if (i > 0) {
            out.push_back({i-1, j});
        }
        if (j > 0) {
            out.push_back({i, j-1});
        }
        if (i < m-1) {
            out.push_back({i+1, j});
        }
        if (j < n-1) {
            out.push_back({i, j+1});
        }
        return out;
    }
}