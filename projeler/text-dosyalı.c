#include <stdio.h>
#define N 5000
int main(void)
{
FILE *fp;
char text[N];

int sayac=0;
int kelimesay=0;
int i,k,met,asa;
int eksi=0;

//açýlan dosyanýn içindeki metinin kelime sayýsýný sayan ve boþluk fazlalarýný bir boþluða indiren kod


if ((fp = fopen ("magpie.txt", "r")) == NULL) {
printf("Dosya açma hatasý!");
return 1;
}


fgets(text, N-1, fp);
printf("%s\n", text);

met=4000;
asa=met-1;


while(text[i]!='\0'){
	
    if(text[i]==' '){
        sayac=sayac+1;
        kelimesay=kelimesay+1;
        }
    else {
        sayac=0;
        }
        
    if(sayac>1){
        for(k=0;k<asa;k++){
        	
            text[i+k-1]=text[i+k];
            
            }
        kelimesay=kelimesay-1;
       
        i=i-1;
        }
   i++;
    
    }
    if (text[1]==' '){
        kelimesay=kelimesay-1;
        }
     
    if(text[met]==' '){
        kelimesay=kelimesay-1;
        }
    
        printf("%s\n",&text);
        printf("kelime sayisi:");
        printf("%d",kelimesay);
        
        
        
        



fclose(fp);
return 0;
}
