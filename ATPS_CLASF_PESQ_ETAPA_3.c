#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define MAX          50000   
#define NumProcurado 32767   
#define parm_sort     4                       // 1ª sessão de Testes
#define parm_search   0                       // 1. Busca linear.                    
                       /*--------------------|   2. Busca Binária.                        
                                      -          3. Ordenação usando seleção.    
                                      -          4. Ordenação usando bubblesort. 
                                      -        
                                      -        5.A. ordenação por troca: quicksort;
                                      -        6.B. ordenação por inserção: binária;
                                      -------> 7.C. ordenação por inserção: shellsort;
                                               8.D. ordenação por seleção: heapsort;
                                               9.E. ordenação por intercalação: mergesort. */
                                    

struct arvorebusca{
int n;
struct arvorebusca *ant,*d,*e;
};
typedef struct arvorebusca no;

no *atual, *aux, *raiz, *busca;

void inserir(int entrada);
void pesquisar();           
int selection(char vetor[], int tamanho, char elementoProcurado);  
void buscaBinaria( int k[], int chave , int N);  // busca binaria
void quick_sort(int *a, int left, int right);    // ordenacao Quick sort
void sequencial( int k[], int chave , int N);    // busca linear
void bubble(int v[],int qtd);                    // ordenação bubble sort
void alimentaVetor();
void initialize();
void selection_sort(int *a);                     // ordenacao selection
void insertionSort(int V[], int tam);            // ordenação inserction binary
void shellSort(int *vet, int size);              // ordenação ShellSort
void heapsort(int a[], int n);                   // ordenação heapsort
void intercalar (int v[],int aux[],int ini1, int ini2,int fim2);
void mergeSort (int v[], int aux[],int esq, int dir); // Ordenacao MergeSort

void compPP();
void trocasPP();

int v_aux[MAX];
int vetor_int[MAX];

time_t tinicio, tfim; 

       int aux_int=0;
       int j=0, x=0, y=0,menu=0;      
       int i=0,c=0, tempo=0;                          /* marca o tempo inicial */ 
       int sair = 0;
       unsigned long int cont_comp   = 0;
       unsigned long int cont_comp_aux   = 0;
       unsigned long int cont_ciclos = 0;
       unsigned long int cont_trocas = 0;
       unsigned long int cont_trocas_aux = 0;
       unsigned long int cont_recrsv = 0;

main(){
int cod;
raiz=NULL;
       printf("\n --------------------------------------------------");
       printf("\n   Teste de performance, ATPS Ago-2013   ");
    
       initialize();  
       alimentaVetor();
       //heapsort(vetor_int,MAX);
       
       tinicio = time(NULL);      
       
       for(c=0;c<MAX;c++){
               inserir(vetor_int[c]);             
             }
       
        pesquisar();
     
        //    printf("\n1.inserir\n2.busca\n3.sair\n");
          //     scanf("%i",&cod);
            //     switch(cod){
                            
    //    for(c=0;c<MAX;c++){
    //      printf("\n %d",vetor_int[c]);   // printa vetor ordenado
           
     //      } 
                 
       //sequencial(vetor_int,NumProcurado,MAX);
    //   buscaBinaria(vetor_int,NumProcurado,MAX);     
                 
       tfim = time(NULL);                           /* marca o tempo final */
       tempo = difftime(tfim, tinicio);             /* marca a diferença tfim-tinicio */
       
       printf("\n \n   Dados Estatísticos  \n                ");
       printf("\n   Tempo de execucao....................: %d segundo(s).     ", tempo);
       printf("\n   Tamanho do vetor.....................: %i   ",MAX);
       printf("\n   Numero de comparacoes (Montag. arvore: %li x %li   ",cont_comp,cont_comp_aux);
       printf("\n   Numero de trocas (montagem da arvore.: %li x %li   ",cont_trocas,cont_trocas_aux);
       printf("\n   Numero de ciclos de busca............: %li    ",cont_ciclos);
       if (cont_recrsv>0) printf("\n   funcao recursiva - Num. Cham...: %li    ",cont_recrsv);
       printf("\n ---------------------------------------------------");
       getch();
      
     }
     

void inserir(int entrada){
               atual=(no *)malloc(sizeof(no));     
     
               if(atual!=NULL){
                               
                 //  printf("\ndigite o numero:\n");
                 //  scanf("%i",&atual->n);
                     
                     atual->n = entrada; 
                     
                    
                     atual->e=NULL;
                     atual->d=NULL;
                     atual->ant=NULL;
              
                cont_comp++;
                if(raiz == NULL){
                                 cont_trocas++;
                                 raiz=atual;
                }
                else{
                     aux=raiz;
                     
                     cont_comp++;
                     while(true){
                                 cont_comp++;
                                 if(atual->n>=aux->n){
                                                      cont_comp++;
                                               if(aux->d == NULL){
                                               cont_trocas++;
                                               aux->d=atual;
                                               atual->ant=aux;
                                               break;
                                               }
                                               else{
                                                    cont_trocas++;
                                                    aux=aux->d;
                                                    }
                          }
                          else{
                               cont_comp++;
                               if(aux->e==NULL){
                                                cont_trocas++;
                                                aux->e=atual;
                                                atual->ant=aux;
                                                break;
                                                }
                               else{
                                    cont_trocas++;
                                    aux=aux->e;
                                    }
                               }
                          }// fim while
              }
    }
else{
     printf("\n memoria insuficiente\n");
     }
}
     

void pesquisar(){
int np;

np = NumProcurado ;

if(raiz==NULL){
               printf("\narvore vazia\n");
}
else{
     busca=raiz;
     printf("\npercurso de busca\n");
     
     while(true){
                 cont_ciclos ++ ;
                 if(busca==NULL){
                                 printf("\n numero nao encontrado\n");
                                 break;
                 }
                 if(busca->n==np){
                                  printf(" [%i] encontrado",busca->n);
                                  break;
                 }
                 else{
                      printf(" [%i] ",busca->n);
                      if(np>busca->n){
                                      busca=busca->d;
                                      }
                      else{
                           busca=busca->e;
                           }
                      }
                 }
}
}     
     
     
void alimentaVetor(){
     
       for(c=0;c<MAX;c++){
                           vetor_int[c] = rand() % MAX;
       }
       
     }
     
           void compPP(){
                if (cont_comp == 0){
                                 cont_comp_aux ++;
                                 cont_comp ++;
                                 }
                                 else{
                                      cont_comp ++;
                                      }
                }
                
       
       void trocasPP(){
            
                if (cont_trocas == 0){
                                 cont_trocas_aux ++;
                                 cont_trocas ++;
                                 }
                                 else{
                                      cont_trocas ++;
                                      }
            }
     
       void initialize(){
       aux_int=0;
       j=0, x=0, y=0,menu=0;      
       i=0,c=0, tempo=0;                        
       sair = 0;
       cont_comp   = 0;
       cont_ciclos = 0;
       cont_trocas = 0;
       cont_recrsv = 0;
     }     
     
     
  
void sequencial( int k[], int chave , int N){
    printf("\n \n   Algoritmo de Busca.............: Sequencial ");
    
    cont_ciclos = 1;
    for(x=0;x<N;x++){
          if (k[x]==chave){
          printf("Sequencial encontrado Posicao: %i",x);
          }
          cont_ciclos ++;
}
}
     
  
  
     
void buscaBinaria( int k[], int chave , int N)
{
     printf("\n \n   Algoritmo de Busca.............: Binaria ");
 int inf,sup,meio;
 inf=0;
 sup=N-1;
 while (inf<=sup)
 {     
      cont_ciclos ++;
      meio=(inf+sup)/2;
      if (chave==k[meio]){
            printf("\n   Numero %i foi localizado no indice %i do vetor",chave,meio);
            aux_int ++;
            break;
            }
      else if (chave<k[meio])
           sup=meio-1;
      else
           inf=meio+1;
 }

}     
     
     
/*
* Retorna -1 caso não encontre ou a posição
* caso encontre.
*/
int selection(char vetor[], int tamanho, char elementoProcurado) {
int i;
for (i = 0; i < tamanho; i++) {
if (vetor[i] == elementoProcurado) {
return i;
}
}

return -1;
}

void bubble( int v[], int qtd )
{
  printf("\n \n   Algoritmo de Ordenacao.........: Bubble Sort");
  printf("\n   Processando . . .");
  int i;
  int j;
  int aux;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(v[j] > v[j+1])
        {
        cont_comp ++;
        cont_trocas ++;
        aux = v[j];
        v[j] = v[j+1];
        v[j+1]= aux;
        }
        else{
             cont_comp ++;
             }
        
        
     }
     k--;
  }
  
  printf("\n   Processado com Sucesso!");
}


void selection_sort(int *a){ 
     printf("\n \n   Algoritmo de Ordenacao.........: Selection Sort");
     printf("\n   Processando . . .");
     
     int j, k, tmp, troca;   
     
     for(i = 0; i < MAX-1; i++) {  
           troca = 0;  
           k = i;  
           tmp = a[i]; 
            
           for(j = i+1; j < MAX; j++){   
                 if(a[j] < tmp){    
                         k = j;    
                         tmp = a[j]; 
                         cont_comp ++;   
                         troca = 1;   
                 }  
           }  
           if(troca)  {  
                      cont_trocas ++;
                      a[k] = a[i];  
                      a[i] = tmp;  
           } 
     }
  printf("\n   Processado com Sucesso!");
}

void quick_sort(int *a, int left, int right) {
    i = left;
    j = right;
    x = a[(left + right) / 2];
    
    cont_recrsv ++ ;
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
            cont_comp ++ ;
        }
        while(a[j] > x && j > left) {
            j--;
            cont_comp ++ ;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            cont_trocas ++;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

void insertionSort(int V[], int tam)
{               
        int i, aux;
        printf("\n \n   Algoritmo de Ordenacao.........: Inserction Sort");
        printf("\n   Processando . . .");
 
        for(i = 1; i < tam; i++){
                while((i != 0) && (V[i] < V[i - 1])) {
                        compPP();
                        aux = V[i];
                        V[i] = V[i - 1];
                        V[i - 1] = aux;
                        trocasPP();
                        i--;    
                }               
        }
        printf("\n   Processado com Sucesso!");
}

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    printf("\n \n   Algoritmo de Ordenacao.........: Shell Sort");
    printf("\n   Processando . . .");
    do {
        gap = 3*gap+1;
    } while(gap < size);
    do {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            cont_comp++;
            cont_trocas++;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
                cont_comp++;
                cont_trocas++;
            }
            vet [j + gap] = value;
            cont_trocas++;
        }
    } while ( gap > 1);
    printf("\n   Processado com Sucesso!");
}

void heapsort(int a[], int n)
{
   printf("\n \n   Algoritmo de Ordenacao.........: Heap Sort");
   printf("\n   Processando . . .");
   
   int pai, filho, t;
   i = n/2;
   
 
   for (;;)
   {
      cont_comp++;
      if (i > 0)
      {
          cont_comp++;
          cont_trocas++;
          i--;
          t = a[i];
          
      }
      else
      {
          n--;
          if (n == 0)
          cont_comp++;
             return;
          t = a[n];
          a[n] = a[0];
          cont_trocas++;
      }
 
 
      pai = i;
 
      /*
        Primeiro será feita a comparação com o filho da esquerda.
      */
      filho = i*2;
 
      while (filho < n)
      {
         cont_comp++;
         /*
            Se o filho da esquerda for menor do que o filho da direita,
           então será feita a troca do filho que será comparado.
         */
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
              cont_comp++;
          if (a[filho] > t)
          {
             cont_comp++;
             cont_trocas++;
             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      a[pai] = t;
      cont_trocas++;
   }
   printf("\n   Processado com Sucesso!");
}



// sub função do mergrSort
void intercalar (int v[],int aux[],int ini1, int ini2,int fim2)
 {
 int in1=ini1,in2=ini2,fim1=in2-1,au=0,i,j;
 cont_recrsv ++;
 while(in1<=fim1 && in2<=fim2)
 {
  if (v[in1]<v[in2])
  {
   cont_comp ++; 
   cont_trocas ++;                  
   aux[au++] = v[in1++];
  }
  else
  {
   cont_comp ++; 
   cont_trocas ++;
   aux[au++] = v[in2++];
  }
 }
 while(in1<=fim1)
 {
  cont_comp ++; 
  cont_trocas ++;
  aux[au++] = v[in1++];
 }
 while(in2<=fim2)
 {
  cont_comp ++; 
  cont_trocas ++;
  aux[au++] = v[in2++];
 }
 
 for(i=0;i<au;i++){
  v[i+ini1]=aux[i];}
  cont_trocas ++;
 }
 

void mergeSort (int v[], int aux[],int esq, int dir)
 {
 int meio,i;
 cont_recrsv ++;
 cont_comp ++; 
 if(esq<dir)
 {
  cont_trocas ++;
  meio=(esq+dir)/2;
  mergeSort(v,aux,esq,meio);
  mergeSort(v,aux,meio+1,dir);
  intercalar(v,aux,esq,meio+1,dir);  
 }
 }
