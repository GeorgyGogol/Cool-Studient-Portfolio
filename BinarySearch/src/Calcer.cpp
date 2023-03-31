//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Calcer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

Calcer::Calcer()
{
    init();
}

Calcer::Calcer(int min, int max)
{
	init();
	Min_ = min;
    Max_ = max;
}

void Calcer::init()
{
    Steps_ = 0;
    Min_ = 0, Max_ = 100;
    CurrentNumber_ = 0, Delta_ = 0;
    isRun_ = false;
}

void Calcer::setMin(int val)
{
    if (val < Max_) Min_ = val;
    else throw Exception("Нельзя установить значение больше максимального");
}

int Calcer::getMin() const {
    return Min_;
}

String Calcer::getMinStr() const {
    return IntToStr(getMin());
}

void Calcer::setMax(int val)
{
    if (val > Min_) Max_ = val;
    else throw Exception("Нельзя установить значение меньше минимального");
}

int Calcer::getMax() const {
    return Max_;
}

String Calcer::getMaxStr() const {
    return IntToStr(getMax());
}

void Calcer::Start() {
    isRun_ = true;
	Delta_ = 1.0 * (Max_ - Min_) / 2.0;
	CurrentNumber_ = Min_ + Delta_;
	Steps_ = 1;
}

void Calcer::Stop() {
    isRun_ = false;
}

void Calcer::Reset()
{
    isRun_ = false;
    Delta_ = 0;
    CurrentNumber_ = 0;
    Steps_ = 0;
}

void Calcer::Calc(double toNumber, double accuracy)
{
    Start();

    while (std::fabs(toNumber - CurrentNumber_) > accuracy)
    {
        if (CurrentNumber_ > toNumber)
            Less();
        else
            More();
    }
    
    Stop();
}

double Calcer::getCurrentNumber() const {
    return CurrentNumber_;
}

void Calcer::More()
{
    Delta_ /= 2;
    CurrentNumber_ += Delta_;
    ++Steps_;
	LastOper_ = 1;
}

void Calcer::Less()
{
    Delta_ /= 2;
    CurrentNumber_ -= Delta_;
    ++Steps_;
	LastOper_ = -1;
}

void Calcer::Redo()
{
    CurrentNumber_ += -LastOper_ * Delta_;
    Delta_ *= 2;
    ++Steps_;
}

int Calcer::getSteps() const {
    return int(Steps_);
}

String Calcer::getStepsStr() const
{
    return IntToStr(getSteps());
}

