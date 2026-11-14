#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Настройка стиля для отображения загаданного слова
    ui->labelWord->setStyleSheet("letter-spacing: 8px; font-size: 20px;");

    // Загрузка зашифрованных слов из файла
    QStringList words = HangmanGame::loadWordsFromFile("C:/Users/kol20/Documents/Shibinica/words.txt");

    // Выбор случайного слова
    QString randomWord = words.at(QRandomGenerator::global()->bounded(words.size()));

    // Инициализация новой игры выбранным словом
    game.startNewGame(randomWord);
    ui->labelWord->setText(game.getGuessedState());
    ui->labelAttempts->setText("Tries: " + QString::number(game.getRemainingAttempts()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Обработка нажатия кнопки
void MainWindow::on_btnGuess_clicked()
{
    // Получаем текст из поля ввода
    QString text = ui->lineLetter->text();
    if (text.isEmpty()) return;

    QChar letter = text.at(0);
    game.guessLetter(letter);

    // Очищаем поле ввода после попытки
    ui->lineLetter->clear();

    // Обновляем состояние слова на экране и количество оставшихся попыток
    ui->labelWord->setText(game.getGuessedState());
    ui->labelAttempts->setText("Tries: " + QString::number(game.getRemainingAttempts()));

    QStringList stages = {
        "----\n|  |\n|\n|\n|",
        "----\n|  |\n|  O\n|\n|",
        "----\n|  |\n|  O\n|  |\n|",
        "----\n|  |\n|  O\n| /|\n|",
        "----\n|  |\n|  O\n| /|\\\n|",
        "----\n|  |\n|  O\n| /|\\\n| /",
        "----\n|  |\n|  O\n| /|\\\n| / \\"
    };

    // Вычисляем количество ошибок и обновляем рисунок на лейбле
    int mistakes = 6 - game.getRemainingAttempts();
    ui->labelHangman->setText(stages[mistakes]);

    // Проверка победы или поражения
    if (game.isWon()) {
        QMessageBox::information(this, "Victory!", "You won!");
        game.saveStatistics();
        close();
    } else if (game.isLost()) {
        QMessageBox::information(this, "Game Over", "You lost!");
        game.saveStatistics();
        close();
    }
}