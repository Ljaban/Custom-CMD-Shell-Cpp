# Custom-CMD-Shell-Cpp
Mini C++ shell developed for practicing OOP concepts, file operations and parsing.

## 📌 Overview
Mini C++ Shell is a custom command-line interpreter that simulates Unix-like CLI behavior.  
It supports execution of built-in commands, file system manipulation, input/output redirection, and piping between commands.  
The project is designed with modular and object-oriented principles, focusing on parsing, file handling, and execution flow.

---

## 🎯 Project Goal (ETF OOP Project)
This project was developed as part of the *Object-Oriented Programming (OOP1)* course at **ETF Belgrade**.  
The main goal is to build a functional command interpreter that demonstrates:
- Object-oriented design
- Text parsing and tokenization
- File system operations
- Command execution and error handling
- Redirection and pipes
- Clean modular architecture

---

## ✅ Features
- Built-in shell prompt
- Fully supported command set
- Robust argument parsing
- Working **pipes** (`|`)
- Working **input/output redirection** (`>`, `>>`, `<`)
- Graceful error handling
- Modular OOP structure

---

## 🧰 Supported Commands
| Command | Description |
|---------|------------|
| `echo` | Prints text to output |
| `prompt` | Changes the shell prompt |
| `time` | Displays current system time |
| `date` | Displays current system date |
| `touch` | Creates a file if it does not exist |
| `truncate` | Empties a file’s content |
| `rm` | Removes a file |
| `wc` | Counts lines, words and characters |
| `tr` | Applies character translation rules |
| `head` | Prints the first N lines of a file |
| `batch` | Executes commands from a script file |

---

## ⛓️ Pipes & Redirection
| Feature | Example |
|---------|---------|
| Pipe (`\|`) | `echo hello \| wc` |
| Output redirection (`>`) | `echo test > file.txt` |
| Append redirection (`>>`) | `echo more >> file.txt` |
| Input redirection (`<`) | `wc < file.txt` |

---

