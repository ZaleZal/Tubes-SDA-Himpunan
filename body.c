#include "header.h"

/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty(List L)
/* Mengirim true jika List Kosong */
{
    return (FirstMahasiswa(L) == Nil);
}
bool HimpunanEmpty(List L)
/* Mengirim true jika List Kosong */
{
    return (FirstHimpunan(L) == Nil);
}
bool UKMEmpty(List L)
/* Mengirim true jika List Kosong */
{
    return (FirstUKM(L) == Nil);
}
bool PusatEmpty(List L)
/* Mengirim true jika List Kosong */
{
    return (FirstPusat(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList(List *L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
    FirstMahasiswa(*L) = Nil;
    FirstHimpunan(*L) = Nil;
    FirstPusat(*L) = Nil;
    FirstUKM(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi(infotype X, infotype NIM, infotype Jurusan)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, NextQ(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) /* Alokasi berhasil */
    {
        strcpy(Nama(P), X);
        strcpy(NIM(P), NIM);
        strcpy(Jurusan(P), Jurusan);
        NextMahasiswa(P) = Nil;
        NextHimpunan(P) = Nil;
        NextPusat(P) = Nil;
        NextUKM(P) = Nil;
    }
    return (P);
}

void DeAlokasi(address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
    if (P != Nil)
    {
        free(P);
    }
}

/**** Pencarian sebuah elemen List ****/
address Search(List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype bool */
{
    /* Kamus Lokal */
    address P;
    bool found = false;
    /* algoritma */
    P = FirstMahasiswa(L);
    while ((P != Nil) && (!found))
    {
        if (strcmp(NIM(P), X) == 0)
        {
            found = true;
        }
        else
        {
            P = NextMahasiswa(P);
        }
    } /* P = Nil atau Ketemu */
    return (P);
}

address SearchHimpunan(List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype bool */
{
    /* Kamus Lokal */
    address P;
    bool found = false;
    /* algoritma */
    P = FirstHimpunan(L);
    while ((P != Nil) && (!found))
    {
        if (strcmp(NIM(P), X) == 0)
        {
            found = true;
        }
        else
        {
            P = NextHimpunan(P);
        }
    } /* P = Nil atau Ketemu */
    return (P);
}

address SearchPusat(List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype bool */
{
    /* Kamus Lokal */
    address P;
    bool found = false;
    /* algoritma */
    P = FirstPusat(L);
    while ((P != Nil) && (!found))
    {
        if (strcmp(NIM(P), X) == 0)
        {
            found = true;
        }
        else
        {
            P = NextPusat(P);
        }
    } /* P = Nil atau Ketemu */
    return (P);
}

address SearchUKM(List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype bool */
{
    /* Kamus Lokal */
    address P;
    bool found = false;
    /* algoritma */
    P = FirstUKM(L);
    while ((P != Nil) && (!found))
    {
        if (strcmp(NIM(P), X) == 0)
        {
            found = true;
        }
        else
        {
            P = NextUKM(P);
        }
    } /* P = Nil atau Ketemu */
    return (P);
}

address getLast(List *L)
{
    address lastTemp = NULL;
    if (!ListEmpty(*L))
    {
        lastTemp = FirstMahasiswa(*L);
        while (NextMahasiswa(lastTemp) != NULL)
        {
            lastTemp = NextMahasiswa(lastTemp);
        }
    }
    return lastTemp;
}

address getLastHimpunan(List *L)
{
    address lastTemp = NULL;
    if (!HimpunanEmpty(*L))
    {
        lastTemp = FirstHimpunan(*L);
        while (NextHimpunan(lastTemp) != NULL)
        {
            lastTemp = NextHimpunan(lastTemp);
        }
    }
    return lastTemp;
}

address getLastPusat(List *L)
{
    address lastTemp = NULL;
    if (!PusatEmpty(*L))
    {
        lastTemp = FirstPusat(*L);
        while (NextPusat(lastTemp) != NULL)
        {
            lastTemp = NextPusat(lastTemp);
        }
    }
    return lastTemp;
}

address getLastUKM(List *L)
{
    address lastTemp = NULL;
    if (!UKMEmpty(*L))
    {
        lastTemp = FirstUKM(*L);
        while (NextUKM(lastTemp) != NULL)
        {
            lastTemp = NextUKM(lastTemp);
        }
    }
    return lastTemp;
}

address getBeforeMahasiswa(List *L, address find)
{
    address lastTemp = NULL;
    if (!ListEmpty(*L))
    {
        lastTemp = FirstMahasiswa(*L);
        while (lastTemp != NULL && NextMahasiswa(lastTemp) != find)
        {
            lastTemp = NextMahasiswa(lastTemp);
        }
    }
    return lastTemp;
}

address getBeforeHimpunan(List *L, address find)
{
    address lastTemp = NULL;
    if (!ListEmpty(*L))
    {
        lastTemp = FirstHimpunan(*L);
        while (lastTemp != NULL && NextHimpunan(lastTemp) != find)
        {
            lastTemp = NextHimpunan(lastTemp);
        }
    }
    return lastTemp;
}

address getBeforeUKM(List *L, address find)
{
    address lastTemp = NULL;
    if (!ListEmpty(*L))
    {
        lastTemp = FirstUKM(*L);
        while (lastTemp != NULL && NextUKM(lastTemp) != find)
        {
            lastTemp = NextUKM(lastTemp);
        }
    }
    return lastTemp;
}

address getBeforePusat(List *L, address find)
{
    address lastTemp = NULL;
    if (!ListEmpty(*L))
    {
        lastTemp = FirstPusat(*L);
        while (lastTemp != NULL && NextPusat(lastTemp) != find)
        {
            lastTemp = NextPusat(lastTemp);
        }
    }
    return lastTemp;
}

void insertMahasiswa(List *L)
{
    ElmtList Mahasiswa ;
    char temp;
    printf("Masukan nama mahasiswa :");
    scanf("%s", Mahasiswa.nama);
    printf("Masukan nim mahasiswa :");
    scanf("%s", Mahasiswa.nim);
    printf("Masukan Jurusan Mahasiswa : ");
    scanf("%s", Mahasiswa.jurusan);

    address mahasiswaBaru = Alokasi(Mahasiswa.nama, Mahasiswa.nim, Mahasiswa.jurusan);
    if (ListEmpty(*L))
    {
        FirstMahasiswa(*L) = mahasiswaBaru;
    }
    else
    {
        address mahasiswaAkhir = getLast(L);
        mahasiswaAkhir->nextMahasiswa = mahasiswaBaru;
    }

    // Masukan ke himpunan
    if (HimpunanEmpty(*L))
    {
        FirstHimpunan(*L) = mahasiswaBaru;
    }
    else
    {
        address himpunanAkhir = getLastHimpunan(L);
        himpunanAkhir->nextHimpunan = mahasiswaBaru;
    }
    // Masukan ke himpunan

    printf("Apakah mahasiswa masuk PUSAT ? (y/n)");
    scanf("\n%c", &temp);
    if (toupper(temp) == 'Y')
    {
        // Masukan ke pusat
        if (PusatEmpty(*L))
        {
            FirstPusat(*L) = mahasiswaBaru;
        }
        else
        {
            address PusatAkhir = getLastPusat(L);
            PusatAkhir->nextPusat = mahasiswaBaru;
        }
        // Masukan ke pusat
    }

    printf("Apakah mahasiswa masuk UKM ? (y/n)");
    scanf("\n%c", &temp);
    if (toupper(temp) == 'Y')
    {
        // Masukan ke UKM
        if (UKMEmpty(*L))
        {
            FirstUKM(*L) = mahasiswaBaru;
        }
        else
        {
            address UKMAkhir = getLastUKM(L);
            UKMAkhir->nextUKM = mahasiswaBaru;
        }
        // Masukan ke UKM
    }
}

void DeleteMahasiswa(List *Data)
{
    infotype namaDicari;
    printf("Masukan NIM mahasiswa yang ingin dicari :");
    scanf("%s", namaDicari);
    address finded = Search(*Data, namaDicari);
    if (!finded)
    {
        printf("Data tidak ditemukan...");
        getch();
        return;
    }
    if (finded == FirstMahasiswa(*Data))
    {
        FirstMahasiswa(*Data) = NextMahasiswa(finded);
    }
    else if (getLast(Data) != NULL && NextMahasiswa(getLast(Data)) == finded)
    {
        address lastMahasiswa = getLast(Data);
        NextMahasiswa(lastMahasiswa) = NULL;
    }
    else
    {
        address beforeMahasiswa = getBeforeMahasiswa(Data, finded);
        address afterMahasiswa = NextMahasiswa(finded);

        NextMahasiswa(beforeMahasiswa) = afterMahasiswa;
    }

    if (finded == FirstUKM(*Data))
    {
        FirstUKM(*Data) = NextUKM(finded);
    }
    else if (getLastUKM(Data) != NULL && NextUKM(getLastUKM(Data)) == finded)
    {
        address lastUKM = getLastUKM(Data);
        NextUKM(lastUKM) = NULL;
    }
    else
    {
        address beforeUKM = getBeforeUKM(Data, finded);
        address afterUKM = NextUKM(finded);

        NextUKM(beforeUKM) = afterUKM;
    }

    if (finded == FirstPusat(*Data))
    {
        FirstPusat(*Data) = NextPusat(finded);
    }
    else if (getLastPusat(Data) != NULL && NextPusat(getLastPusat(Data)) == finded)
    {
        address lastPusat = getLastPusat(Data);
        NextPusat(lastPusat) = NULL;
    }
    else
    {
        address beforePusat = getBeforePusat(Data, finded);
        address afterPusat = NextPusat(finded);

        NextPusat(beforePusat) = afterPusat;
    }

    if (finded == FirstHimpunan(*Data))
    {
        FirstHimpunan(*Data) = NextHimpunan(finded);
    }
    else if (getLastHimpunan(Data) != NULL && NextHimpunan(getLastHimpunan(Data)) == finded)
    {
        address lastHimpunan = getLastHimpunan(Data);
        NextHimpunan(lastHimpunan) = NULL;
    }
    else
    {
        address beforeHimpunan = getBeforeHimpunan(Data, finded);
        address afterHimpunan = NextHimpunan(finded);

        NextHimpunan(beforeHimpunan) = afterHimpunan;
    }

    free(finded);
}

void printDaftarMahasiswa(List L)
{
    printf("\nDaftar Mahasiswa :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada mahasiswa..");
        return;
    }
    address temp = FirstMahasiswa(L);
    int i = 1;
    while (temp)
    {
        printf("%d.\n", i);
        printf("Nama Mahasiswa\t: %s\n", Nama(temp));
        printf("NIM Mahasiswa\t: %s\n", NIM(temp));
        printf("Jurusan\t: %s\n", Jurusan(temp));
        temp = NextMahasiswa(temp);
        i++;
    }
}

void printDaftarHimpunan(List L)
{
    printf("\nDaftar Himpunan :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada Himpunan..");
        return;
    }
    address temp = FirstHimpunan(L);
    int i = 1;
    while (temp)
    {
        printf("%d. ", i);
        printf("Nama Himpunan : Himpunan %s\n", Jurusan(temp));
        // printf("NIM Himpunan : %s\n", NIM(temp));
        temp = NextHimpunan(temp);
        i++;
    }
}

void printDaftarPusat(List L)
{
    printf("\nDaftar Anggoota Pusat :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada Pusat..");
        return;
    }
    address temp = FirstPusat(L);
    int i = 1;
    while (temp)
    {
        printf("%d. ", i);
        printf("Nama Mahasiswa : %s\n", temp);
        temp = NextPusat(temp);
        i++;
    }
}

void printDaftarUKM(List L)
{
    printf("\nDaftar Anggota UKM :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada UKM..");
        return;
    }
    address temp = FirstUKM(L);
    int i = 1;
    while (temp)
    {
        printf("%d. ", i);
        printf("Nama Mahasiswa : %s\n", Nama(temp));
        temp = NextUKM(temp);
        i++;
    }
}

void printDaftarHimpunanNPusat(List L)
{
    printf("\nDaftar Anggota Himpunan irisan pusat :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada Himpunan..");
        return;
    }
    address temp = FirstHimpunan(L);
    int i = 1;
    while (temp)
    {
        if (SearchPusat(L, NIM(temp)))
        {
            printf("%d. ", i);
            printf("Nama Himpunan : Himpunan %s\n", Jurusan(temp));
            i++;
        }
        temp = NextHimpunan(temp);
    }
}

void printDaftarHimpunanNUKM(List L)
{
    printf("\nDaftar Himpunan irisan UKM :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada Himpunan..");
        return;
    }
    address temp = FirstHimpunan(L);
    int i = 1;
    while (temp)
    {
        if (SearchUKM(L, NIM(temp)))
        {
            printf("%d. ", i);
            printf("Nama Mahasiswa : %s\n", Nama(temp));
            // printf("NIM Himpunan : %s\n", NIM(temp));
            i++;
        }
        temp = NextHimpunan(temp);
    }
}

void printDaftarHimpunanNPusatNUKM(List L)
{
    printf("\nDaftar Himpunan irisan pusat irisan ukm :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada Himpunan..");
        return;
    }
    address temp = FirstHimpunan(L);
    int i = 1;
    while (temp)
    {
        if (SearchUKM(L, NIM(temp)) && SearchPusat(L, NIM(temp)))
        {
            printf("%d.\n", i);
            printf("Nama Himpunan : Himpunan %s\n", Jurusan(temp));
            // printf("NIM Himpunan : %s\n", NIM(temp));
            i++;
        }
        temp = NextHimpunan(temp);
    }
}

void printDaftarHimpunanOnly(List L)
{
    printf("\nDaftar Himpunan irisan pusat irisan ukm :\n========\n");
    if (ListEmpty(L))
    {
        printf("Tidak ada Himpunan..");
        return;
    }
    address temp = FirstHimpunan(L);
    int i = 1;
    while (temp)
    {
        if (!SearchUKM(L, NIM(temp)) && !SearchPusat(L, NIM(temp)))
        {
            printf("%d. ", i);
            printf("Nama Himpunan : Himpunan %s\n", Jurusan(temp));
            // printf("NIM Himpunan : %s\n", NIM(temp));
            i++;
        }
        temp = NextHimpunan(temp);
    }
}

void caseInsert(List *DaftarMahasiswa)
{
    int choose = 0;

     printf("####### #     # ######  #######  #####      #####  ######     #       #    # ####### #       ####### #     # ######  ####### #    #\n");
    printf("#    #  #     # #     # #       #     #    #     # #     #   # #      #   #  #       #       #     # ##   ## #     # #     # #   #\n");
    printf("#    #  #     # #     # #       #          #       #     #  #   #     #  #   #       #       #     # # # # # #     # #     # #  #\n");
    printf("#    #  #     # ######  #####    #####      #####  #     # #     #    ###    #####   #       #     # #  #  # ######  #     # ###\n");
    printf("#    #  #     # #     # #             #          # #     # #######    #  #   #       #       #     # #     # #       #     # #  #\n");
    printf("#    #  #     # #     # #       #     #    #     # #     # #     #    #   #  #       #       #     # #     # #       #     # #   #\n");
    printf("#     #  #####  ######  #######  #####      #####  ######  #     #    #    # ####### ####### ####### #     # #       ####### #    #\n");

    printf("Masukan jumlah mahasiswa yang ingin diinput : ");
    scanf("%d", &choose);
    for (size_t i = 0; i < choose; i++)
    {
        printf("\nData Mahasiswa ke %d\n", i + 1);
        insertMahasiswa(DaftarMahasiswa);
    }
}

void casePrint(List DaftarMahasiswa)
{
    printf("========================DATA LUAR========================");
    printDaftarMahasiswa(DaftarMahasiswa);
    printDaftarPusat(DaftarMahasiswa);
    printDaftarHimpunan(DaftarMahasiswa);
    printDaftarUKM(DaftarMahasiswa);

    printf("=======================DATA IRISAN===+===================");
    printDaftarHimpunanNPusat(DaftarMahasiswa);
    printDaftarHimpunanNUKM(DaftarMahasiswa);
    printDaftarHimpunanNPusatNUKM(DaftarMahasiswa);
    printDaftarHimpunanOnly(DaftarMahasiswa);
}

void caseUbahDataMahasiswa(List *DaftarMahasiswa)
{
    infotype namaDicari;
    printf("Masukan nama mahasiswa yang ingin dicari :");
    scanf("%s", namaDicari);
    address finded = Search(*DaftarMahasiswa, namaDicari);
    if (finded)
    {
        printf("Masukan nama mahasiswa baru :");
        scanf("%s", namaDicari);
        strcpy(Nama(finded), namaDicari);
        printf("Masukan NIM mahasiswa baru :");
        scanf("%s", namaDicari);
        strcpy(NIM(finded), namaDicari);
    }
}
