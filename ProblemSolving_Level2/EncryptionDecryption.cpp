#include <iostream>
#include <string>
using namespace std;

string readText(){

    string text;

    cout<<"Please Enter a Text:\n";
    getline(cin, text);

    return text;
}

string EncryptionText(string text, short encryptionKEY){

    for(int i=0; i<=text.length(); i++){
        text[i] = (char)((int)text[i] + encryptionKEY);
    }
    return text;
}

string DecryptionText(string text, short encryptionKEY){

    for(int i=0; i<=text.length(); i++){
        text[i] = (char)((int)text[i] - encryptionKEY);
    }
    return text;
}

int main(){

    const short encryptionKEY = 2;

    string text = readText();
    string textAfterEncryption = EncryptionText(text, encryptionKEY);
    string textAfterDecryption = DecryptionText(textAfterEncryption, encryptionKEY);

    cout<<"\nText Before Encryption: "<<text<<endl;
    cout<<"\nText After Encryption: "<<textAfterEncryption<<endl;
    cout<<"Text After Decryption: "<<textAfterDecryption<<endl;

    return 0;
}