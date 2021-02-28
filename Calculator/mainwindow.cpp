#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <cmath>

double calcVal = 0.0;
double pi = 3.14159;

bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;
bool squareTrigger = false;
bool squareRootTrigger = false;
bool cubeTrigger = false;
bool factorialTrigger = false;
bool sinTrigger = false;
bool cosTrigger = false;
bool tanTrigger = false;
bool piTrigger = false;
bool expTrigger = false;
bool percTrigger = false;
bool logTrigger = false;
bool ceilTrigger = false;
bool sin1Trigger = false;
bool cos1Trigger = false;
bool tan1Trigger = false;
bool compTrigger = false;
bool cubeRootTrigger = false;
bool modTrigger = false;
bool degTrigger = false;
bool radTrigger = false;
bool clearTrigger = false;


int MainWindow::fact(int n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

int MainWindow::prevComplement(int n, int b)
{
    int maxDigit, maxNum = 0, digits = 0, num = n;

    while(n!=0)
    {
        digits++;
        n = n/10;
    }

    maxDigit = b-1;

    while(digits--)
    {
        maxNum = maxNum*10 + maxDigit;
    }

    return maxNum - num;
}

int MainWindow::complement(int n, int b)
{
    return prevComplement(n,b) + 1;
}

bool MainWindow::dblNotZero(int n){
        return n != 0.0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));

    QPushButton *numButtons[10];

    for(int i = 0; i < 10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->Clear, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Equals, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));
    connect(ui->ChangeSign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));
    connect(ui->ArcCos, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ArcSin, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ArcTan, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Ceil, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ComplementOfBase, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Cos, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->CubeRoot, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Cubed, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Deg, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Exp, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Factorial, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Log, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Mod, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Perc, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Pi, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Rad, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Sin, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->SquareRoot, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Squared, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Tan, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();

    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)) {
        ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void MainWindow::MathButtonPressed(){

    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    squareTrigger = false;
    squareRootTrigger = false;
    cubeTrigger = false;
    factorialTrigger = false;
    sinTrigger = false;
    cosTrigger = false;
    tanTrigger = false;
    piTrigger = false;
    expTrigger = false;
    percTrigger = false;
    logTrigger = false;
    ceilTrigger = false;
    sin1Trigger = false;
    cos1Trigger = false;
    tan1Trigger = false;
    compTrigger = false;
    cubeRootTrigger = false;
    modTrigger = false;
    degTrigger = false;
    radTrigger = false;
    clearTrigger = false;

    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();

    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();

    if(QString::compare(butVal, "÷", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    } else if(QString::compare(butVal, "x", Qt::CaseInsensitive) == 0){
        multTrigger = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    } else if(QString::compare(butVal, "√", Qt::CaseInsensitive) == 0){
        squareRootTrigger = true;
    } else if(QString::compare(butVal, "X²", Qt::CaseInsensitive) == 0){
        squareTrigger = true;
    } else if(QString::compare(butVal, "x³", Qt::CaseInsensitive) == 0){
        cubeTrigger = true;
    } else if(QString::compare(butVal, "!", Qt::CaseInsensitive) == 0){
        factorialTrigger = true;
    } else if(QString::compare(butVal, "sin", Qt::CaseInsensitive) == 0){
        sinTrigger = true;
    } else if(QString::compare(butVal, "cos", Qt::CaseInsensitive) == 0){
        cosTrigger = true;
    } else if(QString::compare(butVal, "tan", Qt::CaseInsensitive) == 0){
        tanTrigger = true;
    } else if(QString::compare(butVal, "π", Qt::CaseInsensitive) == 0){
        piTrigger = true;
    } else if(QString::compare(butVal, "e", Qt::CaseInsensitive) == 0){
        expTrigger = true;
    } else if(QString::compare(butVal, "%", Qt::CaseInsensitive) == 0){
        percTrigger = true;
    } else if(QString::compare(butVal, "log", Qt::CaseInsensitive) == 0){
        logTrigger = true;
    } else if(QString::compare(butVal, "⌈x⌉", Qt::CaseInsensitive) == 0){
        ceilTrigger = true;
    } else if(QString::compare(butVal, "sin-1", Qt::CaseInsensitive) == 0){
        sin1Trigger = true;
    } else if(QString::compare(butVal, "cos-1", Qt::CaseInsensitive) == 0){
        cos1Trigger = true;
    } else if(QString::compare(butVal, "tan-1", Qt::CaseInsensitive) == 0){
        tan1Trigger = true;
    } else if(QString::compare(butVal, "compl", Qt::CaseInsensitive) == 0){
        compTrigger = true;
    } else if(QString::compare(butVal, "3√a", Qt::CaseInsensitive) == 0){
        cubeRootTrigger = true;
    } else if(QString::compare(butVal, "mod", Qt::CaseInsensitive) == 0){
        modTrigger = true;
    } else if(QString::compare(butVal, "deg", Qt::CaseInsensitive) == 0){
        degTrigger = true;
    } else if(QString::compare(butVal, "rad", Qt::CaseInsensitive) == 0){
        radTrigger = true;
    } else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        subTrigger = true;
    } else if(QString::compare(butVal, "AC", Qt::CaseInsensitive) == 0){
        clearTrigger = true;
    }

    ui->Display->setText("");

}

void MainWindow::EqualButtonPressed(){
    double solution = 0.0;

    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    if(addTrigger || subTrigger || multTrigger || divTrigger || squareTrigger || cubeTrigger
            || factorialTrigger || sinTrigger || cosTrigger || tanTrigger || piTrigger
            || expTrigger || percTrigger || logTrigger || ceilTrigger || sin1Trigger
            || cos1Trigger || tan1Trigger || compTrigger || cubeRootTrigger || modTrigger
            || degTrigger || radTrigger || clearTrigger || squareTrigger || squareRootTrigger){
        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        } else if(subTrigger){
            solution = calcVal - dblDisplayVal;
        } else if(multTrigger){
            solution = calcVal * dblDisplayVal;
        } else if(squareTrigger){
            solution = calcVal * calcVal;
        } else if(cubeTrigger){
            solution = pow (calcVal, 3.0);
        } else if(factorialTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = fact(dblDisplayVal);
            } else if (dblDisplayVal) {
                solution = fact(calcVal);
            }
        } else if(sinTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = sin(dblDisplayVal);
            } else if (calcVal){
                solution = sin(calcVal);
            }
        } else if(cosTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = cos(dblDisplayVal);
            } else if (calcVal){
                solution = cos(calcVal);
            }
        } else if(tanTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = tan(dblDisplayVal);
            } else if (calcVal){
                solution = tan(calcVal);
            }
        } else if(piTrigger){
            solution = pi;
        } else if(expTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = exp(dblDisplayVal);
            } else if (calcVal){
                solution = exp(calcVal);
            }
        } else if(percTrigger){
            solution = (calcVal * dblDisplayVal) / 100;
        } else if(logTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = log(dblDisplayVal);
            } else if (calcVal){
                solution = log(calcVal);
            }
        } else if(ceilTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = ceil(dblDisplayVal);
            } else if (calcVal){
                solution = ceil(calcVal);
            }
        } else if(sin1Trigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = asin(dblDisplayVal) * 180.0 / pi;
            } else if (calcVal){
                solution = asin(calcVal) * 180.0 / pi;
            }
        } else if(cos1Trigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = acos(dblDisplayVal) * 180.0 / pi;
            } else if (calcVal){
                solution = acos(calcVal) * 180.0 / pi;
            }
        } else if(tan1Trigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = atan(dblDisplayVal) * 180.0 / pi;
            } else if (calcVal){
                solution = atan(calcVal) * 180.0 / pi;
            }
        } else if(compTrigger){
            solution = complement(dblDisplayVal, calcVal);
        } else if(cubeRootTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = cbrt(dblDisplayVal);
            } else if (calcVal){
                solution = cbrt(calcVal);
            }
        } else if(modTrigger){
            solution = std::fmod(calcVal,dblDisplayVal);
        } else if(degTrigger){
            solution = dblDisplayVal * (pi / 180);
        } else if(radTrigger){
            solution = dblDisplayVal * (180/pi);
        } else if (divTrigger){
            solution = calcVal / dblDisplayVal;
        } else if (squareRootTrigger){
            if (dblNotZero(dblDisplayVal)) {
                solution = sqrt(dblDisplayVal);
            } else if (calcVal){
                solution = sqrt(calcVal);
            }
        } else if (clearTrigger){
            solution = 0.0;
        }
    }

    ui->Display->setText(QString::number(solution));

}

void MainWindow::ChangeNumberSign(){

    QString displayVal = ui->Display->text();

    QRegExp reg("[-+]?[0-9.]*");

    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;

        ui->Display->setText(QString::number(dblDisplayValSign));
    }

}
