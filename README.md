# Game-Boggle

Boggle for OS/2, version 1.1

Boggle is a word game played on a 4×4 board of shuffled dice.  Find as
many words as possible by moving through adjacent dice before the timer
runs out.  A native OS/2 Presentation Manager application.

This release is a from-scratch plain C port of the original 1996 IBM
Open Class Boggle game; it needs no C++ class libraries.

![Boggle](/doc/Boggle.png)

* Version:  1.1
* License:  GNU GPL v2 (see `doc\LICENSE.txt`)
* Source:   `src\` (C, PM)
* Original: Bou Software Systems / David Boudah, 1996

## BUILD

Open Watcom is auto-detected (C:\WATCOM or D:\WATCOM).  Run on OS/2:

    compile-wat.cmd

This runs `wmake` on `makefile.wat` and produces under `bin\`:

    BOGGLE.EXE            PM application (resources bound at link time)
    bin\help\boggle_*.hlp help files compiled from help\*.ipf via wipfc

Copy the `data\`, `sound\` and `help\` directories next to `BOGGLE.EXE`
before running.

## RUNTIME DIRECTORY LAYOUT

```
BOGGLE.EXE
data\
    words           English dictionary
    index           dictionary index
    BOGGLE.CFG      saved settings (auto-created)
sound\
    *.wav           seven sound effects
help\
    boggle_en.hlp   English help (and ES, NL, DE, FR, IT)
```

All paths are resolved at run time relative to `BOGGLE.EXE` via
`DosQueryModuleName`; the current working directory is not used.

## HOW TO PLAY

1. **Game → New Game** (Ctrl+N) shuffles the board and starts the timer.
2. **Left-click** (or click-drag) letters to build a word in the
   "Word in Progress" field.
3. **Submit** the word with the **">" button** beside the field, or by
   pressing the **right mouse button** anywhere on the board.
4. The **"Timer: xx sec"** label counts down.  Game ends at zero.
5. After the game **Game → Find All Words** reveals every possible word.

## RELEASE 1.1 CHANGES

See `doc\Changelog.txt` for the full list.  Highlights:

**Port (2026-09-16)**
- Rewritten from IBM Open Class C++ to plain C / PM for Open Watcom.
- Sound via MCI waveaudio string interface.
- Six-language UI (English, Espanol, Nederlands, Deutsch, Francais,
  Italiano); selection persists across sessions.
- Options – Settings dialog (timer length, sound toggle).
- Keyboard accelerators Ctrl+N/P/Q/X/B/F, About dialog, BLDLEVEL
  signature, application icon.

**UI improvements (2026-09-22)**
- Window enlarged to 880×660; dark gray background, white labels.
- Letter dice with 3D raised-bevel effect and Swiss Bold Italic font.
- OS/2 system font applied automatically to all controls.
- Timer label shows remaining seconds ("Timer: xx sec").
- Submit button (">" square) added next to the Word in Progress field.

**Help system (2026-09-22)**
- IPF help in all six UI languages, compiled with `wipfc`.
- **F1** / Help → Help Contents opens the help viewer in the active
  language; switches automatically on language change.

**File layout (2026-09-22)**
- Sound files moved to `sound\`, dictionary and config to `data\`,
  help files to `help\` — all located relative to `BOGGLE.EXE`.

**Note on dictionary:** word validation always uses the English
dictionary regardless of the active UI language.  Language-specific
word lists are a future enhancement.

## AUTHORS

* David Boudah (1996 original)
* OS2World (2026 OS/2 port)
