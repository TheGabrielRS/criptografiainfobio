#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string(void);
char *monta_chave(char *string);
char *inverte_string(char *string);

void main()
{

    char *palavra;

    palavra = read_string();

    puts(palavra);

    char *reverso;
	char *splitado;
reverso = malloc((strlen(palavra)+1)*sizeof(char));

    printf("palavra %d\n", strlen(palavra));

	splitado = strtok(palavra, " ");
	
	while(splitado != NULL)
	{
		printf("\nsplitado: %s", splitado);
		splitado = strtok(NULL, " ");
		reverso = inverte_string(splitado);
		printf("\nreverso: %s", reverso);
		
	}

    
    
   // reverso = inverte_string(palavra);
    
   // printf("\nreverso: %s", reverso);

}

char *monta_chave(char *string)
{
	
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
