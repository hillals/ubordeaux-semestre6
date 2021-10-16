#ifndef PROJET4_H
#define PROJET4_H
#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

class Vaccin
{
private:
    string type; // Suretcertin - Presksur - Fotvoir
public:
    string getTypeVaccin();
    void setTypeVaccin(string nomVaccin);
};

class Personne
{
private:
    string Nom;
    string Prenom;
    int numSS; // numéro sécurité sociale
    string tel;
    string telPort;
    string adresse;
    string ville;
    int codePostal;
    Vaccin v;
    int statusContact;   // contacté:1 - non-contacté:0
    int statusAccepte;   // accepté:1 - non-accepté:0
    string statusVaccin; // non-vacciné, 1 injection réalisée, 2 injections réalisées
    int prioritaire;
public:
    Personne()
    {
        Nom = "";
        Prenom = "";
        numSS = 0;
        tel = "";
        telPort = "";
        adresse = "";
        ville = "";
        codePostal = 0;
        statusContact = 0;
        statusAccepte = 0;
        statusVaccin = "non-vaccine";
    }
    int get_numSS();
    void set_numSS(int numss);
    string getNom();
    void setNom(string nom);
    string getPrenom();
    void setPrenom(string prenom);
    string get_telPort();
    void set_telPort(string telno);
    string getStatusVaccin();
    void setStatusVaccin(string StatusVaccin);
    int getstatusContact();
    void setstatusContact(int a);
    int getstatusAccepte();
    void setstatusAccepte(int a);
    Vaccin getVaccin();
    void setVaccin(Vaccin a);
    int getPrioritaire();
    void setPrioritaire(int a);
};

class Registre
{
private:
    map<int, Personne> leRegistre;
    map<int, Personne>::iterator it;

public: 
    void Ajout(Personne p);
    void Display();
    void Delete(int num);
    void DisplayPremier();
    void DisplayDeuxieme();
    void DisplayPasContacte();
    void DisplayAttente();
    void DisplayPrioritaire();
};
#endif

