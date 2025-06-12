# NumericalLib

*Nowoczesna Biblioteka Metod Numerycznych w C++*

Kompleksowa biblioteka metod numerycznych zaimplementowana w C++17. Projekt został stworzony w ramach przedmiotu *Metody Numeryczne* i oferuje wydajne implementacje klasycznych algorytmów numerycznych. 

## Funkcjonalności

- Modularny Design: Każdy algorytm jest samodzielny i może być używany niezależnie
- Wysoka Wydajność: Zoptymalizowane implementacje w C++17
- Dokładnie Przetestowane: Kompleksowe testy jednostkowe dla wszystkich modułów
- Edukacyjne: Czytelny kod z obszerną dokumentacją i przykładami
- Łatwa Integracja: System budowania oparty na CMake

## Szybki Start

### Wymagania

- Kompilator zgodny z C++17 (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10 lub nowszy

### Kompilacja Biblioteki

git clone https://github.com/ulkae/numerical_lib.git
cd numerical_lib
mkdir build && cd build
cmake ..
make

### Uruchamianie Przykładów

# Przykład interpolacji
./example_interpolation

# Rozwiązywanie układów równań liniowych
./example_linear_systems

# Rozwiązywanie równań nieliniowych
./example_nonlinear

# Rozwiązywanie równań różniczkowych
./example_ode_solver

# Metody całkowania
./example_integration

# Metody aproksymacji
./example_approximation

### Uruchamianie Testów

# Uruchom wszystkie testy
make test

# Lub uruchom konkretne testy
./test_interpolation
./test_ode_solver
./test_approximation
./test_integration
./test_linear_systems
./test_nonlinear

## Zaimplementowane Metody

| Moduł | Algorytm | Opis |
|-------|----------|------|
| Interpolacja | Dzielone Różnice Newtona | Interpolacja wielomianowa przez zadane punkty |
| Układy Liniowe | Dekompozycja LU | Rozwiązywanie układów równań liniowych |
| Aproksymacja | Metoda Najmniejszych Kwadratów | Dopasowywanie krzywych wielomianowych |
| Całkowanie | Kwadratura Gaussa-Legendre'a | Całkowanie numeryczne (n=2,3,4) |
| Równania Różniczkowe | Runge-Kutta 4. rzędu | Rozwiązywanie zwyczajnych równań różniczkowych |
| Równania Nieliniowe | Metoda Newtona-Raphsona | Znajdowanie pierwiastków z analitycznymi pochodnymi |

## Struktura Projektu

numerical_lib/
├── include/              # Pliki nagłówkowe (*.h)
│   ├── approximation.h
│   ├── integration.h
│   ├── interpolation.h
│   ├── linear_systems.h
│   ├── nonlinear_solver.h
│   └── ode_solver.h
├── src/                  # Pliki implementacji (*.cpp)
├── tests/                # Testy jednostkowe
├── examples/             # Przykłady użycia
├── CMakeLists.txt        # Konfiguracja budowania
└── README.md             # Ten plik

## Przykłady Użycia

### Interpolacja Newtona

#include "interpolation.h"

vector<double> x = {1, 2, 4, 7};
vector<double> y = {3, 6, 12, 24};

auto coeffs = computeNewtonCoefficients(x, y);
double wynik = newtonInterpolation(5.0, x, coeffs);

### Rozwiązywanie Układów Liniowych

#include "linear_systems.h"

vector<vector<double>> A = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
vector<double> b = {8, -11, -3};

vector<vector<double>> L, U;
luDecomposition(A, L, U);
auto z = forwardSubstitution(L, b);
auto rozwiazanie = backSubstitution(U, z);

### Całkowanie Numeryczne

#include "integration.h"

auto funkcja = [](double x) { return cos(x * x); };
double wynik = gaussLegendre(funkcja, 0.0, 1.0, 4);

### Rozwiązywanie Równań Różniczkowych

#include "ode_solver.h"

double dydt(double t, double y) {
    return y - t*t + 1;  // y' = y - t² + 1
}

auto rozwiazanie = rungeKutta4(dydt, 0.5, 0.0, 2.0, 10);

## Testowanie

Biblioteka zawiera kompleksowe testy jednostkowe dla wszystkich modułów. Każdy moduł ma dwa typy testów:

### Testy Pozytywne
Sprawdzają poprawność działania algorytmów dla standardowych przypadków użycia.

### Testy Negatywne
Sprawdzają reakcję algorytmów na przypadki brzegowe i potencjalne problemy numeryczne:

- *Aproksymacja*: Test dla wielomianów wysokiego stopnia z małą liczbą punktów
- *Całkowanie*: Test dla nieobsługiwanych rzędów kwadratury
- *Interpolacja*: Test dla identycznych wartości węzłów
- *Układy Liniowe*: Walidacja danych wejściowych i weryfikacja dokładności
- *Newton-Raphson*: Test zbieżności dla małych pochodnych
- *ODE*: Test stabilności dla dużych kroków czasowych

# Testowanie konkretnych modułów
./test_interpolation
./test_linear_systems
./test_approximation
./test_integration
./test_ode_solver
./test_nonlinear
## Dokumentacja API

### Moduł Interpolacji

- computeNewtonCoefficients(x, y) - Oblicza współczynniki interpolacji Newtona
- newtonInterpolation(x_val, x, coeffs) - Oblicza wartość interpolacji w danym punkcie

### Moduł Układów Liniowych

- luDecomposition(A, L, U) - Wykonuje dekompozycję LU macierzy A
- forwardSubstitution(L, b) - Rozwiązuje Lz = b
- backSubstitution(U, z) - Rozwiązuje Ux = z

### Moduł Całkowania

- gaussLegendre(func, a, b, n) - Całkuje funkcję na [a,b] używając n-punktowej kwadratury Gaussa-Legendre'a

### Moduł Równań Różniczkowych

- rungeKutta4(f, y0, t0, t_end, steps) - Rozwiązuje równanie różniczkowe y' = f(t,y) metodą RK4

### Moduł Równań Nieliniowych

- newtonAnalytical(f, df, x0, epsilon, max_iter) - Znajduje pierwiastek metodą Newtona-Raphsona

### Moduł Aproksymacji

- computeLeastSquares(x, y, degree) - Oblicza współczynniki wielomianu
- evaluatePolynomial(x, coeffs) - Oblicza wartość wielomianu w danym punkcie

## Autorzy

- *Urszula Pyka* 
- *Aleksandra Przewoznik* 

*Grupa:* 3  
*Semestr:* Letni 2025  
*Przedmiot:* Metody Numeryczne

## Rozwiązywanie Problemów

### Najczęstsze Problemy

*Problem:* Błąd kompilacji związany z C++17
# Rozwiązanie: Upewnij się, że używasz odpowiedniej wersji kompilatora
g++ --version  # Sprawdź wersję (wymagana 7+)

*Problem:* CMake nie znajduje plików
# Rozwiązanie: Upewnij się, że jesteś w katalogu build
mkdir build && cd build
cmake ..
