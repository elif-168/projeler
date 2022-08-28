#include<stdio.h>
#define TIME 30
#define MAX 7
int harf_kontrol(char isler[MAX], int N);
int aralik_kontrol(int matris[][TIME], int i);
void GanttDraw(int matris[][TIME], int N, char kod[MAX]);

//yapýlacak iþleri gantt grafiði þeklinde gösterir

int main(){
	int N, i, kontrol=1, kontrol2;
	char is[MAX];
	int zaman[TIME][TIME];
	
	
	
	printf("yapilacak is sayisini giriniz:\n");
	scanf("%d", &N);
	
	while(kontrol==1){
		kontrol=1;
		for(i=1;i<=N;i++){
		printf("%d. isin harf kodunu giriniz:\n", i);
		scanf(" %c", &is[i]);
		
	}
	kontrol=harf_kontrol(is, N);
	}
	
	
	
	for(i=1;i<=N;i++){
		kontrol2=1;
		while(kontrol2==1){
			printf("%d. islemin baslangic zamani:\n", i);
		scanf("%d", &zaman[i][0]);
		printf("%d. islemin bitis zamani:\n", i);
		scanf("%d", &zaman[i][1]);
		
		kontrol2=aralik_kontrol(zaman, i);
		}
		
		
	}
	
	GanttDraw(zaman, N, is);
	
	
	return 0;
	
}

int harf_kontrol(char isler[], int N){
	int i, j, kont=0;;
	for(i=1;i<=N;i++){
		for(j=i+1;j<=N;j++){
			if(isler[i]==isler[j]){
				kont=1;
			}
		}
	}
	if(kont==1){
		return 1;
	}else{
		return 0;
	}
	
	
}

int aralik_kontrol(int matris[][TIME], int i){

	if(matris[i][0]>matris[i][1]){
		return 1;
	}
	
	return 0;
}

void GanttDraw(int matris[][TIME], int N, char kod[MAX]){
	int i, j;
	
	for(i=1;i<=N;i++){
		for(j=1;j<=matris[i][1];j++){
			if(j>=matris[i][0]){
				printf("%c", kod[i]);
			}
			else{
				printf("_");
			}
			
		}
		printf("\n");
	}
	
	
}



