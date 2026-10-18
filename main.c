#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    
    int shift;
    int criptograficValue; // Valor para a cifra PA
    int selectedEncription;
    char alfabet[100];
    
} appConfigs;

void logMessage(char fileName[], char message[]) 
{

    FILE *currentFile = fopen(fileName, "a");

    if (currentFile == NULL) 
    {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fprintf(currentFile, message);

    fclose(currentFile);

}

void applyCesar(const char inputWord[], int shift, char alfabet[], char completeCifre[])
{
    int alfabetLength = strlen(alfabet);

    int i;
    for (i = 0; inputWord[i] != '\0'; i++)
    {
        int j;
        for(j = 0; j < alfabetLength; j++)
        {
            if (inputWord[i] == alfabet[j]) {break;}
        }

        if (j < alfabetLength)
        {
            int cifreIndex = ((j + shift) % alfabetLength + alfabetLength) % alfabetLength;
            completeCifre[i] = alfabet[cifreIndex];
        } else 
        {
           completeCifre[i] = inputWord[i];
        }
    }
    completeCifre[i] = '\0';
}

void applyPA(const char inputWord[], int criptograficValue, char alfabet[], char completeCifre[])
{
    int p1 = 1;
    int alfabetLength = strlen(alfabet);

    int i;
    for (i = 0; inputWord[i] != '\0'; i++)
    {
        int j;
        for(j = 0; j < alfabetLength; j++)
        {
            if (inputWord[i] == alfabet[j]) {break;}
        }

        if (j < alfabetLength)
        {
            int cifreIndex = ((criptograficValue % 26) * p1 % 26);
            completeCifre[i] = alfabet[(j + cifreIndex) % 26];
        } else 
        {
           completeCifre[i] = inputWord[i];
        }

        p1 = (((p1 + criptograficValue) % 26) + 26) % 26;
    }
    completeCifre[i] = '\0';
}

void applyGolden(const char inputWord[], char alfabet[], char completeCifre[])
{
    int lastNumber = 0;
    int currentNumber = 1;
    int tempNumber;
    
    int alfabetLength = strlen(alfabet);

    int i;
    for (i = 0; inputWord[i] != '\0'; i++)
    {
        int j;
        for(j = 0; j < alfabetLength; j++)
        {
            if (inputWord[i] == alfabet[j]) {break;}
        }

        if (j < alfabetLength)
        {
            completeCifre[i] = alfabet[(j + currentNumber) % alfabetLength];

            tempNumber = currentNumber;
            currentNumber = (currentNumber + lastNumber) % alfabetLength;
            lastNumber = tempNumber;
            
        } else 
        {
           completeCifre[i] = inputWord[i];
        }

    }
    completeCifre[i] = '\0';
}

void initalMenu(int *menuChoice)
{
	int tempChoice = -1;

	while (tempChoice != 0 && tempChoice != 1 && tempChoice != 2)
	{
		system("clear");
		printf("Escolha o que deseja realizar:\n");
		printf("0: Sair do sistema;\n");
		printf("1: Mudar configurações;\n");
		printf("2: Criptografar mensagem;\n");
		scanf("%d", &tempChoice);
	}

	*menuChoice = tempChoice;

}

void configMenu(appConfigs *currentConfig) 
{
    int tempChoice;

	while (tempChoice != 0)
	{
        
	    system("clear");
        printf("%d\n", tempChoice);
	    printf("Shift Atual: %d\n", currentConfig->shift);
	    printf("Alfabeto atual: %s\n", currentConfig->alfabet);
	    printf("Cifra atual: %d\n", currentConfig->selectedEncription);
	    printf("Peso para a PA: %d\n", currentConfig->criptograficValue);
	    printf("-------------------------------------------------------\n");
	    printf("Tabela de cifras:\n1: Progressão Aritimética\n2: Sequência de Fibonnaci\n");
	    printf("-------------------------------------------------------\n");
	    printf("Escolha o que deseja mudar:\n0: Voltar para o menu inicial\n1: Mudar o shift\n2: Mudar o alfabeto\n3: Mudar a cifra selecionada\n4: Mudar o peso da PA\n");
	    scanf("%d", &tempChoice);
	    
	    switch (tempChoice)
	    {
	        
	        case 0:
            system("clear");
	        break;
	        
	        case 1:
	        system("clear");
	        printf("Digite o shift: ");
	        scanf("%d", &currentConfig->shift);
	        break;
	        
	        case 2:
	        system("clear");
	        printf("Digite o alfabeto atual: ");
	        scanf("%s", currentConfig->alfabet);
	        break;
	        
	        case 3:
	        system("clear");
	        printf("Digite o número correspondente a cifra: ");
	        scanf("%d", &currentConfig->selectedEncription);
	        break;
	        
	        case 4:
	        system("clear");
	        printf("Digite o peso para a PA: ");
	        scanf("%d", &currentConfig->criptograficValue);
	        break;
	        
	    }
	    
	}
}

void criptograficMenu(appConfigs *currentConfig)
{

    int tempChoice;
    char inputWord[100];
    char cesarCifre[100];
    char finishedCifre[100];
    char log[100];


    while (tempChoice != 0)
    {
        system("clear");
        printf("Digite a frase a ser criptografada:\n");
        scanf(" %[^\n]", inputWord);
        system("clear");

        applyCesar(inputWord, currentConfig->shift, currentConfig->alfabet, cesarCifre);

        if (currentConfig->selectedEncription == 1) 
        {
            applyPA(cesarCifre, currentConfig->criptograficValue, currentConfig->alfabet, finishedCifre);
        } else {
            applyGolden(cesarCifre, currentConfig->alfabet, finishedCifre);
        }

        snprintf(log, sizeof(log), "Palavra: %s | Tipo: %d | Letras: %d\n", finishedCifre, currentConfig->selectedEncription, strlen(finishedCifre));

        logMessage("resultado_criptografia.txt", log);
        
        printf("Frase criptografada: \n%s\n", finishedCifre);
        printf("-------------------------------------------------------\n");
        printf("Você deseja:\n0: Sair para o menu principal\n1: Criptografar outra frase\n");
        scanf("%d", &tempChoice);

    }

}

int main()
{
	appConfigs currentConfig;
	strcpy(currentConfig.alfabet, "abcdefghijklmnopqrstuvwxyz");
    currentConfig.shift = 3;
    currentConfig.selectedEncription = 1;
    currentConfig.criptograficValue = 5;
    int menuChoice = -1;
    
    
	while (menuChoice != 0)
	{
		initalMenu(&menuChoice);

		switch (menuChoice)
		{

		case 0:
			break;

		case 1:

			configMenu(&currentConfig);
			break;

		case 2:
		
			criptograficMenu(&currentConfig);
			break;
		}

	}

    return 0;
}
