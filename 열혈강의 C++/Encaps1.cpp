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