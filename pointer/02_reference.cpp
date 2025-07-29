#include <iostream>

class Container {
private:
    int value;

public:
    Container() {
        value = 1;
    }

    void add() {
        value += 1;
    }

    void print_value() {
        std::cout << value << std::endl;
    }
};

void add_pointer(int* a) {
    (*a)++;
}

void add_reference(int& a) {
    a = a + 1;
}

void add_instance_ref(Container& conn) {
    conn.add();
    conn.print_value();
}

void add_instance_ptr(Container* conn) {
    conn->add();
    conn->print_value();
}

int main() {
    int a = 1;
    add_pointer(&a);
    std::cout << a << std::endl; // 2
    add_reference(a);
    std::cout << a << std::endl; // 3

    int& b = a;
    b += b;
    std::cout << a << std::endl; // 6

    Container c = Container();
    add_instance_ref(c); // 2

    Container* d = &c;
    add_instance_ptr(d); // 3

    return 0;
}
