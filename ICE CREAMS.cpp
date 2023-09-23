// Aplikacija za ledo proizvode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <ctime>

using namespace std;
using std::cout;
using std::endl;
using std::getline;
using std::cin;

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
    Sladoled sladoled;
    int kolicina;
};

vector<Sladoled>sladoledi;

void Fail() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void printRedText(const string& text) {
    cout << "\x1B[31m" << text << "\x1B[0m";
}

void printGreenText(const string& text) {
    cout << "\x1B[32m" << text << "\x1B[0m"; 
}

void printBlueText(const string& text) {
    cout << "\x1B[34m" << text << "\x1B[0m"; 
}

void printYellowText(const string& text) {
    cout << "\x1B[33m" << text << "\x1B[0m";
}

Sladoled unosSladoleda() {
        
    Sladoled sladoled;  
    cin.ignore();
        
        cout << "Unesi ime sladoleda: " << '\n';      
        getline(cin, sladoled.ime);    
        cin.ignore();
        Fail();    
        cout << "Unesi datum proizvodnje" << '\n' << '\n';      
        cout << "Godina proizvodnje: " << '\n';
        cin >> sladoled.godProizvodnje;       
        Fail();
        cin.ignore();       
        cout << "Mjesec proizvodnje: " << '\n';
        cin >> sladoled.mjesecProizvodnje;
        Fail();
        while (sladoled.mjesecProizvodnje > 12 || sladoled.mjesecProizvodnje < 1) {
            cout << "Greska! Imamo samo 12 mjeseci u godini, ponovi unos: " << '\n';
            cin >> sladoled.mjesecProizvodnje;
            Fail();
        }   
        cin.ignore();
        cin.ignore();
        cout << "Dan proizvodnje: " << '\n';
        cin >> sladoled.danProizvodnje;
        cin.ignore();
        Fail();
        while (sladoled.danProizvodnje > 31 || sladoled.danProizvodnje < 1) {
            cout << "Greska! Imamo samo 30/31 dan u mjesecu, ponovi unos: " << '\n';
            cin >> sladoled.danProizvodnje;
            Fail();
        }
        cout << "Unesite rok trajanja" << '\n' << '\n';
        cout << "Godina roka: " << '\n';
        cin >> sladoled.godRoka;        
        Fail();
        while (sladoled.godProizvodnje > sladoled.godRoka) {           
               
            cout << "Rok trajanja je manji od godine proizvodnje, ponovi unos: " << '\n';
                cin >> sladoled.godRoka;
                Fail();
        }
        cout << "Mjesec roka: " << '\n';
        cin >> sladoled.mjesecRoka;
        cin.ignore();
        Fail();
        while (sladoled.mjesecRoka > 12 || sladoled.mjesecRoka < 1) {
            cout << "Greska! Imamo samo 12 mjeseci u godini, ponovi unos: " << '\n';
            cin >> sladoled.mjesecRoka;
            Fail();
        }
        while (sladoled.godProizvodnje == sladoled.godRoka && sladoled.mjesecRoka < sladoled.mjesecProizvodnje) {
            cout << "Greska! Mjesec roka mora biti veci od mjeseca proizvodnje, ponovi unos; " << '\n';
            cin >> sladoled.mjesecRoka;
        }
        cout << "Dan roka: " << '\n';
        cin >> sladoled.danRoka;
        cin.ignore();
        Fail();
        while (sladoled.danRoka > 31 || sladoled.danRoka < 1) {
            cout << "Greska! Imamo samo 30/31 dan u mjesecu, ponovi unos: " << '\n';
            cin >> sladoled.danRoka;
            Fail();           
        }
        while (sladoled.mjesecProizvodnje == sladoled.mjesecRoka && sladoled.godProizvodnje == sladoled.godRoka && sladoled.danProizvodnje > sladoled.danRoka) {
            cout << "Greska! Dan roka ne moze biti manji od dana proizvodnje. Ponovi unos: " << '\n';
            cin >> sladoled.danRoka;
            Fail();
        }
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
        Fail();
         
        return sladoled; 
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
        cout << "Tezina sladoleda: " << sladoled.tezina << " grama" << '\n';
        
        cout << "*************************************" << '\n';
    }
}

void isticeRok() {
    int isticeGod;
    int isticeMjesec;
    int isticeDan;

    for (Sladoled& sladoled : sladoledi) {

        isticeGod = sladoled.godRoka - sladoled.godProizvodnje;
        isticeMjesec = sladoled.mjesecRoka - sladoled.mjesecProizvodnje;
        isticeDan = sladoled.danRoka - sladoled.danProizvodnje;

        if (isticeDan < 0) {
            isticeMjesec--;
            isticeDan += 31;
        }
        if (isticeMjesec < 0) {
            isticeGod--;
            isticeMjesec += 12;
        }
        
        cout << sladoled.ime << " - " << sladoled.okus << " - " << sladoled.cijena << '\n';
        printRedText("Rok trajanja sladoleda istice za: "); cout << isticeGod << " godina, " << isticeMjesec << " mjeseci i " << isticeDan << " dana." << endl;
        printYellowText("***********************************************************\n");
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
    cout << "Tezina sladoleda: " << najSladoled.tezina << " grama" << '\n';
    cout << "*************************************" << '\n';
    cout << endl;
}
void najjeftinijiSladoled() {
    if (sladoledi.empty()) {
        cout << "Nema sladoleda u prodaji." << '\n';
        return;
    }

    double najmanjaCijena = numeric_limits<double>::max();
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
    cout << "Tezina sladoleda: " << najsSladoled.tezina << " grama" << '\n';
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
        cout << endl;
        printYellowText("                     *********************************************************************************************************\n");
        printYellowText("*****************************************************************************************************************************************************\n");
        printYellowText("*****************************************************************************************************************************************************\n");
        cout << endl;
        printBlueText("###############    ######           #############    ############       ##############     ######            ##########    ############      ######\n");
        printBlueText("###############    ######           #############    ##############    ################    ######            ##########    ##############    ######\n");
        printBlueText("######             ######           ####     ####    #####    #####    ####        ####    ######            ####          #####    #####    ######\n");
        printBlueText("######             ######           ####     ####    #####    #####    ####        ####    ######            ####          #####    #####    ######\n");
        printBlueText("###############    ######           ####     ####    #####    #####    ####        ####    ######            ##########    #####    #####    ######\n");
        printBlueText("###############    ######           #############    #####    #####    ####        ####    ######            ##########    #####    #####    ######\n");
        printBlueText("         ######    ######           #############    #####    #####    ####        ####    ######            #####         #####    #####    ######\n");
        printBlueText("         ######    #############    ####     ####    #####    #####    ####        ####    ##############    #####         #####    #####    ######\n");
        printBlueText("###############    #############    ####     ####    ##############    ################    ##############    ##########    ##############    ######\n");
        printBlueText("###############    #############    ####     ####    ############       ##############     ##############    ##########    ############      ######\n");
        cout << endl;
        printYellowText("*****************************************************************************************************************************************************\n");
        printYellowText("*****************************************************************************************************************************************************\n");
        printYellowText("                       ********************************************************************************************************\n");

        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t::MENI PRETRAGE::" << endl << '\n';
        printBlueText("1. Pretraga po okusu                                            oooooo     \n");
        printBlueText("2. Pretraga po cijeni                                         oooooooooo   \n");
        printBlueText("3. Pretraga po tezini                                        oooooooooooo  \n");
        printBlueText("4. Pretraga po roku trajanja                                 oooooooooooo  \n");
        printBlueText("5. Pretraga po godini proizvodnje                             oooooooooo  \n");
        printBlueText("6. Pretraga po nazivu sladoleda                                oooooooo   \n");
        printBlueText("7. Nazad na meni                                              ----------   \n");
        printYellowText("                                                              ||||||||||   \n");
        printYellowText("                                                               ||||||||    \n");
        printYellowText("                                                                ||||||     \n");
        printYellowText("                                                                 ||||     \n");
        printYellowText("                                                                 *||*     \n");
        printYellowText("                                                                  ||      \n");
        printYellowText("                                                                  ==      \n");
        printBlueText("Tvoj izbor: ");
        cin >> izbor;
        Fail();
        cin.ignore();
        system("cls");
        switch (izbor) {
        case 1:
        {
            string okus;
            for (const Sladoled& sladoled : sladoledi) {

                printYellowText(sladoled.ime); printBlueText(" - "); printYellowText(sladoled.okus);
                cout << endl;
                cout << "##########################################################################\n";
                cout << endl;
            }
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
            double cijena2;
            for (const Sladoled& sladoled : sladoledi) {

                printYellowText(sladoled.ime); printBlueText(" - "); cout << sladoled.cijena;
                cout << endl;
                cout << "##########################################################################\n";
                cout << endl;
            }
            cout << "Unesi cijenu: " << '\n';
            cin >> cijena2;
            Fail();
            cout << "Sladoledi sa cijenom " << cijena2 << " KM:" << '\n';
            bool pronaden = false;
            for (const Sladoled& sladoled : sladoledi) {
                if (sladoled.cijena == cijena2) {
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
            for (const Sladoled& sladoled : sladoledi) {

                printYellowText(sladoled.ime); printBlueText(" - "); cout << sladoled.tezina;
                cout << endl;
                cout << "##########################################################################\n";
                cout << endl;
            }
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
            for (const Sladoled& sladoled : sladoledi) {

                printYellowText(sladoled.ime); printBlueText(" - "); cout << sladoled.danRoka; printBlueText(" - "); cout << sladoled.mjesecRoka; printBlueText(" - "); cout << sladoled.godRoka;
                cout << endl;
                cout << "##########################################################################\n";
                cout << endl;
            }
            cout << "Unesite rok trajanja" << '\n' << '\n';
            cout << "Dan roka: " << '\n';
            cin >> danRoka;
            cin.ignore();
            Fail();
            while (danRoka > 31 || danRoka < 1) {
                cout << "Greska! Imamo samo 30/31 dan u mjesecu. Ponovi unos: " << '\n';
                cin >> danRoka;
                Fail();
            }
            cout << "Mjesec roka: " << '\n';
            cin >> mjesecRoka;
            cin.ignore();
            Fail();
            while (mjesecRoka > 12 || mjesecRoka < 1) {
                cout << "Greska! Imamo samo 12 mjeseci u godini. Ponovi unos: " << '\n';
                cin >> mjesecRoka;
                Fail();
            }
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
            for (const Sladoled& sladoled : sladoledi) {

                printYellowText(sladoled.ime); printBlueText(" - "); cout << sladoled.danProizvodnje; printBlueText(" - "); cout << sladoled.mjesecProizvodnje; printBlueText(" - "); cout << sladoled.godProizvodnje;
                cout << endl;
                cout << "##########################################################################\n";
                cout << endl;
            }
            cout << "Unesite dan proizvodnje" << '\n' << '\n';
            cout << "Dan proizvodnje: " << '\n';
            cin >> danProizvodnje;
            cin.ignore();
            Fail();
            while (danProizvodnje > 31 || danProizvodnje < 1) {
                cout << "Greska! Imamo samo 30/31 dan u mjesecu. Ponovi unos: " << '\n';
                cin >> danProizvodnje;
                Fail();
            }
            cout << "Mjesec proizvodnje: " << '\n';
            cin >> mjesecProizvodnje;
            cin.ignore();
            Fail();
            while (mjesecProizvodnje > 12 || mjesecProizvodnje < 1) {
                cout << "Greska! Imamo samo 12 mjeseci u godini. Ponovi unos: " << '\n';
                cin >> mjesecProizvodnje;
                Fail();
            }
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
            for (const Sladoled& sladoled : sladoledi) {

                printYellowText(sladoled.ime); printBlueText(" - "); printYellowText(sladoled.okus);
                cout << endl;
                cout << "##########################################################################\n";
                cout << endl;
            }
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

    bool pronad = false;
    string naziv;
    string okus;
    
    cout << "Unesi sladoled koji zelis da kupis od ponudenih (provjeri ispis sladoleda)" << '\n' << '\n';
    
    isticeRok();

    printGreenText("Unesi naziv sladoleda: ");
    getline(cin, naziv);
    Fail();
    printGreenText("Unesi okus sladoleda: ");
    getline(cin, okus);
    Fail();
    for (auto ova = sladoledi.begin(); ova != sladoledi.end(); ++ova) {
        if (ova->ime == naziv && ova->okus == okus && novac >= ova->cijena) {
            printGreenText("Izvolite svoj sladoled: ");
            cout << endl;
            cout << ova->ime << " - " << ova->okus << " - " << ova->cijena << " KM" << '\n';

            novac -= ova->cijena;
            sladoledi.erase(ova);
            pronad = true;
            break;
        }
    }
    if (!pronad) {
        cout << "Nemas para, uplati koju kintu..." << '\n';
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
        cout << endl;
        printYellowText("*****************************************************************************************************************************************************\n");
        printYellowText("    *********************************************************************************************************************************************\n");
        printYellowText("                 *****************************************************************************************************************                   \n");
        cout << endl;
       printBlueText("###############    ######           #############    ############       ##############     ######            ##########    ############      ######\n");  
       printBlueText("###############    ######           #############    ##############    ################    ######            ##########    ##############    ######\n");
       printBlueText("######             ######           ####     ####    #####    #####    ####        ####    ######            ####          #####    #####    ######\n");
       printBlueText("######             ######           ####     ####    #####    #####    ####        ####    ######            ####          #####    #####    ######\n");
       printBlueText("###############    ######           ####     ####    #####    #####    ####        ####    ######            ##########    #####    #####    ######\n");
       printBlueText("###############    ######           #############    #####    #####    ####        ####    ######            ##########    #####    #####    ######\n");
       printBlueText("         ######    ######           #############    #####    #####    ####        ####    ######            #####         #####    #####    ######\n");
       printBlueText("         ######    #############    ####     ####    #####    #####    ####        ####    ##############    #####         #####    #####    ######\n");
       printBlueText("###############    #############    ####     ####    ##############    ################    ##############    ##########    ##############    ######\n");
       printBlueText("###############    #############    ####     ####    ############       ##############     ##############    ##########    ############      ######\n");

        cout << endl;
        printYellowText("                 ******************************************************************************************************************                   \n");
        printYellowText("    **********************************************************************************************************************************************\n");
        printYellowText("******************************************************************************************************************************************************\n");
        cout << endl;
        cout << endl;
        cout << "\t::MENI::" << endl << '\n';     
        printRedText("1. Unesi sladoled                                                                                                        .-. \n");
        printRedText("2. Ispis dostupni sladoleda                                                                                             /**/ \n");
        printRedText("3. Ispis najskupljeg sladoleda                                                                                         /**/ \n");
        printRedText("4. Ispis najjeftinijeg sladoleda                                                                                      /**/ \n");
        printRedText("5. Ispis prosjecne tezine sladoleda                                                                               -- '**/ \n");
        printRedText("6. Ispis prosjecne cijene sladoleda                                                                               | ** / \n");
        printBlueText("7. Pretraga sladoleda (okus, ime, cijena, tezina, godini proizvodnje, roku trajanja)                             | ** / \n");
        printYellowText("8. Stanje/Uplata na racun                                                                                      | *** |__ \n");
        printGreenText("9. Kupovina dostupnog sladoleda                                                                               |________| \n");
        printRedText("10. Provjeri koliko je sladoledu ostalo zivota                                                               |||||||||||| \n");
        printRedText("11. Kraj programa                                                                                           |||||||||||||| \n"); 
        printRedText(" Tvoj izbor:                                                                                                 |||||||||||| \n");
        printRedText("                                                                                                              |||||||||| \n");
        printRedText("                                                                                                               |||||||| \n");
        printRedText("                                                                                                                |||||| \n");
        printRedText("                                                                                                                |____| \n");
        
        cin >> izbor;
        Fail();
        cin.ignore();
        system("cls");
           
        switch (izbor) {
        case 1:
        {      
            r:

            sladoledi.push_back(unosSladoleda());
            int izbor;

            cout << "Zelis da nastavis sa unosom sladoleda (1-DA, 2-NE)?\n";
            cin >> izbor;
            
            Fail();

            switch (izbor) {
            case 1:
                goto r;
                break;
            case 2:
                cout << "Pa nema veze ajde...\n";
                break;
            }
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
                cout << endl;
                printYellowText("*****************************************************************************************************************************************************\n");
                printYellowText("*****************************************************************************************************************************************************\n");
                printYellowText("                 *****************************************************************************************************************                   \n");
                cout << endl;
                printBlueText("###############    ######           #############    ############       ##############     ######            ##########    ############      ######\n");
                printBlueText("###############    ######           #############    ##############    ################    ######            ##########    ##############    ######\n");
                printBlueText("######             ######           ####     ####    #####    #####    ####        ####    ######            ####          #####    #####    ######\n");
                printBlueText("######             ######           ####     ####    #####    #####    ####        ####    ######            ####          #####    #####    ######\n");
                printBlueText("###############    ######           ####     ####    #####    #####    ####        ####    ######            ##########    #####    #####    ######\n");
                printBlueText("###############    ######           #############    #####    #####    ####        ####    ######            ##########    #####    #####    ######\n");
                printBlueText("         ######    ######           #############    #####    #####    ####        ####    ######            #####         #####    #####    ######\n");
                printBlueText("         ######    #############    ####     ####    #####    #####    ####        ####    ##############    #####         #####    #####    ######\n");
                printBlueText("###############    #############    ####     ####    ##############    ################    ##############    ##########    ##############    ######\n");
                printBlueText("###############    #############    ####     ####    ############       ##############     ##############    ##########    ############      ######\n");

                cout << endl;
                printYellowText("                 ******************************************************************************************************************                   \n");
                printYellowText("******************************************************************************************************************************************************\n");
                printYellowText("******************************************************************************************************************************************************\n");
                cout << endl;
                cout << endl;
                cout << "\t::MENI KUPOVINE::" << endl << '\n';
                printYellowText("1. Uplatite novac na racuna                      .--.\n");
                printYellowText("2. Provjerite stanje racuna                     | o_o |\n");
                printYellowText("3. Isplatite novac sa racuna                    |:_/ |\n");
                printYellowText("4. Povratak na glavni meni                     //   \ //\n"); 
                printYellowText("                                              (|      | )\n");
                printYellowText("                                              /'\_   _/` /\n");
                printRedText("Tvoj izbor:                                    \___)=(___/\n");
                
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
        {
          isticeRok();                        
        }
        break;
        case 11:
            cout << "AJD ISKLJUCI SINE TAJ TELEFON KO BOGA TE MOLIM...AJDE...HVALA!" << endl;
            break;
        default:
            cout << "Nepoznat izbor, pokusajte ponovo." << endl;
            break;
        }
    } while (izbor != 11);
    
    spremiSladoledeUDatoteku();
   
    cout << endl;
    return 0;
}
