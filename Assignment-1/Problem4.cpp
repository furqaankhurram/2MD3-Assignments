#include <cstdlib>
#include <iostream>
#include <cmath>

class Progression {
protected:
    int current;  // Current value
    int previous; // Previous value

public:
    Progression(int initial, int second): previous(initial), current(second){}
    
    // Calculate the next value in the progression
    virtual int nextValue() {
        int next = std::abs(current - previous);  // Absolute difference
        previous = current;  // Update previous
        current = next;  // Update current
        return current;
    }

    // Print the progression for n values
    void printProgression(int n) {
        std::cout << previous << " " << current << " ";  // Print first two values
        for (int i = 2; i < n; ++i) {
            std::cout << nextValue() << " ";  // Print next values
        }
        std::cout << std::endl;
    }
};

class AbsoluteProgression : public Progression {
public:
    AbsoluteProgression() : Progression(200, 198) {}  // Default constructor

    AbsoluteProgression(int initial, int second) : Progression(initial, second) {}  // Custom constructor
};

int main() {
    std::cout << "Absolute progression with default constructor:" << std::endl;
    AbsoluteProgression defaultProgression;  // Default progression
    defaultProgression.printProgression(10);

    std::cout << "Absolute progression with custom constructor:" << std::endl;
    AbsoluteProgression customProgression(300, 297);  // Custom progression
    customProgression.printProgression(10); 

    return EXIT_SUCCESS;
}

