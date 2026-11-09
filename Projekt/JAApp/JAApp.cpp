#include <iostream>
#include <windows.h>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <filesystem>
#include <istream>


using namespace std;
/*using MyProc1CFunc = std::uint64_t(*)(std::uint64_t, std::uint64_t);

auto MyProc1C = reinterpret_cast<MyProc1CFunc>(
    GetProcAddress(hDll, "MyProc1C")
    );

if (!MyProc1C)
{
    std::cerr << "Nie znaleziono MyProc1C. Blad: "
        << GetLastError() << '\n';
    FreeLibrary(hDll);
    return 2;
}

a = MyProc1C(x, y);

std::cout << "Wynik MyProc1C: " << a << '\n';

*/


int main(int argc, char* argv[])
{
    using MyProc1Func = std::uint64_t(*)(std::uint64_t, std::uint64_t);

   

   
        HMODULE hDll = LoadLibraryW(L"JADll.dll");

        if (!hDll)
        {
            std::cerr << "Blad LoadLibraryW: "
                << GetLastError() << '\n';
            return 1;
        }

        auto MyProc1 = reinterpret_cast<MyProc1Func>(
            GetProcAddress(hDll, "MyProc1")
            );

        if (!MyProc1)
        {
            std::cerr << "Nie znaleziono MyProc1. Blad: "
                << GetLastError() << '\n';
            FreeLibrary(hDll);
            return 2;
        }

       


        int x = 3, y = 4, z = 0, a=0;

        z = MyProc1(x, y);
      

        std::cout << "Wynik MyProc1: " << z << '\n';
        

        FreeLibrary(hDll);
     
    
        // ODCZYTYWANIE DANYCH
       
       
        fstream p_we("C:\\Users\\kszro\\source\\repos\\JAApp\\JAApp\\probka.wav", ios_base::binary | ios_base::in);
        

        
        struct naglowek {
            //riff chunk
            uint8_t riff[4];
            uint32_t chunkRSize;
            uint8_t wave[4];

            //fmt chunk
            uint8_t fmt[4];
            uint32_t chunkFSize;
            uint16_t FTag;
            uint16_t NumChannels;
            uint32_t SampleRate;
            uint32_t ByteRate;
            uint16_t BlockAlign;
            uint16_t BitsPerSample;

            //data chunk
            uint8_t chunkDId[4];
            uint32_t chunkDSize;
            


        }naglowek;

        
       
        
        /*if (p_we)
        {
            cout << "udalo sie otworzyc plik" << endl;
        }
        else
        {
            cout << "nie udalo sie otworzyc pliku" << endl;
        }*/

        // odczytywanie chunku riff z pliku
        p_we.read(reinterpret_cast<char*>(& naglowek.riff[0]), 4);
        p_we.read(reinterpret_cast<char*>(&naglowek.chunkRSize), sizeof(naglowek.chunkRSize));
        p_we.read(reinterpret_cast<char*>(&naglowek.wave[0]), 4);
        // odczytywanie chunku formatu z pliku
        p_we.read(reinterpret_cast<char*>(&naglowek.fmt[0]), 4);
        p_we.read(reinterpret_cast<char*>(&naglowek.chunkFSize), sizeof(naglowek.chunkFSize));
        p_we.read(reinterpret_cast<char*>(&naglowek.FTag), sizeof(naglowek.FTag));
        p_we.read(reinterpret_cast<char*>(&naglowek.NumChannels), sizeof(naglowek.NumChannels));
        p_we.read(reinterpret_cast<char*>(&naglowek.SampleRate), sizeof(naglowek.SampleRate));
        p_we.read(reinterpret_cast<char*>(&naglowek.ByteRate), sizeof(naglowek.ByteRate));
        p_we.read(reinterpret_cast<char*>(&naglowek.BlockAlign), sizeof(naglowek.BlockAlign));
        p_we.read(reinterpret_cast<char*>(&naglowek.BitsPerSample), sizeof(naglowek.BitsPerSample));
        // odzcytywanie chunku danych z pliku
        p_we.read(reinterpret_cast<char*>(&naglowek.chunkDId[0]), 4);
        p_we.read(reinterpret_cast<char*>(&naglowek.chunkDSize), sizeof(naglowek.chunkDSize));


       
       

        // odczytywanie danych probki do wektora
        vector<int16_t> data;
        int32_t d_size = naglowek.chunkDSize / 2;
        data.resize(d_size);
        p_we.read(reinterpret_cast<char*>(data.data()), naglowek.chunkDSize);
       
      
       



          


           
      /*  for (int i = 0;i < 4;i++)
        {
            cout << naglowek_riff.riff[i] << endl;
        }*/

        
            //cout << naglowek_riff.chunkDSize << endl;
       
        /*for (int i = 0;i < 4;i++)
        {
            cout << naglowek_riff.wave[i] << endl;
        }*/

        /*for (int i = 0;i < 4;i++)
        {
            cout << naglowek_riff.fmt[i] << endl;
        }*/

        //cout << naglowek_riff.chunkDFSize << endl;
        //cout << naglowek_riff.FTag << endl;
        //cout << naglowek_riff.NumChannels << endl;
        //cout << naglowek_riff.SampleRate<< endl;
        //cout << naglowek_riff.ByteRate << endl;
        //cout << naglowek_riff.BlockAlign << endl;

        //cout << naglowek_riff.BitsPerSample << endl;
        
       /* for (int i = 0;i < 4;i++)
        {
            cout << naglowek_riff.chunkDId[i] << endl;
        }*/

        //cout << naglowek_riff.chunkDSize << endl;
        
        //cout << p_we.tellg() << endl;


       
        for (int i = 10000;i <100000;i++)
        {
            cout << data[i] << endl;
        }
            
        return 0;
}


