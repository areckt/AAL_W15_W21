# Projekt z przedmiotu Analiza Algorytmów, 20Z

## Autorzy
### Arkadiusz Dawid
### Illia Yatskevich


## Temat projektu
#### Przedmiotem analizy jest tablica mieszająca: tablica przechowuje rekordy zawierające napisy. Długość tablicy jest ograniczona arbitralnie przez pewną stałą K.
#### Dla danego napisu s obliczamy k=M(s) gdzie M() jest funkcją mieszającą i umieszczamy strukturę reprezentującą napis w tablicy mieszającej: H[k].
#### W przypadku kolizji funkcji mieszającej (H[k] zajęte) reprezentujące napis s struktury danych zapisywane są w sposób alternatywny (W15).
#### Przedmiotem implementacji powinno być: dodanie i usunięcie elementów w H[]. Wybór funkcji mieszającej M(s) do decyzji projektanta.
#### Testy przeprowadzić dla: sztucznie wygenerowanych słów, generator ma posługiwać się tablicą prawdopodobieństw wystąpienia danej litery na początku słowa (początek słowa) oraz litery po poprzedzającej literze, (spacja, kropka, przecinek, itp. traktowane są jako litera specjalna "koniec słowa").
#### Prawdopodobieństwa należy uzyskać z próbki tekstu polskiego.
### W15
#### W przypadku kolizji obliczamy nową lokalizację np. tak: k2=M(s,k1) … i tak do skutku (lub do przepełnienia).
### W21
#### Zastosować jedną funkcję mieszającą; dodatkowo przeprowadzić analizę dla enumeracji tablicy (wydobycia wszystkich elementów).


## Tryby wykonania głównego programu
### Tryb 1: manualne wstawianie słów do tablicy, enumeracja
#### `./prog t1 tableSize`
#### Ten tryb pozwala ręcznie (z konsoli) wpisywać kolejne słowa, które mają być wstawione do tablicy, której pojemność jest równa argumentowi tableSize. Wpisanie znaku '0' przerywa działanie programu. Na koniec, tzn. po zapełnieniu tablicy lub wpisaniu '0', zostaje przeprowadzona enumeracja tablicy i jej zawartość zostaje wypisana na ekranie. Ten tryb pozwala testować poprawności dla małych instancji problemu.
#### Przykład: `./prog t1 11`

### Tryb 2: generacja słów i wstawianie do tablicy aż do osiągnięcia podanej wartości współczynnika wypełnienia, pomiar czasu i zapis wyników, enumeracja, możliwość wielokrotnego wykonania obliczeń i wyznaczenia średniej
#### `./prog t2 tableSize in.txt out.txt repetitions loadFactor`
#### Ten tryb pozwala wielokrotnie wykonać proces wstawiania słów do tablicy o podanej pojemności tableSize. Na podstawie tekstu zawartego w pliku in.txt obliczane są rozkłady prawdopodobieństwa, na bazie których generowane są kolejne słowa. Wypełnianie tablicy trwa aż do osiągnięcia podanego współczynnika zapełnienia loadFactor = liczba elementów w tablicy / pojemność tablicy * 100%. Wartość repetitions wskazuje, ile razy ma być przeprowadzony cały proces. Pomiary czasu i obliczona wartość średnia zostają zapisane do pliku out.txt.
#### Przykład: `./prog t2 10007 ../util/out.txt ../util/result.txt 10 50`
#### Wyjaśnienie: Pojemność tablicy ustawiona na 10007, tekst dla generatora znajduje się w pliku out.txt w równoległym folderze util, a pomiary trafią do pliku result.txt. Proces wstawiania do tabeli powtórzy się 10 razy i za każdym razem zakończy się, gdy współczynnik wypełnienia osiągnie 50%.

### Tryb 3: instrukcja
#### `./prog h`
#### Ten tryb wyświetla instrukcję objaśniającą wszystkie prawidłowe formy aktywacji programu.


## Metoda rozwiązania
#### Funkcja mieszająca przyjmuje łańcuch znaków, który następnie przekształca w nieujemną liczbę naturalną (klucz, hash). Zakładamy, że znaki w łańcuchu mają kod ascii z zakresu 97-122. Klucz ma wartość a_0 × g_n + a_1 × g_n-1 + ... + a_n × g_0 gdzie ai to wartość ascii i-tego znaku w łańcuchu, n to długość łańcucha minus 1, a g to arbitralnie dobrana liczba, najlepiej liczba pierwsza.
#### Klucz dzielimy modulo przez rozmiar tablicy i dostajemy indeks w tablicy dla słowa. Jeśli miejsce jest już zajęte, obliczamy nowy indeks przy użyciu pomocnego klucza. Powtarzamy czynność aż do znalezienia wolnego miejsca w tablicy.


## Przewodnik po plikach źródłowych
### Folder src:
* main.cpp - główna część programu
* generator.cpp - obliczanie rozkładów prawdopodobieństw na podstawie gotowego tekstu i generacja losowych słów na ich podstawie
### Folder include:
* generator.h - plik nagłówkowy dla generator.cpp
* benchmark.h - narzędzie wykorzystywane w main.cpp do pomiarów czasu
### Folder util:
* utility.cpp - Program pomocniczy do formatowania plików tekstowych - usuwa wszystkie niealfabetyczne znaki
* pan-tadeusz.txt - plik tekstowy wykorzystywany przez generator.cpp