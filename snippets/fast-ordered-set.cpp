#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(9);

    auto it = s.find_by_order(2);
}
