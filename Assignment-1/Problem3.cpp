#include <cstdlib>
#include <iostream>
#include <string>

template<typename First, typename Second>
class Pair{
    private:
        First first;
        Second second;

    public:
    Pair(First f, Second s){
        first = f;
        second = s; // Initialize pair with provided values
    }

    void print() const {
        std::cout << "<" << first << ", " << second << ">" << std::endl; // Print pair in desired format
    }
};

int main() {
    Pair<int, double> p1(1, 7.3);
    p1.print(); // Print first 

    Pair<std::string, double> p2("hello", 7.7);
    p2.print(); //second 

    Pair<float, long> p3(1.2f, 777777773L);
    p3.print(); //third

    Pair<char, std::string> p4('A', "World");
    p4.print(); //fourth

    Pair<bool, int> p5(true, 42);
    p5.print(); //fifth

    return EXIT_SUCCESS;
}
