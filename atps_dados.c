#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct RegLista{
       int n;
       struct RegLista *ant;  
       };
       
typedef struct RegLista no; 

no *atual,*aux,*exibir,*pesquisar,*rem,*antes,*depois;

int vetor[25];
int v1[10],v2[10],v3[10];
int ct;// controle para manipulação

void inserir();
void listar();
void consultar();
void receber();
void manipular();
void result();
void removerTudo();

main(){

int opcao;
aux=NULL;

do{
   printf("\n Alocacao Dinamica");      
   printf("\n 1.Inserir \n 2.Listar \n 3.Consultar \n 4.RemoverTUDO \n 9.Receber e processar dados Dinamicos \n 0.Sair");
   scanf("%i",&opcao); 
   
   switch(opcao){
                 case 1: inserir();
                      break;
                 case 2: listar();
                      break;
                 case 3: consultar();
                      break;
                 case 4: removerTudo();
                      break;
                 
                 case 9: receber();
                         manipular();
                         result();
                         getch();
                      break;
                 case 0: return(0);
                      break;
                 default: printf("opcao invalida");
                                 
                 }  
}while(opcao!=5);
    
       
} // FIM MAIN

void inserir(){
     atual=(no*)malloc(sizeof(no));
     if(atual != NULL){
              printf("\n Digite um numero:");
              scanf("%i",&atual->n);
              atual->ant=aux;
              aux=atual;
              }
              else{
                   printf("MEMORIA INSUFICIENTE!!!");
                   }
          }// FIM INSERIR

void listar(){
     if(aux==NULL){
                   printf("\n Lista Vazia!");
                   }
                   else{
                        exibir=atual;
                        while(exibir!=NULL){
                                printf("\n %i \n",exibir->n);
                                exibir=exibir->ant;
                                }
                        
                        }
     
     }// FIM LISTAR
     
void consultar(){
     int np;
     printf("\n Digite o numero procurado:");
     scanf("%i",&np);
     pesquisar=atual;
     while(pesquisar!=NULL){
                            if(pesquisar->n==np){
                                                 printf("\n %i Encontrado \n",np);
                                                 break;
                                                 }
                            pesquisar=pesquisar->ant;
                            }    
     if(pesquisar==NULL){
                         printf("\n Numero encontrado");
                         }   
     }//FIM CONSULTAR
          
void removerTudo(){
     
     if(aux==NULL){
                   printf("\n Lista vazia");
                   }
                   else{
                        rem=atual;
                        atual=atual->ant;
                        aux=atual;
                        rem->ant=NULL;
                        free(rem);
                        removerTudo();
                        }
     
     }//FIM REMOVER TUDO
     
void receber(){
     int a;
     
     
                        if(aux==NULL){
                        printf("\n Lista Vazia!");
                        }
                        else{
                             exibir=atual;
                             while(exibir!=NULL){
                                                 for(a=0;exibir!=NULL;a++){
                                                 printf("\n %i \n",exibir->n);
                                                 vetor[a]=exibir->n;
                                                 exibir=exibir->ant;
                                                 
                                }
                        
                        }
           
           }
     
       
}     

void manipular(){
     int x,y,z[25];
     
     //inversão do vetor
     x=0;
     for(y=24;y>=0;y--){
           z[y]=vetor[x];
           x++;
           }
     for(y=0;y<=24;y++){
           vetor[y]=z[y];
     }//fim inversão
        
     for(x=0;x<=9;x++){
                       v1[x]=vetor[x];
           }
     
     for(x=10;x<=19;x++){
                         v2[x-10]=vetor[x];
     }
     
     for(x=20;x<=29;x++){
                         v3[x-20]=vetor[x];
           }
     
     
     }
     
void result(){
     int x;
     system("cls");
     printf("\n Resultado final dos das pilhas em alocacao estática,");
     printf("\n com dados recebidos de origem dinamica \n");
     printf("\n \n Pilha 1");
     for(x=0;x<=9;x++){
                       printf("\n v.%i = %i",x+1,v1[x]);
                       }
                       
     printf("\n \n Pilha 2");
     for(x=0;x<=9;x++){
                       printf("\n v.%i = %i",x+1,v2[x]);
                       }
                       
     printf("\n \n Pilha 3");
     for(x=0;x<=9;x++){
                       printf("\n v.%i = %i",x+1,v3[x]);
                       }
     
     } // FIM RESULT
