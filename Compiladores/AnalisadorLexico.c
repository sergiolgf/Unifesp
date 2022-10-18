#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
  FILE *arq,*arq2;
  char saida,a;
  int i;
  char p;
  char *c;
  int estado;
  
  if (argc!=3){
    printf("Erro numero de argumentos\n");
    return 1;
  }
  arq=fopen(argv[1],"r");
  arq2=fopen(argv[2],"w");
  if(arq==NULL||arq2==NULL){
    printf("Erro leitura\n");
    return 1;
  }

  p=fgetc(arq);
  estado=1;
  while(estado==1||estado==2){
    switch(estado){
        case 1:
            if((p>64&&p<91)||(p>96&&p<123)){//letra maiuscula ou minuscula
                //tratamento pra funcao
                estado=2;
                p=fgetc(arq);
            }else{
                estado=4;
            }
            break;
        case 2:
            if((p>64&&p<91)||(p>96&&p<123)||(p>47&&p<58)){//letra ou digito
                estado=2;
                p=fgetc(arq);
            }else{
                estado=3;
            }
            break;
    }
  }
  if(estado==3){
      //aceitacao
  }else{
      //erro
  }
  fputc(p,arq2);
  p=fgetc(arq);



  fclose(arq);
  fclose(arq2);
  
  
  return 0;
}