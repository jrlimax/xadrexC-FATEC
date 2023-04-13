#include <iostream>

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

void validarPosicao(int linhaPeca, int colunaPeca) {

  int destinoLinha;
  int destinoColuna;
  char letra = tabuleiro[linhaPeca][colunaPeca];
  int i = 0;

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
    tabuleiro[destinoLinha][destinoColuna] = letra;
    tabuleiro[linhaPeca][colunaPeca] = ' ';
    limparTabuleiro();
  }
}

void movimentarBispo(int linhaPeca, int colunaPeca) {

  int i = 1;

  while (tabuleiro[linhaPeca + i][colunaPeca + i] == ' ') {
    tabuleiro[linhaPeca + i][colunaPeca + i] = 'X';
    i++;
  }

  i = 1;

  while (tabuleiro[linhaPeca - i][colunaPeca + i] == ' ') {
    tabuleiro[linhaPeca - i][colunaPeca + i] = 'X';
    i++;
  }

  i = 1;

  while (tabuleiro[linhaPeca - i][colunaPeca - i] == ' ') {
    tabuleiro[linhaPeca - i][colunaPeca - i] = 'X';
    i++;
  }

  i = 1;

  while (tabuleiro[linhaPeca + i][colunaPeca - i] == ' ') {
    tabuleiro[linhaPeca + i][colunaPeca - i] = 'X';
    i++;
  }
}

void movimentarTorre(int linhaPeca, int colunaPeca) {

  int contador = 1;

  while (tabuleiro[linhaPeca + contador][colunaPeca] == ' ') {
    tabuleiro[linhaPeca + contador][colunaPeca] = 'X';
    contador++;
  }

  contador = 1;

  while (tabuleiro[linhaPeca - contador][colunaPeca] == ' ') {
    tabuleiro[linhaPeca - contador][colunaPeca] = 'X';
    contador++;
  }

  contador = 1;

  while (tabuleiro[linhaPeca][colunaPeca - contador] == ' ') {
    tabuleiro[linhaPeca][colunaPeca - contador] = 'X';
    contador++;
  }

  contador = 1;

  while (tabuleiro[linhaPeca][colunaPeca + contador] == ' ') {
    tabuleiro[linhaPeca][colunaPeca + contador] = 'X';
    contador++;
  }
}

void movimentarCavalo(int linhaPeca, int colunaPeca) {

  if (tabuleiro[linhaPeca + 2][colunaPeca + 1] == ' ') {
    tabuleiro[linhaPeca + 2][colunaPeca + 1] = 'X';
  }

  if (tabuleiro[linhaPeca + 2][colunaPeca - 1] == ' ') {
    tabuleiro[linhaPeca + 2][colunaPeca - 1] = 'X';
  }

  if (tabuleiro[linhaPeca - 2][colunaPeca + 1] == ' ') {
    tabuleiro[linhaPeca - 2][colunaPeca + 1] = 'X';
  }

  if (tabuleiro[linhaPeca - 2][colunaPeca - 1] == ' ') {
    tabuleiro[linhaPeca - 2][colunaPeca - 1] = 'X';
  }
}

void movimentarRei(int linhaPeca, int colunaPeca) {

  int i = -1;

  while (i < 2) {
    if (tabuleiro[linhaPeca + 1][colunaPeca + i] == ' ')
      tabuleiro[linhaPeca + 1][colunaPeca + i] = 'X';
    i++;
  }

  i = -1;

  while (i < 2) {
    if (tabuleiro[linhaPeca - 1][colunaPeca + i] == ' ')
      tabuleiro[linhaPeca - 1][colunaPeca + i] = 'X';
    i++;
  }

  if (tabuleiro[linhaPeca][colunaPeca + 1] == ' ')
    tabuleiro[linhaPeca][colunaPeca + 1] = 'X';

  if (tabuleiro[linhaPeca][colunaPeca - 1] == ' ')
    tabuleiro[linhaPeca][colunaPeca - 1] = 'X';
}

// PEÇAS BRANCAS

void movimentarReiBranco(int linhaPeca, int colunaPeca) {

  movimentarRei(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarCavaloBranco(int linhaPeca, int colunaPeca) {

  movimentarCavalo(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarBispoBranco(int linhaPeca, int colunaPeca) {

  movimentarBispo(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarPeaoBranco(int linhaPeca, int colunaPeca) {

  char linhaInicial = '7';

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

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarTorreBranca(int linhaPeca, int colunaPeca) {

  movimentarTorre(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarRainhaBranca(int linhaPeca, int colunaPeca) {

  movimentarBispo(linhaPeca, colunaPeca);
  movimentarTorre(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

// PEÇAS PRETAS

void movimentarReiPreto(int linhaPeca, int colunaPeca) {

  movimentarRei(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarRainhaPreta(int linhaPeca, int colunaPeca) {

  movimentarBispo(linhaPeca, colunaPeca);
  movimentarTorre(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarBispoPreto(int linhaPeca, int colunaPeca) {

  movimentarBispo(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarCavaloPreto(int linhaPeca, int colunaPeca) {

  movimentarCavalo(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarPeaoPreto(int linhaPeca, int colunaPeca) {

  char linhaInicial = '2';

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

  validarPosicao(linhaPeca, colunaPeca);
}

void movimentarTorrePreta(int linhaPeca, int colunaPeca) {

  movimentarTorre(linhaPeca, colunaPeca);

  colocarTabuleiro();

  validarPosicao(linhaPeca, colunaPeca);
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

    if (tabuleiro[linhaPeca][colunaPeca] == 'C') {
      movimentarCavaloBranco(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 'c') {
      movimentarCavaloPreto(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 'B') {
      movimentarBispoBranco(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 'b') {
      movimentarBispoPreto(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 'Q') {
      movimentarRainhaBranca(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 'q') {
      movimentarRainhaPreta(linhaPeca, colunaPeca);
    }


    if (tabuleiro[linhaPeca][colunaPeca] == 'R') {
      movimentarReiBranco(linhaPeca, colunaPeca);
    }

    if (tabuleiro[linhaPeca][colunaPeca] == 'r') {
      movimentarReiPreto(linhaPeca, colunaPeca);
    }

    colocarTabuleiro();

    i++;
  } while (i < 6);
}
