/*
 * Implement a generic value type named Value that will hold
 * values/objects of different types.  Use type erasure, like you did for
 * Sptr.
 *
 * You may assume that all values have a copy constructor, but you may not
 * assume that they have an assignment operator.
 *
 * Your implementation must be able to work for any type.
 */

#include <string>
#include <iostream>
#include <utility>
#include <vector>

std::ostream &
operator<<(std::ostream &os, const std::pair<int, std::string> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

class MyClass {
    public:
        friend std::ostream &operator<<(std::ostream &os, const MyClass &o) {
            return os << "(" << o.i << ", \"" << o.s << "\")";
        }
        MyClass(int i, const std::string &s) : i(i), s(s) {}
        MyClass(const MyClass &o) : i(o.i), s(o.s) {}
    private:
        const int i;
        const std::string s;
};

// Put your code here.

int
main() {
    
    Value v1(1);
    Value v2(1.3);
    Value v3(std::string("hello"));
    Value v4(MyClass{1234, "goodbye"});

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v4 << std::endl;

    std::vector<Value> list{v1, v2, v3, v4};
    std::cout << "Output vector" << std::endl;
    for (const auto &v : list) {
        std::cout << v << std::endl;
    }

    // Can copy construct.
    Value v = v3;
    std::cout << v << std::endl;

    // Can assign.
    v = v2;
    std::cout << v << std::endl;

    v = Value(std::pair<int, std::string>(123, "hello"));
    std::cout << v << std::endl;

    // Must be able to work if I used any type, such as some random new type called NewClass.
    //     class NewClass { ... };
    //     Value v5(NewClass(...));
}
