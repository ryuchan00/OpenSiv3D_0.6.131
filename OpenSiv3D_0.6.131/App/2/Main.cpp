﻿# include <Siv3D.hpp> // Siv3D v0.6.13


void Main()
{

	// 画像ファイルから画像データを読み込んでテクスチャを作成する
	const Texture texture{ U"example/windmill.png" };


	while (System::Update())
	{
		// テクスチャを描画する
		texture.draw();

		// 1 秒間に何回メインループが実行されているかを取得する
		int32 fps = Profiler::FPS();

		// 1 秒間に何回メインループが実行されているかを、ウィンドウタイトルに表示する
		Window::SetTitle(fps);



	}
}


//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
