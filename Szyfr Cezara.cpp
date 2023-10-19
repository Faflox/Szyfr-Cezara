#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

//tu ma byc funkcja i ma byc typ void

char GetInAlphapetRange(char letter)
{
    if (letter > 90) {
        return letter - 26;
    }
    else if (letter < 65)
    {
        return letter + 26;
    }
    return letter;
}


char Cipher(char letter, int shift, bool right)
{
    letter = toupper(letter);
    if (right) //PRAWO
    {
        return GetInAlphapetRange(letter + shift);
    }
    else //LEWO
    {
        return GetInAlphapetRange(letter - shift);
    }
}

int main()
{
    char wybor, kierunek;
    string tekst, zaszyfrowane;
    int przesuniecie;


    //menu glowne
    cout << "MENU GLOWNE" << endl;
    cout << "--------------" << endl;
    cout << "1. Zaszyfruj tekst" << endl;
    cout << "2. Odszyfruj tekst" << endl;
    cout << "3. Zamknij program" << endl;
    cout << "Wybierz: ";

    cin >> wybor;
    switch (wybor)
    {
    case '1':
    {
        string szyfrogram = "";
        system("cls");
        cout << "Podaj tekst do zaszyfrowania: " << endl;
        cin >> tekst;
        cout << "\nPodaj przesuniecie\n";
        cin >> przesuniecie;
        for (int i = 0; i < tekst.length(); i++)
        {
            szyfrogram += Cipher(tekst[i], przesuniecie, true);
        }
        cout << "Zaszyfrowany tekst:  \n" << szyfrogram;
        break;
    }
    case '2':
    {
        string szyfrogram = "";
        system("cls");
        cout << "Podaj tekst do odszyfrowania: " << endl;
        cin >> tekst;
        cout << "\nPodaj przesuniecie\n";
        cin >> przesuniecie;
        for (int i = 0; i < tekst.length(); i++)
        {
            szyfrogram += Cipher(tekst[i], przesuniecie, false);
        }
        cout << "Odszyfrowany tekst:  \n" << szyfrogram;
        break;
    }
    default:
        cout << "Nie ma takiej opcji w menu!";
    }
}