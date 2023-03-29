#include <cstdio>
#include <iostream>
#include <string.h>

  char tabuleiro[9][9]={

    ' ', '1', '2', '3', '4', '5', '6', '7', '8',
    '1', 'T' , 'C', 'B', 'Q', 'R', 'B', 'C', 'T',
    '2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 
    '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    '7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 
    '8', 'T', 'C', 'B', 'Q', 'R', 'B', 'C', 'T',
  };

void colocarTabuleiro(){

  for (int linha = 0; linha < 9; linha++){
    std::cout << std::endl;
    for (int coluna = 0; coluna < 9; coluna++){
    std::cout << tabuleiro[linha][coluna];
    if (linha == 0){
        std:: cout << "   ";
    }else { 
      std::cout << " | ";
      }
    }
  }
  
  std::cout << std::endl;

}

void movimentarPeao(int linhaPeca, int colunaPeca){
    
    int destinoLinha;
    int destinoColuna;
    char teste = '7';

    if(*tabuleiro[linhaPeca] == teste ){
      tabuleiro[linhaPeca - 1][colunaPeca] = 'X';
      tabuleiro[linhaPeca - 2][colunaPeca] = 'X';
  }
    
    colocarTabuleiro();  

    

    std::cout << "Digite a linha destino: ";
    std::cin >> destinoLinha;

    std::cout << "Digite a coluna destino: ";
    std::cin >> destinoColuna;

      if (tabuleiro[destinoLinha][destinoColuna] == 'X') {
        tabuleiro[destinoLinha][destinoColuna] = 'P';
        tabuleiro[linhaPeca][colunaPeca] = ' ';
      }

}

int main(){

  int linhaPeca;
  int colunaPeca;

  colocarTabuleiro();

  std::cout << std::endl;

  std::cout << "Digite a linha da peça: ";
  std::cin >> linhaPeca;

  std::cout << "Digite a coluna da peça: ";
  std::cin >> colunaPeca;

  if(tabuleiro[linhaPeca][colunaPeca] == 'P'){    
    movimentarPeao(linhaPeca, colunaPeca);   
  }

  colocarTabuleiro();

}
