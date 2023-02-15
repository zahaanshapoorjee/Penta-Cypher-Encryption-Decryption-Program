#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#include <vector>

#define MAX_INPUT 250 
using namespace std; //not sexually transmitted disease

//Declaring Global Variables and Functions
int option, inputMethod, cypherMethod;
int key;
string text, filepath;
vector<vector <char>> RAILFENCE_ENCRYPTION(key,vector<char>(text.length(),' '));
vector<vector <char>> RAILFENCE_DECRYPTION(key,vector<char>(text.length(),' '));
char caesar_charEnc(char, int);
char caesar_charDec(char, int);
void affine_encrypt(int, int);
void affine_decrypt(int, int);
void caesar_art();
void affine_art();
void vignere_art();
void vignere_enc(string);
void vignere_dec(string);
string generate_vignere_key(string);
void playfair_enc(string);
void playfair_dec(string);
void railfence_enc(int);
void search_in_table(char[5][5], char, char, int[]);

void onOpen()
{
    cout << "__________      .__                                                                                                                                                                                     "<< endl;   
    cout << "\\____    /____  |  |__ _____  _____    ____   ______                                                                                                                                                    " << endl;
    cout << "  /     /\\__  \\ |  |  \\__  \\ \\__  \\  /    \\ /  ___/                                                                                                                                                    " << endl;
    cout << " /     /_ / __ \\|   Y  \\/ __ \\_/ __ \\|   |  \\___ \\                                                                                                                                                     " << endl;
    cout << "/_______ (____  /___|  (____  (____  /___|  /____  >                                                                                                                                                    " << endl;
    cout << "         \\/    \\/     \\/     \\/     \\/     \\/     \\/                                                                                                                                                     " << endl;
    cout << "__________               __                   _________               .__                                                                                                                               " << endl;
    
    cout << "\\______   \\ ____   _____/  |______            \\_   ___ \\___.__.______ |  |__   ___________                                                                                                              " << endl;
    cout << " |     ___// __ \\ /    \\   __\\__  \\    ______ /    \\  \\<   |  |\\____ \\|  |  \\_/ __ \\_  __ \\                                                                                                             " << endl;
    cout << " |    |   \\  ___/|   |  \\  |  / __ \\_ /_____/ \\     \\___\\___  ||  |_> >   Y  \\  ___/|  | \\/                                                                                                             " << endl;
    cout << " |____|    \\___  >___|  /__| (____  /          \\______  / ____||   __/|___|  /\\___  >__|                                                                                                                " << endl;
    cout << "               \\/     \\/          \\/                  \\/\\/     |__|        \\/     \\/                                                                                                                    " << endl;
    cout << "___________                                   __  .__                        ________                                      __  .__                __________                                            " << endl;
    cout << "\\_   _____/ ____   ___________ ___.__._______/  |_|__| ____   ____           \\______ \\   ____   ___________ ___.__._______/  |_|__| ____   ____   \\______   \\_______  ____   ________________    _____  " << endl;
    cout << " |    __)_ /    \\_/ ___\\_  __ <   |  |\\____ \\   __\\  |/  _ \\ /    \\   ______  |    |  \\_/ __ \\_/ ___\\_  __ <   |  |\\____ \\   __\\  |/  _ \\ /    \\   |     ___/\\_  __ \\/  _ \\ / ___\\_  __ \\__  \\  /     \\ " << endl;
    cout << " |        \\   |  \\  \\___|  | \\/\\___  ||  |_> >  | |  (  <_> )   |  \\ /_____/  |    `   \\  ___/\\  \\___|  | \\/\\___  ||  |_> >  | |  (  <_> )   |  \\  |    |     |  | \\(  <_> ) /_/  >  | \\// __ \\|  Y Y  \\" << endl;
    cout << "/_______  /___|  /\\___  >__|   / ____||   __/|__| |__|\\____/|___|  /         /_______  /\\___  >\\___  >__|   / ____||   __/|__| |__|\\____/|___|  /  |____|     |__|   \\____/\\___  /|__|  (____  /__|_|  /" << endl;
    cout << "        \\/     \\/     \\/       \\/     |__|                       \\/                  \\/     \\/     \\/       \\/     |__|                       \\/                          /_____/            \\/      \\/ " << endl;
}

void methodChoice()
{
    cout << "Please choose the method you would like to use:\n1)Caesar Cypher\n2)Affine Cypher\n3)Vigenere Cypher\n4)Playfair Cypher\n5)Rail Fence Cypher\n";
    cin >> cypherMethod;
}

void input()
{
    Debug: cout << "Please choose what input method you would like to use:\n1)Direct Input\n2)File Input\n";
    cin >> inputMethod;

    if(inputMethod==1) 
    {
        cout << "Please enter your text:\n";
        getline(cin>>ws, text);
        cout << "Input text:\n" << text << endl;
    }
    else if (inputMethod==2)
    {
        cout << "Please enter your filename (example: ilikemen.txt):\n";
        cin >> filepath;
        ifstream fileInput;
        fileInput.open(filepath);
        ifstream file(filepath);
        if(file.fail())
        {
            cout << "File does not exist...\n";
            goto Debug;
        }
        else
        {
            fileInput >> text;
            cout << "Input text: " << text;
        }

    }
    
}

void caesar_encrypt(int key)
{
    string result = "";

    for(int i = 0 ; i < text.length(); i++)
    {
        result+= caesar_charEnc(text[i], key);
    }

    cout << "Encrypted Text:\n" << result << endl;
}

char caesar_charEnc(char ch, int key)
{
    if(isupper(ch)) return char(int(ch + key-65) % 26 + 65); //Modding will handle edge cases (..., Y, Z)
    else if((ch>= 91 && ch <= 96) || (ch >= 123 && ch <= 127) || ch <= 64) return ch;
    else return char(int(ch+key-97)% 26 + 97);
}

void caesar_decrypt(int key)
{
    string result = "";
    for(int i = 0;i<text.length(); i++)
    {
        result+= caesar_charDec(text[i], key);
    }
    cout << "Decrypted Text:\n" << result << endl;
} 

char caesar_charDec(char ch, int key)
{
    if(isupper(ch))
    {
        ch=ch-key;
        if(ch<'A') ch+=26;
        return ch;
    } 
    else if((ch>= 91 && ch <= 96) || (ch >= 123 && ch <= 127) || ch <= 64) return ch;
    else{
        ch=ch-key;
        if(ch<'a') ch+=26;
        return ch;
    } 
}  

void affine_encrypt(int a, int b)
{
    string result = "";
    for(int i = 0; i<text.length(); i++)
    {
        if(isupper(text[i])) result+=char((a * int(text[i] - 65) + b) % 26 + 65);
        else if((text[i] >= 91 && text[i] <= 96) || (text[i] >= 123 && text[i] <= 127) || text[i] <= 64) result+= text[i];
        else result+=char((a * int(text[i] - 97) + b) % 26 + 97);

    }

    cout << "Encrypted Text:\n" << result << endl;
}

void affine_decrypt(int a, int b)
{
    string result = "";
    int check, a_inverse;
    for(int i = 0; i<26; i++)
    {
        check =  (a * i) % 26;
        if(check==1) a_inverse = i;   
    }
    cout << "The key inverse is : " << a_inverse << endl;

    for(int i = 0; i<text.length(); i++)
    {
        if(isupper(text[i])) result+= char(((((text[i] - 65 - b) % 26 + 26) % 26) * a_inverse) % 26 + 65);
        else if((text[i] >= 91 && text[i] <= 96) || (text[i] >= 123 && text[i] <= 127) || text[i] <= 64) result+= text[i];
        else result+= char(((((text[i] - 97 - b) % 26 + 26) % 26) * a_inverse) % 26 + 97);
    }

    cout << "Decrypted Text:\n" << result << endl;

}
void caesar_art()
{
    cout << "_________                                      _________               .__                  " << endl;
    cout << "\\_   ___ \\_____    ____   ___________ _______  \\_   ___ \\___.__.______ |  |__   ___________ " << endl;
    cout << "/    \\  \\/\\__  \\ _/ __ \\ /  ___/\\__  \\_  __ \\ /    \\  \\<   |  |\\____ \\|  |  \\_/ __ \\_  __ \\" << endl;
    cout << "\\     \\____/ __ \\  ___/ \\___ \\  / __ \\|  | \\/ \\     \\___\\___  ||  |_> >   Y  \\  ___/|  | \\/" << endl;
    cout << " \\______  (____  /\\___  >____  >(____  /__|     \\______  / ____||   __/|___|  /\\___  >__|   " << endl;
    cout << "        \\/     \\/     \\/     \\/      \\/                \\/\\/     |__|        \\/     \\/       " << endl;
}

void affine_art()
{
    cout << "   _____   _____  _____.__                _________               .__                  " << endl;
    cout << "  /  _  \\_/ ____\\/ ____\\__| ____   ____   \\_   ___ \\___.__.______ |  |__   ___________ " << endl;
    cout << " /  /_\\  \\   __\\   __\\|  |/    \\_/ __ \\  /    \\  \\<   |  |\\____ \\|  |  \\_/ __ \\_  __ \\" << endl;
    cout << "/    |    \\  |   |  |  |  |   |  \\  ___/  \\     \\___\\___  ||  |_> >   Y  \\  ___/|  | \\/" << endl;
    cout << "\\____|__  /__|   |__|  |__|___|  /\\___  >  \\______  / ____||   __/|___|  /\\___  >__|   " << endl;
    cout << "        \\/                     \\/     \\/          \\/\\/     |__|        \\/     \\/       " << endl;
}

void vignere_art()
{
    cout << "____   ____.___  ________  _______  ________________________________ ______________.___.__________  ___ ________________________ " << endl;
    cout << "\\   \\ /   /|   |/  _____/  \\      \\ \\_   _____/\\______   \\_   _____/ \\_   ___ \\__  |   |\\______   \\/   |   \\_   _____/\\______   \\" << endl;
    cout << " \\   Y   / |   /   \\  ___  /   |   \\ |    __)_  |       _/|    __)_  /    \\  \\//   |   | |     ___/    ~    \\    __)_  |       _/" << endl;
    cout << "  \\     /  |   \\    \\_\\  \\/    |    \\|        \\ |    |   \\|        \\ \\     \\___\\____   | |    |   \\    Y    /        \\ |    |   \\" << endl;
    cout << "   \\___/   |___|\\______  /\\____|__  /_______  / |____|_  /_______  /  \\______  / ______| |____|    \\___|_  /_______  / |____|_  /" << endl;
    cout << "                       \\/         \\/        \\/         \\/        \\/          \\/\\/                        \\/        \\/         \\/ " << endl;
}

void playfair_art()
{
    cout << "__________.____       _____ _____.___.________________  ._____________  ______________.___.__________  ___ ________________________ " << endl;
    cout << "\\______   \\    |     /  _  \\__  |   |\\_   _____/  _  \\ |   \\______   \\ \\_   ___ \\__  |   |\\______   \\/   |   \\_   _____/\\______   \\" << endl;
    cout << " |     ___/    |    /  /_\\  \\/   |   | |    __)/  /_\\  \\|   ||       _/ /    \\  \\//   |   | |     ___/    ~    \\    __)_  |       _/" << endl;
    cout << " |    |   |    |___/    |    \\____   | |     \\/    |    \\   ||    |   \\ \\     \\___\\____   | |    |   \\    Y    /        \\ |    |   \\" << endl;
    cout << " |____|   |_______ \\____|__  / ______| \\___  /\\____|__  /___||____|_  /  \\______  / ______| |____|    \\___|_  /_______  / |____|_  /" << endl;
    cout << "                  \\/       \\/\\/            \\/         \\/            \\/          \\/\\/                        \\/        \\/         \\/ " << endl;
}

void railfence_art()
{
    cout << "__________    _____  .___.____      ______________________ _______  _________ ___________ ______________.___.__________  ___ ________________________ " << endl;
    cout << "\\______   \\  /  _  \\ |   |    |     \\_   _____/\\_   _____/ \\      \\ \\_   ___ \\_   _____/ \\_   ___ \\__  |   |\\______   \\/   |   \\_   _____/\\______   \\" << endl;
    cout << " |       _/ /  /_\\  \\|   |    |      |    __)   |    __)_  /   |   \\/    \\  \\/ |    __)_  /    \\  \\//   |   | |     ___/    ~    \\    __)_  |       _/" << endl;
    cout << " |    |   \\/    |    \\   |    |___   |     \\    |        \\/    |    \\     \\____|        \\ \\     \\___\\____   | |    |   \\    Y    /        \\ |    |   \\" << endl;
    cout << " |____|_  /\\____|__  /___|_______ \\  \\___  /   /_______  /\\____|__  /\\______  /_______  /  \\______  / ______| |____|    \\___|_  /_______  / |____|_  /" << endl;
    cout << "        \\/         \\/            \\/      \\/            \\/         \\/        \\/        \\/          \\/\\/                        \\/        \\/         \\/ " << endl;
}

void vignere_enc(string key)
{
    string result = "";
    string enc_key = generate_vignere_key(key);

    for(int i = 0; i<text.length();i++)
    {
        int a = isupper(text[i])? text[i]-65 : text[i] - 97;
        int b = isupper(enc_key[i])? enc_key[i]-65 : enc_key[i] - 97;
        int c = isupper(text[i])? ((a+b)%26)+65:((a+b)%26)+97;
        result+= char(c);
    }

    cout << result;
}

void vignere_dec(string key)
{
    string result = "";
    string enc_key = generate_vignere_key(key);
    int c;
    for(int i =0; i<text.length();i++)
    {
        int a = isupper(text[i])? text[i]-65 : text[i] - 97;
        int b = isupper(enc_key[i])? enc_key[i]-65 : enc_key[i] - 97;
        if(isupper(text[i]))
        {
            if(a-b<0)
            {
                c = (a-b+26)%26+65;
            }
            else c = (a-b)%26+65;
        }
        else if(!isupper(text[i]))
        {
            if(a-b<0)
            {
                c = (a-b+26)%26+97;
            }
            else c = (a-b)%26+97;
        }
        else c = text[i];

        result+=char(c);
    }
    
    cout << "The Decrypted text is: " << result << endl;
}

string generate_vignere_key(string key)
{
    string result = "";
    for(int i =0;i<text.length();i++)
    {
        result+= char(key[i%key.length()]);
    }

    return result;
}

string toLowerCase(string s)
{
    for(int i =0;i<s.length();i++)
    {
        if (s[i] > 64 && s[i] < 91)
            s[i] += 32;
    }
    return s;
}

string remove_spaces(string s)
{
    string res = "";
    for(int i =0;i<s.length();i++)
    {
        if(s[i]!=' ') res+=s[i];
    }
    return res;
}

void generateKeyTable(string key, int keysize, char table[5][5])
{
    int i, j, k, flag = 0;
 
    // 26 character hashmap to store frequency of each 26 letters
    int alphabetcount[26] = { 0 };
    for (i = 0; i < keysize; i++) {
        if (key[i] != 'j')
            alphabetcount[key[i] - 97] = 2;
    }
 
    alphabetcount['j' - 97] = 1;
 
    i = 0;
    j = 0;
 
    for (k = 0; k < keysize; k++) {
        if (alphabetcount[key[k] - 97] == 2) {
            alphabetcount[key[k] - 97] -= 1;
            table[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
 
    for (k = 0; k < 26; k++) {
        if (alphabetcount[k] == 0) {
            table[i][j] = (char)(k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }

}

string prepare_playfair(string s)
{
    if(s.length()%2!=0) s+='z';
    return s;
}
void playfair_enc(string key, char table[5][5])
{
    string result = "";
    text = toLowerCase(text);
    text = remove_spaces(text);
    text = prepare_playfair(text);

    key = toLowerCase(key);
    key = remove_spaces(key);

    cout << "The following Key Table has been generated: " ;
    generateKeyTable(key, key.length(),table);
    for(int i =0;i<5;i++)
    {
        cout << endl;
        for(int j =0;j<5;j++){
            cout << table[i][j]<<" ";
        }
    }
    cout << endl;

    int arr[4];
    
    for(int i =0;i<text.length();i+=2)
    {
        search_in_table(table, text[i], text[i+1], arr);
        if(arr[0]==arr[2])
        {
            result+=table[arr[0]][(arr[1]+1)%5];
            result+=table[arr[0]][(arr[3]+1)%5];
        }
        else if(arr[1]==arr[3])
        {
            result+=table[(arr[0]+1)%5][arr[1]];
            result+=table[(arr[2]+1)%5][arr[1]];
        }
        else
        {
            result+=table[arr[0]][arr[3]];
            result+=table[arr[2]][arr[1]];
        }
    }

    cout << result << endl;
 
}

void search_in_table(char table[5][5], char a, char b, int arr[])
{
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';

    for(int i = 0; i<5;i++)
    {
        for(int j = 0; j<5;j++)
        {
            if(table[i][j]==a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if(table[i][j]==b)
            {
                arr[2] = i;
                arr[3] = j; 
            }
        }
    }
}

void playfair_dec(string key, char table[5][5])
{
    string result = "";
    text = toLowerCase(text);
    text = remove_spaces(text);
    text = prepare_playfair(text);

    key = toLowerCase(key);
    key = remove_spaces(key);

    cout << "The following Key Table has been generated: " ;
    generateKeyTable(key, key.length(),table);

    cout << endl;

    int arr[4];
    
    for(int i =0;i<text.length();i+=2)
    {
        search_in_table(table, text[i], text[i+1], arr);
        if(arr[0]==arr[2])
        {
            result+=table[arr[0]][(arr[1]-1)%5];
            result+=table[arr[0]][(arr[3]-1)%5];
        }
        else if(arr[1]==arr[3])
        {
            result+=table[(arr[0]-1)%5][arr[1]];
            result+=table[(arr[2]-1)%5][arr[1]];
        }
        else
        {
            result+=table[arr[0]][arr[3]];
            result+=table[arr[2]][arr[1]];
        }
    }

    cout << result << endl;

}

void railfence_enc(int key)
{
    //First we initialise the railfence vector with number of columnns as the length of the cipher text and 
    //Number of rows as the key

    vector<vector <char>> rail(key,vector<char>(text.length(),' '));
    int j =0;
    bool go_down = true;
    for(int i =0;i<text.length();i++)
    {
        rail[j][i] = text[i];
        if(j==key-1) 
        {
            go_down = false;
        }
        else if(j==0) go_down = true;

        if(go_down==true) j++;
        else if(go_down==false) j--;
    }
    for(int i =0;i<key;i++)
    {
        for(int j = 0;j<text.length();j++)
        {
            if(rail[i][j]!=' ') cout << rail[i][j];
        }
    }
    cout << endl;

}

void railfence_dec(int key)
{
    vector<vector<char>> a(key,vector<char>(text.size(),' '));
    int j=0;
    int flag=0;
    for(int i=0;i<text.size();i++){
        a[j][i] = '0';
         if(j==key-1){
            flag=1;
        }
        else if(j==0)
            flag=0;
        if(flag==0){
            j++;
        }
        else j--;
    }
    int temp =0;
    for(int i=0;i<key;i++){
        for(j=0;j<text.size();j++){
                if(a[i][j]=='0')
                    a[i][j]= text[temp++];
        }
    }
    flag=0;
    j=0;
    for(int i=0;i<text.size();i++){
        cout<<a[j][i];
         if(j==key-1){
            flag=1;
        }
        else if(j==0)
            flag=0;
        if(flag==0){
            j++;
        }
        else j--;
    }

}
int main()
{
    do{
        onOpen();
        cout << "Welcome to Zahaan's Ultimate Cypher Program! Please make your choice: \n1)Encrypt\n2)Decrypt\n3)Exit" << endl;
        cin >> option;

        if(option==1) //If the option chosen is Encrypt:
        {
            input();
            methodChoice();
            if(cypherMethod==1) // If user chooses Caesar Cypher
            {
                caesar_art();
                int key;
                cout << "Enter key: \n";
                cin >> key;
                caesar_encrypt(key);
            }
            else if(cypherMethod==2) //If user chooses Affine Cypher
            {
                affine_art();
                int a,b;
                cout << "Enter first key:\n";
                cin >> a;
                cout << "Enter second key:\n";
                cin >> b;
                affine_encrypt(a,b);
            }
            else if(cypherMethod==3) //If user chooses Vignere Cypher
            {
                vignere_art();
                string key;
                cout << "Enter cypher key:" << endl;
                cin >> key;
                vignere_enc(key);
            }
            else if(cypherMethod==4) //If user chooses Playfair Cypher
            {
                playfair_art();
                string key;
                char table[5][5];
                cout << "Enter cypher key:" << endl;
                cin >> key;
                playfair_enc(key, table);
            }
            else if(cypherMethod==5)
            {
                railfence_art();
                cout << "Enter cypher key: " << endl;
                int key;
                cin >> key;
                railfence_enc(key);
            }
            
        }
        else if(option==2) //If the option chosen is Decrypt:
        {
            input();
            methodChoice();
            if(cypherMethod==1) //If user chooses Caesar Cypher
            {
                caesar_art();
                int key;
                caesar_art();
                cout << "Enter key: \n";
                cin >> key;
                caesar_decrypt(key);
            }
            else if(cypherMethod==2) //If user chooses Affine Cypher
            {
                affine_art();
                int a,b;
                cout << "Enter first key:\n" << endl;
                cin >> a;
                cout << "Enter second key:\n" << endl;
                cin >> b;
                affine_decrypt(a,b);
            }
            else if(cypherMethod==3) //If user chooses Vignere Cypher
            {
                vignere_art();
                string key;
                cout << "Enter cypher key:" << endl;
                cin >> key;
                vignere_dec(key);
            }
            else if(cypherMethod==4) //If user chooses Playfair Cypher
            {
                playfair_art();
                string key;
                char table[5][5];
                cout << "Enter cypher key:" << endl;
                cin >> key;
                playfair_dec(key, table);
            }
            else if(cypherMethod==5) //If user chooses Rail Fence Cypher
            {
                railfence_art();
                cout << "Enter cypher key: " << endl;
                int key;
                cin >> key;
                railfence_dec(key);
            }        
        }
        else cout << "Invalid Input..." << endl;
        
    }
    while (option!=3);
    return 0;

}
