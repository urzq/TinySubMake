# TinySubMake
A playground to test tinyxml2 as a submodule + building the project with cmake, aka a basic package manager for C++.

To get the repository with its submodule:
```bash
git clone --recursive https://github.com/urzq/TinySubMake.git
```


To build the solution (or the makefile / xcode): 
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

I have just tried the compilation on windows, but it's supposed to work on other platforms aswell :)
Remember, the /build folder must **not** be versioned.
And voila ;)