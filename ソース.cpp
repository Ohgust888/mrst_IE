#include<iostream>
using namespace std;

int main() {
	//�����ϋv�Ŏg���N�C�b�N�����߂�
	//�U���Ԋu����v����g�ݍ��킹��������AGuts���w�肷��@�\���]�T������Βǉ�����
	double quick[3] = {}; //�N�C�b�N���[���̖��͒l
	double atkDist[3] = {}; //���j�b�g�̒ʏ펞�̍U���Ԋu
	double eqdAtkDist[3] = {}; //�N�C�b�N���[��������̍U���Ԋu
	double error; //���e����U���Ԋu�̌덷
	double e; //�U���Ԋu�̌덷(�v�Z�l)
	double maxD, minD; //3�l�̓��C�U���Ԋu���Œ��̂��̂ƍŒZ�̂���
	int n; //while���̖������[�v�h�~�p
	int longD; //��ԃN�C�b�N���݂̍U���Ԋu���������j�b�g�̔ԍ�
	
	//������
	quick[0] = 5.000;
	quick[1] = 5.000;
	quick[2] = 5.000;
	error = 0.0;
	e = 0.0;
	maxD = 0.0;
	minD = 0.0;
	n = 0;
	longD = 0;

	//�F�X����
	cout << "1�l�ڂ̍U���Ԋu�����\n";
	cin >> atkDist[0];
	cout << "1�l�ڂ̍U���Ԋu�F" << atkDist[0] << "\n";

	cout << "2�l�ڂ̍U���Ԋu�����\n";
	cin >> atkDist[1];
	cout << "2�l�ڂ̍U���Ԋu�F" << atkDist[1] << "\n";

	cout << "3�l�ڂ̍U���Ԋu�����(3�l�ڂ����Ȃ��ꍇ��2�l�ڂƓ����l)\n";
	cin >> atkDist[2];
	cout << "3�l�ڂ̍U���Ԋu�F" << atkDist[2] << "\n";

	cout << "���e����U���Ԋu�̌덷�����\n";
	cin >> error;
	cout << "���e�덷�F" << error << "\n";

	//�v�Z�J�n
	cout << "�v�Z�J�n\n";

	while (n < 100000) {
		//�N�C�b�N���[��������̍U���Ԋu���v�Z
		eqdAtkDist[0] = atkDist[0] * (1 - (quick[0] / 100.0));
		eqdAtkDist[1] = atkDist[1] * (1 - (quick[1] / 100.0));
		eqdAtkDist[2] = atkDist[2] * (1 - (quick[2] / 100.0));

		//�덷�����߂�
		//�U���Ԋu����Ԓ������j�b�g����肷��
		longD = 0; //������
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

		//�U���Ԋu����ԒZ�����j�b�g����肷��
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

		//�U���Ԋu�����e�덷�Ɏ��܂��Ă�����o��
		if (e <= error) {
			cout << "�N�C�b�N1�l�ځF" << quick[0] << ", 2�l�ځF" << quick[1] << ", 3�l�ځF" << quick[2] << ", �덷�F" << e << "\n";
		}

		//�N�C�b�N�̒l�𑝂₷�A�܂���

		//�l�𑝂₷
		quick[longD] = quick[longD] + 0.001;

		//���͒l��35�𒴂�����I��
		if (quick[longD] > 35.000) {
			cout << "�N�C�b�N�̖��͒l��35�𒴂��郆�j�b�g�����ꂽ���߁A�I��\n";
			break;
		}
		n++;
	}

	//
	cout << "��������͂���Enter�ŏI��\n";
	cin >> e;

	return 0;
}