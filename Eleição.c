#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define senha 6969 //senha do sistema

void menu();
void login();
void votar();
void apurar();

struct db{
       
       int cc1;
       int cc2; 
       int cvb; 
       int cvn;
       
       };
       
struct db db; //Data Base
int x;

main(){
       login();
           
       do{
           menu();                    
           }while(x!=0);
          }// fim main

void menu(){
     
     system("cls");
     printf("\n Eleição 2012!!!");
     printf("\n 1.Votar \n 2.Apurar \n 0.Sair \n >>");
     scanf("%i",&x);
     
     switch(x){
               case 0: system("exit");
                    break;
               case 1: votar();
                    break;
               case 2: apurar();
                    break;
               default: printf("\n ERROR !!");
              
              }
     
     }
void login(){
     int s;
     
     do{
     system("cls");
     
     printf("\n SENHA DE ACESSO:\n \n >>");
     scanf("%i",&s);
     
     if(s!=senha){
                  system("cls");
                  printf("\n SENHA INVALIDA");
                  getch();
                  }
     
     }while(s!=senha);
     
     printf("\n ACESSO GARANTIDO!! \n \n");
     system("pause");
     
         
     
     
     
     }
void votar(){
     int voto=0;
     do{
          printf("\n Votacao \n");
          printf("\n 1.CANDITADO 1 \n 2.CANDIDATO 2 \n 3.BRANCO \n 4.NULO \n 0.SAIR \n >>");
          scanf("%i",&voto);
          if(voto==1){
                     db.cc1++;
                     }
          if(voto==2){
                     db.cc2++;
                     }
          if(voto==3){
                     db.cvb++;
                     }
          if(voto==4){
                     db.cvn++;
                     }
          }while(voto!=0);
     
     }
void apurar(){
              printf("\n votos candidato 1: %i \n", db.cc1);
              printf("\n votos candidato 2: %i \n", db.cc2);
              printf("\n votos em branco: %i \n", db.cvb);
              printf("\n votos nulos: %i \n", db.cvn);
              
          if(db.cc1>db.cc2){
                      printf("\n o candidato vencedor e o numero 1 com %i votos \n", db.cc1);
                      }
          
          if(db.cc2>db.cc1){
                      printf("\n o candidato vencedor e o numero 2 com %i votos \n", db.cc2);
                      }
          
          if(db.cc1==db.cc2){
               printf("\n a eleicao terminou empatada, sera necessario outro turno \n");
               }
          getch();
     
     }          
