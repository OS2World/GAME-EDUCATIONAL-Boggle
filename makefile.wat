#----------------------------------------------------------------------#
#  BOGGLE 1.1 - OS/2 port build (Open Watcom)                          #
#                                                                      #
#  Targets:                                                            #
#    all   -> BOGGLE.EXE (PM app, bound resources)                     #
#    app   -> BOGGLE.EXE only                                          #
#    stage -> host-runnable subset: OBJ + RES objects (no wlink)       #
#    clean -> remove everything under bin\                             #
#                                                                      #
#  Notes:                                                              #
#    - Run via compile-wat.cmd (sets WATCOM/INCLUDE/PATH).             #
#    - data\words + data\index: placed in a data\ subdirectory         #
#      next to BOGGLE.EXE.  sound\ holds the .wav files.               #
#      help\ holds the .hlp files.                                     #
#----------------------------------------------------------------------#

WATCOM    = $(%WATCOM)

!ifndef OS2TK
OS2TK     = c:\os2tk45
!endif

INC       = $(WATCOM)\h;$(WATCOM)\h\os2;src
CC        = wcc386
WLINK     = wlink
WRC       = wrc
WIPFC     = wipfc

OUT       = bin
HELPDIR   = $(OUT)\help

CFLAGS    = -bt=os2 -mf -5 -fpi -Oaxt -W3 -ze -d0 -i=src
LFLAGS    = system os2v2 pm option heapsize=4096 option stack=65536 option map=$(OUT)\BOGGLE.map library $(OS2TK)\lib\mmpm2.lib
RCFLAGS   = -r -bt=os2
BINDWF    = -q -bt=os2

DATA      = words index badword.wav blank.bmp boing.wav excelnt.wav gameover.wav goodword.wav tick.wav usedword.wav BOGGLE.ICO

HLP_FILES = $(HELPDIR)\boggle_en.hlp &
            $(HELPDIR)\boggle_es.hlp &
            $(HELPDIR)\boggle_nl.hlp &
            $(HELPDIR)\boggle_de.hlp &
            $(HELPDIR)\boggle_fr.hlp &
            $(HELPDIR)\boggle_it.hlp

TARGETS   = $(OUT)\BOGGLE.EXE $(HLP_FILES)

all       : $(TARGETS)

$(OUT)    :
	@if not exist $(OUT) mkdir $(OUT)

$(HELPDIR) : $(OUT)
	@if not exist $(HELPDIR) mkdir $(HELPDIR)

#------------------------------------------------------------ help files
$(HELPDIR)\boggle_en.hlp : help\boggle_en.ipf $(HELPDIR)
	$(WIPFC) -o $@ help\boggle_en.ipf

$(HELPDIR)\boggle_es.hlp : help\boggle_es.ipf $(HELPDIR)
	$(WIPFC) -o $@ help\boggle_es.ipf

$(HELPDIR)\boggle_nl.hlp : help\boggle_nl.ipf $(HELPDIR)
	$(WIPFC) -o $@ help\boggle_nl.ipf

$(HELPDIR)\boggle_de.hlp : help\boggle_de.ipf $(HELPDIR)
	$(WIPFC) -o $@ help\boggle_de.ipf

$(HELPDIR)\boggle_fr.hlp : help\boggle_fr.ipf $(HELPDIR)
	$(WIPFC) -o $@ help\boggle_fr.ipf

$(HELPDIR)\boggle_it.hlp : help\boggle_it.ipf $(HELPDIR)
	$(WIPFC) -o $@ help\boggle_it.ipf

#------------------------------------------------------------ objects
$(OUT)\BOGGLE.OBJ : src\BOGGLE.C src\BOGGLE.H src\LANG.H src\DICT.H src\BOARD.H src\SOUND.H $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\BOGGLE.C

$(OUT)\DICT.OBJ : src\DICT.C src\DICT.H src\BOGGLE.H $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\DICT.C

$(OUT)\BOARD.OBJ : src\BOARD.C src\BOARD.H src\DICT.H src\BOGGLE.H $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\BOARD.C

$(OUT)\SOUND.OBJ : src\SOUND.C src\SOUND.H src\BOGGLE.H $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\SOUND.C

$(OUT)\BOGGLE.RES : src\BOGGLE.RC src\BOGGLE.H src\BOGGLE.ICO $(OUT)
	$(WRC) $(RCFLAGS) -fo=$@ -i=src src\BOGGLE.RC

#-------------------------------------------------------------- exe
$(OUT)\BOGGLE.EXE : $(OUT)\BOGGLE.OBJ $(OUT)\DICT.OBJ $(OUT)\BOARD.OBJ $(OUT)\SOUND.OBJ $(OUT)\BOGGLE.RES
	$(WLINK) $(LFLAGS) name $(OUT)\BOGGLE.EXE file $(OUT)\BOGGLE.OBJ, $(OUT)\DICT.OBJ, $(OUT)\BOARD.OBJ, $(OUT)\SOUND.OBJ
	$(WRC) $(BINDWF) -fe=$@ $(OUT)\BOGGLE.RES $@

#-------------------------------------------------------------- misc
app       : $(OUT)\BOGGLE.EXE

# stage - host-runnable subset: everything except the final wlink
# format and the -fe bind (those need the OS/2 build).
stage     : $(OUT)\BOGGLE.OBJ $(OUT)\DICT.OBJ $(OUT)\BOARD.OBJ $(OUT)\SOUND.OBJ $(OUT)\BOGGLE.RES

clean     :
	@if exist bin\BOGGLE.EXE del bin\BOGGLE.EXE >nul
	@if exist bin\BOGGLE.RES del bin\BOGGLE.RES >nul
	@if exist bin\BOGGLE.OBJ del bin\BOGGLE.OBJ >nul
	@if exist bin\DICT.OBJ del bin\DICT.OBJ >nul
	@if exist bin\BOARD.OBJ del bin\BOARD.OBJ >nul
	@if exist bin\SOUND.OBJ del bin\SOUND.OBJ >nul
	@if exist bin\BOGGLE.MAP del bin\BOGGLE.MAP >nul
	@if exist bin\help\boggle_en.hlp del bin\help\boggle_en.hlp >nul
	@if exist bin\help\boggle_es.hlp del bin\help\boggle_es.hlp >nul
	@if exist bin\help\boggle_nl.hlp del bin\help\boggle_nl.hlp >nul
	@if exist bin\help\boggle_de.hlp del bin\help\boggle_de.hlp >nul
	@if exist bin\help\boggle_fr.hlp del bin\help\boggle_fr.hlp >nul
	@if exist bin\help\boggle_it.hlp del bin\help\boggle_it.hlp >nul
	@if exist bin\help rd bin\help >nul
	@if exist bin rd bin >nul
