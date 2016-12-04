#include "list_parent.h"

using namespace std;

void createList(List_parent &L)
{
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P).noKelas = x.noKelas;
    info(P).kapasitas = x.kapasitas;

    next(P) = NULL;
    createList(child(P));

    return P;
}

void dealokasi(address_parent &P)
{
    delete P;
}

void insertFirst(List_parent &L, address_parent P)
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    if (next(Prec) == first(L))
    {
        insertLast(L,P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(List_parent &L, address_parent P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        address_parent Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void deleteFirst(List_parent &L, address_parent &P)
{
    if (next(first(L)) == first(L))
    {
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    }
    else
    {
        address_parent Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        P = first(L);
        next(Q) = next(P);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(List_parent &L, address_parent &P)
{
    if (next(first(L)) == first(L))
    {
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    }
    else
    {
        address_parent Q = first(L);
        while (next(next(Q)) != first(L))
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = next(P);
        next(P) = NULL;
    }
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
{
    if (next(Prec) == first(L))
    {
        deleteFirst(L,P);
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void printInfo(List_parent L)
{
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);

    if(first(L) != NULL)
    {
        do {
            cout << "Kelas : " << info(P).noKelas << endl;
            cout << "Kapasitas : " << info(P).kapasitas << endl;
            cout << endl;
            printInfo(child(P));
            P = next(P);
        } while((P) != first(L));
    }
}

address_parent findElm(List_parent L, infotype_parent x)
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);

    if (first(L) == NULL)
    {
        return NULL;
    }
    else
    {
        do
        {
            if (info(P).noKelas == x.noKelas)
            {
                return P;
            }
            P = next(P);
        }
        while (P != first(L));
    }
    return NULL;
}
