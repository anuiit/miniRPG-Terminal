#include <stdio.h>
 
void init_carte(int map[20][20]);
int affiche_carte(int map[20][20], int pos_player[2]);
int deplace_personnage(int map[20][20], int pos_player[2]);

int game = 1;
int pos_y = 0;
int pos_x = 0;
int direction;
int hp = 10;
int gold = 0;

int main() {

    int map [20][20] ;

    int pos_player[2] = {pos_x, pos_y};

    init_carte(map);

    while (game == 1){
        
        affiche_carte(map, pos_player);

        printf("\nHP : %d    Or : %d\n", hp, gold);

        deplace_personnage(map, pos_player);
        switch (direction) {
            case 8:
                if ((pos_x - 1) < 0 || map[pos_x-1][pos_y] == 2 || map[pos_x-1][pos_y] == 3){
                    printf("\n\n\n\n\n\nDéplacement impossible.\n");
                } else {
                    pos_x -= 1;
                    printf("\n\n\n\n\n\nDéplacement vers le haut.\n");
                }
                break;
            case 4:
                if ((pos_y - 1) < 0 || map[pos_x][pos_y-1] == 2 || map[pos_x][pos_y-1] == 3){
                    printf("\n\n\n\n\n\nDéplacement impossible.\n");
                } else {
                    pos_y -= 1;
                    printf("\n\n\n\n\n\nDéplacement vers la gauche.\n");
                }
                break;
            case 2:
                if ((pos_x + 1) == 20 || map[pos_x+1][pos_y] == 2 || map[pos_x+1][pos_y] == 3){
                    printf("\n\n\n\n\n\nDéplacement impossible.\n");
                } else {
                    pos_x += 1;
                    printf("\n\n\n\n\n\nDéplacement vers le bas.\n");
                }
                break;
            case 6:
                if ((pos_y + 1) == 20 || map[pos_x][pos_y+1] == 2 || map[pos_x][pos_y+1] == 3){
                    printf("\n\n\n\n\n\nDéplacement impossible.\n");
                } else {
                    pos_y += 1;
                    printf("\n\n\n\n\n\nDéplacement vers la droite.\n");
                }
                break;
            case 0:
                game = 0;
                break;
            }

        switch (map[pos_x][pos_y]) {
            case 1:
                printf("Ca sent bon par ici.\n");
                break;
            case 4:
                printf("Vous obtenez une clef.\n");
                map[pos_x][pos_y] = 0;
                break;
            case 5:
                printf("Vous gagnez une pièce !\n");
                gold++;
                map[pos_x][pos_y] = 0;
                break;
            case 6:
                printf("Vous obtenez un cadenas.\n");
                map[pos_x][pos_y] = 0;
                break;
            case 7:
                printf("Vous tombez dans un piège et perdez 1HP.\n");
                hp--;
                map[pos_x][pos_y] = 0;
                break;
            case 8:
                printf("Vous vous retrouvez face à un monstre, vous perdez 1HP.\n");
                hp--;
                map[pos_x][pos_y] = 0;
                break;
            default:
                break;
        }

        if (gold == 10) {
            game = 0;
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nVous avez réussi bien joué.");
        } else if (hp <= 0) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nVous ne pouvez plus continuer l'aventure.");
            game = 0;
        }
        
    }
    
}

int affiche_carte(int map[20][20], int pos_player[2]) {
    int i, j;
    
    for (i = 0 ; i < 20 ; i ++) {
            for (j = 0 ; j < 20 ; j ++) {
                if (i == pos_x && j == pos_y) {
                    printf ("X ") ;
                } else {
                    printf ("%d ", map [i][j]) ;
                }                     
            }
        printf ("\n") ;
    }
    return 0;
}

int deplace_personnage(int map[20][20], int pos_player[2]) {
    printf("\nDans quelle direction se déplacer ?\n\n\t\t8\n\n\t4\t2\t6\n");
    scanf("%d", &direction);
    
    return direction;
}

void init_carte(int map [20][20]) {
    int i ;
	int j ;
	for (i = 0 ; i < 20 ; i ++) {
		for (j = 0 ; j < 20 ; j ++) {
			map [i][j] = 0 ;
		}
	}
    // Modifications manuelles de la carte

    //Fleurs
    map[4][5] = 1;
    map[1][15] = 1;
    map[12][7] = 1;

    //Arbres
    map[0][16] = 2;
    map[0][17] = 2;
    map[0][18] = 2;
    map[0][19] = 2;
    map[1][16] = 2;
    map[1][17] = 2;
    map[1][18] = 2;
    map[1][19] = 2;
    map[2][16] = 2;
    map[2][17] = 2;
    map[2][18] = 2;
    map[2][19] = 2;
    map[3][17] = 2;
    map[3][18] = 2;
    map[3][19] = 2;

    //Rochers
    map[18][17] = 3;
    map[19][17] = 3;
    map[17][18] = 3;
    map[18][18] = 3;
    map[19][18] = 3;
    map[16][19] = 3;
    map[17][19] = 3;
    map[18][19] = 3;
    map[19][19] = 3;

    //Clef
    map[0][3] = 4;

    //Pièces
    map[10][10] = 5;
    map[14][14] = 5;
    map[19][2] = 5;
    map[4][16] = 5;
    map[8][1] = 5;
    map[1][12] = 5;
    map[1][1] = 5;
    map[16][7] = 5;
    map[18][8] = 5;
    map[17][3] = 5;

    //Cadenas
    map[0][9] = 6;

    //Pièges
    map[7][5] = 7;
    map[6][1] = 7;
    map[7][0] = 7;
    map[19][0] = 7;
    map[19][3] = 7;
    map[19][4] = 7;
    map[19][5] = 7;
    map[19][6] = 7;
    map[19][7] = 7;
    map[19][8] = 7;
    map[19][9] = 7;
    map[19][10] = 7;

    //Monstres
    map[12][4] = 8;
    map[14][3] = 8;
    map[16][5] = 8;
    map[19][1] = 8;
    map[8][5] = 8;
    map[16][16] = 8;
    map[19][16] = 8;
    map[19][15] = 8;

}