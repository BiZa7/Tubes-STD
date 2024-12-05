#include "TubesKel13.h"
#include <iostream>

using namespace std;

void createListParent(ListParent &Pr){
    /*IS. -
      FS membuat list gerbong */
    firstP(Pr) = NULL;
    lastP(Pr) = NULL;
}

adrP createElmP(infotypeP dataP){
    /*I.S
      F.S membuat element yang berisikan dataP */

    adrP P = new elmP;
    infoP(P) = dataP;
    nextP(P) = NULL;
    prevP(P) = NULL;
    ListC(P) = NULL;
    return P;
}

bool isEmptyP(ListParent Pr){
    if (firstP(Pr) == NULL && lastP(Pr) == NULL)
    {
        return true;
    }
    return false;
}
/*
bool CheckC(ListParent Pr, string kereta, string kelas, int InGerbong){
    adrP P = searchP(Pr, kereta, kelas, InGerbong);
    if(ListC(P) == NULL)
    {
        return true;
    }
        return false;
}
 */
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
        cout << "List Gerbong Saat ini : " << endl;
        while(P!= NULL)
        {
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
    if(ListC(firstP(Pr)) != NULL)
    {
        cout <<"Penghapusan Tidak Bisa Dilakukan" << endl;
    }
    else
    {
        P = firstP(Pr);
        if(firstP(Pr) == lastP(Pr))
        {
            firstP(Pr) = NULL;
            lastP(Pr)= NULL;
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
    if(ListC(lastP(Pr)) != NULL)
    {
        cout <<"Penghapusan Tidak Bisa Dilakukan" << endl;
    }
    else
    {
        P = firstP(Pr);
        if(firstP(Pr) == lastP(Pr))
        {
            firstP(Pr) = NULL;
            lastP(Pr)= NULL;
        }
        else
        {
            lastP(Pr) = prevP(P);
            nextP(lastP(Pr)) = NULL;
            prevP(P) = NULL;
        }
    }
}

adrP searchP(ListParent Pr)
{
    string Kereta, Kelas;
    int InGerbong;
    cout << "Masukan Nomor Gerbong yang Ingin Dicari : " ; cin >> InGerbong;
    cout << "Masukan Nama Kereta yang Ingin Dicari : " ; cin >> Kereta;
    cout << "Masukan Kelas Gerbong yang Ingin Dicari : " ; cin >> Kelas;

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


adrC createElmChild(infotypeC dataC)
{
    adrC C = new elmC;
    infoC(C) = dataC;
    nextC(C) = NULL;
}

void insertCFirst(adrP &P, adrC C)
{
    if(ListC(P) == NULL)
    {
        ListC(P) = C;
    }
    else
    {
        nextC(C) = ListC(P);
        ListC(P) = C;
    }
}

void UbahDataParent(adrP &P)
{
    cout << "Masukan Nomor Gerbong yang Baru : " ; cin >>infoP(P).NoGerbong;
    cout << "Masukan Nama Kereta yang Baru : " ; cin >>infoP(P).namaKereta;
    cout << "Masukan Kelas Gerbong yang Baru : " ; cin >>infoP(P).KelasGerbong;
}


void showAll(ListParent Pr)
{
    adrP P = firstP(Pr);

    if(firstP(Pr) == NULL)
    {
        cout << "Tidak ada gerbong" << endl;
        return;
    }

    while(P != NULL)
    {
        cout << "List Gerbong Saat ini : " << endl;
        cout << "No Gerbong : " << infoP(P).NoGerbong << endl;
        cout << "Nama Kereta : " << infoP(P).namaKereta << endl;
        cout << "Kelas Gerbong : " << infoP(P).KelasGerbong << endl;
        cout << endl;

        adrC C = ListC(P);

        if(C == NULL)
        {
            cout << "Tidak ada penumpang" << endl;
        }
        else
        {
            cout << "Data Penumpang Gerbong " << infoP(P).NoGerbong << " :" << endl;
            while(C != NULL)
            {
                cout << "Nama : " << infoC(C).Nama << endl;
                cout << "Nomor Kursi : " << infoC(C).NoKursi << endl;
                cout << "Harga Tiket : " << infoC(C).HargaTiket << endl;
                cout << endl;

                C = nextC(C);
            }
        }
        P = nextP(P);
    }
}

adrC searchChild(adrP P, adrC C)
{
    string NamaPenumpang, NoKursi;
    int HargaTiket;
    cout << "Masukan Nama Penumpang yang Ingin Dicari : " ; cin >> NamaPenumpang;
    cout << "Masukan No Kursi yang Ingin Dicari : " ; cin >> NoKursi;
    cout << "Masukan Harga Tiket yang Ingin Dicari : " ; cin >> HargaTiket;
    if(P == NULL)
    {
        cout << "Tidak ada gerbong yng dicari" << endl;
        return NULL;
    }

    C = ListC(P);

    while(C != NULL && infoC(C).Nama != NamaPenumpang && infoC(C).NoKursi != NoKursi && infoC(C).HargaTiket != HargaTiket)
    {
        C = nextC(C);
    }

    if(C == NULL)
    {
        return NULL;
    }
    else
    {
        return C;
    }
}

void deleteFirstChild(adrP &P, adrC &C)
{
    if(P == NULL)
    {
        cout << "Tidak ada data penumpang yang dapat dihapus" << endl;
    }
    else
    {
        C = ListC(P);

        if(ListC(P) == NULL)
        {
            cout << "Tidak ada data penumpang yang dapat dihapus" << endl;
        }
        else
        {
            if(nextC(ListC(P)) == NULL)
            {
                ListC(P) = NULL;
            }
            else
            {
                ListC(P) = nextC(C);
                nextC(C) = NULL;
            }
        }
    }
}

int MenghitungTotalPenumpang(ListParent Pr)
{
    adrP P = firstP(Pr);
    int i = 0;
    if(firstP(Pr) == NULL)
    {
        cout << "Tidak ada gerbong" << endl;
        return -1 ;
    }

    while(P != NULL)
    {
        adrC C = ListC(P);

        if(C == NULL)
        {
            cout << "Tidak ada penumpang" << endl;
        }
        else
        {
            while(C != NULL)
            {
                i++;
                C = nextC(C);
            }
        }
        P = nextP(P);
    }
    return i;
}
