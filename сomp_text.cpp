/*
Вариант 14.
Даны 2 текста. Вывести их общие слова
*/

#include <iostream>
#include <string>

using namespace std;

string toLower(const string& str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

bool isDelimiter(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' ||
        c == ':' || c == ';' || c == '(' || c == ')' || c == '\n' || c == '\t';
}

int extractWords(const string& text, string words[], int maxWords) {
    int wordCount = 0;
    string currentWord = "";

    for (size_t i = 0; i < text.length(); i++) {
        if (!isDelimiter(text[i])) {
            currentWord += text[i];
        }
        else {
            if (currentWord.length() > 0) {
                if (wordCount < maxWords) {
                    words[wordCount] = toLower(currentWord);
                    wordCount++;
                }
                currentWord = "";
            }
        }
    }

    if (currentWord.length() > 0 && wordCount < maxWords) {
        words[wordCount] = toLower(currentWord);
        wordCount++;
    }

    return wordCount;
}

bool contains(const string words[], int count, const string& word) {
    for (int i = 0; i < count; i++) {
        if (words[i] == word) {
            return true;
        }
    }
    return false;
}

int main() {
    const int MAX_WORDS = 1000;
    string text1, text2;
    string words1[MAX_WORDS], words2[MAX_WORDS];
    string commonWords[MAX_WORDS];
    int count1, count2, commonCount = 0;

    // Ввод текстов
    cout << "Введите первый текст:" << endl;
    getline(cin, text1);

    cout << "Введите второй текст:" << endl;
    getline(cin, text2);

    // Извлечение слов
    count1 = extractWords(text1, words1, MAX_WORDS);
    count2 = extractWords(text2, words2, MAX_WORDS);

    // Поиск общих слов
    for (int i = 0; i < count1; i++) {
        if (contains(words2, count2, words1[i])) {
            if (!contains(commonWords, commonCount, words1[i])) {
                commonWords[commonCount] = words1[i];
                commonCount++;
            }
        }
    }

    cout << "\nОбщие слова:" << endl;
    if (commonCount == 0) {
        cout << "Нет общих слов" << endl;
    }
    else {
        for (int i = 0; i < commonCount; i++) {
            cout << commonWords[i] << endl;
        }
    }

    return 0;
}
