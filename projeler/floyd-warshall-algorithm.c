#include <stdio.h>
#define SIZE 30
#define INF 9999// aralar�nda yol bulundurmayan d���mleri belirtirken sonsuz anlam�na gelen INF de�i�keni kullan�l�yor
//c dilinde sonsuz anlam�na gelen bir kod olmad��� i�in INF'e b�y�k bir de�er vererek kullan�l�r

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
  N=6;//matris yukardaki yorum sat�r�na al�nm�� kodla kullan�c�dan al�nabilir ya da haz�r matris kullan�labilir
  


  floyd_warshall(graf, matris, N);
  
  printf("girilen matris:\n");
  print_matris(graf, N);
  printf("sonuc matrisi:\n");
  print_matris(matris, N);
  return 0;
}


void floyd_warshall(int graf[][SIZE], int matris[][SIZE], int N){
  int i, j, k;

  for(i=0;i<N;i++){//sonu�lar�n yaz�laca�� matris, ilk girilen matrise e�itlenir
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

void print_matris(int matris[][SIZE], int N){//sonuclar�n yaz�l� oldu�u matrisi ekrana yazd�r�r
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
