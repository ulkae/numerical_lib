# 📚 NumericalLib – Biblioteka metod numerycznych w C++

Projekt zrealizowany w ramach przedmiotu **Metody Numeryczne**.  
Celem było zaimplementowanie zestawu klasycznych algorytmów numerycznych w języku C++ z zachowaniem modularnej architektury i testów jednostkowych.

---

## 🧩 Zakres funkcjonalny

### 🔢 Układy równań liniowych
- Dekompozycja LU z permutacją wierszy
- Eliminacja Gaussa (opcjonalnie)
- Obliczanie wyznacznika macierzy

### 📈 Interpolacja
- Interpolacja Newtona z różnicami dzielonymi
- Interpolacja Lagrange’a
- Horner dla wielomianów

### 📊 Aproksymacja
- Metoda najmniejszych kwadratów (LSQ)
- Aproksymacja wielomianowa

### ∫ Całkowanie numeryczne
- Kwadratura Gaussa-Legendre’a (n = 2–4)
- Metody prostokątów, trapezów, Simpsona (opcjonalnie)

### 🔄 Równania różniczkowe
- Runge-Kutta 4. rzędu
- Metoda Eulera, Heuna (opcjonalnie)

### 🔍 Równania nieliniowe
- Newton-Raphson z analityczną pochodną
- Metoda bisekcji, siecznych (opcjonalnie)

---

## 🗂 Struktura projektu

```
numerical_lib/
├── include/       # Pliki nagłówkowe (*.h)
├── src/           # Implementacje (*.cpp)
├── tests/         # Testy jednostkowe (z assert)
├── examples/      # Przykłady użycia (z funkcją main)
├── CMakeLists.txt # Plik budujący projekt (CMake)
└── README.md      # Dokumentacja projektu
```

---

## ⚙️ Wymagania systemowe

- Kompilator: GCC 7.0+ lub Clang 6.0+ z obsługą C++17
- System budowania: CMake 3.15+
- System operacyjny: Linux, macOS, Windows (z MSYS2 lub Visual Studio)

---

## 🔧 Budowanie projektu

### CMake (zalecane)

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

### Uruchomienie testów

```bash
ctest --output-on-failure
```

---

## ▶️ Przykłady użycia

### Interpolacja

```cpp
#include "interpolation.h"
int main() {
    std::vector<double> x = {1, 2, 3};
    std::vector<double> y = {2, 4, 9};
    double val = Interpolation::newton(x, y, 2.5);
    std::cout << "Wynik: " << val << std::endl;
}
```

### Układ równań

```cpp
#include "linear_systems.h"
int main() {
    std::vector<std::vector<double>> A = {{3, 2}, {1, 2}};
    std::vector<double> b = {5, 5};
    auto x = LinearSystems::solveLU(A, b);
}
```

---

## 🧪 Struktura testów

```
tests/
├── test_interpolation.cpp
├── test_ode_solver.cpp
└── ...
```

Uruchamiane przez `ctest` lub bezpośrednio jako binaria.

---

## 📄 Dokumentacja

Dokumentacja generowana przez **Doxygen** z komentarzy w `.h`:

- Opis algorytmu
- Parametry wejściowe/wyjściowe
- Przykład użycia
- Złożoność
- Uwagi dot. stabilności

Uruchomienie:

```bash
doxygen Doxyfile
```

---

## 👥 Autorzy

Autorzy: Urszula Pyka, Aleksandra Przewoznik  
Grupa: 3  
Semestr: letni 2025  

---

## 📘 Licencja

Projekt objęty licencją MIT. Szczegóły w pliku `LICENSE`.

