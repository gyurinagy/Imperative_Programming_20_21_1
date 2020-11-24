#include <iostream>

class MyClass{
    public:
    MyClass(){std::cout<<"construct\n";}
    MyClass(const MyClass&){std::cout<<"copy\n";}
    MyClass& operator=(const MyClass&){std::cout<<"assign\n";return *this;}
    ~MyClass(){std::cout<<"destruct\n";}
};

int main() {
    MyClass a();
}

