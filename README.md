# Lab 2 Mycat

## Team

 - [Danylo Sluzhynskyi](https://github.com/sluzhynskyi)

## Prerequisites

 - **C++ compiler** - needs to support **C++17** standard
 - **CMake** 3.15+
 
The rest prerequisites (such as development libraries) can be found in the [packages file](./apt_packages.txt) in the form of the apt package manager package names.

## Installing

1. Clone the project.
    ```bash
    git clone https://github.com/sluzhynskyi/mycat.git
    ```
2. Install required libraries. On Ubuntu:
   ```bash
   sed 's/\r$//' apt_packages.txt | sed 's/#.*//' | xargs sudo apt-get install -y
   ```
3. Build.
    ```bash
    cmake -G"Unix Makefiles" -Bbuild
    cmake --build build
    ```

## Usage

```bash
mycat [-h|--help] [-A] <file1> <file2> ... <fileN> 
```
Help flags `-h`/`--help` support is available.
