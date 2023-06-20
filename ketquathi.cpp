#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
struct thisinh{
	int sbd;
	float diem;
	char hoten[30], nganh[5];
};
void nhap1ThiSinh(thisinh &a){
	printf("Nhap SBD: ");scanf("%d", &a.sbd);getchar();fflush(stdin);
	printf("Ho va ten: ")/*;fgets(a.hoten, sizeof(a.hoten), stdin)*/;gets(a.hoten); fflush(stdin);
	printf("Nhap nganh: ")/*;fgets(a.nganh, sizeof(a.nganh), stdin)*/;gets(a.nganh);
	printf("Nhap diem: ");scanf("%f", &a.diem);
}
void in1ThiSinh(thisinh a){
/*	printf("BKA- %d\t", a.sbd);
	printf("%s\t\t", a.hoten);
	printf("%s\t", a.nganh);
	printf("%.1f\n", a.diem);*/
	printf("BKA- %d   %-15s%8s  %5.1f",a.sbd, a.hoten, a.nganh, a.diem );
	printf("\n");
}
void nhapMangThiSinh(thisinh a[], int n ){
	for(int i=0; i < n; i++){
		printf("Nhap thi sinh thu: %d\n", i+1);
		nhap1ThiSinh(a[i]);
		printf("\n");
	}	
}
void inMangThiSinh(thisinh a[], int n){
	printf("Nhan phim bat ky de xem ket qua thi...\n\n");	getch();
	printf("\t\tKET QUA THI\n\n");
	for(int i=0; i<n; i++){
		printf("%d  ", i+1);
		in1ThiSinh(a[i]);
	}
}
void sinhVienVaoCNTT(thisinh a[], int n){
	printf("\n\nNhan phim bat ky de xem DSSV khoa CNTT\n\n");	getch();
	printf("Danh sach trung tuyen khoa CNTT\n\n");
	int tt=0;
	for(int i=0; i < n; i++){
		if(a[i].diem >= 22.5 && strcmp(a[i].nganh, "CNTT")==0){
			printf("%d  ", tt+1);
			in1ThiSinh(a[i]);
			tt++;
		}
	}	
	if(tt==0) printf("khong co ai");
}
void timThiSinh(thisinh a[], int n){
	int sbdt, v=0;
	printf("Nhap phim bat ky de bat dau tim kiem theo so bao danh\n");
	do {
		printf("\nNhap so bao danh can tim: ");scanf("%d", &sbdt);
		for(int i=0; i < n; i++){
			if(a[i].sbd ==sbdt){
				printf("So bao danh : %d\n", a[i].sbd);
				printf("Ho ten      : %s\n", a[i].hoten);
				printf("Khoa du thi : %s\n", a[i].nganh);
				printf("Ket qua     : %.1f\n", a[i].diem);
				v=i;
			}		
		}
		if(v==0) printf("Khong thay");
		printf("\nTim lai <C/K>? : "); fflush(stdin);
	}while(toupper(getche()) !='K');
}	
void sapXepTheoDiemGiam(thisinh a[], int n){
	printf("Sap xep theo diem gian dan\n\n");
	int tt=0;
	thisinh tmp;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i].diem < a[j].diem){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%d  ", tt+1);
		in1ThiSinh(a[i]);
		tt++;
	}
	printf("\n");
}
void sapXepTheoTen(thisinh a[], int n){
	printf("Sap xep theo ten\n\n");
	int tt=0;
	thisinh tmp;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(strrchr(a[i].hoten, ' '),strrchr(a[j].hoten,' ')) > 0){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%d  ", tt+1);
		in1ThiSinh(a[i]);
		tt++;
	}
}
int main(){
	thisinh a[100];
	int n;
	printf("Nhap so thi sinh: ");scanf("%d", &n);
	nhapMangThiSinh(a,n);
	system("cls");	
	inMangThiSinh(a,n);
	sinhVienVaoCNTT(a,n);getch();
	system("cls");
	sapXepTheoDiemGiam(a,n);
	sapXepTheoTen(a,n);
	timThiSinh(a,n);
	return 0;
}
