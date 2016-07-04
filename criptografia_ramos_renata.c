//ta no PC
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

char *read_string(void);
char *monta_chave(char *string);
char *inverte_string(char *string);
char** split(char* a_str, const char a_delim);
int quant_espaco(char *string);
int *converte_string(char *string);
void *encripta_string(char *string, char* chave);


int main()
{
    char *palavra;
    palavra = read_string();

	char **splitado;
	int quantEspaco = quant_espaco(palavra);
	
	splitado = split(palavra, ' ');
	 
	int x;
	char *chave = malloc((quantEspaco+1)*sizeof(char));
	//gera a chave
	for(x=0; x < quantEspaco; x++)
	{
		chave[x] = splitado[x][0];
	}
	chave[x] = '\0';
	printf("\nchave | %s\n", chave);
	
	//inverte a string
	int tamanhoSplit = 0;
	for(x=0; x < quantEspaco; x++)
	{
		splitado[x] = inverte_string(splitado[x]);
		tamanhoSplit += strlen(splitado[x]);
	}
	
	//remove os espaços - separar em um menu
	/*for(x=0; x < quantEspaco; x++)
	{
		splitado[x]++;
	}*/
	
	splitado[0]++; //tira espaco do primeiro split
	//concatena a string invertida
	char strinvertida[tamanhoSplit];
	strinvertida[0] = '\0';
	for(x=0; x < quantEspaco; x++)
	{
		strcat(strinvertida, splitado[x]);
	}
	
	printf("olha a string invertida concatenada: %s \n", strinvertida);
	
	encripta_string(strinvertida, chave);

	return 0;
}

void *encripta_string(char *string, char *chave)
{	
	int cabeVezes;
	
	int encriptado[strlen(string)];
	
	cabeVezes = strlen(string)/strlen(chave);
	int resto = strlen(string) - strlen(chave)*cabeVezes;
	
	int x, i;
	i=0;
	for(x=0; x < strlen(string); x++)
	{
		if(i == strlen(chave))
			i = 0;
		encriptado[x] = (char)((int)string[x]^(int)chave[i]);
		i++;
	}
	
	for(x=0; x < strlen(string); x++)
		printf("%x", encriptado[x]);
	printf("\n");
	
}



int *converte_string(char *string)
{
	int *convertido;
	
	convertido = malloc((strlen(string))*sizeof(int));
	
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
	
	int tras;//inicia o vetor de inversao
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

char** split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
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
