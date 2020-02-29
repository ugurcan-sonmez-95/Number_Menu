/*****************
   NUMBER MENU
*****************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

void display_menu(); // Displays the menu interface
char selection(); // Prompts the user
void print_nums(const std::vector<int> &nums); // Prints the list
void add_nums(std::vector<int> &nums); // Adds integer(s) to the list
void clear_list(std::vector<int> &nums); // Clears the list
void display_mean(const std::vector<int> &nums); // Displays the mean of the list
void display_smallest(const std::vector<int> &nums); // Displays the smallest integer in the list
void display_largest(const std::vector<int> &nums); // Displays the largest integer in the list
void quit(); // Exits the program
void unknown_key(); // Unknown key warning

void print_format(const std::vector<int> &nums); // Format of printing the list
double calc_mean(const std::vector<int> &nums); // Calculates the mean of the list
int calc_smallest(const std::vector<int> &nums); // Calculates the smallest integer in the list
int calc_largest(const std::vector<int> &nums); // Calculates the largest integer in the list

int main() {
    std::vector<int> numbers {};
    char select {};
    do {
        display_menu();
        select = selection();
        switch (select) {
            case 'P':
                print_nums(numbers);
                break;
            case 'A':
                add_nums(numbers);
                break;
            case 'C':
                clear_list(numbers);
                break;
            case 'M':
                display_mean(numbers);
                break;
            case 'S':
                display_smallest(numbers);
                break;
            case 'L':
                display_largest(numbers);
                break;
            case 'Q': 
                quit();
                break;
            default: 
                unknown_key();
        }
    } while (select != 'Q'); 
    std::cout << std::endl;
    return 0;
}

void display_menu() {
    std::cout << "\nP - Print numbers" << std::endl;
    std::cout << "A - Add numbers" << std::endl;
    std::cout << "C - Clear the list" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "Q - Quit" << std::endl;
}

char selection() {
    char choice {};
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    return toupper(choice);
}

void print_format(const std::vector<int> &nums) {
    std::cout << "\n[ ";
        for (auto n:nums)
            std::cout << n << " ";
        std::cout << ']' << std::endl;
}

void print_nums(const std::vector<int> &nums) {
    if (nums.empty())
        std::cout << "\n[] - the list is empty" << std::endl;
    else
        print_format(nums);
}

void add_nums(std::vector<int> &nums) {
    std::string numstr;
    std::cout << "\nEnter integer(s): ";
    std::cin.ignore();
    getline(std::cin, numstr);
    std::istringstream iss(numstr);
    int number {};
    while (iss >> number)
        nums.push_back(number);
    std::cout << "\nAdded all of the integers" << std::endl;
}

void clear_list(std::vector<int> &nums) {
    if (nums.empty())
        std::cout << "\nThe list is already empty" << std::endl;
    else {
        nums.clear();
        std::cout << "\nThe list is cleared" << std::endl;
    }
}

double calc_mean(const std::vector<int> &nums) {
    int sum {};
    for (auto n: nums)
        sum += n;
    std::cout << std::fixed << std::setprecision(2);
    return (static_cast<double>(sum) / nums.size());
}

void display_mean(const std::vector<int> &nums) {
    if (nums.empty())
        std::cout << "\nUnable to calculate the mean - no data" << std::endl;
    else 
        std::cout << "\nThe mean of the integers is: " << calc_mean(nums) << std::endl;
}

int calc_smallest(const std::vector<int> &nums) {
    int smallest {nums.at(0)};
        for (auto n: nums) {
            if (n < smallest)
                smallest = n;
        }
        return smallest;
}

void display_smallest(const std::vector<int> &nums) {
    if (nums.empty())
        std::cout << "\nUnable to determine the smallest number - the list is empty" << std::endl;
    else 
        std::cout << "\nThe smallest number is: " << calc_smallest(nums) << std::endl;
}

int calc_largest(const std::vector<int> &nums) {
    int largest {nums.at(0)};
        for (auto n: nums) {
            if (n > largest)
                largest = n;
        }
        return largest;
}

void display_largest(const std::vector<int> &nums) {
    if (nums.empty())
        std::cout << "\nUnable to determine the largest number - the list is empty" << std::endl;
    else 
        std::cout << "\nThe largest number is: " << calc_largest(nums) << std::endl;
}

void quit() {
    std::cout << "\nGoodbye!" << std::endl;
}

void unknown_key() {
    std::cout << "\nUnknown selection, please try again" << std::endl;
}