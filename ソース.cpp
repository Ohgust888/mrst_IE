#include<iostream>
using namespace std;

int main() {
	//無限耐久で使うクイックを求める
	//攻撃間隔が一致する組み合わせを見つける、Gutsも指定する機能も余裕があれば追加する
	double quick[3] = {}; //クイックルーンの魔力値
	double atkDist[3] = {}; //ユニットの通常時の攻撃間隔
	double eqdAtkDist[3] = {}; //クイックルーン装備後の攻撃間隔
	double error; //許容する攻撃間隔の誤差
	double e; //攻撃間隔の誤差(計算値)
	double maxD, minD; //3人の内，攻撃間隔が最長のものと最短のもの
	int n; //while文の無限ループ防止用
	int longD; //一番クイック込みの攻撃間隔が長いユニットの番号
	
	//初期化
	quick[0] = 5.000;
	quick[1] = 5.000;
	quick[2] = 5.000;
	error = 0.0;
	e = 0.0;
	maxD = 0.0;
	minD = 0.0;
	n = 0;
	longD = 0;

	//色々入力
	cout << "1人目の攻撃間隔を入力\n";
	cin >> atkDist[0];
	cout << "1人目の攻撃間隔：" << atkDist[0] << "\n";

	cout << "2人目の攻撃間隔を入力\n";
	cin >> atkDist[1];
	cout << "2人目の攻撃間隔：" << atkDist[1] << "\n";

	cout << "3人目の攻撃間隔を入力(3人目がいない場合は2人目と同じ値)\n";
	cin >> atkDist[2];
	cout << "3人目の攻撃間隔：" << atkDist[2] << "\n";

	cout << "許容する攻撃間隔の誤差を入力\n";
	cin >> error;
	cout << "許容誤差：" << error << "\n";

	//計算開始
	cout << "計算開始\n";

	while (n < 100000) {
		//クイックルーン装備後の攻撃間隔を計算
		eqdAtkDist[0] = atkDist[0] * (1 - (quick[0] / 100.0));
		eqdAtkDist[1] = atkDist[1] * (1 - (quick[1] / 100.0));
		eqdAtkDist[2] = atkDist[2] * (1 - (quick[2] / 100.0));

		//誤差を求める
		//攻撃間隔が一番長いユニットを特定する
		longD = 0; //初期化
		if (eqdAtkDist[0] < eqdAtkDist[1]) {
			if (eqdAtkDist[1] < eqdAtkDist[2]) {
				longD = 2;
			}
			else {
				longD = 1;
			}
		}
		else if (eqdAtkDist[0] < eqdAtkDist[2]) {
			longD = 2;
		}

		maxD = eqdAtkDist[longD];

		//攻撃間隔が一番短いユニットを特定する
		minD = eqdAtkDist[0];
		if (eqdAtkDist[0] > eqdAtkDist[1]) {
			if (eqdAtkDist[1] > eqdAtkDist[2]) {
				minD = eqdAtkDist[2];
			}
			else {
				minD = eqdAtkDist[1];
			}
		}
		else if (eqdAtkDist[0] > eqdAtkDist[2]) {
			minD = eqdAtkDist[2];
		}

		e = maxD - minD;

		//攻撃間隔が許容誤差に収まっていたら出力
		if (e <= error) {
			cout << "クイック1人目：" << quick[0] << ", 2人目：" << quick[1] << ", 3人目：" << quick[2] << ", 誤差：" << e << "\n";
		}

		//クイックの値を増やす、まずは

		//値を増やす
		quick[longD] = quick[longD] + 0.001;

		//魔力値が35を超えたら終了
		if (quick[longD] > 35.000) {
			cout << "クイックの魔力値が35を超えるユニットが現れたため、終了\n";
			break;
		}
		n++;
	}

	//
	cout << "何かを入力してEnterで終了\n";
	cin >> e;

	return 0;
}