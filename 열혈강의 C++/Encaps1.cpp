#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SinivelCap	// �๰ óġ�� ĸ��
{
public:
	void take() const { cout << "�๰�� �� ���ϴ�." << endl; }
};

class SneezeCap		// ��ä�� óġ�� ĸ��	
{
public:
	void take() const { cout << "��ä�Ⱑ �ܽ��ϴ�." << endl; }
};

class SnuffleCap	// �ڸ��� óġ�� ĸ��
{
public:
	void take() const { cout << "�ڰ� �� �ո��ϴ�." << endl; }
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap& cap) const { cap.take(); }
	void TakeSneezeCap(const SneezeCap& cap) const { cap.take(); }
	void TakeSnuffleCap(const SnuffleCap& cap) const { cap.take(); }
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}