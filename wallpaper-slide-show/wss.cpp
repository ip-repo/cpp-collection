#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>
#include <Windows.h>

// Function to change the wallpaper using SystemParametersInfoW
void changeWallpaper(const std::wstring& imagePath) {
    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)imagePath.c_str(), SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
    std::wcout << "Changed wallpaper to: " << imagePath << std::endl;
}

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <image_folder_path> <delay_ms:int> <repeat_count:int>" << std::endl;
        std::cout << "Example: programName C:\\Path\\To\\Images\\Folder\\ 1000 2" << std::endl;
        std::cout << "Example(Infinite): programName C:\\Path\\To\\Images\\Folder\\ 1000 -1" << std::endl;
        return 1;
    }

    // Extract command-line arguments
    const std::string imageFolderPath = argv[1];
    const int delayMs = std::stoi(argv[2]);
    int repeatCount = std::stoi(argv[3]);

    // Determine if infinite repetition is requested
    bool infiniteRepeat = false;
    if (repeatCount < 0) {
        infiniteRepeat = true;
        std::cout << "Images Folder Path: " << imageFolderPath << std::endl;
        std::cout << "Delay time between images: " << delayMs << " ms" << std::endl;
        std::cout << "Infinite repeat: on" << std::endl;
    } else {
        std::cout << "Images Folder Path: " << imageFolderPath << std::endl;
        std::cout << "Delay time between images: " << delayMs << " ms" << std::endl;
        std::cout << "Infinite repeat: off" << std::endl;
    }

    // Main loop for changing wallpapers
    while (infiniteRepeat || repeatCount > 0) {
        for (const auto& entry : std::filesystem::directory_iterator(imageFolderPath)) {
            if (entry.is_regular_file()) {
                const std::wstring imagePath = entry.path().wstring();
                changeWallpaper(imagePath);
                std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            }
        }
        if (!infiniteRepeat) {
            --repeatCount;
        }
    }

    return 0;
}
