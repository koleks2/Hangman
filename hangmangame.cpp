#include "hangmangame.h"
#include <QFile>
#include <QTextStream>

HangmanGame::HangmanGame() {
    remainingAttempts = 6;
}

// Начало новой игры
void HangmanGame::startNewGame(const QString &word) {
    secretWord = word;

    // Создаем строку подчеркиваний длиной в секретное слово
    guessedState = QString(word.length(),'_');
    enteredLetters.clear();
    remainingAttempts = 6;

    gameTimer.restart(); // Запуск таймера игры
}

// Логика проверки введенной буквы
bool HangmanGame::guessLetter(QChar letter) {
    // Если букву уже вводили ранее тогда ничего не делаем
    if (enteredLetters.contains(letter)) {
        return false;
    }
    enteredLetters.insert(letter);

    // Если слово содержит введенную букву то открываем ее в загаданном состоянии
    if (secretWord.contains(letter)) {
        for (int i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letter) {
                guessedState[i] = letter;
            }
        }
        return true;
    } else {
        // Если буквы нет то уменьшаем количество попыток
        remainingAttempts--;
        return false;
    }
}

// Проверка отгадано ли все слово
bool HangmanGame::isWon() const {
    return guessedState == secretWord;
}

// Проверка закончились ли попытки
bool HangmanGame::isLost() const {
    return remainingAttempts <= 0;
}

// Сбор статистики текущей игры
QString HangmanGame::getStatistics() const {
    double timeInSec = gameTimer.elapsed() / 1000.0;

    QString lettersStr = "";
    for (QChar ch : enteredLetters) {
        lettersStr.append(ch).append(" ");
    }

    return "Word: " + secretWord +
           " | Time: " + QString::number(timeInSec) + "sec" +
           " | Letters: " + lettersStr;
}

// Сохранение собранной статистики в файл stats.txt
void HangmanGame::saveStatistics() const {
    QFile file("stats.txt");

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << getStatistics() << "\n";
        file.close();
    }
}

// Возвращает текущий открытый статус слова
QString HangmanGame::getGuessedState() const {
    return guessedState;
}

// Возвращает количество оставшихся попыток
int HangmanGame::getRemainingAttempts() const {
    return remainingAttempts;
}

// Считывание слов из зашифрованного Base64 файла и их расшифровка
QStringList HangmanGame::loadWordsFromFile(const QString &filePath) {
    QStringList words;
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                // Декодирование строки из формата Base64
                QByteArray decoded = QByteArray::fromBase64(line.toUtf8());
                words.append(QString::fromUtf8(decoded));
            }
        }
        file.close();
    }
    return words;
}