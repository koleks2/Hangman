#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <QString>
#include <QSet>
#include <QElapsedTimer>

class HangmanGame
{
private:
    QString secretWord;
    QString guessedState;
    QSet<QChar> enteredLetters;
    int remainingAttempts;
    QElapsedTimer gameTimer;

public:
    HangmanGame();
    void startNewGame(const QString &word);
    bool guessLetter(QChar letter);
    bool isWon() const;
    bool isLost() const;
    QString getStatistics() const;
    void saveStatistics() const;
    QString getGuessedState() const;
    int getRemainingAttempts() const;

    static QStringList loadWordsFromFile(const QString &filePath);
};

#endif // HANGMANGAME_H
