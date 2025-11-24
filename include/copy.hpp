#ifndef COPY_HPP
#define COPY_HPP

#include <windows.h>
#include <iostream>


void copyToClipboard(const std::string &text){
    #ifdef _WIN32
        // Windows Implementation
        if (OpenClipboard(nullptr)) {
            EmptyClipboard();
            HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
            if (hg) {
                memcpy(GlobalLock(hg), text.c_str(), text.size() + 1);
                GlobalUnlock(hg);
                SetClipboardData(CF_TEXT, hg);
            }
            CloseClipboard();
            std::cout << "   (Copied to clipboard!)\n";
        } else {
            std::cout << "   (Failed to access clipboard)\n";
        }
    #elif __APPLE__
        // macOS Implementation
        FILE* pipe = popen("pbcopy", "w");
        if (pipe) {
            fwrite(text.c_str(), 1, text.size(), pipe);
            pclose(pipe);
            std::cout << "   (Copied to clipboard!)\n";
        }
    #else 
        // Linux Implementation (try xclip or xsel)
        // You usually need to install xclip: sudo apt install xclip
        FILE* pipe = popen("xclip -selection clipboard", "w");
        if (pipe) {
            fwrite(text.c_str(), 1, text.size(), pipe);
            pclose(pipe);
            std::cout << "   (Copied to clipboard!)\n";
        } else {
            std::cout << "   (Clipboard requires 'xclip' package on Linux)\n";
        }
    #endif
}

#endif //COPY_HPP