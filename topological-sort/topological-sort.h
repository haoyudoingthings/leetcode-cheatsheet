#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
namespace N {
    std::vector<int> topological_sort(std::unordered_set<int>& lst, 
      std::unordered_map<int, std::unordered_set<int>>& pred,
      std::unordered_map<int, std::unordered_set<int>>& succ) {
        std::vector<int> out;
        std::deque<int> no_b4;
        for (int i: lst) {
            if (pred[i].empty()) {
                no_b4.push_back(i);
            }
        }
        int cur;
        while (!no_b4.empty()) {
            cur = no_b4.front(); no_b4.pop_front();
            out.push_back(cur);
            for (int i: succ[cur]) {
                pred[i].erase(cur);
                if (pred[i].empty()) {
                    no_b4.push_back(i);
                }
            }
        }
        if (out.size() != lst.size()) {
            out.clear();
        }
        return out;
    }
}