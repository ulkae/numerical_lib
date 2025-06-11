# 📚 NumericalLib – Biblioteka metod numerycznych w C++

Projekt zrealizowany w ramach przedmiotu **Metody Numeryczne**.  
Celem było zaimplementowanie zestawu klasycznych algorytmów numerycznych w języku C++ z zachowaniem modularnej architektury i testów jednostkowych.

---

## 🧩 Moduły i metody

| Moduł                       | Metoda zastosowana                            |
|----------------------------|-----------------------------------------------|
| 🔢 Interpolacja            | Interpolacja Newtona z dzielonymi różnicami  |
| 🧮 Układy równań liniowych | Dekompozycja LU                               |
| 📈 Aproksymacja            | Metoda najmniejszych kwadratów (LSQ)          |
| ∫ Całkowanie numeryczne    | Kwadratura Gaussa (Legendre, n = 2–4)         |
| 📉 Równania różniczkowe    | Runge-Kutta 4. rzędu                          |
| 🔍 Równania nieliniowe     | Newton-Raphson z analityczną pochodną         |

---

## 📁 Struktura katalogów


numerical_lib/
├── include/ # Nagłówki .h (interfejsy modułów)
├── src/ # Implementacje .cpp (logika algorytmów)
├── examples/ # Pliki demonstracyjne (z main())
├── tests/ # Testy jednostkowe z assert
├── CMakeLists.txt
└── README.md # Ten plik


---

Przykłady
Każdy plik w katalogu examples/ to osobny program. Możesz je uruchomić np.:
./example_interpolation
./example_linear_systems
./example_nonlinear

Projekt zawiera zestaw testów jednostkowych. Możesz je uruchomić np.:
./test_interpolation
./test_ode_solver

Informacje dodatkowe
Projekt stworzony z myślą o pełnej modularności (każdy plik niezależny).



Autor i kontekst
Autor: [Urszula Pyka i Aleksandra Przewoznik]
Grupa: 3
Semestr: letni 2025