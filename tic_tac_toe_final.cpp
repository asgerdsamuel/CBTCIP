#include <iostream>
using namespace std;

char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

char player = 'X';


void drawgame() {
    cout << "   0   1   2  " << endl;
    cout << "0  " << game[0][0] << " | " << game[0][1] << " | " << game[0][2] << "  " << endl;
    cout << "  ---|---|---" << endl;
    cout << "1  " << game[1][0] << " | " << game[1][1] << " | " << game[1][2] << "  " << endl;
    cout << "  ---|---|---" << endl;
    cout << "2  " << game[2][0] << " | " << game[2][1] << " | " << game[2][2] << "  " << endl;
}


bool check() {
    for (int i = 0; i < 3; i++) {
        if (game[i][0] == player && game[i][1] == player && game[i][2] == player) {
            return true;
        }
        if (game[0][i] == player && game[1][i] == player && game[2][i] == player) {
            return true;
        }
    }
    if (game[0][0] == player && game[1][1] == player && game[2][2] == player) {
        return true;
    }
    if (game[0][2] == player && game[1][1] == player && game[2][0] == player) {
        return true;
    }
    return false;
}


bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


bool makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || game[row][col] != ' ') {
        return false;
    }
    game[row][col] = player;
    return true;
}

int main() {
    int row, col;

    cout << " TIC TAC TOE game using C++ " << endl;
    drawgame();

    while (true) {
        cout << "Player " << player << ", enter the  row and column (e.g., 0 1): ";
        cin >> row >> col;

        if (makeMove(row, col)) {
            if (check()) {
                drawgame();
                cout << "The winner is player : " << player << endl;
                break;
            } else if (isDraw()) {
                drawgame();
                cout << "No one wins , it is a draw!" << endl;
                break;
            } else {

                player = (player == 'X') ? 'O' : 'X';
                drawgame();
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
