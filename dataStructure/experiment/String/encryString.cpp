#include <iostream>
using namespace std;

typedef char ElemType;
typedef struct
{
    ElemType *data;
    int length, maxSize;
} String, *SqString;

// Initialize the String
void InitString(SqString &S, int initSize)
{
    S = new String;
    S->data = new ElemType[initSize];
    S->length = 0;
    S->maxSize = initSize;
}

// Destroy the String
void DestroyString(SqString &S)
{
    delete[] S->data;
    delete S;
}

// Assign a String
void StrAssign(SqString &S)
{
    int cstrLength;
    cout << "Please enter your string's max length: ";
    cin >> cstrLength;
    if (cstrLength <= S->maxSize && cstrLength > 0)
    {
        char cstr[cstrLength];
        cout << "Please enter the string: ";
        cin >> cstr;
        for (int i = 0; cstr[i] != '\0'; i++)
        {
            S->data[i] = cstr[i];
            S->length = i + 1;
        }
    }
    else
    {
        cout << "Assign failed,the input is illegal!" << endl;
    }
}

// Display stirng
void DispStr(SqString S)
{
    if (S->length > 0)
    {
        for (int i = 0; i < S->length; i++)
        {
            cout << S->data[i];
        }
    }
    else
    {
        cout << "Display failed,the string is null";
    }
    cout << endl;
}

// Encrypt operation
SqString EncryOp(SqString S, SqString ES, SqString MS)
{
    SqString resStr;
    InitString(resStr, S->maxSize);
    for (int i = 0; i < S->length; i++)
    {
        for (int j = 0; j < ES->length; j++)
        {
            if (S->data[i] == ES->data[j])
            {
                resStr->data[i] = MS->data[j];
                break;
            }
            else
            {
                // don't macth the mapping just input '?'
                resStr->data[i] = '?';
            }
        }
    }
    resStr->length = S->length;
    return resStr;
}

// Decrypt operation
SqString DecryOp(SqString S, SqString ES, SqString MS)
{
    SqString resStr;
    InitString(resStr, S->maxSize);
    for (int i = 0; i < S->length; i++)
    {
        for (int j = 0; j < MS->length; j++)
        {
            if (S->data[i] == MS->data[j])
            {
                resStr->data[i] = ES->data[j];
                break;
            }
            else
            {
                // don't macth the mapping just input '?'
                resStr->data[i] = '?';
            }
        }
    }
    resStr->length = S->length;
    return resStr;
}

int main()
{
    // MS: MappingString
    // ES: EncryptString
    // S: Need to be encrypted string
    SqString S, ES, MS;
    cout << "----Encrypt string----" << endl;
    InitString(ES, 26);
    StrAssign(ES);
    cout << "----Mapping string----" << endl;
    InitString(MS, 26);
    StrAssign(MS);
    cout << "----Need to be encrypted string----" << endl;
    InitString(S, 50);
    StrAssign(S);
    cout << "---------------------------------" << endl;
    cout << "---------------Test--------------" << endl;
    cout << "---------------------------------" << endl;
    cout << "----Encrypt table----" << endl;
    DispStr(ES);
    DispStr(MS);
    cout << "----Need to be encrypted string----" << endl;
    DispStr(S);
    cout << "----Encrypted result string----" << endl;
    SqString encryResString = EncryOp(S, ES, MS);
    DispStr(encryResString);
    cout << "----Decrypted result string----" << endl;
    SqString decryResString = DecryOp(encryResString, ES, MS);
    DispStr(decryResString);
    DestroyString(S);
    DestroyString(ES);
    DestroyString(MS);
    DestroyString(encryResString);
    DestroyString(decryResString);
    return 0;
}