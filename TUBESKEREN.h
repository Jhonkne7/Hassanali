#ifndef TUBESKEREN_H_INCLUDED
#define TUBESKEREN_H_INCLUDED
#include <iostream>
using namespace std;
#include "CHILD.h"

#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define child(p) p->child


typedef struct elemen1 *adr1;

struct infotype1 {
   string nama, asalUniv;
   int nim, angkatan, scoreLomba, peringkat;
};

struct list1{
    adr1  first, last;
};

struct elemen1{
    infotype1 info;
    adr1 next;
    adr1 prev;
    adr_child child;
};





//list pertama CDLL
//lisrt ke dua DLL

//LIST PART
void createListPeserta(list1 &L); //BENER
adr1 newElementPeserta(infotype1 x); //BENER
void showAllPeserta(list1 L); //BENER
void deleteFirstPeserta(list1 &L, adr1 p); //BENER
void deleteAfterPeserta(list1 &L, adr1 p); //BENER
void deleteLastPeserta(list1 &L, adr1 p); //BENER
void insertFirstPeserta(list1 &L, adr1 p); //BENER
bool cekPeserta(list1 L, adr1 p);//BENER
void deletePeserta(list1 &L,adr1 &P, string PESER);//BENER

//ADD CHILD PART
bool cekAngkatan(adr1 p, adr_child q);//BENER
bool cekKuota(List_child L2, adr_child q);//BENER
void addChild(list1 &L, List_child &L2, adr1 p, string NAMALOMBA);//BENER
adr_child findLomba(List_child L2, string NAMALOMBA); //BENER
void showJumlahPeserta(list1 L);//BENER

//SHOW PART
void showAllPesertaNLomba(list1 L); //BENER
void showLombaPesertanya(list1 L, string nama);//BENER
void showPesertaLombanya(list1 L, string NAMALOMBA);

adr1 findPeserta(list1 L, string nama);//BENER
adr1 findPeserta2(list1 L, string nama);//BENER

void moveChild(list1 &L, adr_child q,List_child Lc);//BENER
void gantilomba(list1 &Lp,adr1 &p, List_child L, string tl, string nama);//BENER
void deleteChild(List_child &L,  list1 &LP, string R);//BENER


int selectMenu();


#endif // TUBESKEREN_H_INCLUDED
