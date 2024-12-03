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


#endif // TUBESKEL13_H_INCLUDED
