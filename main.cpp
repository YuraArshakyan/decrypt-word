#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream file;
    file.open("test.txt");
    string text;
    string text1[1000];
    int max = 0;
    int temp;
    int word_from_doc = 1;
    while (!file.eof()){
        file >> text;
        word_from_doc++;
        temp = stoi(text);
        file >> text1[temp];
        if(temp > max){
            max = temp;
        }
    }
    int temp1 = 2;
    int temp2;
    int itteration = 1;
    int word[1000];
    int word_position = 0;
    for(int i = 0; i < max; i++){
        temp2 = temp1;
        if(i == 0){
            word[word_position] = itteration;
            word_position++;
            itteration++;
        } else{
            while (temp1 >= i){
                if(itteration == max+1){
                    break;
                }
                if(temp1 == i){
                    word[word_position] = itteration;
                    word_position++;
                }
                itteration++;
                temp1--;
            }
            if(itteration != max+1){
                temp1= temp2+2;
            }
        }
    }
    for(int i = 0; i < 1000; i++){
        if(word[i] != 0) {
            cout << text1[word[i]] << " ";
        }
    }
    file.close();
}
