#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string(void);
char *monta_chave(char *string);
char *inverte_string(char *string);
char **split(char frase[], char separador);
int quant_espaco(char *string);
int *converte_string(char *string);


void main()
{

    char *palavra;

    palavra = read_string();

    puts(palavra);

	char **splitado;
	
	splitado = split(palavra, ' ');
	 
	int x, quantEspaco = quant_espaco(palavra);
	
	char chave[quantEspaco];
	
	//gera a chave
	for(x=0; x < quantEspaco; x++)
	{
		chave[x] = splitado[x][0];
	}
	chave[x] = '\0';
	
	//inverte a string
	for(x=0; x < quantEspaco; x++)
	{
		splitado[x] = inverte_string(splitado[x]);
	}

	printf("\nchave | %s\n", chave);
	
	int *convertido;
	
	int i;
	for(x=0; x < quantEspaco; x++)
	{
		convertido = converte_string(splitado[x]);
		for(i = 0; i < strlen(splitado[x]); i++)
		{
			printf("posicao %d | codigo %d \t| letra %c \n", i, convertido[i], (char)convertido[i]);
		}
	}
}

int *converte_string(char *string)
{
	int *convertido;
	
	convertido = malloc((strlen(string)));
	
	int x;
	for(x=0; x < strlen(string); x++)
	{
		convertido[x] = (int)string[x];
	}
	return convertido;
}

int quant_espaco(char *string)
{
	int x, quant=0;
	for(x = 0; x < strlen(string); x++)
		if((string[x] == ' ') || (string[x+1] == '\0'))
			quant++;
	
	return quant;
}

char *inverte_string(char *string)
{
	char *invertida = NULL;
	
	invertida = malloc((strlen(string))*sizeof(char));
	
	int tras;
	for(tras = 0; tras < strlen(string)+1; tras++)
	{
		invertida[tras] = ' ';
	}
	
	invertida[strlen(string)+1] = '\0';
	
	for(tras = strlen(string); tras > 0; tras--)
	{
		invertida[tras] = string[strlen(string) - tras];
	}
	
	return invertida;
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
  puts(big);
  return big;
}
