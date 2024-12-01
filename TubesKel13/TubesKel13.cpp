#include "TubesKel13.h"
#include <iostream>

using namespace std;

void creteListParent(ListParent &Pr){
    firstP(Pr) = NULL;
    lastP(Pr) = NULL;
}

adrP createElmP(infotypeP dataP){
    adrP P = new elmP;
    infoP(P) = dataP;
    nextP(P) = NULL;
    prevP(P) = NULL;
    ListC(P).firstC = NULL;
    return P;
}

bool isEmptyP(ListParent Pr){
    if (firstP(Pr) == NULL && lastP(Pr) == NULL)
    {
        return true;
    }
    return false;
}

bool isEmptyC(ListChild C){
    if (firstC(C) == NULL)
    {
        return true;
    }
    return false;
}

void insertFirstP(ListParent &Pr, adrP P){
    if (isEmptyP(Pr) == true)
    {
        firstP(Pr) = P;
        lastP(Pr) = P;
    }else
    {
        nextP(P) = firstP(Pr);
        prevP(firstP(Pr)) = P;
        firstP(Pr) = P;
        prevP(firstP(Pr)) = NULL;
    }
}

void insertLastP(ListParent &Pr, adrP P)
{
    if(isEmptyP(Pr))
    {
        firstP(Pr) = P;
        lastP(Pr) = P;
    }else
    {
        prevP(P) = lastP(Pr);
        nextP(lastP(Pr)) = P;
        lastP(Pr) = P;
    }
}

//Menunjukan list yang ada di parent
void showP(ListParent Pr)
{
    if(isEmptyP(Pr))
    {
        cout << "Tidak ada Gerbong" << endl;
    }
    else
    {
        adrP P = firstP(Pr);
        while(P!= NULL)
        {
            cout << "List Gerbong Saat ini : " << endl;
            cout << "No Gerbong : " << infoP(P).NoGerbong << endl;
            cout << "Nama Kereta : " << infoP(P).namaKereta << endl;
            cout << "Kelas Gerbong : " << infoP(P).KelasGerbong << endl;
            cout << endl;

            P = nextP(P);
        }
    }
}

void deleteFirstP(ListParent &Pr, adrP &P)
{
    ListChild C;
    if(!isEmptyC(C))
    {
        cout <<"Penghapusan Tidak Bisa Dilakukan" << endl;
    }
    else
    {
        P = firstP(Pr);
        if(firstP(Pr) == lastP(Pr))
        {
            firstP(Pr) = NULL;
            lastP(Pr)= NULl;
        }
        else
        {
            firstP(Pr) = nextP(P);
            prevP(firstP(Pr)) = NULL;
            nextP(P) = NULL;
        }
    }
}

void deleteLastP(ListParent &Pr, adrP &P)
{
    ListChild C;
    if(!isEmptyC(C))
    {
        cout <<"Penghapusan Tidak Bisa Dilakukan" << endl;
    }
    else
    {
        P = firstP(Pr);
        if(firstP(Pr) == lastP(Pr))
        {
            firstP(Pr) = NULL;
            lastP(Pr)= NULl;
        }
        else
        {
            lastP(Pr) = prevP(P);
            nextP(lastP(Pr)) = NULL;
            prevP(P) = NULL;
        }
    }
}

adrP searchP(ListParent Pr,string Kereta, string Kelas, int InGerbong)
{
    adrP P = firstP(Pr);
    while(P != NULL && infoP(P).NoGerbong != InGerbong && infoP(P).namaKereta != Kereta && infoP(P).KelasGerbong != Kelas)
    {
        P = nextP(P);
    }
    if(P == NULL)
    {
        return NULL;
    }
    else
    {
        return P;
    }
}





