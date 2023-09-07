// text_edit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <vector>
#include <iostream>
#include <cstdlib> // For atoi
#include <utility> // For std::pair

// Function to check if a string is a valid number
bool isNumber(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cout << "Usage: " << argv[0] << " -r <num1> -f <num2>" << std::endl;
        return 1; // Return an error code
    }

    if ((strcmp(argv[1], "-r") == 0) && (strcmp(argv[3], "-f") == 0)) {
        if (isNumber(argv[2]) && isNumber(argv[4])) {
            int num1 = atoi(argv[2]);
            int num2 = atoi(argv[4]);
            std::pair<int, int> input_commands = { num1, num2 };
            std::cout << "Parsed values: " << input_commands.first << " " << input_commands.second << std::endl;
        }
        else {
            std::cout << "Invalid numeric arguments." << std::endl;
        }
    }
    else if ((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-r") == 0)) {
        if (isNumber(argv[2]) && isNumber(argv[4])) {
            int num1 = atoi(argv[2]);
            int num2 = atoi(argv[4]);
            std::pair<int, int> input_commands = { num2, num1 };
            std::cout << "Parsed values: " << input_commands.first << " " << input_commands.second << std::endl;
        }
        else {
            std::cout << "Invalid numeric arguments." << std::endl;
        }
    }
    else {
        std::cout << "Invalid command-line arguments." << std::endl;
    }

    return 0;
}
