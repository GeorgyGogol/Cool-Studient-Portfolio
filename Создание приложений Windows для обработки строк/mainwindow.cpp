#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QMessageBox"

#include "qcword.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	on_pushButton_about_clicked();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_Work_clicked()
{
	// Считываем строку из формы
	QString str = ui->textEdit_input->toPlainText();

	// Проверяем ввобимые слова и попутно находим количество слов
	ui->label_Status->setText("Проверка ввода");
	int n_words = 1;
	int word_length = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ',') {
			n_words++;
			word_length = 0;
			continue;
		}
		if (str[i] == ' ') continue;
		word_length++;
		if (word_length >= 10) {
			QMessageBox::warning(this, "Внимание", "Во вводимой строке присутствует слово с длинной более 10 букв! Операция прервана!");
			ui->label_Status->setText("Ошибка ввода.");
			return;
		}
	}

	// Формируем "фразу" из "слов"
	QcWord* phrase = new QcWord[n_words];
	QString buf;
	ui->label_Status->setText("Обработка введенных слов");

	for (int symbol = 0, i_word = 0; i_word < n_words && symbol < str.length(); ++i_word) {
		do{
			if (str[symbol] == ',') {
				symbol++;
				break;
			}
			if (str[symbol] == ' ' && str[symbol - 1] == ',') {
				symbol++;
				continue;
			}
			buf.push_back(str.at(symbol));
			symbol++;
		} while (symbol < str.length());
		phrase[i_word].set(buf);
		buf.clear();
	}

	// Теперь найдем количество слов с одинаковой первой и последней буквой и сформируем новую строку для вывода
	int startNend = 0;
	QString out_str;
	for (int i = 0; i < n_words; ++i) {
		if (phrase[i].isStartAndEnd()) startNend++;
		buf = phrase[i].getFullWord();
		out_str += buf;
	}

	// Вывод
	ui->textEdit_output->setText(out_str);
	ui->label_Status->setText("Найденное количество слов: " + QString::number(startNend));
	QMessageBox::information(this, "Выполненно", "Программа успешно завершила обработку введенных слов, ошибок не возникло. В результате была сформирована строка, "
							 "состоящая из слов с каждой 10й позиции и посчитано количество слов, которые начинаются и заканчиваются на одну и ту же букву. Их "
							 "количество: " + QString::number(startNend) + "\n"
							 "Работу выполнил студент группы БИК2051 Гоголев Георгий");
	// Очистка памяти и выход
	delete [] phrase;
	return;
}

void MainWindow::on_pushButton_Clear_clicked()
{
	ui->textEdit_input->clear();
	ui->textEdit_output->clear();
	ui->label_Status->setText("Готово к вводу");
	return;
}


void MainWindow::on_pushButton_about_clicked()
{
	QString about_text;
	about_text.push_back("Лабораторная работа № "); about_text.push_back(LAB_NUM); about_text += "\n";
	about_text.push_back(LAB_TEXT); about_text += "\n";
	about_text.push_back("Вариант: "); about_text.push_back(VAR); about_text += "\n";
	about_text.push_back(VAR_TEXT); about_text += "\n";
	about_text.push_back("Работу выполнил: "); about_text.push_back(FIO); about_text += "\n";
	about_text.push_back("Группа: "); about_text.push_back(GROUP);

	QMessageBox::information(this, "О проекте", about_text);
}
