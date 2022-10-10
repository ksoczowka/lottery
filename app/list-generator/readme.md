# Generator listy
## Co to jest i jak to działa?
Jest to aplikacja pomocnicza!!!<br>
Aplikacja generuje listę przedmiotów na użytek aplikacji do obsługi listy w tym formacie
### Formatowanie listy
Poprawny format listy to:
><code style="background-color: black; color: white;"><i>Nazwa przedmiotu[tab]ilość</i></code>
><br><code style="background-color: black; color: white;"><i>[tab]</i></code> - pojedyncza tabulacja (sprawdź, czy nie została zmieniona na spacje)
<p>Poprawny zapis został umieszczony w pliku <code style="background-color: black; color: white;"><i>example.txt</i></code></p>
### Użytkowanie aplikacji
<p>Po sfromatowaniu listy możemy zacząć korzystać z aplikacji</p>
<p>Są 2 sposoby na jakie możemy użyć generatora</p>
#### Sposób I:
> W terminalu w odpowiednim katalogu/folderze wpisujemy:
>> <code style="background-color: black; color: white;"><i>./Generator [ścieżka do pliku]</i></code>
#### Sposób II:
> Włączamy aplikację klikając na plik <code style="background-color: black; color: white;"><i>Generator</i></code> (linux) lub <code style="background-color: black; color: white;"><i>Generator.exe</i></code> (Windows)
### Po wygenerowaniu listy
Po wygenerowaniu listy powinniśmy otrzymać plik <code style="background-color: black; color: white;"><i>list.lottery</i></code> i ten plik przenosimy do katalogu/folderu o nazwie <code style="background-color: black; color: white;"><i>lottery/</i></code>
<p><b>Uwaga!!!</b> W katalagu znajdują się pliki <code style="background-color: black; color: white;"><i>example.txt</i></code> i <code style="background-color: black; color: white;"><i>list-example.lottery</i></code>. Służą jako podgląd tego co należy wprowadzić do aplikacji i co aplikacja wygeneruje</p>
### Disclaimer
Program był testowany tylko na systemie linux i jest napisany pod ten system, jeżeli nie będzie działać na innych systemach polecam go przekompilować na sprzęcie na którym ma być użytkowany.
#### Zależności
Kompilator z obsługą c++20
> <p>Aplikacja była testowana z gcc w wersji 12.1.0</p>
> <p>W celu skompilowania aplikacji na systemie windows polecam użyć minGW w najnowszej obecnie wydanej wersji</p>
> <p>Nie zalecam kompilowania tej aplikacji przy pomocy niczego innego niż terminal/cmd/powershell. Może to skutkować błędami, których nie przewidziałem w fazie produkcji</p>
> <p>Jeżeli będzie potrzebna pomoc, proszę o kontakt</p>