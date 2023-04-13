#include <iostream>

char tabuleiro[9][9] = {

    ' ', '1', '2', '3', '4', '5', '6', '7', '8', '1', 't', 'c', 'b', 'q',
    'r', 'b', 'c', 't', '2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '3',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', '5', ' ', ' ', ' ', 'T', ' ', ' ', ' ', ' ', '6', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', '7', ' ', 'P', 'P', 'P', 'P', 'P',
    'P', 'P', '8', ' ', 'C', 'B', 'Q', 'R', 'B', 'C', 'T',
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

void movimentarTorre(int linhaPeca, int colunaPeca){
  int contador = 1;

  while(tabuleiro[linhaPeca + contador][colunaPeca] == ' '){
    tabuleiro[linhaPeca + contador][colunaPeca] = 'X';
    contador++;
  }

  contador = 1;

  while(tabuleiro[linhaPeca - contador][colunaPeca] == ' '){
    tabuleiro[linhaPeca - contador][colunaPeca] = 'X';
    contador++;
  }

  contador = 1;

  while(tabuleiro[linhaPeca][colunaPeca - contador] == ' '){
    tabuleiro[linhaPeca][colunaPeca - contador] = 'X';
    contador++;
  }

  contador = 1;

  while(tabuleiro[linhaPeca][colunaPeca + contador] == ' '){
    tabuleiro[linhaPeca][colunaPeca + contador] = 'X';
    contador++;
  }


}

void movimentarPeaoBranco(int linhaPeca, int colunaPeca) {

  int destinoLinha;
  int destinoColuna;
  char linhaInicial = '7';
  int i = 0;

  if (*tabuleiro[linhaPeca] == linhaInicial &&
      tabuleiro[linhaPeca - 1][colunaPeca] == ' ' &&
      tabuleiro[linhaPeca - 2][colunaPeca] == ' ') {
    tabuleiro[linhaPeca - 1][colunaPeca] = 'X';
    tabuleiro[linhaPeca - 2][colunaPeca] = 'X';
  } else if (tabuleiro[linhaPeca - 1][colunaPeca] == ' ') {
    tabuleiro[linhaPeca - 1][colunaPeca] = 'X';

  } else {
    std::cout << "Movimento invalido.";
    std::cout << std::endl;
    return;
  }

  colocarTabuleiro();

  std::cout << std::endl;

  do {

    if (i > 0) {
      std::cout << "Movimento Invalido, escolha uma casa X.";
      std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Digite a linha destino: ";
    std::cin >> destinoLinha;

    std::cout << "Digite a coluna destino: ";
    std::cin >> destinoColuna;

    i++;

  } while (tabuleiro[destinoLinha][destinoColuna] != 'X');

  if (tabuleiro[destinoLinha][destinoColuna] == 'X') {
    tabuleiro[destinoLinha][destinoColuna] = 'P';
    tabuleiro[linhaPeca][colunaPeca] = ' ';
    limparTabuleiro();
  }
}

void movimentarTorreBranca(int linhaPeca, int colunaPeca) {
  
  int destinoLinha;
  int destinoColuna;
  int i = 0;
  
  movimentarTorre(linhaPeca,colunaPeca);
  colocarTabuleiro();

  do {

    if (i > 0) {
      std::cout << "Movimento Invalido, escolha uma casa X.";
      std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Digite a linha destino: ";
    std::cin >> destinoLinha;

    std::cout << "Digite a coluna destino: ";
    std::cin >> destinoColuna;

    i++;

  } while (tabuleiro[destinoLinha][destinoColuna] != 'X');

  if (tabuleiro[destinoLinha][destinoColuna] == 'X') {
    tabuleiro[destinoLinha][destinoColuna] = 'T';
    tabuleiro[linhaPeca][colunaPeca] = ' ';
    limparTabuleiro();
  }
}

void movimentarPeaoPreto(int linhaPeca, int colunaPeca) {

  int destinoLinha;
  int destinoColuna;
  char linhaInicial = '2';
  int i = 0;

  if (*tabuleiro[linhaPeca] == linhaInicial &&
      tabuleiro[linhaPeca + 1][colunaPeca] == ' ' &&
      tabuleiro[linhaPeca + 2][colunaPeca] == ' ') {
    tabuleiro[linhaPeca + 1][colunaPeca] = 'X';
    tabuleiro[linhaPeca + 2][colunaPeca] = 'X';
  } else if (tabuleiro[linhaPeca + 1][colunaPeca] == ' ') {
    tabuleiro[linhaPeca + 1][colunaPeca] = 'X';

  } else {
    std::cout << "Movimento invalido.";
    std::cout << std::endl;
    return;
  }

  colocarTabuleiro();

  std::cout << std::endl;

  do {

    if (i > 0) {
      std::cout << "Movimento Invalido, escolha uma casa X.";
      std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Digite a linha destino: ";
    std::cin >> destinoLinha;

    std::cout << "Digite a coluna destino: ";
    std::cin >> destinoColuna;

    i++;

  } while (tabuleiro[destinoLinha][destinoColuna] != 'X');

  if (tabuleiro[destinoLinha][destinoColuna] == 'X') {
    tabuleiro[destinoLinha][destinoColuna] = 'P';
    tabuleiro[linhaPeca][colunaPeca] = ' ';
    limparTabuleiro();
  }
}

void movimentarTorrePreta(int linhaPeca, int colunaPeca) {
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

    if (tabuleiro[linhaPeca][colunaPeca] == 'p') {
      movimentarPeaoPreto(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 'T') {
      movimentarTorreBranca(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 't') {
      movimentarTorrePreta(linhaPeca, colunaPeca);
    }

    colocarTabuleiro();

    i++;
  } while (i < 6);
}
