#ifndef header_h
#define header_h
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define Nil NULL
#define Nama(P) (P)->nama
#define NIM(P) (P)->nim
#define Jurusan(P) (P)->jurusan
#define NextHimpunan(P) (P)->nextHimpunan
#define NextMahasiswa(P) (P)->nextMahasiswa
#define NextPusat(P) (P)->nextPusat
#define NextUKM(P) (P)->nextUKM
#define FirstMahasiswa(L) (L).FirstMahasiswa
#define FirstHimpunan(L) (L).FirstHimpunan
#define FirstPusat(L) (L).FirstPusat
#define FirstUKM(L) (L).FirstUKM

typedef char infotype[100]; //! Mengubah tipe menjadi karkakter
typedef struct tElmtList *address;
typedef struct tElmtList
{
	infotype nama;
	infotype nim;
	infotype jurusan;
	address nextMahasiswa;
	address nextHimpunan;
	address nextPusat;
	address nextUKM;
} ElmtList;

/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct
{
	address FirstMahasiswa;
	address FirstHimpunan;
	address FirstPusat;
	address FirstUKM;
} List;

#endif
