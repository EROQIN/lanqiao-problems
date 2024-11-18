/*
问题描述
"在五子棋的对弈中，友谊的小船说翻就翻？" 不！对小蓝和小桥来说，五子棋不仅是棋盘上的较量，更是心与心之间的沟通。这两位挚友秉承着"友谊第一，比赛第二"的宗旨，决定在一块5×5 的棋盘上，用黑白两色的棋子来决出胜负。但他们又都不忍心让对方失落，于是决定用一场和棋（平局）作为彼此友谊的见证。

比赛遵循以下规则：

棋盘规模：比赛在一个 

5×5 的方格棋盘上进行，共有 25 个格子供下棋使用。
棋子类型：两种棋子，黑棋与白棋，代表双方。小蓝持白棋，小桥持黑棋。
先手规则：白棋（小蓝）具有先手优势，即在棋盘空白时率先落子（下棋）。
轮流落子：玩家们交替在棋盘上放置各自的棋子，每次仅放置一枚。
胜利条件：率先在横线、竖线或斜线上形成连续的五个同色棋子的一方获胜。
平局条件：当所有 25 个棋盘格都被下满棋子，而未决出胜负时，游戏以平局告终。
在这一设定下，小蓝和小桥想知道，有多少种不同的棋局情况，既确保棋盘下满又保证比赛结果为平局。

 */
#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
using namespace std;

vector<bool> map2(25);
void print(vector<bool> map){
  for(auto i : map){
      cout << i;
  }
  cout << "  ";
}

bool isValid(vector<bool> map2){
  vector<vector<bool>> map(5,vector<bool>(5));
  int index = 0;
  for(int i = 0;i<5;++i){
    for(int j = 0;j<5;++j){
      map[i][j] = map2[index];
      ++index;
    }
  }
  //横线判断
  for(int i = 0;i<5;++i){
    int res = 0;
    for(auto j : map[i]){
      res += j;
    }
    if(res==0 || res ==5){
        return false;
      }
  }
  //纵线
  for(int i = 0;i<5;++i){
    int res = 0;
    for(int j = 0;j<5;++j){
      res += map[j][i];
    }
    if(res == 0 || res ==5){
      return false;
    }
  }
  //斜线
  int res2 = 0;
  for(int i = 0;i<5;++i){
    res2 +=map[i][i];
  }
  if(res2 == 0 || res2 == 5){
    return false;
  }
  res2 = 0;
  for(int i = 0;i<5;++i){
    res2 += map[i][4-i];
  }
  if(res2 == 0 || res2 == 5){
    return false;
  }
  return true;


}

int res = 0;
int path = 0;
void backtracking(int startx){
  if(path == 13){
    if(isValid(map2)){
      ++res;
    }
    return;
  }
  for(int i = startx ;i < 25;++i){
      ++path;
      map2[i] = true;
      backtracking(i+1);
      map2[i] = false;
      --path;
  }
}



int main()
{
  backtracking(0);
  cout << res;
  return 0;
}