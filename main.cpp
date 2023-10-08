#include <iostream>
#include <ctype.h>
using namespace std;

char *_strstr(const char *string, const char *strCharSet) {
    int strsize = 0;
    int chrsize = 0;
    while (string[strsize] != '\0') {
        strsize++;
    }
    while (strCharSet[chrsize] != '\0') {
        chrsize++;
    }
    for (int i = 0; i <= strsize - chrsize; i++) {
        int j;
        for (j = 0; j < chrsize; j++) {
            if (string[i + j] != strCharSet[j]) {
                break;
            }
        }
        if (j == chrsize) {
            const char *result = &string[i];
            cout << static_cast<const void*>(result) << endl;
            return const_cast<char *>(result);
        }
    }
    cout << "NULL"<< endl;
    return NULL;
}

int main() {
    // A
    const char *string = "Hello, World!";
    const char *strCharSet = "World";
    _strstr(string, strCharSet);
    const char *string1 = "Hello, Wrld!";
    const char *strCharSet1 = "World";
    _strstr(string1, strCharSet1);

    // B
    char str[300];
    cout << "Enter the line:"<< endl;
    cin.getline(str, sizeof(str));
    cout << "The line: " << str << std::endl;
    int LatWordAmnt = 0;
    bool word = false;
    int VowAmnt = 0;
    int ConAmnt = 0;
    int VowEqCon = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (isalpha(str[i]) && isascii(str[i]) && (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')) {
            word = true;
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y'   )
            {
                VowAmnt++;
            }else{
                ConAmnt++;
            }
        }else{
            if (str[i])
            if (word && str[i]==' ') {
                LatWordAmnt++;
                word = false;
                if (VowAmnt == ConAmnt){
                    VowEqCon++;
                }
                VowAmnt=0;
                ConAmnt=0;
            }
        }
    }
    if (word) {
        LatWordAmnt++;
        if (VowAmnt == ConAmnt) {
            VowEqCon++;
        }
    }
    cout << "Amount of words containing only Latin characters: "<< LatWordAmnt << endl;
    cout << "Amount of words with an equal number of vowels and consonants: "<< VowEqCon;
    return 0;
}
