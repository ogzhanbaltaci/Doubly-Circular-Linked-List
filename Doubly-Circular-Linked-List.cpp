#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct node{
	int veri;
	struct node* next;
	struct node* prev;		
}; 
int dugumOlustur(struct node** head,int rdeger) // Düðüm oluþturma kodu
{ 
   struct node *yeni_dugum=(struct node*)malloc(sizeof(struct node));
   yeni_dugum->veri=rdeger;
   yeni_dugum->next=(*head);
   yeni_dugum->prev=NULL;
   
   if ((*head) != NULL){
        (*head)->prev = yeni_dugum; }    
    
	(*head) = yeni_dugum;
}
void printList(struct node *head){ // Listeyi yazdýrma kodu
    struct node *gecici=head;
    while(gecici!=NULL)
    {
        printf("%d\t",gecici->veri);
        gecici=gecici->next;
    }
}  
void dugumdenSonraEkle(struct node* head,int hangiSayidanSonra, int yeniSayi) { // Düðüme sonradan ekleme kodu
	struct node *yeni_dugum=(struct node*)malloc(sizeof(struct node));
	struct node *tempo=head;
	
	while(tempo->veri!=hangiSayidanSonra){// Ýstenilen sayiyi bulma
		tempo=tempo->next;
		if(tempo->next==NULL&&tempo->veri!=hangiSayidanSonra){ // Verilen sayinin listede olup olmadýðý kontrolü				
		printf("\nGirdiginiz sayi bulunmamaktadir.");
		getch();
		}
	}
	if(tempo->veri==hangiSayidanSonra&&tempo->next==NULL)	{ // Ýstenilen sayýnýn sonda olup olmadýðý kontrolü
  		yeni_dugum->next=tempo->next;
  		tempo->next=yeni_dugum;
  		yeni_dugum->prev=tempo;
  		yeni_dugum->veri=yeniSayi;		
  	}
  	else {	  	                                 // Normal sonradan ekleme kodu
	  yeni_dugum->next=tempo->next;
	  tempo->next->prev=yeni_dugum;
	  yeni_dugum->prev=tempo;
	  tempo->next=yeni_dugum;
	  yeni_dugum->veri=yeniSayi;	  
  	}	 	
}      						
int main(){
	struct node *list=NULL;
	int tdugum,i,yeniSayi,hangiSayidanSonra,rdeger1;
	
	srand(time(0));		
	printf("Kac dugum olusturmak istersiniz=");
	scanf("%d",&tdugum);
	printf("\n");
	
	for(i=0;i<tdugum;i++){	   		
        rdeger1=rand()%753;		// Her düðüme random bir sayý atar
		dugumOlustur(&list,rdeger1);	
	}
    printList(list);		
	printf("\n\nYeni degerinizi giriniz=");	
	scanf("%d",&yeniSayi);	
	printf("\nHangi sayidan sonra eklemek istediginizi giriniz=");
	scanf("%d",&hangiSayidanSonra);
	dugumdenSonraEkle(list,hangiSayidanSonra,yeniSayi);
	printf("\nYeni listeniz asagidaki gibidir.");
	printf("\n\n");
	printList(list);	
	printf("\n\nProgramdan cikmak icin entera basiniz.\n");
	getch();			
} 