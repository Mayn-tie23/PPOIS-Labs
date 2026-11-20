# Lab 2 — Oceanarium

C++17 Oceanarium management project. The domain implementation is in `Oceanarium/`,
and the original 30 Google Test cases are in `OceanariumTests/test.cpp`.

## Build from the console

Requires Visual Studio 2022 C++ build tools, CMake 3.20+, and internet access
on first configuration to retrieve Google Test.

```powershell
cmake -S lab2 -B lab2/build -G "Visual Studio 17 2022" -A x64
cmake --build lab2/build --config Debug
ctest --test-dir lab2/build -C Debug --output-on-failure
```

Run the menu application:

```powershell
.\lab2\build\Debug\OceanariumApp.exe
```

## Source groups

- MarineAnimals
- AquariumSystems
- AnimalCare
- StaffManagement
- VisitorManagement
- OperationsFinance
- OceanariumExceptions (header-only exceptions)

## Verification status

The original Visual Studio test run was reported as 30/30 passing.
The **new CMake build, CI pipeline, static analysis and coverage threshold
have not yet been executed or verified**. Do not claim >90% coverage until
the CI coverage report proves it

## Before submission

Document each class, its fields and behaviors, associations, and exceptions
according to the lab rubric. Verify coverage and resolve any CI failures.
Submit changes on a feature branch and open an instructor-approved pull request.
