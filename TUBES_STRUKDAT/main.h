#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
using namespace std;

struct Developer{
    string nama;
    Developer *next;
    Developer *prev;
};

struct Client{
    string nama;
    Client *next;
    Client *prev;
};

struct Relation{
    Developer *dev;
    Client *cli;
    string namaProject;
    Relation *next;
};

void createListDeveloper(Developer *&first);

void createListClient(Client *&first);

void createListRelation(Relation *&first);

void createNewDeveloper(string nama, Developer *&newDeveloper);

void createNewClient(string nama, Client *&newClient);

void createNewRelation(Developer *dev, Client *cli, string namaProject, Relation *&newRelation);

void insertFirstDeveloper(Developer *&first, Developer *newDeveloper);

void insertFirstClient(Client *&first, Client *newClient);

void insertFirstRelation(Relation *&first, Relation *newRelation);

void deleteFirstDeveloper(Developer *&first, Developer *&deletedDeveloper);

void deleteFirstClient(Client *&first, Client *&deletedClient);

void deleteFirstRelation(Relation *&first, Relation *&deletedRelation);

void printAllDeveloper(Developer *first);

void printAllClient(Client *first);

void printAllRelation(Relation *first);

#endif // MAIN_H_INCLUDED
