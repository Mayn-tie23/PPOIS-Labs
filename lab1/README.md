# PPOIS-Labs



\# PPOIS Labs



Laboratory works and projects for Design of Software for Intelligent Systems.



\## Lab 1 - Set and Polynomial



This laboratory work implements two C++ classes using object-oriented programming.



\### Set

Supports:

\- Adding and removing unique integers

\- Searching for elements

\- Union, intersection, and difference

\- Comparing and copying sets

\- Stream input and output



\### Polynomial

Supports:

\- Creating polynomials from coefficients

\- Adding, subtracting, and multiplying polynomials

\- Evaluating polynomials

\- Comparing and copying polynomials

\- Stream input and output



\## Technologies

\- C++

\- Visual Studio

\- CMake

\- Git and GitHub

\- Doxygen

\- GitHub Actions



\## Build Instructions



From the repository root:



```powershell

cmake -S lab1 -B lab1/build -G "Visual Studio 17 2022" -A x64

cmake --build lab1/build --config Debug

```



\## Run Unit Tests



```powershell

ctest --test-dir lab1/build -C Debug --output-on-failure

```



The project includes Set and Polynomial unit tests.



\## Documentation



Doxygen configuration is provided in `lab1/Doxyfile`.



Generate documentation from the `lab1` directory using:



```powershell

doxygen Doxyfile

```



\## Continuous Integration



GitHub Actions automatically builds the project and runs unit tests when changes are pushed or submitted through a pull request.



