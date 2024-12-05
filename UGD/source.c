#include "header.h"
//printf("\n");
void init(Mahasiswa m[5]){
	int i =0;
	for(i=0;i<5;i++){
		m[i].npm = -1;
		strcpy(m[i].nama,"-");
		m[i].nilai = -1;
	}
}
Mahasiswa input(Mahasiswa m[5]){
	int npm = 0;
	Mahasiswa out;
	do{
		printf("\nMasukkan Nama Mahasiswa : ");fflush(stdin);gets(out.nama);
		if(strlen(out.nama)==0){
			printf("\n[!] Nama tidak boleh kosong");			
		}else{
			break;
		}
	}while(1);
	
	do{
		printf("\nMasukkan Nilai Struktur Data : ");scanf("%d",&out.nilai);
		if(out.nilai<0 || out.nilai>100){
			printf("\n[!] Nilai tidak valid");
		}else{
			break;
		}
	}while(1);
	
	do{
		npm = (rand() % (999 - 100 + 1)) + 100;
		if(isUnik(m,npm)!=0){
			break;
		}
	}while(1);
	
	out.npm=npm;
	return out;
}

int isUnik(Mahasiswa m[5], int cek){
	int i = 0; 
	for(i=0;i<5;i++){
		if(m[i].npm == cek){
			return 0;
		}
	}
	return 1;
}

void tampil(Mahasiswa m[5]){
	int i = 0;
	for(i=0;i<5;i++){
		printf("\n======%d======", i+1);
		printf("\nNPM	: %d",m[i].npm);
		printf("\nNama 	: %s",m[i].nama);
		printf("\nNilai	: %d",m[i].nilai);
	}
}

int isEmpty(Mahasiswa m[5]){
	int i =0;
	for(i=0;i<5;i++){
		if(m[i].nilai != -1){
			return 0;
		}
	}
	return 1;
}

int isFull(Mahasiswa m[5]){
	int i = 0;
	for(i=0;i<5;i++){
		if(m[i].nilai == -1){
			return 0;
		}
	}
	return 1;
}

void bubbleSortByNPM(Mahasiswa m[]) {
	int i,j;
    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (m[j].npm > m[j + 1].npm) {
                Mahasiswa temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
}

void tampilNpm(Mahasiswa m[5]){
	printf("\nDaftar Npm\n");
	int i = 0;
	for(i=0;i<5;i++){
		if(i==4){
			printf("|%d|", m[i].npm);
		}else{	
			printf("|%d| - ", m[i].npm);
		}
	}
}

int sequentialSeach(Mahasiswa m[5],string nama){
	int i= 0;
	for(i=0;i<5;i++){
		if(strcmpi(m[i].nama,nama)==0){
			return i;
		}
	}
	return -1;
}

int binarySearch(Mahasiswa m[5], int kiri, int kanan, int npm){
	if(kanan>=kiri){
		int mid = (kiri+kanan)/2;
		
		if(npm == m[mid].npm){
			return mid;
		}else if(npm < m[mid].npm){
			return binarySearch(m,kiri,mid-1,npm);
		}else{
			return binarySearch(m,mid+1,kanan,npm);
		}
	}
	return -1;
}
























