#include <cstdlib>
#include <iostream>

// Calculates total cost with tax for one potato and decrements available count
float BuyOnePotato(float price, int &num_potato) {
    num_potato--;
    return price * 1.13;
}

// Calculates total cost with tax for multiple potatoes and decrements available count
float BuyNumPotatoes(float price, int &num_potato, int num_buy) {
    if (num_buy > num_potato) {
        std::cout << "Not enough potatoes" << std::endl;
        return 0;
    }
    num_potato -= num_buy;
    return price * 1.13 * num_buy;
}

int main(void) {
    float potato_price = 30.0; // Price per potato
    int num_potato = 20;       // Initial potato count

    std::cout << "$" << BuyOnePotato(potato_price, num_potato) << std::endl;
    std::cout << num_potato << std::endl << std::endl;

    std::cout << "$" << BuyNumPotatoes(potato_price, num_potato, 3) << std::endl;
    std::cout << num_potato << std::endl;

    return EXIT_SUCCESS;
}
