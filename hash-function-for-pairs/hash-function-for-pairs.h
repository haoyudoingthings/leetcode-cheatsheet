#include <utility> // std::pair
namespace N {
    struct pair_hash {
        template <class T1, class T2>
        size_t operator () (std::pair<T1, T2> const &v) const {
            auto [x, y] = v;
            return hash<T1>()((x+y+1)*(x+y)/2 * x); // Cantor pairing function, choose smaller of x and y for the last multiplication
        }
    };
}