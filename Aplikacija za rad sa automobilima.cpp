#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <curses.h>

using namespace std;
using std::cout;
using std::endl;

struct Automobil {
    string naziv;
    string boja;
    string firma;
    double tezina;
    double cijena;
};

vector<Automobil>auti;

void Failed()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

Automobil unosAuta() {
    int max;
    cout << "Koliko zelite automobila da unesete: " << '\n';
    cin >> max;
    Failed();
    cin.ignore();

    vector<Automobil> noviAuti;

    Automobil automobil;
    for (int i = 0; i < max; i++) {
        cout << "Unesite naziv automobila: " << '\n';
        getline(cin, automobil.naziv);
        Failed();
        cout << "Unesite firmu automobila: " << '\n';
        getline(cin, automobil.firma);
        Failed();
        cout << "Unesite boju automobila: " << '\n';
        getline(cin, automobil.boja);
        Failed();
        cout << "Unesite tezinu automobila (kg): " << '\n';
        cin >> automobil.tezina;
        Failed();
        cout << "Unesite cijenu automobila (KM): " << '\n';
        cin >> automobil.cijena;
        Failed();
        cin.ignore();
       
        noviAuti.push_back(automobil);
    }

    for (const Automobil& noviAutomobil : noviAuti) {
        auti.push_back(noviAutomobil);
    }

    return noviAuti.back();
}

void ispisAuta() {
    if (auti.empty()) {
        cout << "Nema podataka o autima." << endl;
        return;
    }

    for (const Automobil& automobil : auti) {
        cout << endl;
        cout << "-------------------------" << '\n';
        cout << "Naziv auta: " << automobil.naziv << '\n';
        cout << "Firma auta: " << automobil.firma << '\n';
        cout << "Boja auta: " << automobil.boja << '\n';
        cout << "Tezina auta: " << automobil.tezina << " kg" << '\n'; 
        cout << "Cijena auta: " << automobil.cijena << " KM" << '\n';
        cout << "--------------------------" << '\n';
    }
}

void najskupljiAuto() {
    if (auti.empty()) {
        cout << "Nema podataka o autima." << '\n';
        return;
    }

    double najvecaCijena = -1;
    Automobil najskupljiAuto;

    for (const Automobil& automobil : auti) {
        if (automobil.cijena > najvecaCijena) {
            najvecaCijena = automobil.cijena;
            najskupljiAuto = automobil;
        }
    }
    cout << "******************************" << '\n';
    cout << "Najskuplji auto:\n";
    cout << "Naziv: " << najskupljiAuto.naziv << '\n';
    cout << "Firma: " << najskupljiAuto.firma << '\n';
    cout << "Boja: " << najskupljiAuto.boja << '\n';
    cout << "Cijena: " << najskupljiAuto.cijena << " KM" << '\n';
    cout << "Tezina: " << najskupljiAuto.tezina << " kg" << '\n';
    cout << "******************************" << '\n';
}

void najjeftinijiAuto() {
    if (auti.empty()) {
        cout << "Nema podataka o autima." << '\n';
        return;
    }

    double najmanjaCijena = numeric_limits<double>::max();
    Automobil najjeftinijiAuto;

    for (const Automobil& automobil : auti) {
        if (automobil.cijena < najmanjaCijena) {
            najmanjaCijena = automobil.cijena;
            najjeftinijiAuto = automobil;
        }
    }
    cout << "******************************" << '\n';
    cout << "Najjeftiniji auto:\n";
    cout << "Naziv: " << najjeftinijiAuto.naziv << '\n';
    cout << "Firma: " << najjeftinijiAuto.firma << '\n';
    cout << "Boja: " << najjeftinijiAuto.boja << '\n';
    cout << "Cijena: " << najjeftinijiAuto.cijena << " KM" << '\n';
    cout << "Tezina: " << najjeftinijiAuto.tezina << " kg" << '\n';
    cout << "*******************************" << '\n';
}

float prosjecnaTezina() {
    if (auti.empty()) {
        cout << "Nema podataka o autima." << endl;
        return 0.0;
    }
    float suma = 0;
    for (Automobil& automobil : auti) {
        suma += automobil.tezina;
    }
    double prosjek = suma / auti.size();

    return prosjek;
}

float prosjecnaCijena() {
    if (auti.empty()) {
        cout << "Nema podataka o automobilima." << endl;
        return 0.0;
    }
    float suma = 0;
    for (Automobil& automobil : auti) {
        suma += automobil.cijena;
    }
    double prosjek = suma / auti.size();

    return prosjek;
}

void pretragaAuta() {
    if (auti.empty()) {
        cout << "Nema podataka o automobilima." << endl;
        return;
    }
    int izbor;
    do {
        cout << endl;
        cout << "\t::MENI::" << endl << '\n';
        cout << "1. Pretraga po boji" << endl;
        cout << "2. Pretraga po cijeni" << endl;
        cout << "3. Pretraga po tezini" << '\n';
        cout << "4. Pretraga po firmi" << '\n';
        cout << "5. Pretraga po imenu auta" << '\n';
        cout << "6. Nazad na meni" << endl;
        cout << "Tvoj izbor: ";
        cin >> izbor;
        Failed();
        cin.ignore();
        system("cls");
        switch (izbor) {
        case 1:
        {
            string boja;
            cout << "Unesi boju: " << '\n';
            getline(cin, boja);
            Failed();
            cout << "Automobili sa bojom '" << boja << "':" << '\n';
            bool pronaden = false;
            for (const Automobil& automobil : auti) {
                if (automobil.boja == boja) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << automobil.naziv << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema automobila sa tom bojom. " << '\n';
            }
        }
        break;
        case 2:
        {
            double cijena;
            cout << "Unesi cijenu: " << '\n';
            cin >> cijena;
            Failed();
            cout << "Automobili sa cijenom " << cijena << " KM:" << '\n';
            bool pronaden = false;
            for (const Automobil& automobil : auti) {
                if (automobil.cijena == cijena) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << automobil.naziv << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema automobila sa tom cijenom. " << '\n';
            }
        }
        break;
        case 3:
        {
            int tezina;
            cout << "Unesi tezinu: " << '\n';
            cin >> tezina;
            Failed();
            cout << "Automobili sa tom tezinom '" << tezina << "':" << '\n';
            bool pronaden = false;
            for (const Automobil& automobil : auti) {
                if (automobil.tezina == tezina) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << automobil.naziv << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema automobila sa tom tezina. " << '\n';
            }
        }
        break;
        case 4:
        {
            string firma;
            cout << "Unesi firmu: " << '\n';
            getline(cin, firma);
            Failed();
            cout << "Automobili iz firme '" << firma << "':" << '\n';
            bool pronaden = false;
            for (const Automobil& automobil : auti) {
                if (automobil.firma == firma) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << automobil.naziv << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema automobila iz te firme. " << '\n';
            }
        }
        break;
        case 5:
        {
            string naziv;
            cout << "Unesi ime auta: " << '\n';
            getline(cin, naziv);
            Failed();
            cout << "Automobili sa tim imenom '" << naziv << "':" << '\n';
            bool pronaden = false;
            for (const Automobil& automobil : auti) {
                if (automobil.naziv == naziv) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << automobil.naziv << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema automobila sa tim nazivom. " << '\n';
            }
        }
        break;
        case 6:
            cout << "Nazad na glavni meni." << '\n';
            break;
        default:
            cout << "Nepoznat izbor, pokusajte ponovo." << endl;
            break;
        }
    } while (izbor != 6);
}

void ucitajAutomobileIzDatoteke() {
    ifstream datoteka("auti.txt");
    if (!datoteka) {
        cout << "Datoteka 'auti.txt' nije pronađena." << endl;
        return;
    }

    Automobil automobil;
    while (datoteka >> automobil.naziv >> automobil.firma >> automobil.boja >> automobil.tezina >> automobil.cijena) {
        auti.push_back(automobil);
    }

    datoteka.close();
}

void spremiAutomobileUDatoteku() {
    ofstream datoteka("auti.txt");
    if (!datoteka) {
        cout << "Nemoguće otvoriti datoteku za pisanje." << endl;
        return;
    }

    for (const Automobil& automobil : auti) {
        datoteka << automobil.naziv << " " << automobil.firma << " " << automobil.boja << " " << automobil.tezina << " " << automobil.cijena << " ";
        datoteka << endl;
    }
    datoteka.close();
}

int main()
{
    ucitajAutomobileIzDatoteke();
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    int izbor;
    int highlight = -1;

    do
    {
        clear();

        cout << endl;
        cout << "\t::MENI::" << endl << '\n';
        cout << "1. Unesi automobil" << endl;
        cout << "2. Ispis automobila" << endl;
        cout << "3. Ispis najskupljeg automobila" << endl;
        cout << "4. Ispis najjeftinijeg automobila" << '\n';
        cout << "5. Ispis prosjecne tezine automobila" << endl;
        cout << "6. Ispis prosjecne cijene automobila" << '\n';
        cout << "7. Pretraga automobila (boja, cijena, tezina, firma i naziv)" << endl;
        cout << "8. Kraj programa" << endl;
        cout << "Tvoj izbor: ";
        
        Failed();
        cin.ignore();

        system("cls");
        for (int i = 1; i <= 8; i++) {
            if (highlight == i) {
                attron(A_REVERSE);
            }
            mvprintw(i + 2, 0, "%d. Odaberi opciju", i);
            attroff(A_REVERSE);
        }

        izbor = getch();

        switch (izbor) {
        case KEY_UP:
            if (highlight == 1)
                highlight = 8;
            else
                highlight--;
            break;
        case KEY_DOWN:
            if (highlight == 8)
                highlight = 1;
            else
                highlight++;
            break;
        case 10: // Enter tipka
            switch (highlight) {
            case 1:
                unosAuta();
                break;
            case 2:
                ispisAuta();
                break;
            case 3:
                najskupljiAuto();
                break;
            case 4:
                najjeftinijiAuto();
                break;
            case 5:
            {
                float tezina = prosjecnaTezina();
                cout << "Prosjecna tezina svih automobila je: " << tezina << '\n';
            }
            break;
            case 6:
            {
                float cijena = prosjecnaCijena();
                cout << "Prosjecna cijena svih automobila je: " << cijena << '\n';
            }
            break;
            case 7:
                pretragaAuta();
                break;
            case 8:
                cout << "Kraj programa." << endl;
                break;
            default:
                cout << "Nepoznat izbor, pokusajte ponovo." << endl;
                break;
            }
            break;
        default:
            break;
        }

    } while (izbor != 8);

    spremiAutomobileUDatoteku();

    cout << endl;

    return 0;
}
