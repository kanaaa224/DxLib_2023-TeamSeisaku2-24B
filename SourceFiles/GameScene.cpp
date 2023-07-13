﻿/********************************
* ゲームメインシーン
* 担当：島袋、
********************************/
#include "main.h"

Game::Game() {
	// 初期化処理
	btn_flg = 0;
	state = 0;

	// 仮
	block[0] = 200;
	block[1] = SCREEN_HEIGHT - 180;
	block[2] = 460;
	block[3] = SCREEN_HEIGHT - 200;
};

Game::~Game() {
	// 終了処理
};

AbstractScene* Game::Update() {

	player.SetState(CheckCollideSquares(block[0], block[1], block[2], block[3], player.GetPosition().x - player.GetSize().width, player.GetPosition().y - player.GetSize().height, player.GetPosition().x + player.GetSize().width, player.GetPosition().y + player.GetSize().height));


	if (!CheckHitKey(KEY_INPUT_0) && !CheckHitKey(KEY_INPUT_1) && !CheckHitKey(KEY_INPUT_2) && !CheckHitKey(KEY_INPUT_3) && !CheckHitKey(KEY_INPUT_4)) {
		btn_flg = 0;
	};
	if (CheckHitKey(KEY_INPUT_0) && btn_flg == 0) {

		state = 0;
		player.SetState(0);

		btn_flg = 1;
	}
	else if (CheckHitKey(KEY_INPUT_1) && btn_flg == 0) {
		
		state = 1;
		player.SetState(1);

		btn_flg = 1;
	}
	else if (CheckHitKey(KEY_INPUT_2) && btn_flg == 0) {

		state = 2;
		player.SetState(2);

		btn_flg = 1;
	}
	else if (CheckHitKey(KEY_INPUT_3) && btn_flg == 0) {

		state = 3;
		player.SetState(3);

		btn_flg = 1;
	}
	else if (CheckHitKey(KEY_INPUT_4) && btn_flg == 0) {

		state = 4;
		player.SetState(4);

		btn_flg = 1;
	};

	player.Update();
	player.Debug();

	if (state > 1) {
		player.SetState(0);
	};

	return this;
};

void Game::Draw() const {
	SetFontSize(16);

	//stage.Draw();

	player.Draw();

	//ui.Draw();

	//DrawFormatString(20, 50, 0xffffff, "ゲームメイン");

	if (state == 0) {
		//DrawFormatString(20, 100, 0xffffff, "ボタンが押されました");
	} else if (state == 1) {
		//DrawFormatString(20,150, 0xffffff, "ボタンが押されました");
	};

	// 仮
	DrawBox(block[0], block[1], block[2], block[3], 0xffffff, FALSE);
};

