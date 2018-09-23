#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct End Endereco;

struct End
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int compara(const void *end1, const void *end2)
{
	return strncmp(((Endereco*)end1)->cep,((Endereco*)end2)->cep,8);
}

int main(int argc, char**argv)
{
	FILE *arq1, *arq2, *output;
	Endereco end1, end2;

	arq1 = fopen("cep1.dat","r");
	arq2 = fopen("cep2.dat","r");
	output = fopen("cep_output.dat","w");

	fread(&end1,sizeof(Endereco),1,arq1);
	fread(&end2,sizeof(Endereco),1,arq2);

	while(!feof(arq1) && !feof(arq2))
	{
		if(compara(&end1,&end2)<0)
		{
			fwrite(&end1,sizeof(Endereco),1,output);
			fread(&end1,sizeof(Endereco),1,arq1);
		}
		else
		{
			fwrite(&end2,sizeof(Endereco),1,output);
			fread(&end2,sizeof(Endereco),1,arq2);
		}
	}

	while(!feof(arq1))
	{
		fwrite(&end1,sizeof(Endereco),1,output);
		fread(&end1,sizeof(Endereco),1,arq1);		
	}
	while(!feof(arq2))
	{
		fwrite(&end2,sizeof(Endereco),1,output);
		fread(&end2,sizeof(Endereco),1,arq2);		
	}

	fclose(arq1);
	fclose(arq2);
	fclose(output);
}
