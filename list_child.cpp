#include "list_child.h"

void createList(List_child &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x)
{
    address_child P = new elmlist_child;
    info(P).nama = x.nama;
    info(P).kelas = x.kelas;
    info(P).nim = x.nim;

    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void dealokasi(address_child &P)
{
    delete P;
}

void insertFirst(List_child &L, address_child P)
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_child L)
{
    address_child P;

    if (first(L) == NULL)
    {
        cout << "Tidak ada data yang diinputkan" << endl;
    }
    else
    {
        P = first(L);
        while (P != NULL)
        {
            cout << "NIM   : " << info(P).nim << endl;
            cout << "Nama  : " << info(P).nama << endl;
            cout << "Kelas : " << info(P).kelas << endl;
            cout << endl;
            P = next(P);
        }
    }
}

address_child findElm(List_child L, infotype_child x)
{
    address_child P = first(L);

    while(P != NULL)
    {
        if(info(P).nim == x.nim)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child Prec, address_child P)
{
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void insertLast(List_child &L, address_child P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List_child &L, address_child &P)
{
    if (first(L) != NULL)
    {
        P = first(L);

        if (first(L) == last(L))
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}

void deleteLast(List_child &L, address_child &P)
{
    if (first(L) != NULL)
    {
        P = first(L);

        if (first(L) == last(L))
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteAfter(address_child Prec, address_child &P)
{
    P = next(Prec);

    next(Prec) = next(P);
    prev(next(Prec)) = prev(P);

    next(P) = NULL;
    prev(P) = NULL;
}
