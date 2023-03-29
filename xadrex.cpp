#include <cstdio>
#include <iostream>
#include <string.h>

char tabuleiro[9][9] = {

    ' ', '1', '2', '3', '4', '5', '6', '7', '8', '1', 't', 'c', 'b', 'q',
    'r', 'b', 'c', 't', '2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '3',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '6', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', '7', 'P', 'P', 'P', 'P', 'P', 'P',
    'P', 'P', '8', 'T', 'C', 'B', 'Q', 'R', 'B', 'C', 'T',
};

void limparTabuleiro() {
  for (int linha = 0; linha < 9; linha++) {
    for (int coluna = 0; coluna < 9; coluna++) {
      if (tabuleiro[linha][coluna] == 'X') {
        tabuleiro[linha][coluna] = ' ';
      }
    }
  }
}

void colocarTabuleiro() {

  for (int linha = 0; linha < 9; linha++) {
    std::cout << std::endl;
    for (int coluna = 0; coluna < 9; coluna++) {
      std::cout << tabuleiro[linha][coluna];
      if (linha == 0) {
        std::cout << "   ";
      } else {
        std::cout << " | ";
      }
    }
  }

  std::cout << std::endl;
}

void movimentarPeaoBranco(int linhaPeca, int colunaPeca) {

  int destinoLinha;
  int destinoColuna;
  char linhaInicial = '7';

  if (*tabuleiro[linhaPeca] == linhaInicial) {
    tabuleiro[linhaPeca - 1][colunaPeca] = 'X';
    tabuleiro[linhaPeca - 2][colunaPeca] = 'X';
  } else {
    tabuleiro[linhaPeca - 1][colunaPeca] = 'X';
  }

  colocarTabuleiro();

  std::cout << std::endl;

  std::cout << "Digite a linha destino: ";
  std::cin >> destinoLinha;

  std::cout << "Digite a coluna destino: ";
  std::cin >> destinoColuna;

  if (tabuleiro[destinoLinha][destinoColuna] == 'X') {
    tabuleiro[destinoLinha][destinoColuna] = 'P';
    tabuleiro[linhaPeca][colunaPeca] = ' ';
    limparTabuleiro();
  }
}

int main() {

  int i = 0;

  do {

    int linhaPeca;
    int colunaPeca;

    colocarTabuleiro();

    std::cout << std::endl;

    std::cout << "Digite a linha da peça: ";
    std::cin >> linhaPeca;

    std::cout << "Digite a coluna da peça: ";
    std::cin >> colunaPeca;

    if (tabuleiro[linhaPeca][colunaPeca] == 'P') {
      movimentarPeaoBranco(linhaPeca, colunaPeca);
    }

    colocarTabuleiro();

    i++;
  } while (i < 6);
}
