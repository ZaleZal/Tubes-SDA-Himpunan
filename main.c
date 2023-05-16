#include "header.h"
#include "body.c"

int main()
{
    int choose = 0;
    List DaftarMahasiswa;
    CreateList(&DaftarMahasiswa);

    caseInsert(&DaftarMahasiswa);

Start:
    system("cls");

    printDaftarMahasiswa(DaftarMahasiswa);

    printf("\n======================\n");
    printf("\n======================\n");


    
    printf("Masukan aksi :\n");
    printf("1. Tambah Mahasiswa\n");
    printf("2. Hapus Mahasiswa\n");
    printf("3. Ubah Data Mahasiswa\n");
    printf("4. Print Daftar Himpunan\n");
    printf("5. Print Daftar UKM\n");
    printf("6. Print Daftar Pusat\n");
    printf("7. Print Semua Daftar\n");
    printf(": ");

    scanf("%d", &choose);
    system("cls");
    switch (choose)
    {
    case 1:
        caseInsert(&DaftarMahasiswa);
        break;
    case 2:
        DeleteMahasiswa(&DaftarMahasiswa);
        break;
    case 3:
        caseUbahDataMahasiswa(&DaftarMahasiswa);
        break;
    case 4:
        printDaftarHimpunan(DaftarMahasiswa);
        break;
    case 5:
        printDaftarUKM(DaftarMahasiswa);
        break;
    case 6:
        printDaftarPusat(DaftarMahasiswa);
        break;
    case 7:
        casePrint(DaftarMahasiswa);
        break;
    }

    printf("Tekan ENTER untuk melanjutkan...");

    getch();
    goto Start;
}