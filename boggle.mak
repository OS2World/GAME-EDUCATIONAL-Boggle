# boggle.mak:
#
# Makefile for the boggle application

# tools and command lines
CPP       = icc
LINK      = icc
RC        = rc
RLINK     = rc

#CPPOPTS   = -C+ -Gm+ -Gd+ -N15 -Ti+ -O- -DIC_TRACE_DEVELOP -Wgen -W3 -Q+ /Fi /Si
CPPOPTS   = -C+ -Gm+ -Gd- -N15 -Oc+ -DIC_TRACE_DEVELOP -Wgen -W3 -Q+ /Fi /Si
#LINKOPTS  = /de /noi /align:4 /OPTF
LINKOPTS  =  /noi /align:4 /OPTF
RCOPTS    = -r

# targets
MAIN_TARGET = boggle.exe
MAP_NAME = boggle.map
OBJS = boggle.obj bogwin.obj board.obj square.obj wlist.obj timer.obj wip.obj score.obj dict.obj lastsq.obj random.obj dice.obj ammvehdr.obj options.obj sound.obj about.obj

LIBS = os2386.lib

.SUFFIXES : .cpp .rc .obj .exe .ipf .hlp


#
# implicit rules
#
{.}.dlg.res:
  $(RC) $(RCOPTS) .\$*.rc

{.}.rc.res:
  $(RC) $(RCOPTS) .\$*.rc

{.}.ipf.hlp:
  ipfc $*.ipf

{.}.cpp.obj:
  $(CPP) $(CPPOPTS) .\$*.cpp


#
# explicit rules
#

ALL : boggle.exe

boggle.obj : boggle.cpp bogwin.hpp

board.obj : board.cpp board.hpp

square.obj : square.cpp square.hpp

bogwin.obj : bogwin.cpp bogwin.hpp

wlist.obj : wlist.cpp wlist.hpp

timer.obj : timer.cpp timer.hpp

wip.obj : wip.cpp wip.hpp

score.obj : score.cpp score.hpp

dict.obj : dict.cpp dict.hpp

lastsq.obj : lastsq.cpp lastsq.hpp

random.obj : random.cpp random.hpp

dice.obj : dice.cpp dice.hpp

ammvehdr.obj : ammvehdr.cpp ammvehdr.hpp

options.obj : options.cpp aoptions.hpp

sound.obj : sound.cpp sound.hpp

about.obj : about.cpp about.hpp

menu.res : menu.rc about.dlg

boggle.exe : $(OBJS) boggle.def boggle.mak menu.res
    $(LINK) @<<
 /Q /Tdp /B"$(LINKOPTS)"
 /Fe"$(MAIN_TARGET)"
 $(OBJS)

 boggle.def
<<
    $(RLINK) $(RLINKOPTS) menu.res $*.exe


# $(LIBS) - before boggle.def
