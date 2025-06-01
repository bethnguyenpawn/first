# first
### Sudoku Grid Manager

This C++ program allows users to load a Sudoku grid from a file, display it in a formatted layout, and validate its correctness according to Sudoku rules.

#### Features
1. **Grid Input**  
   - Reads Sudoku values from a text file
   - Each line specifies `row`, `column`, and `value` (e.g., `001` sets cell (0,0) to '1')
   - Validates input coordinates (0-8) and values (1-9)

2. **Error Handling**  
   - Detects and reports:
     - Invalid file access
     - Malformed input lines
     - Out-of-bound coordinates
     - Non-digit values in the grid
     - Duplicate values in rows

3. **Grid Display**  
   - Prints a formatted 9×9 Sudoku grid with block separators
   - Uses `#` for block borders and `|` + `-` for cell separators

4. **Validation**  
   - Checks for duplicate values in rows (column/block checks implied)

#### Project Structure
| File          | Purpose                                  |
|---------------|------------------------------------------|
| `sudoku.hh`   | Class definition and constants           |
| `sudoku.cpp`  | Sudoku class implementation              |
| `main.cpp`    | File I/O, user input, and grid operations|
| `input.txt`   | Example input data                       |
| `output.txt`  | Sample program output                    |
| `sudoku.pro`  | QMake project configuration              |

#### Usage
1. **Compilation**  
   ```bash
   qmake sudoku.pro
   make
   ```

2. **Execution**  
   ```bash
   ./sudoku
   Enter file name: input.txt
   ```

3. **Input Format**  
   Each line in `input.txt` must contain exactly 3 characters:  
   - First char: Row index (0-8)
   - Second char: Column index (0-8)
   - Third char: Digit (1-9)  
   Example: `532` → Sets cell (5,3) to '2'

#### Sample Output
```
#####################################
# 1 | 2 | 3 # 4 | 5 | 6 # 7 | 8 | 9 #
#---+---+---#---+---+---#---+---+---#
# 4 | 5 | 6 # 7 | 8 | 9 # 1 | 2 | 3 #
...
#####################################
Row 4 has multiple 2's!
```

#### Error Examples
- `Trying to access illegal cell (9, 1)!` → Invalid coordinate
- `Trying to set illegal character f to (3, 4)!` → Non-digit value
- `Error: the line 29g is not valid!` → Malformed input

---

This project demonstrates file handling, input validation, and grid management in C++. The Sudoku class can be extended to support full puzzle validation (columns/blocks) and solving features.
