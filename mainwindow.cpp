#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* EX8 */
    setStartUpLocaleEX8();
    /* EX 9*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

/* EX2 */
void MainWindow::on_checkValue_clicked()
{
    QString lineText = ui->lineEdit->displayText();
    int number;
    try{
        number = std::stoi(lineText.toStdString()); // 'ch11' -- err / '11ch' -- 11
    } catch (std::invalid_argument const& ex) {
        ui->labelParity->setText( "invalid_argument");
        return;
    }
//sign
    if(number < 0)
        ui->labelSign->setText("NEGATIVE");
    else
        ui->labelSign->setText("POSITIVE");
//parity
    if(number%2 == 1 || number%2 == -1)
        ui->labelParity->setText("ODD");
    else
        ui->labelParity->setText("HONEST");
//range

    int s = std::to_string(number).length();
    if(number < 0) s--;
    else if(number == 0) s = 0;
    ui->labelRange->setText("RANGE: " + QString::number(s));

}

/* EX4 */
void MainWindow::on_checkAnswer_b_clicked()
{
    QString text_b = "check answer";
    QString rightAnswer = "4";

    if(ui->checkAnswer_b->text() != text_b){
        ui->returnCheck->clear();
        ui->checkAnswer_b->setText(text_b);

    }else{
        QString answer = ui->optionsAnswer->currentText();
        if(rightAnswer == answer)
            ui->returnCheck->setText("right");
        else
            ui->returnCheck->setText("not right");

        ui->checkAnswer_b->setText("try again");

    }
}

/* EX7 */
void MainWindow::on_checkInfo_OS_clicked()
{
    QString kernelType = QSysInfo::kernelType();
    QString kernelVersion = QSysInfo::kernelVersion();
    ui->outputInfo_OS->setText("u use: " + kernelType +"\n" + kernelVersion);
}

/* EX8 */
void MainWindow::setStartUpLocaleEX8(){
    ui->languageLable->setLocale(QLocale::Language::Russian);
    ui->languageLable->setText("русский");
}

void MainWindow::on_setLocale_box_activated(int index)
{
    if(ui->setLocale_box->itemText(index) == "ru_RU"){
        ui->languageLable->setLocale(QLocale::Language::Russian);
        ui->languageLable->setText("русский");
    }
    else if(ui->setLocale_box->itemText(index) == "en_EN"){
        ui->languageLable->setLocale(QLocale::Language::English);
        ui->languageLable->setText("english");
    }
}

/* EX9 */
std::vector<float> vecValue;

void MainWindow::on_formInputValue_returnPressed()
{
    QString value_str = ui->formInputValue->text();
    ui->formInputValue->clear();
    ui->outputEx9->clear();
    ui->outputEx10->clear();// EX 10

    float value;
    try{
        value = std::stof(value_str.toStdString());
    } catch (std::invalid_argument const& ex) {
        ui->outputEx9->setText( "invalid_argument");
        return;
    }

    vecValue.push_back(value);

}

void MainWindow::on_printArr_b_clicked()
{
    QString textArr;
    /*vectorToQString*/
    std::vector<float> vecValue_c;

    for (int i=0; i < (int)vecValue.size(); i++){
            vecValue_c.push_back(vecValue[i]);
    }
    sort(vecValue_c.begin(), vecValue_c.end());
    for(int i = 0; i < (int)vecValue_c.size(); i++){
        textArr += QString::number(vecValue_c.at(i)) + " ";
    }
    ui->outputEx9->setText(textArr);
    textArr.clear();
    /* EX10 BEGIN */
    for(int i = (int)vecValue_c.size()-1; i >= 0; --i){
        textArr += QString::number(vecValue_c.at(i)) + " ";
    }
    ui->outputEx10->setText(textArr);
    /* EX10 FINISH */

}

void MainWindow::on_clearArr_b_clicked()
{

    ui->formInputValue->clear();
    ui->outputEx9->clear();
    ui->outputEx10->clear();// EX 10
    vecValue.clear();
}

