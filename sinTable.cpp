// Copyright 2025 Viviana Hurtado
// Created by: Viviana Hurtado
// Date: May, 2025
// This program generates a sine table from 1 up to a number entered by the
// user (between 1 and 360)
// It asks if the user wants to start, handles invalid inputs, and uses nested
// loops

#include <cmath>     // for sin function
#include <cstdlib>   // for exit function
#include <iostream>  // for input/output
#include <string>    // for using string variables

int main() {
    std::string answer;  // User answer

    while (true) {  // Outer loop to ask if the user wants to start again
        std::cout << "Do you want to start? ";
        std::cout << "(please answer with a 'yes' or 'no'): ";
        std::cin >> answer;

        if (answer == "no") {  // Exit if user doesn't want to start
            std::cout << "Have a nice day!" << std::endl;
            break;  // End
        } else if (answer == "yes") {
            int counter = 0;  // To count degrees

            std::string user_num;  // Input as string
            int num_int;

            std::cout << "Enter a number between 1 and 360: ";
            std::cin >> user_num;

            try {
                num_int = std::stoi(user_num);
                // Try to convert string to integer

                if (num_int <= 0 || num_int > 360) {
                    std::string retry;
                    std::cout << "Number should be between 1 and 360. "
                              << "Do you want to try again? (yes/no): ";
                    std::cin >> retry;

                    if (retry != "yes") {
                        std::cout << "Thank you for using this program."
                                  << std::endl;
                        break;  // Exit
                    }

                    continue;  // Restart from top
                }

                // Nested loop to show sin values for each degree
                for (counter = 1; counter <= num_int; counter++) {
                    double radians = counter * M_PI / 180;
                    double result = sin(radians);
                    std::cout << "sin(" << counter << ") = " << result
                              << std::endl;
                }

                std::cout << "Thank you for using this program. "
                          << "Do you want to start again? (yes/no): ";
                std::cin >> answer;

                if (answer != "yes") {
                    std::cout << "Goodbye!" << std::endl;
                    break;
                }
            } catch (...) {
                std::string retry;
                std::cout << "Input is not a valid integer. "
                          << "Do you want to try again? (yes/no): ";
                std::cin >> retry;

                if (retry != "yes") {
                    std::cout << "Thank you for using this program."
                              << std::endl;
                    break;
                }
                continue;
            }
        } else {
            std::cout << "Invalid input. Please answer with 'yes' or 'no'."
                      << std::endl;
        }
    }
}
