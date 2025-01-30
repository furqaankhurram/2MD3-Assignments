#include <iostream>
#include <cstdlib>
#include <ctime>

class Birthday { 
    public:
        int month;
        int day;

    Birthday(){
        random();
    }

    void random() {
        month = 1 + rand() % 12;  // Random month between 1 and 12
        day = 1 + rand() % 31;    // Random day between 1 and 31
    }

    bool operator==(const Birthday &other) const{
        return month == other.month && day == other.day; // Check if birthdays are equal
    }
    
};

class BirthdayParadox {
public:
    Birthday *birthdays; 
    const int num_ppl;

    // Constructor to initialize birthdays array
    BirthdayParadox(int n) : num_ppl(n) {
        birthdays = new Birthday[num_ppl];
    }

    // Destructor to release memory
    ~BirthdayParadox() {
        delete[] birthdays;
    }

    int CheckDuplicates(){
        // Check if any two birthdays are the same
        for (int i = 0; i < num_ppl; i++){
            for (int j = i + 1; j < num_ppl; j++){
                if (birthdays[i] == birthdays[j]){
                    return 1; // Found a duplicate
                }
            }
        }
        return 0; // No duplicate
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    const int experiments = 100; 
    for (int n = 5; n <= 100; n += 5) {
        int duplicate_count = 0;

        for (int i = 0; i < experiments; ++i) {
            BirthdayParadox test(n); 
            duplicate_count += test.CheckDuplicates(); // Run experiment and count duplicates
        }
        float probability = static_cast<float>(duplicate_count) / experiments;
        std::cout << n << "," << duplicate_count << "," << probability << std::endl;
    }

    return EXIT_SUCCESS;
}
