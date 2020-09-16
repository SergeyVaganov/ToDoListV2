#include "ClassGlobal.h"

bool UseFiles::haveIni()
{
    FILE* fileInI;
    errno_t errInI;
    errInI = _wfopen_s(&fileInI, iniFile.c_str(), L"r");
    if (errInI) { return false; }
    fclose(fileInI); 
    return true;
}

bool UseFiles::createIni(std::wstring datFile)
{
    this->datFile = datFile;
    FILE* fileOut;
    errno_t errOut;
    errOut = _wfopen_s(&fileOut, iniFile.c_str(), L"w+");
    if (errOut) {
        MessageBoxW(NULL, L"Ошибка записи файла ini", L"Ошибка", MB_YESNO);
        return false; 
    }
    wchar_t ch, end = L'\0';
    int i(0);
    while (datFile[i] != end)
    {
        ch = datFile[i];
        fwrite(&ch, sizeof(wchar_t), 1, fileOut);
        i++;
    }
    fwrite(&end, sizeof(wchar_t), 1, fileOut);
    fclose(fileOut);    
    return false;
}


std::wstring UseFiles::getDat()
{
    return datFile;
}

void UseFiles::setFiles()
{
    bool ret(true);
    FILE* fileIn;
    errno_t errIn;
    errIn = _wfopen_s(&fileIn, iniFile.c_str(), L"r");
    if (errIn) { return; }
    std::wstring str;
    wchar_t ch= L' ', end = L'\0';
    while (ch != end)
    {
        fread(&ch, sizeof(wchar_t), 1, fileIn);
        str.push_back(ch);
    }
    datFile = str;  
    fclose(fileIn);
}
