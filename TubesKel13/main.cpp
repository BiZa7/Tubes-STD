#include <iostream>
#include "TubesKel13.h"
using namespace std;

int main() {
    ListParent Pr;
    createListParent(Pr);

    int choice;
    do {
        cout << "========== MENU ==========" << endl;
        cout << "1. Insert Gerbong (Depan/Belakang)" << endl;
        cout << "2. Show All Gerbong" << endl;
        cout << "3. Delete Gerbong (Beserta Penumpang)" << endl;
        cout << "4. Search Gerbong" << endl;
        cout << "5. Insert Penumpang ke Gerbong" << endl;
        cout << "6. Ubah Data Gerbong/Penumpang" << endl;
        cout << "7. Show All Data (Gerbong & Penumpang)" << endl;
        cout << "8. Search Penumpang di Gerbong Tertentu" << endl;
        cout << "9. Delete Penumpang di Gerbong Tertentu" << endl;
        cout << "10. Hitung Total Penumpang & Pendapatan Per Gerbong" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Insert Gerbong
            infotypeP dataGerbong;
            cout << "No Gerbong: "; cin >> dataGerbong.NoGerbong;
            cout << "Kapasitas Gerbong : "; cin >> dataGerbong.MaxPenumpang;
            cout << "Kelas Gerbong: "; cin >> dataGerbong.KelasGerbong;

            adrP P = createElmP(dataGerbong);
            cout << "Insert (1: Depan, 2: Belakang): ";
            int pos;
            cin >> pos;

            if (pos == 1) {
                insertFirstP(Pr, P);
            } else {
                insertLastP(Pr, P);
            }
            break;
        }
        case 2:
            showP(Pr);
            break;
        case 3: {
            // Delete Gerbong
            adrP P;
            cout << "Delete (1: Depan, 2: Belakang): ";
            int pos;
            cin >> pos;

            if (pos == 1) {
                deleteFirstP(Pr, P);
            } else {
                deleteLastP(Pr, P);
            }
            break;
        }
        case 4: {
            // Search Gerbong
            adrP P = searchP(Pr);
            if (P != NULL) {
                cout << "Gerbong ditemukan!" << endl;
                cout << "No Gerbong: " << infoP(P).NoGerbong << endl;
                cout << "Kapasitas Gerbong: " << infoP(P).MaxPenumpang << endl;
                cout << "Kelas Gerbong: " << infoP(P).KelasGerbong << endl;
            } else {
                cout << "Gerbong tidak ditemukan!" << endl;
            }
            break;
        }
        case 5: {
            // Insert Penumpang ke Gerbong
            adrP P = searchP(Pr);
            if (P != NULL) {
                infotypeC dataPenumpang;
                cout << "Nama Penumpang: "; cin >> dataPenumpang.Nama;
                cout << "Nomor Kursi: "; cin >> dataPenumpang.NoKursi;
                cout << "Harga Tiket: "; cin >> dataPenumpang.HargaTiket;

                adrC C = createElmChild(dataPenumpang);
                insertCFirst(P, C, Pr);
            } else {
                cout << "Gerbong tidak ditemukan!" << endl;
            }
            break;
        }
        case 6: {
            // Ubah Data
            cout << "1. Ubah Gerbong, 2. Ubah Penumpang: ";
            int updateChoice;
            cin >> updateChoice;

            if (updateChoice == 1) {
                adrP P = searchP(Pr);
                if (P != NULL) {
                    cout << "Ubah Kapasitar Gerbong: "; cin >> infoP(P).MaxPenumpang;
                    cout << "Ubah Kelas Gerbong: "; cin >> infoP(P).KelasGerbong;
                }
            } else if (updateChoice == 2) {
                adrP P = searchP(Pr);
                if (P != NULL) {
                    adrC C = searchChild(P, C);
                    if (C != NULL) {
                        cout << "Ubah Nama Penumpang: "; cin >> infoC(C).Nama;
                        cout << "Ubah Nomor Kursi: "; cin >> infoC(C).NoKursi;
                    }
                }
            }
            break;
        }
        case 7:
            showAll(Pr);
            break;
        case 8: {
            adrP P = searchP(Pr);
            if (P != NULL) {
                adrC C = searchChild(P, NULL);
                if (C != NULL) {
                    cout << "Penumpang Ditemukan: " << infoC(C).Nama << endl;
                }
            }
            break;
        }
        case 9: {
            adrP P = searchP(Pr);
            if (P != NULL) {
                adrC C;
                deleteFirstChild(P, C);
                if (C != NULL) {
                    cout << "Penumpang Berhasil Dihapus: " << infoC(C).Nama << endl;
                }
            }
            break;
        }
        case 10: {
            adrP P = firstP(Pr);
            while (P != NULL) {
                adrC C = ListC(P);
                int totalPenumpang = 0, totalPendapatan = 0;
                while (C != NULL) {
                    totalPenumpang++;
                    totalPendapatan += infoC(C).HargaTiket;
                    C = nextC(C);
                }
                cout << "Gerbong " << infoP(P).NoGerbong << ": " << totalPenumpang
                     << " Penumpang, Pendapatan: Rp" << totalPendapatan << endl;
                P = nextP(P);
            }
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
