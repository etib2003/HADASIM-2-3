#include <iostream>
#include <cmath>

using namespace std;

const int MAX_DIFFERENCE = 5; // Maximum difference allowed for a rectangle to be considered a square

// Function to calculate area or perimeter of a rectangle based on user input
void rectangle() {
    int height, length;
    cout << "Enter height and length:";
    cin >> height >> length;

    // Check if height and length are positive
    if (height <= 0 || length <= 0) {
        cout << "Error: Height and length must be positive.\n";
        return;
    }

    // Calculate and output area or perimeter based on conditions
    if (height == length || abs(height - length) > MAX_DIFFERENCE)
        cout << "The area of the rectangle is: " << height * length << '\n';
    else
        cout << "The perimeter of the rectangle is: " << 2 * (height + length) << '\n';
}

// Function to calculate perimeter or print triangle based on user input
void triangle() {
    int height, length, choice;
    cout << "Enter height and length: ";
    cin >> height >> length;

    // Check if height and length are positive
    if (height <= 0 || length <= 0) {
        cout << "Error: Height and length must be positive.\n";
        return;
    }

    // Prompt user for action choice
    cout << "What is the action you would like to take:\n"
        << "1) Print the perimeter of the triangle\n"
        << "2) Printing the triangle\n";
    cin >> choice;

    // Calculate perimeter or print triangle based on user choice
    if (choice == 1) {
        double triangle_side = sqrt(pow(length / 2.0, 2) + pow(height, 2));
        cout << "The perimeter of the triangle is: " << 2 * triangle_side + length << '\n';
    }
    else if (choice == 2) {
        // Check if triangle can be printed
        if (length % 2 == 0 || length > 2 * height)
            cout << "Error: The triangle cannot be printed.\n";
        else {
            // Print top part of the triangle
            cout << string((length - 1) / 2, ' ') << "*\n";

            // Calculate number of odd rows needed for middle part of the triangle
            int oddAmount = (length - 2) / 2;
            int rowsPerSet = (height - 2) / oddAmount;
            int remainingRows = (height - 2) % oddAmount;

            // Print additional odd rows if necessary
            for (int i = 0; i < remainingRows; i++) {
                cout << string((length - 2) / 2, ' ') << "***\n";
            }

            // Print the main body of the triangle
            for (int i = 1; i < oddAmount + 1; i++) {
                for (int j = 0; j < rowsPerSet; j++) {
                    cout << string((length - (2 * i + 1)) / 2, ' ');
                    cout << string(2 * i + 1, '*') << '\n';
                }
            }

            // Print bottom part of the triangle
            cout << string(length, '*') << '\n';
        }
    }
    else {
        cout << "Error: Invalid choice.\n";
    }
}

int main() {
    int choice;
    cout << "Welcome to Twitter Towers!\n\n"
        << "Which shape would you like:\n"
        << "1) Rectangle\n"
        << "2) Triangle\n"
        << "To finish, press 3\n";

    // Main loop to repeatedly prompt user for shape choice
    while (true) {
        cin >> choice;
        if (choice == 1) {
            rectangle();
        }
        else if (choice == 2) {
            triangle();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Error: Invalid choice.\n";
        }

        cout << "\nWhich shape would you like:\n"
            << "1) Rectangle\n"
            << "2) Triangle\n"
            << "To finish, press 3\n";
    }

    cout << "Finish, goodbye!\n";

    return 0;
}
