#include "projet4.h"

 string Vaccin :: getTypeVaccin()
    {
        return type;
    };
void Vaccin :: setTypeVaccin(string nomVaccin)
    {
        type = nomVaccin;
    };

int Personne :: get_numSS()
    {
        return numSS;
    };
void Personne :: set_numSS(int numss)
    {
        numSS = numss;
    };
    string Personne ::  getNom()
    {
        return Nom;
    };
 void Personne :: setNom(string nom)
    {
        Nom = nom;
    };

string Personne ::  getPrenom()
    {
        return Prenom;
    };
void Personne :: setPrenom(string prenom)
    {
        Prenom = prenom;
    };

string Personne :: get_telPort()
    {
        return telPort;
    };
void Personne :: set_telPort(string telno)
    {
        telPort = telno;
    };
string Personne :: getStatusVaccin()
    {
        return statusVaccin;
    };
void Personne :: setStatusVaccin(string StatusVaccin)
    {
        statusVaccin = StatusVaccin;
    };
int Personne :: getstatusContact()
    {
        return statusContact;
    };
void Personne :: setstatusContact(int a)
    {
        statusContact = a;
    };
int Personne :: getstatusAccepte()
    {
        return statusAccepte;
    };
void Personne :: setstatusAccepte(int a)
    {
        statusAccepte = a;
    };
Vaccin Personne :: getVaccin()
    {
        return v;
    };
void Personne :: setVaccin(Vaccin a)
    {
        v = a;
    };
int Personne :: getPrioritaire()
    {
        return prioritaire;
    };
 void  Personne :: setPrioritaire(int a)
    {
        prioritaire = a;
    }

 void Registre :: Ajout(Personne p)
    {
        int nss = p.get_numSS();
        leRegistre.insert(pair<int, Personne>(nss, p));
    }

void Registre :: Display()
    {
        int nss;
        Personne p;
        cout << "Numero Securite Sociale"
             << "\t"
             << "Prenom"
             << "\t"
             << "Nom"
             << "\t"
             << "Telephone Portable"
             << "\t"
             << "Vaccin Statut" << endl;
        for (it = leRegistre.begin(); it != leRegistre.end(); it++)
        {
            nss = (*it).first;
            p = (*it).second;
            cout << nss << "\t\t\t" << p.getPrenom() << "\t" << p.getNom() << "\t" << p.get_telPort() << "\t\t" << p.getStatusVaccin() << endl;
        }
    }
void Registre :: Delete(int num)
    {
        leRegistre.erase(num);
    }
void Registre :: DisplayPremier()
    {
        int nss;
        Personne p;
        Vaccin v;
        for (it = leRegistre.begin(); it != leRegistre.end(); it++)
        {
            nss = (*it).first;
            p = (*it).second;
            v = p.getVaccin();
            if ((p.getstatusAccepte() == 1 && p.getstatusContact() == 0 && p.getStatusVaccin() == "non-vaccine") || (p.getstatusAccepte() == 1 && p.getstatusContact() == 1 && p.getStatusVaccin() == "non-vaccine"))
            {
                cout << nss << "\t\t\t" << p.getPrenom() << "\t" << p.getNom() << "\t" << p.get_telPort() << "\t\t" << v.getTypeVaccin() << endl;
            }
        }
    }
void Registre :: DisplayDeuxieme()
    {
        int nss;
        Personne p;
        Vaccin v;
        for (it = leRegistre.begin(); it != leRegistre.end(); it++)
        {
            nss = (*it).first;
            p = (*it).second;
            v = p.getVaccin();
            if ((p.getstatusAccepte() == 1 && p.getstatusContact() == 0 && p.getStatusVaccin() == "1 injection realisee") || (p.getstatusAccepte() == 1 && p.getstatusContact() == 1 && p.getStatusVaccin() == "1 injection realisee"))
            {
                cout << nss << "\t\t\t" << p.getPrenom() << "\t" << p.getNom() << "\t" << p.get_telPort() << "\t\t" << v.getTypeVaccin() << endl;
            }
        }
    }
void Registre ::DisplayPasContacte()
    {
        int nss;
        Personne p;
        for (it = leRegistre.begin(); it != leRegistre.end(); it++)
        {
            nss = (*it).first;
            p = (*it).second;
            if (p.getstatusAccepte() == 0 && p.getstatusContact() == 0)
            {
                cout << nss << "\t\t\t" << p.getPrenom() << "\t" << p.getNom() << "\t" << p.get_telPort() << "\t" << endl;
            }
        }
    }
void Registre :: DisplayAttente()
    {
        int nss;
        Personne p;
        Vaccin v;
        for (it = leRegistre.begin(); it != leRegistre.end(); it++)
        {
            nss = (*it).first;
            p = (*it).second;
            v = p.getVaccin();
            if (p.getstatusAccepte() == 0 && p.getstatusContact() == 1)
            {
                cout << nss << "\t\t\t" << p.getPrenom() << "\t" << p.getNom() << "\t" << p.get_telPort() << "\t\t" << v.getTypeVaccin() << endl;
            }
        }
    }
void Registre :: DisplayPrioritaire(){
        int nss;
        Personne p;
        Vaccin v;
        for (it = leRegistre.begin(); it != leRegistre.end(); it++)
        {
            nss = (*it).first;
            p = (*it).second;
            v = p.getVaccin();
            if (p.getPrioritaire()==1)
            {
                cout << nss << "\t\t\t" << p.getPrenom() << "\t" << p.getNom() << "\t" << p.get_telPort() << "\t\t" << v.getTypeVaccin() << endl;
            }
        }
    }



int main()
{
    int choice;
    Registre r;
   
    while (1)
    {
        cout << "\n---------------------" << endl;
        cout << "Menu" << endl;
        cout << "\n---------------------" << endl;
        cout << "1.Insert New Patient" << endl;
        cout << "2.Display Patients" << endl;
        cout << "3.Les patients a contacter pour une premiere injection" << endl;
        cout << "4.Les patiens a contacter pour une deuxieme injection" << endl;
        cout << "5.Les patients n'ayant pas ete contactes" << endl;
        cout << "6.Les patients etant en attente d'une injection" << endl;
        cout << "7.Les patients prioritaire" << endl;
        cout << "8.Erase patient" << endl;
        cout << "9.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int a;
            string s;
            Personne p;
            Vaccin v;
            cout << "Enter numero securite sociale:";
            cin >> a;
            p.set_numSS(a);
            cout << "Enter nom:";
            cin >> s;
            p.setNom(s);
            cout << "Enter prenom:";
            cin >> s;
            p.setPrenom(s);
            cout << "Enter telephone portable:";
            cin >> s;
            p.set_telPort(s);
            cout<<"Is this patient prioritaire? [Y/N]:";
            cin >> s;
            if (s == "Y" || s == "y")
            {
                p.setPrioritaire(1);
            }
            else if (s == "N" || s == "n")
            {
                p.setPrioritaire(0);
            };
            cout << "Is this patient contacted? [Y/N]:";
            cin >> s;
            if (s == "Y" || s == "y")
            {
                p.setstatusContact(1);
            }
            else if (s == "N" || s == "n")
            {
                p.setstatusContact(0);
            };
            cout << "Is this patient accepted? [Y/N]:";
            cin >> s;
            if (s == "Y" || s == "y")
            {
                p.setstatusAccepte(1);
            }
            else if (s == "N" || s == "n")
            {
                p.setstatusAccepte(0);
            };
            if ((p.getstatusAccepte() == 1 && p.getstatusContact() == 0) || (p.getstatusAccepte() == 1 && p.getstatusContact() == 1))
            {
                cout << "Enter type vaccin:" << endl;
                cout << "1.Suretcertin" << endl;
                cout << "2.Presksur" << endl;
                cout << "3.Fotvoir" << endl;
                cin >> a;
                if (a == 1)
                {
                    v.setTypeVaccin("Suretcertin");
                }
                else if (a == 2)
                {
                    v.setTypeVaccin("Presksur");
                }
                else if (a == 3)
                {
                    v.setTypeVaccin("Fotvoir");
                }
                p.setVaccin(v);
                cout << "How many times is this patient vaccined? [0/1/2]]:";
                cin >> a;
                if (a == 0)
                {
                    p.setStatusVaccin("non-vaccine");
                }
                else if (a == 1)
                {
                    p.setStatusVaccin("1 injection realisee");
                }
                else
                {
                    p.setStatusVaccin("2 injection realisee");
                };
            }
            else if (p.getstatusAccepte() == 0 && p.getstatusContact() == 1)
            {
                cout << "Enter type vaccin:" << endl;
                cout << "1.Suretcertin" << endl;
                cout << "2.Presksur" << endl;
                cout << "3.Fotvoir" << endl;
                cin >> a;
                if (a == 1)
                {
                    v.setTypeVaccin("Suretcertin");
                }
                else if (a == 2)
                {
                    v.setTypeVaccin("Presksur");
                }
                else if (a == 3)
                {
                    v.setTypeVaccin("Fotvoir");
                }
                p.setVaccin(v);
                p.setStatusVaccin("non-vaccine");
            }
            else
            {
                p.setStatusVaccin("non-vaccine");
            };

            r.Ajout(p);
        }
        break;

        case 2:
        {
            cout << "Displaying Patients:" << endl;
            r.Display();
        }
        break;
        case 3:
        {
            cout << "Displaying Les patients a contacter pour une premiere injection:" << endl;
            r.DisplayPremier();
        }
        break;
        case 4:
        {
            cout << "Displaying Les patients a contacter pour une deuxieme injection:" << endl;
            r.DisplayDeuxieme();
        }
        break;
        case 5:
        {
            cout << "Displaying Les patients n'ayant pas ete contactes:" << endl;
            r.DisplayPasContacte();
        }
        break;
        case 6:
        {
            cout << "Displaying Les patients etant en attente d'une injection:" << endl;
            r.DisplayAttente();
        }
        break;
        case 7:
        {
            cout<<"Displaying patients prioritaire:"<<endl;
            r.DisplayPrioritaire();
        }
        break;
        case 8:
        {
            int a;
            cout << "Enter numero securite sociale:";
            cin >> a;
            r.Delete(a);
        }
        break;

        case 9:
        {
            exit(1);
        }
        break;
        default:
        {
            cout << "Wrong Choice" << endl;
        }
        }
    }
    return 0;
}