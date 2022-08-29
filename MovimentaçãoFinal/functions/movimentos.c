#define MAPA_L 30
#define MAPA_C 120
#define TAMANHO_BLOCOS 64

void jogCima(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *animacaoVertical, int *dMov, int *frameCounter) {
    if (mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS] != 15) {
        switch (mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS]) {
            case 01 ... 10:
                *porta = mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS];
                break;
            case 11 ... 13:
                *bau = mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS];
                break;
        }
    }
    movVertical(yJog, animacaoVertical, -1, frameCounter, dMov);
}

void jogBaixo(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *animacaoVertical, int *dMov, int *frameCounter) {
    if (mapa[*yJog / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS] != 15) {
        *bau = 0;
        *porta = 0;
    }
    movVertical(yJog, animacaoVertical, 1, frameCounter, dMov);
}

void jogEsquerda(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft, bool *animacaoHorizontal, int *dMov, int *frameCounter) {
    if (*facingLeft) {
        if (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1] < 16) {
            switch (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1]) {
                case 00:
                    *porta = 0;
                    *bau = 0;
                    break;
                case 01 ... 10:
                    *porta = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1];
                    *bau = 0;
                    break;
                case 11 ... 13:
                    *porta = 0;
                    *bau = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1];
                    break;
                case 15:
                    *porta = 0;
                    *bau= 0;
                    break;
            }
            movHorizontal(xJog, animacaoHorizontal, -1, frameCounter, dMov);
        }

    } else {
        *facingLeft = true;
    }
}

void jogDireita(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft, bool *animacaoHorizontal, int *dMov, int *frameCounter) {
    if (*facingLeft) {
        *facingLeft = false;
    } else {
        if (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1] < 16) {
            switch (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1]) {
                case 00:
                    *porta = 0;
                    *bau = 0;
                    break;
                case 01 ... 10:
                    *porta = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1];
                    *bau = 0;
                    break;
                case 11 ... 13:
                    *porta = 0;
                    *bau = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1];
                    break;
                case 15:
                    *porta = 0;
                    *bau = 0;
                    break;
            }
            movHorizontal(xJog, animacaoHorizontal, 1, frameCounter, dMov);
        }
    }

}


void abrePorta(int mapa[MAPA_L][MAPA_C], int *porta, int *xJog, int *yJog, int linhas, int colunas) {
    int i = 0, j = 0, xPorta, yPorta;
    bool rodar = true;

    *xJog = *xJog / TAMANHO_BLOCOS;
    *yJog = *yJog / TAMANHO_BLOCOS;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if ((mapa[i][j] == *porta) && ((i != *yJog) || (j != *xJog))) {
                xPorta = j;
                yPorta = i;
            }
        }
    }

    *xJog = xPorta;
    *yJog = yPorta;
    *xJog = *xJog * TAMANHO_BLOCOS;
    *yJog = *yJog * TAMANHO_BLOCOS;
}


void abreBau(int mapa[MAPA_L][MAPA_C], int *bau, int *xJog, int *yJog) {

    *xJog = *xJog / TAMANHO_BLOCOS;
    *yJog = *yJog / TAMANHO_BLOCOS;
    switch (mapa[*yJog][*xJog]) {
        case 11:
            printf("Voc� achou a chave!\n");
            break;
        case 12:
            printf("Voc� explodiu!\n");
            break;
        case 13:
            printf("Voc� achou um item bacana!\n");
            break;
    }
    *xJog = *xJog * TAMANHO_BLOCOS;
    *yJog = *yJog * TAMANHO_BLOCOS;
}

int altura(int mapa[MAPA_L][MAPA_C], int *xJog, int *yJog) {
    int h = 0;
    while (mapa[(*yJog / TAMANHO_BLOCOS) + (h + 1)][(*xJog / TAMANHO_BLOCOS)] < 15) {
        h += 1;
    }
    return h;
}
