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

class CONTAC600
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void take() const
	{
		sin.take();
		sne.take();
		snu.take();
	}
};

class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600& cap) const { cap.take(); }
};

int main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}