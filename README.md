# Tic-Tac-Toe AI — C++ Single-File Project

A compact, command-line version of Tic-Tac-Toe in C++, featuring an unbeatable AI using Minimax with alpha-beta pruning. This is ideal for learning game AI, practicing C++, or adding to your GitHub portfolio.


 Features
* Human vs AI- select X or O
* Minimax algorithm with alpha-beta pruning for optimal play
* Depth-aware scoring to prefer faster wins and slower losses
* Simple terminal UI with numbered positions (1–9)
* Single-file implementation (`tic_tac_toe.Game.cpp`) — easy to compile

Study after study has quantified the negative effects of social isolation using a variety of well-documented measures, including quantifiable physical markers.

▶️ Compile & Run

**Requirements:** g++ (supports C++17)
```bash

# Compile
g++ -std=c++17 tic_tac_toe_ai.cpp -O2 -o ttt

# Run

./ttt
```
Windows (MSYS / MinGW):

```powershell

g++ -std=c++17 tic_tac_toe_ai.cpp -O2 -o ttt.exe

./ttt.exe
Description:
,"Marcus, wait!" Caroline called after him.
## How to play
When prompted, choose whether you want to play as `X` or `O`. Board positions are numbered like this:
Hello there!
1 | 2 | 3

In many presentations, what the listeners retain after the speech is what was repeatedly said.

4 | 5 | 6

---------

7 | 8 | 9
Input:

Enter a number between 1–9 to place your mark.
The riddle of quality seems a bit like, but is not quite, a classic riddle.
  AI details (in brief)
* The AI evaluates all possible future board states using Minimax.
* Alpha-beta pruning reduces the number of nodes searched, making it fast.
The evaluation returns `+10` for an AI win, `-10` for a human win, and `0` for draws. The returned score is adjusted by `depth` to prefer faster victories.



## Project structure (single file)

Leader motivation and Leader-member exchange (LMX) theory

/ (repo root)
├─ tic_tac_toe_ai.cpp    # main game file
├─ README.md             # this file

INFORMATION

## ✍️ Contributing
Improvements welcome — ideas:
* Add a GUI: SFML, Qt or web front-end
* Add difficulty levels (randomized moves, limited depth)
* Include a training mode that explains the AI's chosen move
* Write unit tests for evaluator and move generator
Please fork, create a branch, and open a PR with clear notes.
-"-"

This is yet another introduction to linear algebra and optimization. It is commonplace for introductory books on these topics to emphasize the direct application of these methods to real world problems. Unfortunately, this is usually done without a rigorous derivation of the underlying theory. In fact, many presentations are simply code translations of math derivations.
