/*
 * Implement the variadic get_sizes() function.  It should be able to work with any arbitrary type, not just the
 * ones given in the example.
 *
 * Hint: You may need a helper function.
 */

#include <vector>
#include <iostream>
#include <cstddef>
#include <cxxabi.h>
#include <assert.h>
#include <string>
#include <vector>
#include <list>

// Use the function below to retrieve a human-readable type from a std::type_info object.
std::string
type_info_to_string(const std::type_info &ti) {
    int ec;
    char *p = abi::__cxa_demangle(ti.name(), 0, 0, &ec);
    assert(ec == 0);
    std::string s(p);
    free(p);
    return s;
}

// Put your code here.

int main() {
    struct Foo { int i; double x; };
    auto sizes = get_sizes(1, 3.14, Foo{1, 3.14}, std::string("hello"), std::list<int>(), std::vector<int>());
    for (auto s : sizes) {
        std::cout << "type name: " << s.name << ", size: " << s.size << std::endl;
    }

    // Your code should work without change if I add a new type.
    //     struct NewFoo { ... };
    //     auto sizes2 = get_sizes(NewFoo{...}, 1, NewFoo{...});
    //     ...
}
