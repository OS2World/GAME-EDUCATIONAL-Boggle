BOGGLE for OS/2, version 1.1
============================

OVERVIEW
--------
Boggle is a word game based on the classic Boggle board game.  Sixteen
dice are shuffled and laid out on a 4x4 board.  Your job is to find as
many words as possible in the time allowed.  Words are made by moving
from die to adjacent die (including diagonals) without reusing a die
within one word.

This release is a from-scratch plain C / Presentation Manager port of
the original 1996 IBM* Open Class Boggle game.  It runs as a native
OS/2 PM application and needs no C++ class libraries.

HOW TO PLAY
-----------
1. Start a new game (Game - New Game or Ctrl+N).  The dice are
   shuffled and a new 4x4 board appears.

2. Click on the first die of a word, then drag or click through each
   adjacent die in order (horizontal, vertical, or diagonal).  The
   letters you select appear in the "Word in Progress" field.

3. Submit the word by doing one of:
   - Click the ">" button to the right of the Word in Progress field.
   - Click the right mouse button anywhere on the board.
   - Good words are added to the word list and score points.
   - Words not in the dictionary, shorter than three letters, or
     already found are rejected with a warning sound.

4. Watch the "Timer: xx sec" countdown at the bottom.  The game ends
   when the timer reaches zero.

5. When the game is over you can use Game - Find All Words to have
   the program reveal every word that was possible on the board.

Scoring:
   3-4 letters:  1 point
   5 letters:    2 points
   6 letters:    3 points
   7 letters:    5 points
   8+ letters:  11 points

Note: the dictionary contains English words.  Word validation uses
English regardless of the UI language selected.

CONTROLS
--------
Mouse
  Left button click / drag ........ select letters on the board
  Right button .................... submit the current word
  ">" button (next to WIP field) .. submit the current word

Keyboard
  F1 ............... open Help
  Ctrl+N ........... New Game
  Ctrl+P ........... Pause / Resume
  Ctrl+Q ........... Quit current game
  Ctrl+X ........... Exit Boggle
  Ctrl+B ........... Toggle Background Run
  Ctrl+F ........... Toggle Frame Controls

Menu
  Game - New Game .............. start a new game
  Game - Find All Words ........ reveal all words on the board
  Game - Pause Game ............ pause / resume the clock
  Game - Quit Game ............. end the current game
  Game - Exit .................. quit Boggle
  Options - Detail ............. high / medium / low drawing detail
  Options - Language ........... English, Espanol, Nederlands,
                                 Deutsch, Francais, Italiano
  Options - Save settings on exit
  Options - Background Run ..... keep running when focus is lost
  Options - Frame Controls ..... show/hide title bar and menu bar
  Options - Settings ........... timer length and sound on/off
  Help - Help Contents ......... open the help viewer (F1)
  Help - About Boggle .......... version and copyright

OPTIONS - SETTINGS
------------------
Timer Length (secs): sets the duration of one timer tick in tenths of
a second.  The game always runs for 100 ticks; changing this value
makes each tick shorter (faster game) or longer (slower game).

Sound: enables or disables all sound effects.

DIRECTORY LAYOUT (next to BOGGLE.EXE)
--------------------------------------
BOGGLE.EXE          the program (PM application)

data\
  words             English dictionary (one word per line)
  index             dictionary search index
  BOGGLE.CFG        saved settings (created automatically)

sound\
  badword.wav       sound: rejected or too-short word
  boing.wav         sound: word submitted
  excelnt.wav       sound: excellent (long word)
  gameover.wav      sound: game over
  goodword.wav      sound: valid word accepted
  tick.wav          sound: timer tick
  usedword.wav      sound: word already in the list

help\
  boggle_en.hlp     English help
  boggle_es.hlp     Spanish help
  boggle_nl.hlp     Dutch help
  boggle_de.hlp     German help
  boggle_fr.hlp     French help
  boggle_it.hlp     Italian help

doc\
  Readme.txt        this file
  Changelog.txt     version history
  LICENSE.txt       GNU General Public License version 2

All paths are resolved relative to BOGGLE.EXE at run time.  The game
does not depend on the current working directory.

BUILDING FROM SOURCE
--------------------
Open Watcom is required (C:\WATCOM or D:\WATCOM).  Run on OS/2:

  compile-wat.cmd

This invokes wmake on makefile.wat and produces under bin\:
  BOGGLE.EXE, bin\help\boggle_*.hlp

Copy the data\, sound\ and help\ trees next to BOGGLE.EXE to run.

DISCLAIMER
----------
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

AUTHOR
------
Original game (1996):  Bou Software Systems, David Boudah.
OS/2 port (2026):      OS2World, under the GNU General Public License.
