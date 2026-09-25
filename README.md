# vectory-cpp

A simple command-line list manager written in C++. Add, view, remove, and purge items from an in-memory list using `std::vector<std::string>`.

## Features

- **Show list** — display all items with their position number
- **Add to list** — append a new item
- **Remove from list** — delete an item by its number
- **Purge list** — clear the entire list (with confirmation)

## Requirements

- A C++ compiler that supports C++14 or later (e.g. `g++`, `clang++`)
- CMake 3.16 or later (matches `cmake_minimum_required(VERSION 3.16)` in `CMakeLists.txt`)

## Clone

```bash
git clone https://github.com/Benjy0812/vectory-cpp.git
cd vectory-cpp
```

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Or open the project folder in CLion (it uses its bundled CMake + MinGW toolchain) and press `Ctrl+F9` / `Build Project`. If you previously had a configure error, do `Tools > CMake > Reload CMake Project` (delete `cmake-build-debug/` if cached).

## Run

```bash
./vectory-cpp
```

On Windows:

```powershell
.\build\vectory-cpp.exe
# or, for a CLion Debug build:
.\cmake-build-debug\vectory-cpp.exe
```

## Usage

On launch, you'll see a menu:
```text
Welcome!
1. Show list
2. Add to list
3. Remove from list
4. Purge list
5. Exit
Enter here:
```

Enter the number corresponding to the action you want to perform, and follow the prompts.

| Option | Action                                              |
|:------:|:----------------------------------------------------|
|   1    | Show all items in the list                          |
|   2    | Add a new item to the list                          |
|   3    | Remove an item by its number                        |
|   4    | Purge (clear) the entire list, with y/n confirmation|
|   5    | Exit the program                                    |

## Notes

- Input is validated — invalid menu choices, non-numeric input, or out-of-range positions are handled gracefully.
- The list is stored in memory only; it resets each time the program is restarted.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
