#define _CRT_SECURE_NO_WARNINGS 1	//在VS编译器用 scanf 等函数
//需要定义该符号

//需要的包含的头文件
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")//处理接口
using namespace std;

//需要更改棋盘的大小或棋子的符号，改这里就可以了
#define ROW 12					//棋盘的行数
#define COL 15					//棋盘的列数
#define PIECE_ONE '*'			//玩家1 的棋子
#define PIECE_TWO '#'			//玩家2 的棋子

//初始化
void init_board(int board[ROW][COL], int row, int col);

//打印棋盘
void print_board(int board[ROW][COL], int row, int col);

//玩家下棋,并判断游戏是否结束，用返回值带回判断的结果
//第四个参数通过传递玩家的棋子，用来代表不同的玩家
char play_board(int board[ROW][COL],
	int row, int col,
	char piece);
    #define u (int)32
#define Black 1
#define White 2

void BGM();

void BoardPrint();

void BlackSet();

void WhiteSet();

int Judgement();

int EXE();

void Reset();

int Gobang_Exe(int color);

int gobang[15][15] = { 0 };