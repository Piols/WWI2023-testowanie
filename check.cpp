#include<bits/stdc++.h>
using namespace std;

/// Ten program nalezy oczywiscie skompilowac i uruchomic z linuxa.
int main() {
  /// Ta sekcja kompiluje pliki z odpowiednimi nazwami.
  /// Jesli masz je juz skompilowane, to nie jest potrzebne.
  /// Zakladamy, ze masz wzorcowke o nazwie wzo.cpp, brut brut.cpp  i
  /// generatorke gen.cpp w folderze z ktorego sie odpala ta checkerke.
  /// Mozna tu wrzucic wiecej flag do tych kompilacji, na przyklad te
  /// ktorymi kompilowane sa programy na olimpiadzie, czyli np. -std=c++17
  system("g++ ./gen.cpp -o gen");
  system("g++ ./wzo.cpp -o wzo");
  system("g++ ./brut.cpp -o brut");
  /// Testuj w nieskonczonosc, az nie bedzie bledu lub uzytkownik zatzyma sam.
  for (int i = 1; true; i++) {
    /// Przekazujemy aktualny index jako ziarno do generatorki, i generujemy test.
    /// Z przyczyn technicznych c++ musimy osobno skleic stringa,
    /// a potem wywolujac system wyciagnac z niego c_stringa.
    string command = "echo " + to_string(i) + " | ./gen > test.in";
    system(command.c_str());
    /// Odpalamy test na wzorcowce i zapisujemy wynik do wzo.out.
    system("./wzo < test.in > wzo.out");
    /// Odpalamy test na brucie i zapisujemy wynik do brut.out.
    system("./brut < test.in > brut.out");
    /// Sprawdzamy czy oba wyjscia sa takie same.
    /// Jesli nie sa to system("diff[...]") zwraca niezerowa liczbe i wchodzimy do ifa.
    if (system("diff wzo.out brut.out") != 0) {
      cout << "BLAD! Na tescie " << i << "\n";
      return 0;
    }
    else {
      /// Wypisywanie 'ok' po kazdym tescie nie jest koniecznie dobrym pomyslem.
      /// Wypisywanie na konsole potrafi byc wolne w porownaniu do samego testowania,
      /// spowalniajac proces znaczaca.
      /// Mozna na przyklad co iles testow, np. 100 lub 1000 informowac o progressie.
      cout << "OK " << i << "\n";
    }
  }
}
