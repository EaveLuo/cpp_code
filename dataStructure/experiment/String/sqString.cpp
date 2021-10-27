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

// Count string's length
int strLength(SqString S)
{
    return S->length;
}

// Insert a string S2 into another string S1
// that genarate a new string and return it
SqString InsertStr(SqString S1, SqString S2, int location)
{
    SqString resStr;
    InitString(resStr, S1->maxSize + S2->maxSize);
    if (location > 0 && location <= S1->length + 1)
    {
        for (int i = 0; i < location - 1; i++)
        {
            resStr->data[i] = S1->data[i];
        }
        for (int i = 0; i < S2->length; i++)
        {
            resStr->data[i + location - 1] = S2->data[i];
        }
        for (int i = location - 1; i < S1->length; i++)
        {
            resStr->data[S2->length + i] = S1->data[i];
        }
        resStr->length = S1->length + S2->length;
        return resStr;
    }
    else
    {
        cout << "Insert failed,your location is illegal" << endl;
        resStr->length = 0;
        return resStr;
    }
}

// Delete string length from location in S
// that genarate a new string and return it
SqString DeleteStr(SqString S, int location, int length)
{
    SqString resStr;
    InitString(resStr, S->maxSize - length);
    if (location > 0 && location <= S->length && location + length <= S->length + 1)
    {
        for (int i = 0; i < location - 1; i++)
        {
            resStr->data[i] = S->data[i];
        }
        for (int i = location - 1; i < S->length; i++)
        {
            resStr->data[i] = S->data[i + length];
        }
        resStr->length = S->length - length;
        return resStr;
    }
    else
    {
        cout << "Delete failed,your location is illegal" << endl;
        resStr->length = 0;
        return resStr;
    }
}

// Replace string length from location in S1 to S2
// that genarate a new string and return it
SqString ReplaceStr(SqString S1, SqString S2, int location, int length)
{
    SqString resStr;
    InitString(resStr, S1->maxSize - length + S2->maxSize);
    if (location > 0 && location <= S1->length && location + length <= S1->length + 1)
    {
        for (int i = 0; i < location - 1; i++)
        {
            resStr->data[i] = S1->data[i];
        }
        for (int i = 0; i < S2->length; i++)
        {
            resStr->data[location + i - 1] = S2->data[i];
        }
        for (int i = location - 1 + length; i < S1->length; i++)
        {
            resStr->data[i + S2->length - length] = S1->data[i];
        }

        resStr->length = S1->length - length + S2->length;
        return resStr;
    }
    else
    {
        cout << "Replace failed,your location is illegal" << endl;
        resStr->length = 0;
        return resStr;
    }
}

// get a substring length from location in S 
// that genarate a new string and return it
SqString SubStr(SqString S, int location, int length)
{
    SqString resStr;
    InitString(resStr, length);
    if (location > 0 && location <= S->length 
    && location + length <= S->length + 1 && length > 0)
    {
        for (int i = location - 1; i < location + length - 1; i++)
        {
            resStr->data[i - location + 1] = S->data[i];
        }
        resStr->length = length;
        return resStr;
    }
    else
    {
        cout << "Get substring failed,your location is illegal" << endl;
        resStr->length = 0;
        return resStr;
    }
}

// Concat string S1 and S2 that genarate a new string and return it
SqString Concat(SqString S1, SqString S2)
{
    SqString resStr;
    InitString(resStr, S1->maxSize + S2->maxSize);
    for (int i = 0; i < S1->length; i++)
    {
        resStr->data[i] = S1->data[i];
    }
    for (int i = 0; i < S2->length; i++)
    {
        resStr->data[S1->length + i] = S2->data[i];
    }
    resStr->length = S1->length + S2->length;
    return resStr;
}

// Display stirng
void DispStr(SqString S)
{
    if (S->length > 0)
    {
        cout << "Display the string: ";
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

int main()
{
    SqString S, S1;
    InitString(S, 20);
    StrAssign(S);
    InitString(S1, 5);
    StrAssign(S1);
    DispStr(S);
    cout << "The string s's length is: " << strLength(S) << endl;
    SqString S2 = InsertStr(S, S1, 9);
    DispStr(S2);
    S2 = DeleteStr(S, 2, 5);
    DispStr(S2);
    S2 = ReplaceStr(S, S1, 2, 5);
    DispStr(S2);
    SqString S3 = SubStr(S, 2, 10);
    DispStr(S3);
    SqString S4 = Concat(S1, S2);
    DispStr(S4);
    DestroyString(S);
    DestroyString(S1);
    DestroyString(S2);
    DestroyString(S3);
    DestroyString(S4);
    return 0;
}