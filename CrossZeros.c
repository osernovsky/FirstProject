#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>

void BoardInit(int size, char board[size][size]){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
        board[i][j]=' ';
        }
    }
}

void BoardPrint(int size, char board[size][size]){
    
    // Печатаем верхнюю часть таблицы
    printf("  ");
    for (int i=1; i<=size; i++) printf("  %d ",i); 
    printf("\n  ┌");
    for (int i=1; i<size; i++) printf("───┬"); 
    printf("───┐\n");

    // Печатаем строки таблицы, кроме последней + разделитель
    for (int i=0; i<(size-1); i++){
        printf("%d │ ",i+1);
        for (int j=0; j<size; j++){
            printf("%c │ ", board[i][j]);
        }
        printf("\n");
    printf("  ├");
    for (int b=1; b<size; b++) printf("───┼"); // разбивка между строками, кроме нижней
    printf("───┤\n");
    }

    // Печатаем нижнюю строку таблицы + нижнюю часть таблицы
    printf("%d │ ",size);
    for (int j=0; j<size; j++){
            printf("%c │ ", board[size-1][j]);
        }
        printf("\n");
    printf("  └");
    for (int i=1; i<size; i++) printf("───┴"); // разбивка
    printf("───┘\n");
}

int CheckWin(int size, char board[size][size], char Player){
    bool win;

    // Проверка строк
    for (int i=0; i<size; i++){
        win = true;
        for (int j=0; j<size; j++){
            if (board[i][j] != Player){
                win = false; // Игрок не выиграл в этой строке
                break;
                }
        }
        if (win) return 1; // Игрок победил
    }

    // Проверка столбцов
    for (int i=0; i<size; i++){
        win = true;
        for (int j=0; j<size; j++){
            if (board[j][i] != Player){
                win = false; // Игрок не выиграл в этой строке
                break;
                }
        }
        if (win) return 1; // Игрок победил
    }

    // Проверка диагонали 1
    win = true;
    for (int i=0; i<size; i++){ 
         if (board[i][i] != Player){
                win = false; // Игрок не выиграл по диагонали
                break;
                }
    }
    if (win) return 1; // Игрок победил

    // Проверка диагонали 2
    win = true;
    for (int i=0; i<size; i++){
         if (board[size-1-i][i] != Player){
                win = false; // Игрок не выиграл по диагонали
                break;
                };
    }
    if (win) return 1; // Игрок победил

    return 0; // Нет победителя
}

int CheckDraw(int size, char board[size][size]){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (board[i][j]==' '){
                return 0; // Еще есть пустые места для игры
                } 
        }
    }
    return 1; // Игра окончена, ничья
}

void main(void){

    int BSIZE = 0;
    int row, col;
    char Player = 'X';
    bool input_error;

    // Ввод размера таблицы для игры
    system("clear");
    while(BSIZE < 3 || BSIZE > 9){
        printf("\nВведите размер игровой доски (от 3 до 9):");
        scanf("%d", &BSIZE);
    }
    
    // Начальная инициализация
    char board[BSIZE][BSIZE];
    BoardInit(BSIZE, board);    

    //Игровой процесс
    
    while (1){

        // Выводим таблицу на чистый экран
        system("clear");
        if (input_error) printf("Неправильный ввод. Попробуйте снова.\n");
        BoardPrint(BSIZE, board);
        input_error=false;
        
        // Выполняем ввод хода
        printf("\nИгрок, который ходит %c, введите столбец вашего хода:", Player);
        scanf("%d", &col);
        printf("Игрок, который ходит %c, введите строку вашего хода:", Player);
        scanf("%d", &row);

        row--;
        col--;

        if (col < 0 || col > BSIZE || row < 0 || row > BSIZE || board[row][col]!=' '){
            input_error=true;
            continue;
        }

        // Делаем ход
        board[row][col] = Player;
        
        // Проверка на выигрыш
        if (CheckWin(BSIZE, board, Player)){
            system("clear");
            BoardPrint(BSIZE, board);
            printf("\n\n Выиграл игрок ставивший %c. Победа!\n", Player);
            break;
        }

        // Проверка на ничью. Хотя можно просто считать количество ходов BSIZE*2
        if (CheckDraw(BSIZE, board)){
            system("clear");
            BoardPrint(BSIZE, board);
            printf("\n\n Ничья!\n");
            break;
        }

        // Передача хода другому игроку
        if (Player=='X') Player = '0'; else Player = 'X';
    }
    
}
