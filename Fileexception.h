#pragma once
using namespace System;
using namespace System::IO;
public ref class Fileexception : public System::Exception
{
private:
    String^ filename1;

public:
    Fileexception(String^ message, String^ filename) : System::Exception(message) {
        filename1 = filename;
    }

    property String^ Filename {
        String^ get() {
            return filename1;
        }
    }

    // Функция для проверки существования файла
    static void checkfileexists(String^ filename) {
        if (!File::Exists(filename)) {
            throw gcnew Fileexception("Файл не найден!", filename);
        }
    }
};

