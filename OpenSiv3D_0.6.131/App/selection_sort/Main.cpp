# include <Siv3D.hpp>
using namespace std;

bool Button(const Rect& rect, const Font& font, const String& text, bool enabled)
{
	if (enabled && rect.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (enabled)
	{
		rect.draw(ColorF{ 0.3, 0.7, 1.0 });
		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2));
	}
	else
	{
		rect.draw(ColorF{ 0.5 });
		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2), ColorF{ 0.7 });
	}

	return (enabled && rect.leftClicked());
}

void print_array(int v[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		Logger << v[i] << U" ";
	}
}

// 選択ソート
vector<vector<int>> selection_sort(vector<int> v, int n) {
	int i, j, t, min_index;
	vector<vector<int>> array;
	for (i = 0; i < n - 1; i++) {
		min_index = i;
		for (j = i + 1; j < n; j++) {
			if (v[j] < v[min_index]) {
				min_index = j;
			}
		}
		t = v[i];
		v[i] = v[min_index];
		v[min_index] = t;
		if (v[i] != v[min_index]) {
			array.push_back({ max(i,min_index), min(i,min_index) });
		}
	}
	return array;
}

void Main()
{
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	//const Font font{ 20, Typeface::Bold };
	//const String text = U"The quick brown fox jumps over the lazy dog.";

	//constexpr Rect rect1{ 50, 20, 200, 100 };
	//constexpr Rect rect2{ 50, 160, 300, 100 };
	//constexpr Rect rect3{ 50, 300, 400, 100 };
	//constexpr Circle cir1{ 100, 100, 20 };

	const Font font{ 50 };
	int text = 1;

	constexpr Vec2 pos{ 20, 20 };

	// RectF rect = font(text).region(pos);

	double tt = 0;
	double t = 0;

	vector<int> A = { 1,3,5,7,9,11,13,15 };
	int sec = 0;
	int before_sec = 0;
	//int interva
	RectF rect;
	bool process = false;
	bool move = true;

	/*int array[10] = { 80,40,30,20,10,00,70,90,50,60 };
	print_array(array, 10);
	quicksort_stack(array, 10);*/

	vector<int> array = { 300,100,200,500,400 };
	//print_array(array, 5);
	vector<vector<int>> selection = selection_sort(array, 5);
	int step = 0;
	//print_array(array, 5);

	double x1 = selection[0][0] * 100 + 100;
	double x2 = selection[0][1] * 100 + 100;

	double speed = 0.5;

	while (System::Update())
	{
		if (Button(Rect{ 250, 400, 300, 80 }, font, U"スタート", true))
		{
			process = true;
		}
		t = Scene::Time();
		sec = t;

		before_sec = t;
		int n = array.size();

		int x;
		double min = 0;
		double max = 0;

		if (step < selection.size()) {
			max = selection[step][0] * 100 + 100;
			min = selection[step][1] * 100 + 100;
		}
		else {

		}

		if (move && step < selection.size()) {
			for (int i = 0; i < n; i++) {
				text = array[i];
				ColorF color;
				color = ColorF{ 0.25 };

				if (selection[step][0] == i) {
					if (min < x1) {
						x1 -= speed;
					}

					x = x1;
				}
				else if (selection[step][1] == i) {
					if (x2 < max) {
						x2 += speed;
					}
					x = x2;
				}
				else {
					x = 100 * (i + 1);
				}
				rect = font(100).region(x, 20);
				rect.draw();
				font(text).draw(x, 20, color);
			}
			if (x1 <= min && max <= x2) {
				int t;
				t = array[selection[step][0]];
				array[selection[step][0]] = array[selection[step][1]];
				array[selection[step][1]] = t;

				if (step < selection.size()) {
					step++;
				}
				if (step < selection.size()) {
					x1 = selection[step][0] * 100 + 100;
					x2 = selection[step][1] * 100 + 100;
				}
				else {
					move = false;
				}
			}

		}
		else {
			for (int i = 0; i < n; i++) {
				text = array[i];
				rect = font(100).region(100 * (i + 1), 20);
				rect.draw();
				ColorF color;
				color = ColorF{ 0.25 };
				font(text).draw(100 * (i + 1), 20, color);
			}
		}

		font(U"二分探索の動き").draw(200, 200, ColorF{ 0.1 });
		font(U"探索対象は5").draw(200, 250, ColorF{ 0.1 });
		font(U"赤い文字が現在の探索位置").draw(200, 300, ColorF{ 0.1 });
	}
}

//# include <Siv3D.hpp>
//using namespace std;
//
//bool Button(const Rect& rect, const Font& font, const String& text, bool enabled)
//{
//	if (enabled && rect.mouseOver())
//	{
//		Cursor::RequestStyle(CursorStyle::Hand);
//	}
//
//	if (enabled)
//	{
//		rect.draw(ColorF{ 0.3, 0.7, 1.0 });
//		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2));
//	}
//	else
//	{
//		rect.draw(ColorF{ 0.5 });
//		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2), ColorF{ 0.7 });
//	}
//
//	return (enabled && rect.leftClicked());
//}
//
//void print_array(int v[], int n) {
//	int i;
//	for (i = 0; i < n; i++) {
//		Logger << v[i] << U" ";
//	}
//}
//
//// クイックソート
//int partition(int v[], int lower_bound, int upper_bound) {
//	int a, down, up, temp;
//
//	a = v[lower_bound];
//	up = upper_bound;
//	down = lower_bound;
//
//	while (down < up) {
//		while ((v[down] <= a) && (down < upper_bound)) {
//			down++;
//		}
//		while (v[up] > a) {
//			up--;
//		}
//		if (down < up) {
//			temp = v[down];
//			v[down] = v[up];
//			v[up] = temp;
//		}
//	}
//	v[lower_bound] = v[up];
//	v[up] = a;
//
//	return up;
//}
//
//#define STACK_SIZE 2048
//
//void quicksort_stack(int v[], int n) {
//	int left, right, i, sptr;
//	int stack_lower_bound[STACK_SIZE];
//	int stack_upper_bound[STACK_SIZE];
//
//	stack_lower_bound[0] = 0;
//	stack_upper_bound[0] = n - 1;
//	sptr = 1;
//
//	while (sptr > 0) {
//		sptr--;
//		left = stack_lower_bound[sptr];
//		right = stack_upper_bound[sptr];
//
//		if (left >= right) {
//			;
//		}
//		else {
//			i = partition(v, left, right);
//
//			if ((i - left) < (right - i)) {
//				stack_lower_bound[sptr] = i + 1;
//				stack_upper_bound[sptr++] = right;
//				stack_lower_bound[sptr] = left;
//				stack_upper_bound[sptr++] = i - 1;
//			}
//			else {
//				stack_lower_bound[sptr] = left;
//				stack_upper_bound[sptr++] = i - 1;
//				stack_lower_bound[sptr] = i + 1;
//				stack_upper_bound[sptr++] = right;
//			}
//		}
//	}
//	print_array(v, 10);
//}
//
//
//
//void Main()
//{
//	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });
//
//	//const Font font{ 20, Typeface::Bold };
//	//const String text = U"The quick brown fox jumps over the lazy dog.";
//
//	//constexpr Rect rect1{ 50, 20, 200, 100 };
//	//constexpr Rect rect2{ 50, 160, 300, 100 };
//	//constexpr Rect rect3{ 50, 300, 400, 100 };
//	//constexpr Circle cir1{ 100, 100, 20 };
//
//	const Font font{ 50 };
//	int text = 1;
//
//	constexpr Vec2 pos{ 20, 20 };
//
//	// RectF rect = font(text).region(pos);
//
//	double tt = 0;
//	double t = 0;
//
//	vector<int> A = { 1,3,5,7,9,11,13,15 };
//	int ok = A.size();
//	int ng = -1;
//	int mid = 1e9;
//	int target = 5;
//	int sec = 0;
//	int before_sec = 0;
//	//int interva
//	RectF rect;
//	bool process = false;
//
//	int array[10] = { 80,40,30,20,10,00,70,90,50,60 };
//	print_array(array, 10);
//	quicksort_stack(array, 10);
//
//
//	while (System::Update())
//	{
//		if (Button(Rect{ 250, 400, 300, 80 }, font, U"スタート", true))
//		{
//			process = true;
//		}
//		// 二分探索
//		t = Scene::Time();
//		sec = t;
//
//		//Print(t);
//		if (process && before_sec < sec && abs(ok - ng) > 1) {
//			mid = (ok + ng) / 2;
//			if (A[mid] >= target) {
//				ok = mid;
//			}
//			else {
//				ng = mid;
//			}
//		}
//		before_sec = t;
//
//		for (int i = 0; i < A.size(); i++) {
//			//RectF rect = font(text).region(tt, 20);
//			//// 描画領域の長方形を事前に塗りつぶす
//			//rect.draw(Palette::Skyblue);
//
//			//// 長方形の上にテキストを描く
//			//font(text).draw(tt, 20, ColorF{ 0.25 });
//			text = A[i];
//			rect = font(10).region(100 * (i + 1), 20);
//			rect.draw();
//			ColorF color;
//			if (mid == i) {
//				color = ColorF{ 1.0,0,0 };
//			}
//			else {
//				color = ColorF{ 0.25 };
//			}
//
//			font(text).draw(100 * (i + 1), 20, color);
//		}
//		font(U"二分探索の動き").draw(200, 200, ColorF{ 0.1 });
//		font(U"探索対象は5").draw(200, 250, ColorF{ 0.1 });
//		font(U"赤い文字が現在の探索位置").draw(200, 300, ColorF{ 0.1 });
//	}
//}
