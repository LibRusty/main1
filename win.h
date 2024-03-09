#ifndef WIN_H
#define WIN_H
#include <QObject>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QBoxLayout>
#include <QValidator>
#include <QMessageBox>


class Win : public QWidget //класс окна
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
    QTextCodec *codec;
    QFrame *frame;            // рамка
    QLabel *inputLabel;       // метка ввода
    QLineEdit *inputEdit;     // строчный редактор ввода
    QLabel *outputLabel;      // метка вывода
    QLineEdit *outputEdit;    // строчный редактор вывода
    QPushButton *nextButton;  // кнопка Следующее
    QPushButton *exitButton;  // кнопка выхода
public:
    Win(QWidget *parent = 0); // конструктор
public slots:
    void begin();      // метод начальной настройки интерфейса
    void calc();       // метод реализации вычислений
};

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos) const
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
};
#endif // WIN_H
