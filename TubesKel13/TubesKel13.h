#ifndef TUBESKEL13_H_INCLUDED
#define TUBESKEL13_H_INCLUDED
#define firstP(Pr) Pr.firstP
#define lastP(Pr) Pr.lastP
#define nextP(P) P->nextP
#define prevP(P) P->prevP
#define infoP(P) P->infoP
#define ListC(P) P->ListC
#define nextC(C) C->nextC
#define infoC(C) C->infoC
#include <iostream>

using namespace std;

struct gerbong
{
    int NoGerbong;
    string namaKereta;
    string KelasGerbong;
};
struct dataPenumpang
{
    string Nama;
    string NoKursi;
    int HargaTiket;
};

typedef gerbong infotypeP;
typedef dataPenumpang infotypeC;
typedef struct elmP *adrP;
typedef struct elmC *adrC;


struct elmP
{
    infotypeP infoP;
    adrP nextP;
    adrP prevP;
    adrC ListC;
};

struct elmC
{
    infotypeC infoC;
    adrC nextC;
};

struct ListParent
{
    adrP firstP;
    adrP lastP;
};

void createListParent(ListParent &Pr);
adrP createElmP(infotypeP dataP);
bool isEmptyP(ListParent Pr);
void insertFirstP(ListParent &Pr, adrP P);
void insertLastP(ListParent &Pr, adrP P);
void showP(ListParent Pr);
void deleteFirstP(ListParent &Pr, adrP &P);
void deleteLastP(ListParent &Pr, adrP &P);
adrP searchP(ListParent Pr,string Kereta, string Kelas, int InGerbong);
adrC createElmChild(infotypeC dataC);
void insertCFirst(adrP &P, adrC C);

void showAll(ListParent Pr);
adrC searchChild(ListParent Pr, string Kereta, string Kelas, int InGerbong, string NamaPenumpang, string NoKursi, int HargaTiket );
void deleteFirstChild(adrP &P, adrC &C, ListParent Pr,string Kereta, string Kelas, int InGerbong);

#endif // TUBESKEL13_H_INCLUDED
