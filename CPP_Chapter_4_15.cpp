/************************************************************
 * Fast Freight Shipping Charges Calculator                 *
 *                                                          *
 * This program calculates shipping charges based on:       *
 * - Weight of the package (in kilograms)                   *
 * - Distance to be shipped (in miles)                      *
 *                                                          *
 * Rates per 500 miles:                                     *
 *   <= 2 kg     : $1.10                                    *
 *   > 2 - 6 kg  : $2.20                                    *
 *   > 6 - 10 kg : $3.70                                    *
 *   > 10 - 20kg : $4.80                                    *
 *                                                          *
 * Validation:                                              *
 * - Weight must be > 0 and <= 20                           *
 * - Distance must be >= 10 and <= 3000                     *
 *                                                          *
 * Program exits with a proper error message if input       *
 * does not meet the required range.                        *
 ************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    /************************************************************
     * Declare variables                                        *
     ************************************************************/
    double weight, rate, charges, distance;

    /************************************************************
     * Get user input                                           *
     ************************************************************/
    cout << "Enter the weight of the package (in Kilograms): ";
    cin >> weight;

    cout << "Enter the distance to be shipped (in Miles): ";
    cin >> distance;

    /************************************************************
     * Input validation                                         *
     ************************************************************/
    bool inputValid = true;

    if (weight <= 0) {
        cout << "Error: The weight of the package must be greater than 0 kg.\n";
        inputValid = false;
    }
    else if (weight > 20) {
        cout << "Error: The weight of the package must not exceed 20 kg.\n";
        inputValid = false;
    }
    else if (distance < 10) {
        cout << "Error: The minimum shipping distance is 10 miles.\n";
        inputValid = false;
    }
    else if (distance > 3000) {
        cout << "Error: The maximum shipping distance is 3000 miles.\n";
        inputValid = false;
    }

    /************************************************************
     * Calculate shipping charges if input is valid             *
     ************************************************************/
    if (inputValid) {
        // Determine rate based on weight
        if (weight <= 2)
            rate = 1.10;
        else if (weight <= 6)
            rate = 2.20;
        else if (weight <= 10)
            rate = 3.70;
        else
            rate = 4.80;

        // Calculate total charges (rounded up per 500 miles)
        charges = rate * ceil(distance / 500.0);

        // Output the shipping charges
        cout << fixed << setprecision(2);
        cout << "Shipping Charges: $" << charges << endl;
    }

    /************************************************************
     * Developer signature                                      *
     ************************************************************/
    cout << "_____________________________" << endl;
    cout << "                             " << endl;
    cout << "Developed by: Nikita Baiborodov." << endl;

    return 0;
}

