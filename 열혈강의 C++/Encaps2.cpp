#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SinivelCap	// Äà¹° Ã³Ä¡¿ë Ä¸½¶
{
public:
	void take() const { cout << "Äà¹°ÀÌ ½Ï ³³´Ï´Ù." << endl; }
};

class SneezeCap		// ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶	
{
public:
	void take() const { cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << endl; }
};

class SnuffleCap	// ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶
{
public:
	void take() const { cout << "ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù." << endl; }
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