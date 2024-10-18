#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is a Kaprekar number in a specific base
bool isKaprekar(int number, int base)
{
    // If the number is negative or the base is less than or equal to 1, it's invalid
    if (number < 0 || base <= 1)
    {
        return false;
    }

    // Square the number
    long long squared = static_cast<long long>(number) * number;

    // Initial divisor to extract right part of the squared number
    long long divisor = 1;

    // Find the appropriate divisor for the base
    while (squared / divisor >= base)
    {
        divisor *= base;
    }

    // Check for all possible ways to split the squared number
    while (divisor > 0)
    {
        // Split the squared number into left and right parts
        long long left = squared / divisor;
        long long right = squared % divisor;

        // Check if the sum of the left and right parts equals the original number
        // Also, ensure that the right part is non-zero to avoid trivial solutions
        if (left + right == number && right > 0)
        {
            return true;
        }

        // Reduce divisor to check the next possible split
        divisor /= base;
    }

    // If no valid split is found, return false
    return false;
}

int main()
{
    int number, base;

    // Input the number and the base
    cout << "Enter a number: ";
    cin >> number;

    cout << "Enter the base: ";
    cin >> base;

    // Check if the number is a Kaprekar number in the given base
    if (isKaprekar(number, base))
    {
        cout << number << " is a Kaprekar number in base " << base << endl;
    }
    else
    {
        cout << number << " is not a Kaprekar number in base " << base << endl;
    }

    return 0;
}
