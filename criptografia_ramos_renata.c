#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string(void);
char *monta_chave(char *string);
char *inverte_string(char *string);
char **split(char frase[], char separador);
int quant_espaco(char *string);


void main()
{

    char *palavra;

    palavra = read_string();

    puts(palavra);

    char *reverso;
	char **splitado;
	
	//reverso = malloc((strlen(palavra)+1)*sizeof(char));

    printf("palavra %d\n", strlen(palavra));

	splitado = split(palavra, ' '); 
	
	int x=0;
	for(x=0; x < quant_espaco(palavra); x++)
	{
		printf("split %d - %s\n",x, splitado[x]);
		splitado[x] = inverte_string(splitado[x]);
		printf("split invertido %d - %s\n",x, splitado[x]);
	}
}

int quant_espaco(char *string)
{
	int x, quant=0;
	for(x = 0; x < strlen(string); x++)
		if((string[x] == ' ') || (string[x+1] == '\0'))
			quant++;
	
	return quant;
}


char **split(char frase[], char separador)
{
    int i, j, k, contsep = 0;

     for(i=0,contsep=0;i<strlen(frase);i++)
       if(frase[i] == separador)
          contsep++;

    char  aux[contsep][20];
    char **result = (char**)malloc(contsep*sizeof(char));
    
    if(contsep)
    {
        for(i=0; i<=contsep; i++ )
          *(result + i) = (char*)malloc(40*sizeof(char));
        
        for(i=0,k=0,j=0; i < strlen(frase); i++)
           if(frase[i] != separador)
           {
              aux[k][j] = frase[i];
              j++;
           }
           else
           {
              aux[k][j] = 0;
              k++;
              j=0;
           }
        aux[k][j] = 0;
        
        for(i=0;i<=contsep;i++)
          *(result+i) = strcpy(*(result+i), aux[i]);
        
        return result;
    }
    else
        return '\0';
}

char *inverte_string(char *string)
{
	char *invertida = NULL;
	
	invertida = malloc((strlen(string))*sizeof(char));
	
	int tras = 0;
	for(tras; tras < strlen(string)-1; tras++)
		invertida[tras] = ' ';
		
	invertida[strlen(string)+1] = '\0';
	
	for(tras = strlen(string); tras > 0; tras--)
	{
		invertida[tras] = string[strlen(string) - tras];
	}
	return invertida;
}



char *read_string(void)
{
  char *big = NULL, *old_big;
  char s[11] = {0};
  int len = 0, old_len;

  do {
    old_len = len;
    old_big = big;
    scanf("%10[^\n]", s);
    if (!(big = realloc(big, (len += strlen(s)) + 1))) {
      free(old_big);
      fprintf(stderr, "Out of memory!\n");
      return NULL;
    }
    strcpy(big + old_len, s);
  } while (len - old_len == 10);
  return big;
}
