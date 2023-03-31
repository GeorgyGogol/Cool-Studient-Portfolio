//---------------------------------------------------------------------------

#ifndef CalcerH
#define CalcerH

#include <Classes.hpp>
//---------------------------------------------------------------------------
class Calcer
{
public:
    Calcer();
	Calcer(int min, int max);

private:
    unsigned int Steps_;
    int Min_, Max_;
    double CurrentNumber_, Delta_;
    short int LastOper_;
    bool isRun_;

    void init();

public:
    void setMin(int val);
    int getMin() const;
	String getMinStr() const;
	__property int Min = { read = Min_, write = setMin };

	void setMax(int val);
	int getMax() const;
	String getMaxStr() const;
	__property int Max = { read = Max_, write = setMax};

	void Start();
	void Stop();
    void Reset();
	__property bool IsRunning = { read = isRun_ };
    void Calc(double toNumber, double accuracy);

	double getCurrentNumber() const;
    void More();
    void Less();
	void Redo();

	int getSteps() const;
	String getStepsStr() const;
    __property int StepCount = { read = getSteps };

};
//---------------------------------------------------------------------------
#endif
