#include "sudoku.hh"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * Reads an input file line by line and sets the values to the sudoku grid.
 * The input file should contain lines of three characters: row, column, and value.
 * Example:
 *   001  // Sets the value 1 to the top left corner
 *   014  // Sets the value 4 to the cell at row 0 and column 1
 *   027  // Sets the value 7 to the cell at row 0 and column 2
 * Erroneous lines are ignored.
 */
int main()
{
    string input_file = "input.txt";
    Sudoku sudoku;

    cout << "Enter file name: ";
    getline(cin, input_file);
    ifstream file(input_file);
    if(not file)
    {
        cout << "Error: the file " << input_file << " cannot be opened!" << endl;
        return EXIT_FAILURE;
    }

    string line;
    while(getline(file, line))
    {
        if (line.length() != 3)
        {
            cout << "Error: the line " << line << " is not valid!" << endl;
            continue;
        }

        // Deduct 48 ('0') from the ASCII value of the first characters to get the integer value
        sudoku.set(line.at(0) - '0', line.at(1) - '0', line.at(2));
    }

    sudoku.print();
    sudoku.check();
    return 0;
}
