:userdoc.
:docprof toc=123456.
:title.Boggle Spiel Hilfe

:h1 id=0 res=1.Einfuehrung
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Einfuehrung
.br
:ehp7.Das Boggle Computerspiel basiert auf dem gleichnamigen Brettspiel&per.
Das Spiel besteht aus einem Spielfeld, 16 Wuerfeln und einem Timer&per.
Das Ziel des Spiels ist es, die Wuerfel zu wuerfen und so viele Woerter
wie moeglich aus den Buchstaben auf den Wuerfeloberflaechen zu bilden&per.
Die Woerter muessen mindestens drei Buchstaben lang sein und die verwendeten
Buchstaben muessen nebeneinander liegen&per.
:p.Das Computerspiel verfuegt ueber ein eingebautes Woerterbuch mit 29956
Woertern&per. Nachdem das Spiel beendet ist, koennen Sie
:link reftype=hd refid=1.Optionen:elink./Alle Finden waehlen, und der Computer listet jedes Wort
auf, das er in diesem Woerterbuch gefunden hat&per.
:p.:link reftype=hd refid=1.Ton :elink.wird ueber die OS/2-Multimediaklassen bereitgestellt&per.
:p.:hp7.Punkte
.br
:ehp7.Die Punktzahl basiert auf der Anzahl der Buchstaben im gebildeten Wort&colon.
:p.   2 Buchstaben   = 1 Punkt
.br
   3 Buchstaben   = 1 Punkt
.br
   4 Buchstaben   = 1 Punkt
.br
   5 Buchstaben   = 2 Punkte
.br
   6 Buchstaben   = 3 Punkte
.br
   7 Buchstaben   = 5 Punkte
:p.   Mehr als 7 Buchstaben = 11 Punkte&per.
.br

:h1 id=1 res=2.Das Spiel Spielen
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Spielbeginn
.br
:ehp7.Um das Spiel zu starten, klicken Sie auf Spiel/Neues Spiel&per. Der Timer
beginnt den Fortschrittsanzeiger am unteren Bildschirmrand gemaess dem in
den Optionen/Einstellungen festgelegten Timer-Intervall zu verschieben&per.
Der Standardwert betraegt 1&per.5 Sekunden pro Timer-Tick&per.
:p.Klicken Sie mit der linken Maustaste auf einen Buchstaben und der
Buchstabe wird markiert und in das Texteingabefeld fuer das aktuelle Wort
kopiert&per. Klicken Sie auf benachbarte Buchstaben, um Woerter zu bilden&per.
Wenn ein vollstaendiges Wort gebildet wurde, klicken Sie mit der rechten
Maustaste&per.
:p.:hp7.Tipp
.br
:ehp7.Sie koennen auch die linke Maustaste gedrueckt halten und Woerter
bilden, indem Sie :link reftype=hd refid=2.ziehen:elink. Sie die Maus ueber die gewuenschten Buchstaben&per.
:p.:hp7.Hinweis
.br
:ehp7.Die Systemtone koennen deaktiviert sein, wenn Sie DOS/Windows-Anwendungen
ausfuehren&per.
.br

:h1 id=2 res=3.Funktionen
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
:p.Das Spiel unterstuetzt die Erstellung eines Wortes durch Ziehen der Maus
bei gedrueckter linker Maustaste&per.
.br

.br
:link reftype=hd refid=1.Ton :elink.wird ueber die OS/2-Multimediaklassen bereitgestellt&per.
Sie koennen die Toene im Dialogfeld :link reftype=hd refid=1.Optionen:elink./Einstellungen ein- und
ausschalten&per.
.br

.br
Die Laenge jedes Timer-Ticks betraegt standardmaessig 1&per.5 Sekunden&per.
Sie koennen dies im Dialogfeld :link reftype=hd refid=1.Optionen:elink./Einstellungen aendern&per.
Nach hundert Timer-Intervallen ist das Spiel vorbei&per.
.br

:h1 id=3 res=4.Tasten und Mausaktionen
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp2.Linke Maustaste :ehp2. - zum Auswaehlen von Buchstaben auf dem Spielfeld&per.
:p.:hp2.Rechte Maustaste :ehp2. - zum Abschliessen eines Wortes&per.
:p.F1              Hilfemenu&per.
.br
F3              Spiel beenden&per.
.br
<Strg-N>        Neues Spiel&per.
.br
<Strg-Q>        Spiel stoppen&per.
.br
<Strg-P>        Spiel pausieren&per.
.br
<Strg-S>        Einstellungen Dialogfeld&per.
.br

:h1 id=4 res=5.Entwicklungsumgebung
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.System
.br
:ehp7.Das Boggle-Spiel wurde mit dem Open Watcom Compiler auf ArcaOS portiert&per.
Der urspruengliche Code wurde von David Boudah fuer IBM VisualAge C++
geschrieben und fuer die Kompatibilitaet mit Open Watcom nach C portiert&per.
:p.:hp7.Compiler
.br
:ehp7.Der verwendete Compiler ist Open Watcom C/C++ fuer OS/2&per.
:p.:hp7.Hilfesystem
.br
:ehp7.Das Hilfesystem wurde mit WIPFC erstellt, dem Open Watcom Hilfe-Compiler
fuer das OS/2 IPF-Format&per.
.br

:h1 id=5 res=6.Lizenz
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
Dieses Programm wird unter der GNU GPL v2 Lizenz verteilt&per.
:p.Urspruenglicher Code &colon. David Boudah (1996)
.br
Portierung auf Open Watcom &colon. OS2World (2026)
.br

:h1 id=6 res=7.Garantie
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Haftungsausschluss
.br
:ehp7.Diese Software wird ohne jegliche Garantie bezueglich Leistung oder
andere ausdrueckliche oder stillschweigende Garantien verkauft&per. Aufgrund
der vielen Hardware- und Softwareumgebungen, in denen dieses Programm
verwendet werden kann, wird keine Garantie der Eignung fuer einen bestimmten
Zweck angeboten&per. Der Benutzer muss das gesamte Risiko der Verwendung
des Programms uebernehmen&per.
.br
:euserdoc.
