#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//#define larg 20 //dias do mes
#define alt 10 //paises suportados
#define mes 10 //dias uteis do mes de Abril de 2012

float tabela[10][10];

void menu();
void cadastro();
void cotacao();
void manual();
void bot();
void especifica();
int medias(int m);
float calc(float x,float y);

main(){
       menu();
       
       }//FIM MAIN
       

void menu(){
     int op;
     
     do{
     do{
     system("cls");
     printf("\n*** COTACAO ELETRONICA ***");
     printf("\n 1.Cadastro de cotacao");
     printf("\n 2.Exibir Cotações");
     printf("\n 3.Cotacao especifica");
     printf("\n 0.Sair");
     printf("\n \n >>");
     scanf("%i",&op);
     }while(op<0||op>4);
     
     switch(op){
                case 1: cadastro();
                     break;
                case 2: cotacao();
                     break;
                case 3: especifica();
                     break;
                case 0: system("exit");
                     break;
                default: printf("ERROR SWITCH MENU");
                
                
                
                }
     
     }while(op!=0);
     
     }//FIM MENU
void especifica(){
     int m1,m2,d1,d2,op;
     float res;
     
     system("cls");
     printf("\n *** CALCULAR ***");
     printf("\n SELECIONE MOEDA 1: \n");
     printf("\n 1.Dollar Americano \n 2.Euro \n 3.Libra \n 4.Peso Argentino \n 5.Kwanza Angola \n 6.Dollar Canadense \n 7.Peso Chileno \n 8.Iene \n 9.Novosol Peru \n 10.Peso Mexicano");
     scanf("%i",&m1);
     printf("\n Selecione Dia de Cotação 1-10 \n");
     scanf("%i",&d1);
     
     printf("\n SELECIONE MOEDA 2: \n");
     printf("\n 1.Dollar Americano \n 2.Euro \n 3.Libra \n 4.Peso Argentino \n 5.Kwanza Angola \n 6.Dollar Canadense \n 7.Peso Chileno \n 8.Iene \n 9.Novosol Peru \n 10.Peso Mexicano");
     scanf("%i",&m2);
     printf("\n Selecione Dia de Cotação 1-10 \n");
     scanf("%i",&d2);

     res=calc(tabela[m1-1][d1-1],tabela[m2-1][d2-1]);
     
     printf("Resultado: M1 x M2 = %.2f",res);
     

     getch();
     
     
     
     
     
     
     
     }//
void cadastro(){
     int x,y,op;
     
     system("cls");
     printf("\n *** CADASTRO COTACOES ***");
     printf("\n ");
     printf("\n 1.Dollar Americano \n 2.Euro \n 3.Libra \n 4.Peso Argentino \n 5.Kwanza Angola \n 6.Dollar Canadense \n 7.Peso Chileno \n 8.Iene \n 9.Novosol Peru \n 10.Peso Mexicano");
     scanf("%i",&op);
     system("cls");
     
     switch(op){
                case 1:
                     for(x=0;x<=9;x++){
                                       printf("\n DOLLAR");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[0][x]);
                                       
                           }
                     
                     break;
                case 2:
                     for(x=0;x<=9;x++){
                                       printf("\n EURO");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[1][x]);
                           }
                     break;
                case 3:
                     for(x=0;x<=9;x++){
                                       printf("\n LIBRA");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[2][x]);
                           }
                     break;
                case 4:
                     for(x=0;x<=9;x++){
                                       printf("\n PESO ARGENTINO");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[3][x]);
                           }
                     break;
                case 5:
                     for(x=0;x<=9;x++){
                                       printf("\n KWANZA ANGOLA");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[4][x]);
                           }
                     break;
                case 6:
                     for(x=0;x<=9;x++){
                                       printf("\n DOLLAR CANADENSE");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[5][x]);
                           }
                     break;
                case 7:
                     for(x=0;x<=9;x++){
                                       printf("\n PESO CHILENO");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[6][x]);
                           }
                     break;
                case 8:
                     for(x=0;x<=9;x++){
                                       printf("\n IENE");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[7][x]);
                           }
                     break;
                case 9:
                     for(x=0;x<=9;x++){
                                       printf("\n NOVOSOL PERU");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[8][x]);
                           }
                     break;
                case 10:
                     for(x=0;x<=9;x++){
                                       printf("\n PESO MEXICANO");
                                       printf("\n Digite dia %i:",x+1);
                                       scanf("%f",&tabela[9][x]);
                           }
                     break;
                     }
     
     }//
     
float calc(float x,float y){
      float total=0;
      total=x*y;
      return(total);
      }
      
void cotacao(){
     int x,y,op;
     
     system("cls");
     printf("\n *** EXIBIR COTACOES ***");
     printf("\n ");
     printf("\n 1.Dollar Americano \n 2.Euro \n 3.Libra \n 4.Peso Argentino \n 5.Kwanza Angola \n 6.Dollar Canadense \n 7.Peso Chileno \n 8.Iene \n 9.Novosol Peru \n 10.Peso Mexicano");
     scanf("%i",&op);
     system("cls");
     
     switch(op){
                case 1: printf("\n DOLLAR");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[0][x]);
                                       }
                     medias(0);
                     break;
                case 2: printf("\n EURO");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[1][x]);
                                       
                           }
                     medias(1);
                     break;
                case 3: printf("\n LIBRA");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[2][x]);
                                  
                           }
                     medias(2);
                     break;
                case 4: printf("\n PESO ARGENTINO");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[3][x]);
                                    
                           }
                     medias(3);
                     break;
                case 5: printf("\n KWANZA ANGOLA");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[4][x]);
                                       
                           }
                     medias(4);
                     break;
                case 6: printf("\n DOLLAR CANADENSE");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[5][x]);
                                       
                           }
                     medias(5);
                     break;
                case 7: printf("\n PESO CHILENO");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[6][x]);
                                       
                           }
                     medias(6);
                     break;
                case 8: printf("\n IENE");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[7][x]);
                                       
                           }
                     medias(7);
                     break;
                case 9: printf("\n NOVOSOL PERU");
                     for(x=0;x<=9;x++){
                                       
                                       printf("\n Dia: %i $:%.2f",x+1,tabela[8][x]);
                                       
                           }
                           medias(8);
                           break;
                case 10: printf("\n PESO MEXICANO");
                         for(x=0;x<=9;x++){
                                           printf("\n Dia: %i $:%.2f",x+1,tabela[9][x]);
                                            }
                         medias(9);
                         break;
                }
                getch();
     }

int medias(int m){
    
    float c1=0,c2=0,c3=0,t=0,medt=0,med1=0,med2=0,med3=0; //c1 periodo de 1-3; c2 periodo 4-6;c3 periodo 7-10
    int x;
    
    printf("\n \n Medias dos períodos:");
    
    for(x=0;x<=2;x++){
                      c1=c1+tabela[m][x];         
                      }
    for(x=3;x<=5;x++){
                      c2=c2+tabela[m][x];         
                      }    
    for(x=6;x<=9;x++){
                      c3=c3+tabela[m][x];         
                      } 
    for(x=0;x<=9;x++){
                      t=t+tabela[m][x];         
                      }
     med1=c1/3;
     med2=c2/3;
     med3=c3/4;
     medt=t/10;
     
     printf("\n  1-3: %.2f",med1);
     printf("\n  4-6: %.2f",med2);
     printf("\n 7-10: %.2f",med3);
     printf("\n 1-10: %.2f",medt);
     return(0);    
    
    
}
       
       
       
       
