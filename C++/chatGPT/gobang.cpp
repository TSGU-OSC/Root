#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROW = 15;
const int COL = 15;
int board[ROW][COL] = {0};

void print_board()
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(board[i][j] == 1)
                cout << "O ";
            else if(board[i][j] == 2)
                cout << "X ";
            else
                cout << "+ ";
        }
        cout << endl;
    }
}

bool is_valid_pos(int row, int col)
{
    if(row<0 || row>=ROW || col<0 || col>=COL)
        return false;
    if(board[row][col] != 0)
        return false;
    return true;
}

bool has_five_in_line(int row, int col)
{
    int i, j, cnt;
    // check horizontal line
    cnt = 1;
    i = row;
    j = col-1;
    while(j>=0 && board[i][j]==board[row][col])
    {
        cnt++;
        j--;
    }
    j = col + 1;
    while(j<COL && board[i][j]==board[row][col])
    {
        cnt++;
        j++;
    }
    if(cnt >= 5)
        return true;
    // check vertical line
    cnt = 1;
    i = row - 1;
    j = col;
    while(i>=0 && board[i][j]==board[row][col])
    {
        cnt++;
        i--;
    }
    i = row + 1;
    while(i<ROW && board[i][j]==board[row][col])
    {
        cnt++;
        i++;
    }
    if(cnt >= 5)
        return true;
    // check diagonal line
    cnt = 1;
    i = row - 1;
    j = col - 1;
    while(i>=0 && j>=0 && board[i][j]==board[row][col])
    {
        cnt++;
        i--;
        j--;
    }
    i = row + 1;
    j = col + 1;
    while(i<ROW && j<COL && board[i][j]==board[row][col])
    {
        cnt++;
        i++;
        j++;
    }
    if(cnt >= 5)
        return true;
    // check anti-diagonal line
    cnt = 1;
    i = row - 1;
    j = col + 1;
    while(i>=0 && j<COL && board[i][j]==board[row][col])
    {
        cnt++;
        i--;
        j++;
    }
    i = row + 1;
    j = col - 1;
    while(i<ROW && j>=0 && board[i][j]==board[row][col])
    {
        cnt++;
        i++;
        j--;
    }
    if(cnt >= 5)
        return true;

    return false;
}

void human_move()
{
    int row, col;
    while(true)
    {
        cout << "Your turn (O): ";
        cin >> row >> col;
        if(!is_valid_pos(row, col))
        {
            cout << "Invalid position, please try again!" << endl;
            continue;
        }
        board[row][col] = 1;
        if(has_five_in_line(row, col))
        {
            print_board();
            cout << "Congratulations! You win!" << endl;
            exit(0);
        }
        break;
    }
}

void computer_move()
{
    while(true)
    {
        int row = rand() % ROW;
        int col = rand() % COL;
        if(is_valid_pos(row, col))
        {
            board[row][col] = 2;
            cout << "Computer moves: (" << row << ", " << col << ")" << endl;
            if(has_five_in_line(row, col))
            {
                print_board();
                cout << "Computer wins!" << endl;
                exit(0);
            }
            break;
        }
    }
}

int main()
{
    srand(time(NULL));
    bool is_human_turn = true;
    while(true)
    {
        print_board();
        if(is_human_turn)
            human_move();
        else
            computer_move();
        is_human_turn = !is_human_turn;
    }

    return 0;
}
