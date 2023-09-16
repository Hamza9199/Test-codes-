// Aplikacija za ledo proizvode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
using std::cout;
using std::endl;

struct Sladoled {
    string ime;
    int godProizvodnje;
    int mjesecProizvodnje;
    int danProizvodnje;
    int godRoka;
    int mjesecRoka;
    int danRoka;
    double cijena;
    string okus;
    double tezina;
    /*
    Sladoled() {
        cout << "KOLEGA SVAKA CAST.." << '\n';
    }
    */
};

struct Kutija {
    struct Sladoled;
    int kolicina;
};

vector<Sladoled>sladoledi;

void Fail() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

Sladoled unosSladoleda() {
    int max;
    cout << "Koliko zelite sladoleda da unesete: " << '\n';
    cin >> max;
    Fail();
       
    vector<Sladoled> noviSladoledi;
    Sladoled noviSladoled;
    Sladoled sladoled;
    for (int i = 0; i < max; i++) {
        cout << "Unesi ime sladoleda: " << '\n';
        cin.ignore();
        getline(cin, sladoled.ime);    
        Fail();    
        cout << "Unesi datum proizvodnje" << '\n' << '\n';      
        cout << "Godina proizvodnje: " << '\n';
        cin >> sladoled.godProizvodnje;       
        Fail();
        cin.ignore();       
        cout << "Mjesec proizvodnje: " << '\n';
        cin >> sladoled.mjesecProizvodnje;
        Fail();
        cin.ignore();
        cin.ignore();
        cout << "Dan proizvodnje: " << '\n';
        cin >> sladoled.danProizvodnje;
        cin.ignore();
        Fail();
        cout << "Unesite rok trajanja" << '\n' << '\n';
        cout << "Godina roka: " << '\n';
        cin >> sladoled.godRoka;        
        Fail();
        while (sladoled.godProizvodnje > sladoled.godRoka) {
            if (sladoled.godProizvodnje > sladoled.godRoka) {
                cout << "Molim te uozbilji se" << '\n';
                cin >> sladoled.godRoka;
            }
        }
        cout << "Mjesec roka: " << '\n';
        cin >> sladoled.mjesecRoka;
        cin.ignore();
        Fail();
        cout << "Dan roka: " << '\n';
        cin >> sladoled.danRoka;
        cin.ignore();
        Fail();
        cout << "Unesite cijenu sladoleda: " << '\n';
        cin >> sladoled.cijena;
        cin.ignore();
        Fail();
        cout << "Unesite okus sladoleda: " << '\n';
        cin >> sladoled.okus;
        cin.ignore();
        Fail();
        cout << "Unesite koliko tezi sladoled (gram): " << '\n';
        cin >> sladoled.tezina;
        cin.ignore();
        Fail();
        
            noviSladoledi.push_back(sladoled);
        
        system("cls");
    }
    
        for (const Sladoled& noviSladoled : noviSladoledi) {
            sladoledi.push_back(noviSladoled);
        }
    
    
    if (!noviSladoledi.empty()) {
        return noviSladoledi.back();
    }
}

void ispisSladoleda() {
    if (sladoledi.empty()) {
        cout << "Nema dostupni sladoleda" << endl;
        return;
    }
    
    for (const Sladoled& sladoled : sladoledi) {
        cout << endl;
        cout << "*************************************" << '\n';
        cout << "Naziv sladoleda: " << sladoled.ime << '\n';
        cout << "Godina proizvodnje: " << sladoled.danProizvodnje << "." << sladoled.mjesecProizvodnje << "." << sladoled.godProizvodnje << '\n';
        cout << "Rok trajanja: " << sladoled.danRoka << "." << sladoled.mjesecRoka << "." << sladoled.godRoka << '\n';
        cout << "Okus sladoleda: " << sladoled.okus << '\n';
        cout << "Cijena sladoleda: " << sladoled.cijena << " KM" << '\n';
        cout << "Tezina sladoleda: " << sladoled.tezina << " kg" << '\n';
        cout << "*************************************" << '\n';
    }
}

void najskupljiSladoled() {
    if (sladoledi.empty()) {
        cout << "Nema sladoleda u prodaji." << '\n';
        return;
    }

    double najvecaCijena = -1;
    Sladoled najSladoled;

    for (const Sladoled& sladoled : sladoledi) {
        if (sladoled.cijena > najvecaCijena) {
            najvecaCijena = sladoled.cijena;
            najSladoled = sladoled;
        }
    }
    cout << "*************************************" << '\n';
    cout << "Naziv sladoleda: " << najSladoled.ime << '\n';
    cout << "Godina proizvodnje: " << najSladoled.danProizvodnje << "." << najSladoled.mjesecProizvodnje << "." << najSladoled.godProizvodnje << '\n';
    cout << "Rok trajanja: " << najSladoled.danRoka << "." << najSladoled.mjesecRoka << "." << najSladoled.godRoka << '\n';
    cout << "Okus sladoleda: " << najSladoled.okus << '\n';
    cout << "Cijena sladoleda: " << najSladoled.cijena << " KM" << '\n';
    cout << "Tezina sladoleda: " << najSladoled.tezina << " kg" << '\n';
    cout << "*************************************" << '\n';
    cout << endl;
}
void najjeftinijiSladoled() {
    if (sladoledi.empty()) {
        cout << "Nema sladoleda u prodaji." << '\n';
        return;
    }

    double najmanjaCijena = numeric_limits<double>::max();;
    Sladoled najsSladoled;

    for (const Sladoled& sladoled : sladoledi) {
        if (sladoled.cijena < najmanjaCijena) {
            najmanjaCijena = sladoled.cijena;
            najsSladoled = sladoled;
        }
    }
    cout << "*************************************" << '\n';
    cout << "Naziv sladoleda: " << najsSladoled.ime << '\n';
    cout << "Godina proizvodnje: " << najsSladoled.danProizvodnje << "." << najsSladoled.mjesecProizvodnje << "." << najsSladoled.godProizvodnje << '\n';
    cout << "Rok trajanja: " << najsSladoled.danRoka << "." << najsSladoled.mjesecRoka << "." << najsSladoled.godRoka << '\n';
    cout << "Okus sladoleda: " << najsSladoled.okus << '\n';
    cout << "Cijena sladoleda: " << najsSladoled.cijena << " KM" << '\n';
    cout << "Tezina sladoleda: " << najsSladoled.tezina << " kg" << '\n';
    cout << "*************************************" << '\n';
    cout << endl;
}

float prosjecnaTezina() {
    if (sladoledi.empty()) {
        cout << "Nema dostupni sladoleda." << endl;
        return 0.0;
    }
    float suma = 0;
    for (Sladoled& sladoled : sladoledi) {
        suma += sladoled.tezina;
    }
    double prosjek = suma / sladoledi.size();

    return prosjek;
}

float prosjecnaCijena() {
    if (sladoledi.empty()) {
        cout << "Nema dostupni sladoleda." << endl;
        return 0.0;
    }
    float suma = 0;
    for (Sladoled& sladoled : sladoledi) {
        suma += sladoled.cijena;
    }
    double prosjek = suma / sladoledi.size();

    return prosjek;
}

void pretragaSladoleda() {
    if (sladoledi.empty()) {
        cout << "Nema sladoleda za pretragu." << endl;
        return;
    }
    int izbor;
    do {
        cout << endl;
        cout << "\t::MENI PRETRAGE::" << endl << '\n';
        cout << "1. Pretraga po okusu" << endl;
        cout << "2. Pretraga po cijeni" << endl;
        cout << "3. Pretraga po tezini" << '\n';
        cout << "4. Pretraga po roku trajanja" << '\n';
        cout << "5. Pretraga po godini proizvodnje" << '\n';
        cout << "6. Pretraga po nazivu sladoleda" << '\n';
        cout << "7. Nazad na meni" << endl;
        cout << "Tvoj izbor: ";
        cin >> izbor;
        Fail();
        cin.ignore();
        system("cls");
        switch (izbor) {
        case 1:
        {
            string okus;
            cout << "Unesi okus: " << '\n';
            getline(cin, okus);
            Fail();
            cout << "Sladoledi sa '" << okus << "':" << '\n';
            bool pronaden = false;
            for (const Sladoled& sladoled : sladoledi) {
                if (sladoled.okus == okus) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << sladoled.ime << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema sladoleda sa tim okusom. " << '\n';
            }
        }
        break;
        case 2:
        {
            double cijena;
            cout << "Unesi cijenu: " << '\n';
            cin >> cijena;
            Fail();
            cout << "Sladoledi sa cijenom " << cijena << " KM:" << '\n';
            bool pronaden = false;
            for (const Sladoled& sladoled : sladoledi) {
                if (sladoled.cijena == cijena) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << sladoled.ime << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema sladoleda sa tom cijenom. " << '\n';
            }
        }
        break;
        case 3:
        {
            int tezina;
            cout << "Unesi tezinu: " << '\n';
            cin >> tezina;
            Fail();
            cout << "Sladoledi sa tezinom '" << tezina << "':" << '\n';
            bool pronaden = false;
            for (const Sladoled& sladoled : sladoledi) {
                if (sladoled.tezina == tezina) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << sladoled.ime << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema sladoleda sa tom tezinom. " << '\n';
            }
        }
        break;
        case 4:
        {
            int godRoka;
            int mjesecRoka;
            int danRoka;
            cout << "Unesite rok trajanja" << '\n' << '\n';
            cout << "Dan roka: " << '\n';
            cin >> danRoka;
            cin.ignore();
            Fail();
            cout << "Mjesec roka: " << '\n';
            cin >> mjesecRoka;
            cin.ignore();
            Fail();
            cout << "Godina roka: " << '\n';
            cin >> godRoka;
            cin.ignore();
            Fail();
            cout << "Sladoled sa godinom roka '" << danRoka << "." << mjesecRoka << "." << godRoka << "':" << '\n';
            bool pronaden = false;
            for (const Sladoled& sladoled : sladoledi) {
                if (sladoled.danRoka == danRoka && sladoled.mjesecRoka == mjesecRoka && sladoled.godRoka == godRoka) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << sladoled.ime << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema sladoleda kojima istice rok trajanja te godine. " << '\n';
            }
        }
        break;
        case 5:
        {
            int godProizvodnje;
            int mjesecProizvodnje;
            int danProizvodnje;
            cout << "Unesite dan proizvodnje" << '\n' << '\n';
            cout << "Dan proizvodnje: " << '\n';
            cin >> danProizvodnje;
            cin.ignore();
            Fail();
            cout << "Mjesec proizvodnje: " << '\n';
            cin >> mjesecProizvodnje;
            cin.ignore();
            Fail();
            cout << "Godina proizvodnje: " << '\n';
            cin >> godProizvodnje;
            cin.ignore();
            Fail();
            cout << "Sladoled sa godinom proizvodnje '" << danProizvodnje << "." << mjesecProizvodnje << "." << godProizvodnje << "':" << '\n';
            bool pronaden = false;
            for (const Sladoled& sladoled : sladoledi) {
                if (sladoled.danProizvodnje == danProizvodnje && sladoled.mjesecProizvodnje == mjesecProizvodnje && sladoled.godProizvodnje == godProizvodnje) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << sladoled.ime << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema sladoleda da je napravljen te godine. " << '\n';
            }
        }
        break;
        case 6:
        {
            string ime;
            cout << "Unesi naziv sladolea: " << '\n';
            getline(cin, ime);
            Fail();
            cout << "Sladoledi sa nazivom '" << ime << "':" << '\n';
            bool pronaden = false;
            for (const Sladoled& sladoled : sladoledi) {
                if (sladoled.ime == ime) {
                    pronaden = true;
                    cout << "----------------" << '\n';
                    cout << sladoled.ime << '\n';
                    cout << "----------------" << '\n';
                }
            }
            if (!pronaden) {
                cout << "Nema sladoleda sa tim nazivom. " << '\n';
            }
        }
        break;
        case 7:
            cout << "Nazad na glavni meni." << '\n';
            break;
        default:
            cout << "Nepoznat izbor, pokusajte ponovo." << endl;
            break;
        }
    } while (izbor != 7);
}

void kupovinaSladoleda(int& novac) {
    if (sladoledi.empty()) {
        cout << "Nema dostupni sladoleda za prodaju." << endl;
        return;
    }

    for (Sladoled& sladoled : sladoledi) {
        string naziv;
        string okus;
        
        cout << "Unesi sladoled koji zelis da kupis od ponudenih (provjeri ispis sladoleda)" << '\n' << '\n';
        cout << "Unesi naziv sladoleda: ";       
        getline(cin, naziv);      
        Fail();
        cout << "Unesi okus sladoleda: ";      
        getline(cin, okus);
        Fail();      

            if (naziv == sladoled.ime && okus == sladoled.okus && novac >= sladoled.cijena) {
            novac -= sladoled.cijena;
            cout << "Izvolite svoj sladoled: " << '\n';
            cout << sladoled.ime << " - " << sladoled.okus << " - " << sladoled.cijena << " KM" << '\n';
                for (auto ova = sladoledi.begin(); ova != sladoledi.end(); ++ova) {
                     if (ova->ime == naziv && ova->okus == okus && novac >= ova->cijena) {
                        novac -= ova->cijena;
                        sladoledi.erase(ova);
                        break;  
                     }
                }
                break;
            }
            
            else {
                cout << "Nemate dovoljno novca" << '\n';
                return;
            }
    }
}



void ucitajSladoledeIzDatoteke() {
    ifstream datoteka("sladoledi.txt");
    if (!datoteka) {
        cout << "Datoteka 'sladoledi.txt' nije pronađena." << endl;
        return;
    }

    Sladoled sladoled;
    while (datoteka >> sladoled.ime >> sladoled.danProizvodnje >> sladoled.mjesecProizvodnje >> sladoled.godProizvodnje >> sladoled.danRoka >> sladoled.mjesecRoka >> sladoled.godRoka >> sladoled.cijena >> sladoled.okus >> sladoled.tezina) {
        sladoledi.push_back(sladoled);
    }

    datoteka.close();
}

void spremiSladoledeUDatoteku() {
    ofstream datoteka("sladoledi.txt");
    if (!datoteka) {
        cout << "Nemoguće otvoriti datoteku za pisanje." << endl;
        return;
    }

    for (const Sladoled& sladoled : sladoledi) {
        datoteka << sladoled.ime << " " << sladoled.danProizvodnje << " " << sladoled.mjesecProizvodnje << " " << sladoled.godProizvodnje << " " << sladoled.danRoka << " " << sladoled.mjesecRoka << " " << sladoled.godRoka << " " << sladoled.cijena << " " << sladoled.okus << " " << sladoled.tezina << " ";
        datoteka << endl;
    }
    datoteka.close();
}


int main()
{
    ucitajSladoledeIzDatoteke();
    int izbor;
    int novac = 0;   
    do
    {
        cout << endl;
        cout << "\t::MENI::" << endl << '\n';
        cout << "1. Unesi sladoled" << endl;
        cout << "2. Ispis dostupni sladoleda" << endl;
        cout << "3. Ispis najskupljeg sladoleda" << endl;
        cout << "4. Ispis najjeftinijeg sladoleda" << '\n';
        cout << "5. Ispis prosjecne tezine sladoleda" << endl;
        cout << "6. Ispis prosjecne cijene sladoleda" << '\n';
        cout << "7. Pretraga sladoleda (okus, ime, cijena, tezina, godini proivodnje, roku trajanja)" << endl;
        cout << "8. Stanje/Uplata na racun" << '\n';
        cout << "9. Kupovina dostupnog sladoleda" << '\n';
        cout << "10. Kraj programa" << endl;
        cout << "Tvoj izbor: ";
        cin >> izbor;
        Fail();
        cin.ignore();
        system("cls");
     
        switch (izbor) {
        case 1:
        {           
            unosSladoleda();
        }
            break;
        case 2:
            ispisSladoleda();
            break;
        case 3:
            najskupljiSladoled();
            break;
        case 4:
            najjeftinijiSladoled();
            break;
        case 5:
        {
            float tezina = prosjecnaTezina();
            cout << "Prosjecna tezina svih sladoleda je: " << tezina << '\n';
        }
        break;
        case 6:
        {
            float cijena = prosjecnaCijena();
            cout << "Prosjecna cijena svih sladoleda je: " << cijena << '\n';
        }
        break;
        case 7:
            pretragaSladoleda();
            break;
        case 8:
        {
            int izbori;
            do {              
                cout << endl;
                cout << "\t::MENI KUPOVINE::" << endl << '\n';
                cout << "1. Uplatite novac na racuna" << '\n';
                cout << "2. Provjerite stanje racuna" << '\n';
                cout << "3. Isplatite novac sa racuna" << '\n';
                cout << "4. Povratak na glavni meni" << '\n';
                cin >> izbori;
                Fail();
                system("cls");
                switch (izbori) {
                    case 1:
                    {
                        int noviNovac;
                        cout << "Unesite novac na racun: " << '\n';
                        cin >> noviNovac;
                        Fail();
                        novac = novac + noviNovac;
                    }
                    break;
                    case 2:
                    {
                        cout << "Stanje racuna" << '\n';
                        cout << novac << '\n';
                    }
                    break;
                    case 3:
                    {
                        int minusNovac;
                        cout << "Koliko zelite uzeti novca sa racuna: " << '\n';
                        cin >> minusNovac;
                        Fail();
                        if (minusNovac > novac) {
                            cout << "Nemas toliko sredstava na racunu" << '\n';
                            break;
                        }
                        novac = novac - minusNovac;
                    }
                    break;
                    case 4:
                    {
                        cout << "Povratak na glavni meni" << '\n';
                    }
                    break;
                }
            } while (izbori != 4);
            break;
        }
        case 9:
            kupovinaSladoleda(novac);      
        break;
        case 10:
            cout << "MARS NAPOLJE PICKICE MALA!" << endl;
            break;
        default:
            cout << "Nepoznat izbor, pokusajte ponovo." << endl;
            break;
        }
    } while (izbor != 10);
    
    spremiSladoledeUDatoteku();

    cout << endl;
    return 0;
}