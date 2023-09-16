// Aplikacija za evidenciju plodova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using std::cout;
using std::endl;

struct Plod {
    string naziv;
    string boja;
    double tezina;
    double cijena;
};

vector<Plod>plodovi;

Plod unosPloda() {
    int max;
    cout << "Koliko zelite unijeti plodova: " << '\n';
    cin >> max;
    cin.ignore();
    Plod plod;
    for (int i = 0; i < max; i++) {       
        cout << "Unesite naziv ploda: " << '\n';
        getline(cin, plod.naziv);
        cout << "Unesite boju ploda: " << '\n';
        getline(cin, plod.boja);
        cout << "Unesite tezinu ploda (kg): " << '\n';
        cin >> plod.tezina;
        cout << "Unesite cijenu ploda (KM): " << '\n';
        cin >> plod.cijena;
        cin.ignore();
       
        system("cls");     
    }
    return plod;
}

void ispisPlodova() {
    if (plodovi.empty()) {
        cout << "Nema podataka o plodovima." << endl;
        return;
    }
    for (const Plod& plod : plodovi) {
        cout << endl;
        cout << "---------------------------" << '\n';
        cout << "Naziv ploda: " << plod.naziv << '\n';
        cout << "Boja ploda: " << plod.boja << '\n';
        cout << "Tezina ploda: " << plod.tezina << " kg" << '\n';
        cout << "Cijena ploda: " << plod.cijena << " KM" <<'\n';
        cout << "---------------------------" << '\n';
    }
}

void najskupljiPlod(){
    if (plodovi.empty()) {
        cout << "Nema podataka o plodovima.\n";
        return;
    }

    double najvecaCijena = -1;
    Plod najskupljiPlod;

    for (const Plod& plod : plodovi) {
        if (plod.cijena > najvecaCijena) {
            najvecaCijena = plod.cijena;
            najskupljiPlod = plod;
        }
    }

    cout << "Najskuplji plod:\n";
    cout << "Naziv: " << najskupljiPlod.naziv << '\n';
    cout << "Boja: " << najskupljiPlod.boja << '\n';
    cout << "Cijena: " << najskupljiPlod.cijena << " KM" << '\n';
    cout << "Tezina: " << najskupljiPlod.tezina << " kg" << '\n';
} 

float prosjecnaTezina() {
    if (plodovi.empty()) {
        cout << "Nema podataka o plodovima." << endl;
        return 0.0;
    }
    float suma = 0;
    for (Plod& plod : plodovi) {
        suma += plod.tezina;
    }
    double prosjek = suma / plodovi.size();
    
    return prosjek;
}

void pretragaPloda() {
    if (plodovi.empty()) {
        cout << "Nema podataka o plodovima." << endl;
        return;
    }     
        int izbor;
        do {
            cout << endl;
            cout << "\t::MENI::" << endl << '\n';
            cout << "1. Pretraga po boji" << endl;
            cout << "2. Pretraga po cijeni" << endl;
            cout << "3. Nazad na meni" << endl;
            cout << "Tvoj izbor: ";
            cin >> izbor;
            cin.ignore();
            system("cls");
            switch (izbor) {
            case 1:
            {
                string boja;
                cout << "Unesi boju: " << '\n';
                getline(cin, boja);
                cout << "Plodovi sa bojom '" << boja << "':" << '\n';
                bool pronaden = false;
                for (const Plod& plod : plodovi) {
                    if (plod.boja == boja) {
                        pronaden = true;
                        cout << "----------------" << '\n';
                        cout << plod.naziv << '\n';
                        cout << "----------------" << '\n';
                    }
                }
                if (!pronaden) {
                    cout << "Nema plodova sa tom bojom. " << '\n';
                }
            }
            break;
            case 2:
            {
                double cijena;
                cout << "Unesi cijenu: " << '\n';
                cin >> cijena;
                cout << "Plodovi sa cijenom " << cijena << " KM:" << '\n';
                bool pronaden = false;
                for (const Plod& plod : plodovi) {
                    if (plod.cijena == cijena) {
                        pronaden = true;
                        cout << "----------------" << '\n';
                        cout << plod.naziv << '\n';
                        cout << "----------------" << '\n';
                    }
                }
                if (!pronaden) {
                    cout << "Nema plodova sa tom cijenom. " << '\n';
                }
            }
            break;
            case 3:
                cout << "Nazad na glavni meni." << '\n';                        
                break;
            default:
                cout << "Nepoznat izbor, pokusajte ponovo." << endl;
                break;
            }
        } while (izbor != 3);
}

void ucitajPlodoveIzDatoteke() {
    ifstream datoteka("plodovi.txt");
    if (!datoteka) {
        cout << "Datoteka 'plodovi.txt' nije pronađena." << endl;
        return;
    }

    Plod plod;
    while (datoteka >> plod.naziv >> plod.boja >> plod.tezina >> plod.cijena) {
        plodovi.push_back(plod);
    }

    datoteka.close();
}

void spremiPlodoveUDatoteku() {
    ofstream datoteka("plodovi.txt");
    if (!datoteka) {
        cout << "Nemoguće otvoriti datoteku za pisanje." << endl;
        return;
    }

    for (const Plod& plod : plodovi) {
        datoteka << plod.naziv << " " << plod.boja << " " << plod.tezina << " " << plod.cijena << " ";     
        datoteka << endl;
    }
    datoteka.close();
}

int main()
{
    ucitajPlodoveIzDatoteke();
    int izbor;
    do
    {   
        
        cout << endl;
        cout << "\t::MENI::" << endl << '\n';
        cout << "1. Unesi plod" << endl;
        cout << "2. Ispis ploda" << endl;
        cout << "3. Ispis najskupljeg ploda" << endl;
        cout << "4. Ispis prosjecne tezine ploda" << endl;
        cout << "5. Pretraga ploda (boja, cijena)" << endl;
        cout << "6. Kraj programa" << endl;
        cout << "Tvoj izbor: ";
        cin >> izbor;
        cin.ignore();

        system("cls");
        switch (izbor) {
        case 1:
            plodovi.push_back(unosPloda());
            break;
        case 2:
            ispisPlodova();
            break;
        case 3:
            najskupljiPlod();
            break;
        case 4:       
           float tezina = prosjecnaTezina();
           cout << "Prosjecna tezina svih plodova je: " << tezina << '\n';
           break;
        case 5:
            pretragaPloda();                
            break;
        case 6:
            cout << "Kraj programa." << endl;
            break;
        default:
            cout << "Nepoznat izbor, pokusajte ponovo." << endl;
            break;
        }

    } while (izbor != 6);

    spremiPlodoveUDatoteku();

    cout << endl;
    return 0;
}
