﻿#pragma once

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define GAME_NAME "バルーンファイト"

#include <stdio.h>
#include <math.h>
#include <string>
using std::string;
using std::to_string;
#include <time.h>
#include "SceneManager.h"

//#include "PadInput.h"

#include "DxLib.h"

// ゲーム処理のヘッダーファイル
#include "GamePlayer.h"
#include "GameStage.h"

// 各シーンのヘッダーファイル
//#include "Title.h"
#include "GameScene.h"
//#include "Result.h"
//#include "Help.h"
//#include "Ranking.h"
//#include "DrawRanking.h"
//#include "InputRanking.h"
//#include "Credit.h"


// リソース管理
#define IMG 0
#define SND 1

#define BGM 0
#define SE 1

#define TITLE 0
#define MAIN 1

class Resources {
private:
    static int snd_bgm[];
    static int snd_se[];
public:
    static int Get(int media, int type, int getNum) {
        if (media == 1) {
            if (type == 0) {
                return snd_bgm[getNum];
            }
            else if (type == 1) {
                return snd_se[getNum];
            };
        }
    };
    static void Set(int media, int type, int getNum, int data) {
        if (media == 1) {
            if (type == 0) {
                snd_bgm[getNum] = data;
            }
            else if (type == 1) {
                snd_se[getNum] = data;
            };
        }
    };
};