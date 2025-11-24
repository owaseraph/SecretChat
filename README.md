# 🔒 SecureChat - Encryption Tool 💬

A lightweight C++ tool that allows you to encrypt and decrypt messages for secure communication over any chat application.


## ✨ Features

 * **🛠️ Custom Encryption:** Uses a custom XOR stream cipher with key rotation and Base64 encoding.
 * **📋 Clipboard Integration:** Automatically copies encrypted messages to your clipboard for quick pasting.
 * **👻 Zero-Trace:** No text saved to disk; everything happens in memory.
 * **💻 Cross-Platform:** Runs on Windows, Linux, and macOS.

## 🏗️ Build Instructions

 ### Prerequisites
* C++ Compiler (MinGW, MSVC, Clang)
* CMake (Version 3.10 or higher)

 ### Compilation

1. Clone the repository
```bash
git clone https://github.com/owaseraph/SecretChat.git
```

2. Create build directory
```bash
mkdir build
cd build
```

3. Compile with CMake
```bash
cmake ..
cmake --build .
```

4. Run the executable
```bash
./Debug/SecureChat.exe
```

## 🚀 Usage
1. Run the application
2. Enter a **Shared Password 🔑** (must be the same as your recipient)
3. **📤 To Send (Encrypt)**
    * Select Option `1`.
    * Type your message.
    * The tool will encrypt it and **automatically copy the result to your clipboard**.
    * Paste `CTRL+V` it into your app.
4. **📥 To Receive (Decrypt)**
    * Select Option `2`.
    * Paste the encrypted code into the terminal.
    * The tool will decrypt it and **show it into the terminal**.