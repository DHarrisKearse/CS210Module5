/*
 * Module5_TempConversion.cpp
 * 
 *  Date: 2/8/2026
 *  Author: Dhandeaka Harris-Kearse
 *  Purpose: Read city temperatures in Fahrenheit from a file,
 *           convert them to Celsius, and write the results to
 *           a new file.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFS;   // Input file stream
    ofstream outFS;  // Output file stream

    string cityName;
    int cityTemperatureF;
    double cityTemperatureC;

    // Open input file
    inFS.open("FahrenheitTemperature.txt");

    if (!inFS.is_open()) {
        cout << "Could not open file FahrenheitTemperature.txt." << endl;
        return 1;
    }

    // Open output file
    outFS.open("CelsiusTemperature.txt");

    if (!outFS.is_open()) {
        cout << "Could not open file CelsiusTemperature.txt." << endl;
        return 1;
    }

    // Read from input file and write to output file
    // Loop continues only while reading succeeds
    while (inFS >> cityName >> cityTemperatureF) {

        // Convert Fahrenheit to Celsius
        cityTemperatureC = (cityTemperatureF - 32) * 5.0 / 9.0;

        // Write city and Celsius temperature to output file
        outFS << cityName << " " << cityTemperatureC << endl;
    }

    // Close files
    inFS.close();
    outFS.close();

    cout << "Conversion complete. Data written to CelsiusTemperature.txt." << endl;

    return 0;
}
