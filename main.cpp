#include <iostream>
#include "list_parent.h"
#include "list_child.h"
#include "cstdlib"
using namespace std;

int pil;
List_parent LP;
address_parent P;
address_child Q;
address_parent R;
address_child C;

void menuUtama();
void menuInsertData();
void menuFindData();
void menuDeleteData();
void menuViewData();
void menuReportData();
void menuEditData();
void menuSortData();
void findDataMhs();
void findDataKelas();
void deleteDataMhs();
void deleteDataKelas();

int main()
{
    createList(LP);
    system("CLS");

    /** Menu utama */
    menuUtama();

    return 0;
}

void menuUtama()
{
    system("CLS");
    cout << "------------------------------------------" << endl;
    cout << "     PROGRAM INPUT ABSENSI MAHASISWA      " << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "--------------- MENU UTAMA ---------------" << endl;
    cout << " 1. INSERT DATA                           " << endl;
    cout << " 2. VIEW DATA                             " << endl;
    cout << " 3. DELETE DATA                           " << endl;
    cout << " 4. REPORT DATA                           " << endl;
    cout << " 5. EDIT DATA                             " << endl;
    cout << " 6. SORT DATA                             " << endl;
    cout << "------------------------------------------" << endl;
    cout << " 7. EXIT                                  " << endl;
    cout << "------------------------------------------" << endl;
    cout << "Pilih Menu : ";
    cin >> pil;

    switch (pil)
    {
    case 1 :
        {
            menuInsertData();
            break;
        }
    case 2 :
        {
            menuViewData();
            break;
        }
    case 3 :
        {
            // menuDeleteData();
            break;
        }
    case 4 :
        {
            // menuReportData();
            break;
        }
    case 5 :
        {
            menuEditData();
            break;
        }
    case 6 :
        {
            // menuSortData();
            break;
        }
    case 7 :
        {
            cout << endl;
            cout << " Terima kasih :)" << endl;
            break;
        }
    default :
        cout << "------------------------------------------" << endl;
        cout << "   Menu yang anda pilih tidak tersedia    " << endl;
        cout << "------------------------------------------" << endl;
        cout << endl;
        menuUtama();
    }
}

void menuInsertData()
{
    infotype_parent x;
    infotype_child y;

    system("CLS");
    cout << "------------------------------------------" << endl;
    cout << "     PROGRAM INPUT ABSENSI MAHASISWA      " << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "------------- MENU INPUT DATA ------------" << endl;
    cout << endl;
    cout << " Masukkan kelas : ";
    cin >> x.noKelas;

    cout << " Masukkan kapasitas : ";
    cin >> x.kapasitas;
    cout << endl;

    P = alokasi(x);
    insertLast(LP, P);

    for (int i=0; i<x.kapasitas; i++)
    {
        cout << "Nama : ";
        cin >> y.nama;
        cout << "NIM : ";
        cin >> y.nim;
        cout << "Kelas : ";
        cin >> y.kelas;

        C = alokasi(y);
        insertLast(child(P), C);
    }

    cout << endl;
    cout << " Data telah diinputkan" << endl;
    cout << endl;
    cout << " 1. Menu Utama " << endl;
    cout << " 2. Exit " << endl;
    cout << endl;
    cout << " Pilih Menu : ";
    cin >> pil;

    switch (pil)
    {
    case 1 :
        {
            menuUtama();
            break;
        }
    case 2 :
        {
            cout << endl;
            cout << "Makasih sayang :*" << endl;
        }
    }
}

void menuViewData()
{
    infotype_parent x;
    infotype_child y;
    List_parent L;

    system("CLS");
    cout << "------------------------------------------" << endl;
    cout << "     PROGRAM INPUT ABSENSI MAHASISWA      " << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "------------- MENU VIEW DATA -------------" << endl;
    cout << " Masukkan data yang ingin dicari          " << endl;
    cout << endl;

    if (first(L) != NULL)
    {
        cout << " Masukkan Kelas : ";
        cin >> x.noKelas;
        cout << " Masukkan NIM : ";
        cin >> y.nim;

        P = findElm(LP, x);
        if (P != NULL)
        {
            Q = findElm(child(P), y);
            if (Q != NULL)
            {
                cout << " Nama   : " << info(C).nama << endl;
                cout << " Kelas  : " << info(C).kelas << endl;
                cout << " NIM    : " << info(C).nim << endl;
            }
        }
        else
        {
            cout << " Data mahasiswa tidak ditemukan" << endl;
        }
    }

    cout << endl;
    cout << " Data telah dicari" << endl;
    cout << endl;
    cout << " 1. Menu Utama " << endl;
    cout << " 2. Exit " << endl;
    cout << endl;
    cout << " Pilih Menu : ";
    cin >> pil;

    switch (pil)
    {
    case 1 :
        {
            menuUtama();
            break;
        }
    case 2 :
        {
            cout << endl;
            cout << " Makasih sayang :*" << endl;
        }
    }
}

void menuEditData()
{
    infotype_parent x;
    infotype_child y;
    List_parent L;

    system("CLS");
    cout << "------------------------------------------" << endl;
    cout << "     PROGRAM INPUT ABSENSI MAHASISWA      " << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "-------------- MENU EDIT DATA ------------" << endl;
    cout << endl;

    cout << " Masukkan Kelas : ";
    cin >> x.noKelas;
    cout << " Masukkan NIM : ";
    cin >> y.nim;

    P = findElm(LP, x);
    if (P != NULL)
    {
        Q = findElm(child(P), y);
        if (Q != NULL)
        {
            cout << " Nama : ";
            cin >> y.nama;
            cout << " Kelas : ";
            cin >> y.kelas;

        }
    }
    else
    {
        cout << "Data mahasiswa tidak ditemukan" << endl;
    }

    cout << endl;
    cout << "Data telah diedit" << endl;
    cout << endl;
    cout << " 1. Menu Utama " << endl;
    cout << " 2. Exit " << endl;
    cout << endl;
    cout << " Pilih Menu : ";
    cin >> pil;

    switch (pil)
    {
    case 1 :
        {
            menuUtama();
            break;
        }
    case 2 :
        {
            cout << endl;
            cout << "Makasih sayang :*" << endl;
        }
    }
}

void menuDeleteData()
{
    system("CLS");
    cout << "------------------------------------------" << endl;
    cout << "     PROGRAM INPUT ABSENSI MAHASISWA      " << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "------------ MENU DELETE DATA ------------" << endl;
    cout << endl;
}
