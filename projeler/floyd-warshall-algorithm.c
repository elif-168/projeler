#include <stdio.h>
#define SIZE 30
#define INF 9999// aralarýnda yol bulundurmayan düðümleri belirtirken sonsuz anlamýna gelen INF deðiþkeni kullanýlýyor
//c dilinde sonsuz anlamýna gelen bir kod olmadýðý için INF'e büyük bir deðer vererek kullanýlýr

void print_matris(int matris[][SIZE], int N);
void floyd_warshall(int graf[][SIZE], int matris[][SIZE], int N);

int main() {
  int matris[SIZE][SIZE], graf[SIZE][SIZE]={{0, 3, INF, 5, 6, INF},
 {2, 0, INF, 4, 7, INF},
 {INF, 1, 0, INF, INF, 8},
 {INF, INF, 2, 0, 9, 4},
 {6, 7, INF, 9, 0, 3},
 {INF, INF, 8, 4, 3, 0}};
  int N, i, j;
  
/*  printf("dugum sayisini giriniz:\n");
  scanf("%d", &N);
    printf("eger dugumler arasi yol yoksa 9999 giriniz\n");
           
  for(i=0;i<N;i++){
  	for(j=0;j<N;j++){
  		printf("%d. dugum ile %d. dugum arasindaki mesafeyi girniz:\n", i+1, j+1);
  		scanf("%d", &graf[i][j]);
  		if(graf[i][j==9999]){
  			graf[i][j]=INF;
		  }
	  }
  }
*/  
  N=6;//matris yukardaki yorum satýrýna alýnmýþ kodla kullanýcýdan alýnabilir ya da hazýr matris kullanýlabilir
  


  floyd_warshall(graf, matris, N);
  
  printf("girilen matris:\n");
  print_matris(graf, N);
  printf("sonuc matrisi:\n");
  print_matris(matris, N);
  return 0;
}


void floyd_warshall(int graf[][SIZE], int matris[][SIZE], int N){
  int i, j, k;

  for(i=0;i<N;i++){//sonuçlarýn yazýlacaðý matris, ilk girilen matrise eþitlenir
    for(j=0;j<N;j++){
    	matris[i][j] = graf[i][j];
	}
}


  for(k=0;k<N;k++){
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        if((matris[i][k]+matris[k][j])<matris[i][j]){
        	matris[i][j]=matris[i][k]+matris[k][j];
		}
        
      }
    }
  }
  

}

void print_matris(int matris[][SIZE], int N){//sonuclarýn yazýlý olduðu matrisi ekrana yazdýrýr
  int i, j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(matris[i][j]==INF){
      	printf("INF\t");
	  }
      else{
      	 printf("%d\t", matris[i][j]);
	  }
    }
    printf("\n");
  }
}
