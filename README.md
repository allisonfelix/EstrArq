# Merge de Arquivos de Endereços Ordenados por CEP

Este programa em C realiza a fusão (merge) de dois arquivos binários contendo registros de endereços ordenados por CEP, gerando um terceiro arquivo com os dados mesclados também em ordem crescente.

## 📌 Como Funciona

1. O código define uma estrutura `Endereco` para armazenar os dados de um endereço, incluindo logradouro, bairro, cidade, UF, sigla e CEP.
2. Abre dois arquivos de entrada (`cep1.dat` e `cep2.dat`), ambos contendo registros de endereços ordenados por CEP.
3. Lê e compara os registros de ambos os arquivos, utilizando a função `compara()`, que realiza a comparação com base no campo `cep`.
4. Escreve os registros no arquivo de saída (`cep_output.dat`) na ordem correta.
5. Caso um dos arquivos termine antes do outro, os registros restantes do outro arquivo são copiados diretamente para o arquivo de saída.
6. Garante que todos os registros sejam processados até o fim dos arquivos.

## 🛠 Estrutura do Código

- **Estrutura `Endereco`**: Define o formato dos registros armazenados nos arquivos binários.
- **Função `compara()`**: Compara dois endereços com base no campo `cep`.
- **Função `main()`**:
  - Abre os arquivos de entrada e saída.
  - Faz a leitura e comparação dos registros.
  - Mescla os dados mantendo a ordenação por CEP.
  - Fecha os arquivos após a operação.

## 📂 Estrutura dos Arquivos de Entrada

Os arquivos `cep1.dat` e `cep2.dat` são arquivos binários contendo registros da estrutura `Endereco`. Eles devem estar previamente ordenados por CEP para que o algoritmo funcione corretamente.
Descrição da estrutura `Endereco`:
```c
typedef struct {
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char uf[72];
    char sigla[2];
    char cep[8];
    char lixo[2];
} Endereco;
```

## ▶️ Como usar
Você pode utilizar o **executável** já fornecido ou **compilar o código manualmente**.

### Opção 1: Usando o Executável (Recomendado)

1. Certifique-se de que os arquivos `cep1.dat` e `cep2.dat` estão no mesmo diretório do executável.
2. Navegue pelo terminal até a pasta onde está o executável e os arquivos de entrada.
3. Execute o programa:
- Linux/macOS:
  ```bash
  ./intercala
  ```
- Windows:
  ```bash
  intercala.exe
  ```
   
4. O arquivo mesclado será salvo como `cep_output.dat`.

### Opção 2: Compilando o Código Manualmente
Caso prefira compilar o código fonte:

1. Compile e execute o programa usando:
- Linux/macOS:
```bash
gcc intercala.c -o intercala
./intercala
```

- Windows:
```bash
gcc intercala.c -o intercala.exe
intercala.exe
```

## 📌 Observações
- O programa não ordena os arquivos, apenas os mescla. Portanto, os arquivos de entrada devem estar previamente ordenados por CEP.
- O processo de merge é eficiente e pode ser usado em bases de dados grandes.

## 📜 Licença
Este projeto está sob a licença MIT, então fique à vontade para modificar e compartilhar!
