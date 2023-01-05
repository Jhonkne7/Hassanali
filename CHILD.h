#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
using namespace std;


#define first(L) L.first
#define last(L) L.last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define nil NULL


struct lomba{
    string nama;
 int kuota;
 int angkatan;
 string level;
};

typedef int infotype ;
typedef struct lomba infotypechild;
typedef struct elmlist_child *adr_child;
typedef struct elmlist *adr_parent ;

struct elmlist_child{
    infotypechild info;
    adr_child next;
    adr_child prev;

};

struct List_child{
    adr_child first;
    adr_child last;
};


void insertFirst_1301213501(List_child &L, adr_child P) ;
void createListchild(List_child &L);
adr_child alokasichild(infotypechild child);

//void dealokasichild(adr_child &P);

void insertLastChild(List_child &L, adr_child P);
void insertMember(List_child &L, adr_child P);
void deleteFirstchild(List_child &L);
void deleteLastChild(List_child &L);
void deleteAfterChild(List_child &L, adr_child Prec);
void printchild(List_child L);
adr_child findchild(List_child L, infotypechild P);

// void insertLastLomba(list2 &L2, adr2 q);
// void insertMember(list2 &L2, adr2 q);
// void deleteFirstLomba(list2 &L2);
// void deleteLastLomba(list2 &L2);
// void deleteAfterLomba(list2 &L2, adr2 prec);
// void deleteLomba(list2 &L2, infotype2 x);
// void showAllLomba(list2 L2);
// adr2 findLomba(list2 L2, infotype2 x);


#endif // CHILD_H_INCLUDED
