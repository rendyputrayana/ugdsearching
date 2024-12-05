#include "header.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//printf("\n");
int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	Mahasiswa m[5];
	int menu = 0,i = 0, nilai = 0, index =-1, npm = -1;
	string nama;
	init(m);
	string konfirmasi;
	
	do{
		system("cls");
		printf("\n\t\tUGD SEARCHING");
		printf("\n");
		if(!isEmpty(m)){
			tampilNpm(m);
			printf("\n");
		}
		printf("\n[1] Input Mahasiswa");
		printf("\n[2] Tampil Mahasiswa");
		printf("\n[3] Edit Nama		(Sequential Search)");
		printf("\n[4] Edit Nilai		(Binary Search)");
		printf("\n>>>>");scanf("%d",&menu);
		switch(menu){
			case 1:{
				if(!isFull(m)){
					for(i=0;i<5;i++){
						m[i] = input(m);
					}
					bubbleSortByNPM(m);
				}else{
					printf("\n[!] Nguwawor Array Sudah Penuh");
				}
				break;
			}
			case 2:{
				if(!isEmpty(m)){
					tampil(m);
				}else{
					printf("\n[!]Nguwawor Array Masih Kosonk");
				}
				break;
			}
			case 3:{
				if(!isEmpty(m)){
					do{
						printf("\nMasukkan Nama Mahasiswa : ");fflush(stdin);gets(nama);
						if(strlen(nama)==0){
							printf("\n[!] Nguwawor banget ");
							printf("\n[!] Nama tidak boleh kosong");
						}else{
							break;
						}
					}while(1);
					
					index = sequentialSeach(m,nama);
					if(index!=-1){
						do{
							printf("\nMasukkan Nama Baru : ");fflush(stdin);gets(nama);
							if(strlen(nama)==0){
								printf("\n[!] Nguwawor banget ");
								printf("\n[!] Nama tidak boleh kosong");
							}else{
								break;
							}
						}while(1);
						printf("\nNama %s berubah menjadi %s ? (Y/N)",m[index].nama, nama);fflush(stdin);gets(konfirmasi);
						if(strcmpi(konfirmasi, "Y")!=0 && strcmpi(konfirmasi, "N")!=0){
							printf("\n[!] Invalid");
						}else{
							if(strcmpi(konfirmasi,"Y")==0){
								strcpy(m[index].nama,nama);
							}
						}
					}else{
						printf("\n[!] Mahasiswa dengan nama %s tidak ada", nama);
					}
					
				}else{
					printf("\n[!]Nguwawor Array Masih Kosonk");
				}
				break;
				break;
			}
			case 4:{
				if(!isEmpty(m)){
					do{
						printf("\nMasukkan NPM yang dicari : ");scanf("%d",&npm);
						if(npm < 100 || npm > 999){
							printf("\n[!] Nguwawor banget NPM invalid");
						}else{
							break;
						}
					}while(1);
					
					index = binarySearch(m,0,5,npm);
					
					if(index != -1){
						printf("\nMasukkan Nilai yang baru untuk %s : ",m[index].nama);scanf("%d",&nilai);
						if(nilai < 0 || nilai > 100){
							printf("\n[!] Nilainya Nguwawor loh ya");
						}else{
							m[index].nilai = nilai;
							break;
						}
					}else{
						printf("\n[!] Nguwwor bangeet NPM tidak ditemukan");
					}
				}else{
					printf("\n[!]Nguwawor Array Masih Kosonk");
				}
				break;
				break;
			}
			case 55:{
				for(i=0;i<5;i++){
					m[i].npm= 100+i;
					m[i].nilai = 55;
					strcpy(m[i].nama,"meitha");
				}
				break;
			}
			default:{
				printf("\n[!] Nguwawor Banget loh ya 	[!]");
				printf("\n[!] Menu Belum Ada		[!]");
				break;
			}
			case 0:{
				printf("\nNAMA || NPM || KELAS");
				printf("\nTelah menyelesaikan ISD :)");
				break;
			}
		}
		getch();
	}while(menu!=0);
	return 0;
}
