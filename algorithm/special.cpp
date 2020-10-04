#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> s;

s.insert(1);
s.insert(2);
s.insert(5);
s.insert(7);
std::cout << *s.find_by_order(1) << std::endl; // s[1] = 2
s.erase(2);