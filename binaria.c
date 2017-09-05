#include<conio.h>
#include<stdio.h>
main()
{
int vet[5], i,j, aux, in, fim, meio, np;

//entrada
for(i=0;i<=4;i++){
printf("\nDigite o valor:\n");
scanf("%i", &vet[i]);
}
//ordenação
for(i=0;i<=3;i++){
 for(j=i+1;j<=4;j++){
   if(vet[i]>vet[j]){
      aux=vet[i];
      vet[i]=vet[j];
      vet[j]=aux;
      }
      }
      }
      //numero procurado
  printf("\nDigite o numero procurado:\n");
  scanf("%i",&np);
  //busca binária
  in=0;
  fim=4;
  meio=(in+fim)/2;
  while(in!=fim && np!= vet[meio]){
    if(np>vet[meio]){
      in=meio+1;
       //meio=(in+fim)/2;
      }
      else{
      fim=meio-1;
       //meio=(in+fim)/2;
      }
       meio=(in+fim)/2;
       }
       
       if(np==vet[meio]){
        printf("\n %i elemento encontrado\n",np);
        }
        else{
        printf("\n elemento não encontrado\n");
        }
        getch();
        }
                
  
  
  
  
  
  
  
  
  
      
      
