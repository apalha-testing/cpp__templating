#include <iostream>
#include <memory>
#include <string>

template <typename T>
void show(T input) {
  std::cout << input->print() << std::endl;
}

class A {
public:
  std::string print(){
    return std::string("Printing from class A object!");
  }
};

class B {
public:
  std::string print(){
    return std::string("Printing from class B object!");
  }
};

int main() {
    A A_object;
    B B_object;
    std::unique_ptr<B> B_unique(new B);
    std::shared_ptr<A> A_shared(new A);

    show<A*>(&A_object);  // pass the pointer to the object
    show<B*>(&B_object);  // pass the pointer to the object
    show<std::unique_ptr<B>&>(B_unique);  // pass by reference (pass the smart pointer)
    show<std::shared_ptr<A>>(A_shared);  // pass by copy, the shared pointer allows this

    return 0;
}
