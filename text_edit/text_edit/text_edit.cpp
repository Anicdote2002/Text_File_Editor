// text_edit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <vector>
#include <iostream>
#include <cstdlib> // For atoi
#include <utility> // For std::pair
#include <string> // For std::stoi
#include <stdexcept> // For std::invalid_argument and std::out_of_range exceptions
#include <fstream>
#include <sstream>
using namespace std;

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
    if (!strcmp(argv[0], "text_edit")) // If first input parameter is not the executable name return false
    {
        return 0;
    }
    //Simple Check for record and fields
    if ((strcmp(argv[1], "-r") == 0) && (strcmp(argv[3], "-f") == 0)) {
        if (isNumber(argv[2]) && isNumber(argv[4])) {
            int num1 = stoi(argv[2]);
            int num2 = stoi(argv[4]);
            std::pair<int, int> rec_field = { num1, num2 };
            std::cout << "Parsed values: " << rec_field.first << " " << rec_field.second << std::endl;
        }
        else {
            std::cout << "Invalid numeric arguments." << std::endl;
        }
    }
    else if ((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-r") == 0)) {
        if (isNumber(argv[2]) && isNumber(argv[4])) {
            int num1 = stoi(argv[2]);
            int num2 = stoi(argv[4]);
            std::pair<int, int> field_rec = { num2, num1 };
            std::cout << "Parsed values: " << field_rec.first << " " << field_rec.second << std::endl;
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
vector<vector<string>> read_file(const std::string& filename)
{
    std::vector<std::vector<string>> data; // The 2D vector to store the data
    std::ifstream file(filename); // Open the file

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file " << filename << std::endl;
        return data; // Return an empty vector if the file cannot be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row; // Create a vector to store the values in the current row
        std::istringstream iss(line);
        int value;

        while (iss >> value) {
            row.push_back(value); // Add each value to the row vector
        }

        data.push_back(row); // Add the row vector to the 2D vector
    }

    file.close(); // Close the file
    return data; // Return the populated 2D vector
}


