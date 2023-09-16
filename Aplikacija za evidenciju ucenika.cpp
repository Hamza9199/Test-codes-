// Aplikacija za evidenciju ucenika.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Ucenik{
    string ime;
    string prezime;
    int razred;
    int ocijene[5];
};

vector<Ucenik>ucenici;

void unosUcenika() {
    int max;
    cout << "Unesite broj ucenika: ";
    cin >> max;
    cin.ignore();

    for (int i = 0; i < max; i++) {
        Ucenik ucenik;
        cout << "Unesite podatke za sljedecu osobu " << i + 1 << '\n';      
        cout << "Unesite ime ucenika: " << '\n';
        getline(cin, ucenik.ime);
        cout << "Unesite prezime ucneika: " << '\n';
        getline(cin, ucenik.prezime);
        cout << "Razred u koji ucenik ide: " << '\n';
        cin >> ucenik.razred;
        cin.ignore();

        cout << "Unesite ocjene za: " << ucenik.ime << " " << ucenik.prezime << '\n';
        for (int j = 0; j < 5; j++) {
            cout << "Unesite ocjenu za test: " << j + 1 << ": ";
            cin >> ucenik.ocijene[j];
        }
        cin.ignore();

        ucenici.push_back(ucenik);
        system("cls");
    }
}

void ispisUcenika(const string& ime, const string& prezime) {
    for (const Ucenik& ucenik : ucenici) {
        cout << endl;
        cout << "-------------------------" << '\n';
        cout << "Ime: " << ucenik.ime << '\n';
        cout << "Prezime: " << ucenik.prezime << '\n';
        cout << "Razred: " << ucenik.razred << '\n';
        for (int i = 0; i < 5; i++) {
            cout << "Ocijene: " << ucenik.ocijene[i] << " " << '\n';
        }
        cout << "-------------------------" << '\n';
    }
}

void ispisOcjena(const string& ime, const string& prezime) {
    for (const Ucenik& ucenik : ucenici) {
        if (ucenik.ime == ime && ucenik.prezime == prezime) {
            cout << "Ocjene za " << ime << " " << prezime << ":\n";
            for (int i = 0; i < 5; i++) {
                cout << "| Test " << i + 1 << ": " << ucenik.ocijene[i] << "| ";
            }
            return;
        }
    }
    cout << "Ucenik " << ime << " " << prezime << " nije pronaden.\n";

}

float izracunajProsjek(const Ucenik& ucenik) {
    float suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += ucenik.ocijene[i];
    }
    return suma / 5.0;
}

void ispisProsjeka(const string& ime, const string& prezime) {
   for (const Ucenik& ucenik : ucenici) {
        
        if (ucenik.ime == ime && ucenik.prezime == prezime) {
            float prosjek = izracunajProsjek(ucenik);
            cout << "Prosjek ocjena za " << ime << " " << prezime << " je: " << prosjek << '\n';
            return;
        }   
    }
   cout << "Unecik " << ime << " " << prezime << " nije pronaden.\n";
}

void ispisNajboljegUcenika() {
    if (ucenici.empty()) {
        cout << "Nema podataka o ucenicima.\n";
        return;
    }

    float najveciProsjek = -1;
    Ucenik najboljiUcenik;

    for (const Ucenik& ucenik : ucenici) {
        float prosjek = izracunajProsjek(ucenik);
        if (prosjek > najveciProsjek) {
            najveciProsjek = prosjek;
            najboljiUcenik = ucenik;
        }
    }

    cout << "Najbolji ucenik:\n";
    cout << "Ime: " << najboljiUcenik.ime << '\n';
    cout << "Prezime: " << najboljiUcenik.prezime << '\n';
    cout << "Razred: " << najboljiUcenik.razred << '\n';
    cout << "Prosjek ocjena: " << najveciProsjek << '\n';
}

void ucitajUcenikeIzDatoteke() {
    ifstream datoteka("ucenici.txt");
    if (!datoteka) {
        cout << "Datoteka 'ucenici.txt' nije pronađena." << endl;
        return;
    }

    Ucenik ucenik;
    while (datoteka >> ucenik.ime >> ucenik.prezime >> ucenik.razred) {
        for (int i = 0; i < 5; i++) {
            datoteka >> ucenik.ocijene[i];
        }
        ucenici.push_back(ucenik);
    }

    datoteka.close();
}

void spremiUcenikeUDatoteku() {
    ofstream datoteka("ucenici.txt");
    if (!datoteka) {
        cout << "Nemoguće otvoriti datoteku za pisanje." << endl;
        return;
    }

    for (const Ucenik& ucenik : ucenici) {
        datoteka << ucenik.ime << " " << ucenik.prezime << " " << ucenik.razred << " ";
        for (int i = 0; i < 5; i++) {
            datoteka << ucenik.ocijene[i] << " ";
        }
        datoteka << endl;
    }

    datoteka.close();
}


int main()
{
    ucitajUcenikeIzDatoteke();
    int izbor;
    do
    {
        cout << endl;
        cout << "\t::MENI::" << endl << '\n';
        cout << "1. Unesi Ucenika" << endl;
        cout << "2. Ispis ocjena" << endl;
        cout << "3. Ispis prosjeka" << endl;
        cout << "4. Ispis najboljeg ucenika" << endl;
        cout << "5. Ispis svih ucenika" << endl;
        cout << "6. Kraj programa" << endl;
        cout << "Tvoj izbor: ";
        cin >> izbor;
        system("cls");
        switch (izbor) {
        case 1:
            unosUcenika();
            break;
        case 2:
            {
                cin.ignore();
                string ime, prezime;
                cout << "Unesite ime ucenika: ";
                getline(cin, ime);
                cout << "Unesite prezime ucenika: ";
                getline(cin, prezime);
                ispisOcjena(ime, prezime);
            }
            break;
        case 3:
            {
            cin.ignore();
            string ime, prezime;
            cout << "Unesite ime ucenika: ";
            getline(cin, ime);
            cout << "Unesite prezime ucenika: ";
            getline(cin, prezime);
            ispisProsjeka(ime, prezime);
            }
            break;
        case 4:
            ispisNajboljegUcenika();
            break;
        case 5:
            {
                cin.ignore();
                string ime, prezime;
                ispisUcenika(ime, prezime); 
            }  
            break;
        case 6:
            cout << "Kraj programa." << endl;
            break;
        default:
            cout << "Nepoznat izbor, pokusajte ponovo." << endl;
            break;
        
        }
        
    } while (izbor != 6);

    spremiUcenikeUDatoteku();
    return 0;
}
