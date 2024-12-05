#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[100];

typedef struct{
	int npm;
	string nama;
	int nilai;
}Mahasiswa;


void init(Mahasiswa m[5]);
Mahasiswa input(Mahasiswa m[5]);
int isUnik(Mahasiswa m[5], int cek);
void tampil(Mahasiswa m[5]);
int isEmpty(Mahasiswa m[5]);
int isFull(Mahasiswa m[5]);
void bubbleSortByNPM(Mahasiswa m[]);
void tampilNpm(Mahasiswa m[5]);
int sequentialSeach(Mahasiswa m[5],string nama);
int binarySearch(Mahasiswa m[5], int kiri, int kanan, int npm);
