# Toolchain & Development Environment

Before you can run your first C program, you need three things:
a **compiler**, a **text editor**, and a **terminal**.

> **In plain words: compiler**
> A compiler is a program that reads your code and translates it into a language the
> computer can actually run. Think of it like a human translator who reads a document
> in English and produces a version in Japanese. Your C source code is the English;
> the compiled program is the Japanese. Without the translation, the computer cannot
> understand your instructions.

> **In plain words: text editor**
> A text editor is the tool you use to write and save your code files. It is similar
> to a word processor (like Microsoft Word), but it saves files as plain text with
> no hidden formatting. You cannot use Word or Google Docs to write C code because
> they add invisible characters that the compiler cannot understand. A good code
> editor also colours your code (syntax highlighting) and warns you about mistakes
> before you even compile.

> **In plain words: terminal**
> A terminal (also called a command prompt or shell) is a text window where you
> type commands. Instead of clicking buttons, you type `gcc hello.c -o hello` and
> press Enter. The computer runs the command and shows you the result as text.
> Compiling, running your program, and checking output all happen in the terminal.

---

## Option A: Online Compiler (No Install Required)

If you are in the first session and your machine is not set up yet, use a browser-based compiler:

| Site | URL |
|------|-----|
| OnlineGDB | <https://www.onlinegdb.com/online_c_compiler> |
| Programiz | <https://www.programiz.com/c-programming/online-compiler/> |

**How to use OnlineGDB in three steps:**
1. Open the URL in your browser.
2. Click the language selector (top-left) and choose **C**.
3. Type your code in the editor pane, then click the green **Run** button.
   Your output appears in the pane at the bottom.

This is a fallback; you will set up a local environment during Lab 01.

---

## Option B: Local Setup

A local setup runs entirely on your computer and works without an internet connection.
Follow the three steps below in order.

### Step 1: Install a C Compiler

The compiler turns your `.c` file into a program you can run.
Follow the instructions for your operating system.

---

**Linux (Ubuntu or Debian)**

1. Open a terminal (search for "Terminal" in your applications).
2. Type this command exactly and press Enter:
   ```bash
   sudo apt update && sudo apt install build-essential
   ```
   You will be asked for your password. Type it (nothing appears as you type; that is normal) and press Enter.
3. When it finishes, verify the installation:
   ```bash
   gcc --version
   ```
   You should see something like `gcc (Ubuntu 11.4.0) 11.4.0`. If you do, the compiler is ready.

---

**macOS**

1. Open a terminal (search for "Terminal" in Spotlight with ⌘ + Space).
2. Type this command and press Enter:
   ```bash
   xcode-select --install
   ```
   A pop-up window appears asking you to install the command-line tools. Click **Install** and wait (this may take a few minutes).
3. Verify:
   ```bash
   gcc --version
   ```
   You should see output mentioning `Apple clang`. That is fine; it behaves the same as `gcc` for this course.

---

**Windows**

Windows does not come with a C compiler. You have two options:

**Option W-1: WSL 2 (Recommended for Windows)**

WSL 2 runs a real Linux environment inside Windows. It is the closest thing to a Linux terminal.

1. Open **PowerShell** as Administrator: press the Windows key, type `powershell`, right-click, and choose "Run as Administrator".
2. Type this command and press Enter:
   ```
   wsl --install
   ```
3. Restart your computer when prompted.
4. After restart, open **Ubuntu** from the Start menu. The first time it runs, it will ask you to create a username and password.
5. In the Ubuntu terminal, follow the **Linux** steps above to install `gcc`.

**Option W-2: MinGW-w64 (native Windows, no Linux layer)**

1. Go to <https://winlibs.com/> and download the latest GCC release for Windows (look for a `.zip` file for your architecture, usually 64-bit).
2. Extract the archive. Move the extracted folder (e.g., `mingw64`) to `C:\mingw64`.
3. Add the compiler to your PATH:
   - Press Windows + R, type `sysdm.cpl`, press Enter.
   - Click **Advanced** → **Environment Variables**.
   - Under "System variables", find `Path`, click **Edit**, then **New**, and type `C:\mingw64\bin`. Click OK.
4. Open a new Command Prompt and verify:
   ```
   gcc --version
   ```

> **In plain words: PATH**
> PATH is a list of folders the computer searches through when you type a command.
> When you type `gcc`, the terminal looks through each folder in PATH and runs the
> first `gcc` it finds. Adding `C:\mingw64\bin` to PATH tells Windows where to find
> the compiler. Without this, the terminal would say `'gcc' is not recognized as a
> command`.

---

### Step 2: Install VS Code (Recommended Editor)

**Visual Studio Code (VS Code)** is a free, lightweight code editor from Microsoft.
It works on Windows, macOS, and Linux. For this course it is the recommended choice
because it has a built-in terminal, instant error highlighting, and a free C extension.

> **Why VS Code?**
> Think of VS Code as a specialised workshop for writing code. It has a file
> browser on the left, an editor in the centre, and a terminal at the bottom.
> You can write, compile, and run your program without leaving the window.

**Install VS Code: step by step:**

1. Go to <https://code.visualstudio.com/> and click the large **Download** button.
   Download the installer for your operating system.
2. Run the installer and follow the prompts. Accept the licence, choose the default install location, and click **Install**.
   - On Windows: check the boxes "Add to PATH" and "Add 'Open with Code' to context menu" when offered.
3. Open VS Code after the installer finishes.

**Install the C/C++ Extension Pack:**

The base VS Code cannot compile C. The extension pack adds syntax highlighting,
error squiggles, and awareness of C-specific keywords.

1. In VS Code, click the **Extensions** icon in the left sidebar (it looks like four squares).
2. In the search box that appears, type: `C/C++ Extension Pack`.
3. Click the result published by **Microsoft** and click **Install**.
4. Wait for the installation to complete (a few seconds to a minute).

---

### Step 3: Your First Program in VS Code

Follow these steps to write, compile, and run `hello.c` from inside VS Code.

**Create your working folder:**

1. On your computer, create a folder called `cprog-labs` somewhere easy to find
   (for example, inside your Documents folder).
2. In VS Code, go to **File → Open Folder**, navigate to `cprog-labs`, and click **Select Folder**.

**Write hello.c:**

3. In VS Code's Explorer panel (left sidebar), click the **New File** icon and name the file `hello.c`.
4. Type this code into the file exactly as written:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

5. Save the file: **Ctrl + S** (Windows/Linux) or **Cmd + S** (macOS).

**Open the integrated terminal:**

6. Go to **Terminal → New Terminal** (or press `` Ctrl + ` ``).
   A terminal pane opens at the bottom of the VS Code window.
   You should see a prompt showing your `cprog-labs` folder path.

**Compile:**

7. In the terminal, type this command and press Enter:
   ```bash
   gcc hello.c -o hello -Wall
   ```
   If there are no errors, the terminal shows a new prompt with no output. That is correct.
   Silence means success at compile time.

**Run:**

8. Type the run command for your operating system and press Enter:
   ```bash
   ./hello            # Linux, macOS, or WSL 2
   hello.exe          # Windows MinGW (native)
   ```

**Expected output:**
```
Hello, world!
```

If you see that line, your toolchain is fully working.

> **Why `./hello` and not just `hello`?**
> The `.` means "the current folder". Without it, the terminal would search
> through PATH to find a program called `hello`, not find one, and give an error.
> Writing `./hello` tells the terminal exactly where to look.

---

### Alternatives to VS Code

| Editor | Best for | Notes |
|--------|----------|-------|
| **Code::Blocks** | Windows beginners who want one installer | Bundles a compiler and editor together. Download from <https://www.codeblocks.org/>; choose the version labelled "mingw-setup.exe" to get a compiler included. No separate PATH setup needed. |
| OnlineGDB / Programiz | Fallback when nothing is installed | Already covered in Option A above. |
| Vim / Neovim | Experienced users who prefer keyboard-only | Powerful, but the learning curve is steep for a complete beginner. |

---

## Compiler Flags We Use in This Course

```bash
gcc file.c -o file -Wall -Wextra -std=c99
```

| Flag | Meaning |
|------|---------|
| `-Wall` | Enable common warnings |
| `-Wextra` | Enable extra warnings |
| `-std=c99` | Use C99 standard (what this course targets) |

Always compile with `-Wall -Wextra`. Warnings are not errors, but they almost always
point to a real problem. Fix every warning before moving on.

---

## Verify Checklist

Before you come to Lab 01, confirm all four items:

- [ ] `gcc --version` prints a version number in the terminal
- [ ] `hello.c` compiles with `gcc hello.c -o hello -Wall` and shows no errors or warnings
- [ ] Running `./hello` (or `hello.exe`) prints `Hello, world!`
- [ ] VS Code opens `.c` files and shows the code in different colours (syntax highlighting)

Once all four boxes are checked, you are ready for Lab 01.
