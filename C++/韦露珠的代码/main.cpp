#include "game.h"
#include "gobang.h"


void mnue()
{
    printf("******************\n");
    printf("***  1.player  ***\n");
    printf("***   0.exit   ***\n");
    printf("******************\n");
}

void game()
{
    char ret = 0;
    int a[ROW][COL];
    init_board(a, ROW, COL);//初始化
    print_board(a, ROW, COL);		//打印棋盘

    printf("********************\n");
    printf("本游戏通过坐标来下棋\n");
    printf("********************\n");

    while (1)
    {
        printf("玩家1 请下棋：>");
        ret = play_board(a, ROW, COL, PIECE_ONE);
        if (ret != 'C')
            break;

        system("cls");
        print_board(a, ROW, COL);

        printf("玩家2 请下棋：>");
        ret = play_board(a, ROW, COL, PIECE_TWO);
        if (ret != 'C')
            break;

        system("cls");
        print_board(a, ROW, COL);
    }

    if (ret == PIECE_ONE)
    {
        printf("恭喜玩家1，获胜\n");
    }
    else if (ret == PIECE_TWO)
    {
        printf("恭喜玩家2，获胜\n");
    }
    else
    {
        printf("很遗憾，没有决出胜负\n");
    }

    Sleep(5000);
    system("cls");
}


void init_board(int board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            board[i][j] = ' ';
}

void print_board(int board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;

    //打印列号
    printf("  ");		//为了对齐
    for (i = 1; i <= COL; i++)
        printf(" %x  ", i);

    printf("\n");

    for (j = 0; j < row; j++)
    {
        //打印行号
        printf("%x ", j + 1);
        //打印 * | * | * 
        for (i = 0; i < col; i++)
        {
            printf_s(" %c ", board[j][i]);

            if (i < col - 1)
                printf_s("|");
        }
        printf_s("\n");

        //为了对齐
        printf_s("  ");
        //打印___|___|___ ,最后一行打印   |   |   
        for (i = 0; i < col; i++)
        {
            j == row - 1 ? printf("   ") : printf("___");

            if (i < col - 1)
                printf("|");
        }
        printf_s("\n");
    }
}


static char is_win(int board[ROW][COL], int row, int col, int x, int y, char piece)
{
    int i = 0;
    int j = 0;
    int k = 0;

    //记录当前棋盘的总棋子数
    static int count = 0;
    count++;

    //判断竖线
    for (i = x - 4; i <= x; i++)
    {
        if (i < 0 || i + 4 >= row)
            continue;

        for (j = 0; j < 5; j++)
        {
            if (board[i + j][y] != piece)
                break;
        }

        //判断是否获胜
        if (j == 5)
            return  piece;
    }

    //判断横线
    for (i = y - 4; i <= y; i++)
    {
        if (i < 0 || i + 4 >= col)
            continue;

        for (j = 0; j < 5; j++)
        {
            if (board[x][i + j] != piece)
                break;
        }

        //判断是否获胜
        if (j == 5)
            return  piece;
    }

    //判断正斜线
    for (i = x - 4, j = y - 4; i <= x; i++, j++)
    {
        if (i < 0 || j < 0 || i + 4 >= row || j + 4 >= col)
            continue;

        for (k = 0; k < 5; k++)
        {
            if (board[i + k][j + k] != piece)
                break;
        }

        //判断是否获胜
        if (k == 5)
            return  piece;
    }

    //判断副斜线
    for (i = x + 4, j = y - 4; i <= x; i++)
    {

        if (i >= row || j < 0 || i + 4 < 0 || j + 4 >= col)
            continue;

        for (k = 0; k < 5; k++)
        {
            if (board[i - k][j + k] != piece)
                break;
        }

        //判断是否获胜
        if (k == 5)
            return  piece;
    }

    //判断是否平局
    if (count == row * col)
        return 'Q';

    return 'C';
}

char play_board(int board[ROW][COL], int row, int col, char piece)
{
    int x = 0;
    int y = 0;

    while (1)
    {
        scanf_s("%d %d", &x, &y);
        //坐标合法
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            //坐标是否被占用
            if (board[x - 1][y - 1] != PIECE_ONE && board[x - 1][y - 1] != PIECE_TWO)
            {
                board[x - 1][y - 1] = piece;

                return is_win(board, row, col, x - 1, y - 1, piece);		//判断是否结束游戏
            }
            else
            {
                printf("输入错误，请重新输入：>");
            }
        }
        else
        {
            printf("坐标非法，请重新输入：>");
        }
    }
    int l;
    cin >> l;
}


void BGM()
{
    //文件为.mp3为后缀才可播放，要把音乐拷贝到项目所在文件夹里
    mciSendString(L"open music.mp3", 0, 0, 0);//0，0,0为默认输出控制台
    mciSendString(L"play music.mp3 repeat", 0, 0, 0);
    if (0)
    {
        mciSendString(L"close music.mp3", 0, 0, 0);
    }
}

void Reset()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            gobang[i][j] = 0;
        }
    }
    BoardPrint();
}

void BoardPrint()
{
    initgraph(512 + u, 512 + u, EX_SHOWCONSOLE); // 初始化图形窗口
    setbkcolor(GREEN);
    cleardevice();
    HWND hand = GetHWnd();
    SetWindowText(hand, L"welcome");
    setlinecolor(BLACK);
    for (int i = 0; i < 16; i++)
    {
        line(u, u * (i + 1), u * 16, u * (i + 1));
        line(u * (i + 1), u, u * (i + 1), u * 16);
    }
}

void BlackSet()
{
    setfillcolor(BLACK);
    while (1)
    {
        ExMessage m = getmessage(EX_MOUSE);
        if (m.message == WM_LBUTTONDOWN)
        {

            if (m.x / u > 0 && m.x / u < 16 && m.y / u > 0 && m.y / u < 16 && gobang[m.x / u - 1][m.y / u - 1] == 0)
            {
                gobang[m.x / u - 1][m.y / u - 1] = Black;
                std::cout << "BLACK: " << m.x / u - 1 << " " << m.y / u - 1 << " " << gobang[m.x / u - 1][m.y / u - 1] << std::endl;
                solidcircle((m.x / u) * u + 16, (m.y / u) * u + 16, 16);
                return;
            }
        }
    }
}

void WhiteSet()
{
    setfillcolor(WHITE);
    while (1)
    {
        ExMessage m = getmessage(EX_MOUSE);
        if (m.message == WM_LBUTTONDOWN)
        {
            if (m.x / u > 0 && m.x / u < 16 && m.y / u > 0 && m.y / u < 16 && gobang[m.x / u - 1][m.y / u - 1] == 0)
            {
                gobang[m.x / u - 1][m.y / u - 1] = White;
                std::cout << "WHITE " << m.x / u - 1 << " " << m.y / u - 1 << " " << gobang[m.x / u - 1][m.y / u - 1] << std::endl;
                solidcircle((m.x / u) * u + 16, (m.y / u) * u + 16, 16);
                return;
            }

        }
    }
}

int Gobang_Exe(int color)
{
    int count, i, j;

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (gobang[i][j] == color) {

                // 检查行
                if (j <= 10)
                {
                    count = 1;
                    for (int k = 1; k < 5; k++)
                    {
                        if (gobang[i][j + k] == color)
                        {
                            count++;
                        }
                        else break;
                    }
                    if (count == 5) return color;
                }

                // 检查列
                if (i <= 10)
                {
                    count = 1;
                    for (int k = 1; k < 5; k++)
                    {
                        if (gobang[i + k][j] == color)
                        {
                            count++;
                        }
                        else break;
                    }
                    if (count == 5) return color;
                }

                // 检查正斜线
                if (i <= 10 && j <= 10)
                {
                    count = 1;
                    for (int k = 1; k < 5; k++)
                    {
                        if (gobang[i + k][j + k] == color)
                        {
                            count++;
                        }
                        else break;
                    }
                    if (count == 5) return color;
                }

                // 检查反斜线
                if (i >= 4 && j <= 10)
                {
                    count = 1;
                    for (int k = 1; k < 5; k++)
                    {
                        if (gobang[i - k][j + k] == color)
                        {
                            count++;
                        }
                        else break;
                    }
                    if (count == 5) return color;
                }
            }
        }
    }
    // 如果没有五子连珠，则返回0
    return 0;
}

int Judgement()
{
    int b = 0, i = 0, j = 0;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (gobang[i][j] != 0)
            {
                b++;
            }
        }
    }
    if (b == 225)
    {
        printf("stalemate!\n");
        return 3;
    }
}

int EXE()
{
    int temporary = 0;
    do {
        BlackSet();
        temporary = Gobang_Exe(Black);
        if (temporary == 1 || temporary == 2) { break; }
        temporary = Judgement();
        if (temporary == 3) { return 3; }

        WhiteSet();
        temporary = Gobang_Exe(White);
        if (temporary == 1 || temporary == 2) { break; }
        temporary = Judgement();
        if (temporary == 3) { return 3; }
    } while (temporary != 1 && temporary != 2 && temporary != 3);

    if (temporary == 1)
    {
        printf("black win!\n");
        return 1;
    }
    if (temporary == 2)
    {
        printf("white win!\n");
        return 2;
    }
    return 0;
}

int main()
{
    BoardPrint();
    BGM();
    bool tem = false;
    do
    {
        int log = EXE();
        HWND hand = GetHWnd();
        int i = 0;
        if (log == 1)
            i = MessageBox(hand, L"Black win!Do you wanna play it agin?", L"message", MB_YESNO);
        else if (log == 2)
            i = MessageBox(hand, L"White win!Do you wanna play it agin?", L"message", MB_YESNO);
        else if (log == 3)
            i = MessageBox(hand, L"stalemate!White win!Do you wanna play it agin?", L"message", MB_YESNO);
        if (IDYES == i)
        {
            tem = true;
            std::cout << "Play again!" << std::endl;
            Reset();
        }
        else if (IDNO == i)
        {
            std::cout << "Exit!" << std::endl;
            HWND hand1 = GetHWnd();
            int i = MessageBox(hand1, L"Exiting~", L"message", MB_OK);
            return 0;
        }
    } while (tem);

    _getch();
    closegraph();
    int input = 0;
    do
    {
        //菜单
        mnue();
        printf_s("请输入：>");
        scanf_s("%d", &input);
        system("cls");

        //用户选择
        switch (input)
        {
        case 1:
            printf("欢迎来到五子棋，游戏开始\n");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    } while (input);
    return 0;
}