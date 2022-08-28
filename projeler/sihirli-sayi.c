#include <stdio.h>
#define SIZE 30

int main(){

int i=0, k, N, kontrol=0;
int dizi[SIZE], ss[SIZE]={0};
//verilen dizideki sihirli sayýlarý bulan algoritma
//ss=sihirli sayý=elemanýn dizide bulunduðu indisle ayný olmasý
//örnek: dizi[3]=3 ise bu bir sihirli sayýdýr

printf("dizinin boyutunu giriniz:\n\t");
scanf("%d", &N);

printf("\ndizinin elemanlarini giriniz:\n\t");
for (i=0;i<N;i++){
	scanf("%d", &dizi[i]);
	printf("\t");
}
 for(i=0;i<N;i++){
 	k=dizi[i];
 	ss[k] += 1;
 	
 }

printf("\ndizideki sihirli sayilar:\n");

 for(i=1;i<N;i++){
 	if(ss[i]==i){
 		printf("\t%d\n", i);
 		kontrol=1;
	 }
 }
if(kontrol==0){
	printf("\nbu dizide sihirli sayi yoktur");
}



return 0;
}
