# VirtuFS 🗂️ - A Virtual File System Simulator

VirtuFS is a **file system simulator** that mimics core command-line operations (`mkdir`, `ls`, `cd`, `rm`, etc.) using a **Node.js-powered frontend** and a **C++ backend**. This project simulates the functionality of a Unix-like shell in a controlled environment.

---

## 🚀 Features

- 📁 Create folders and files (`mkdir`, `touch`)
- 🧭 Navigate with `cd`, `ls`, and path handling
- 🧹 Delete files and folders with `rm`
- 🔄 Inter-process communication via text files
- ⚙️ Backend logic powered by C++ for speed and structure
- 🌐 Frontend in HTML, CSS, and JS for interaction

---

## 🧠 Tech Stack

| Layer        | Technology             |
| ------------ | ---------------------- |
| 🧑 UI        | HTML + CSS             |
| 🧠 Logic     | JavaScript (Node.js)   |
| 🧱 Core      | C++ (OOP, File I/O)    |
| 📦 Interface | input.txt / output.txt |

---

## 🛠️ How It Works

1. User enters commands via the frontend UI.
2. JavaScript writes commands to `input.txt`.
3. Node.js triggers `fs.exe` (C++ backend executable).
4. Backend reads the command, simulates the operation.
5. Result is written to `output.txt` and shown in the UI.

---

## 📂 Project Structure

VirtuFS/
│
├── index.html # Frontend UI
├── styles.css # UI styling
├── main.js # JS logic & file bridge
│
├── backend/
│ ├── FileSystem.cpp # Core logic (class-based)
│ ├── FileSystem.h
│ ├── main.cpp # Entry point for backend
│ ├── input.txt
│ ├── output.txt
│ └── fs.exe # Compiled binary
│
├── package.json
└── README.md

---

## 🧪 Sample Commands

mkdir projects
cd projects
touch index.txt
ls
rm index.txt
cd ..

---

## 📦 Setup & Run

1. Clone the repo:
   ```bash
   git clone https://github.com/yuvraj613/virtuFS.git
   cd virtuFS
   ```
2. Run frontend (open index.html in browser)

3. Compile backend (if not already done):

   g++ backend/\*.cpp -o backend/fs.exe
   
   Start interacting via frontend!
