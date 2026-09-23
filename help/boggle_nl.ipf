:userdoc.
:docprof toc=123456.
:title.Boggle Spel Help

:h1 id=0 res=1.Inleiding
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Inleiding
.br
:ehp7.Het Boggle computerspel is gebaseerd op het gelijknamige bordspel&per.
Het spel bestaat uit een spelbord, 16 dobbelstenen en een timer&per. Het doel
van het spel is om de dobbelstenen te gooien en zoveel mogelijk woorden te
vormen met de letters op de bovenkant van de dobbelstenen&per. De woorden moeten
minimaal drie letters lang zijn en de gebruikte letters moeten naast elkaar
liggen&per.
:p.Het computerspel heeft een ingebouwd woordenboek met 29956 woorden&per. Na
afloop van het spel kunt u :link reftype=hd refid=1.opties:elink./Vind alle kiezen en de computer
zal alle woorden die het vond op basis van dit woordenboek weergeven&per.
De woorden die u vond worden gemarkeerd in het lijstvak&per.
:p.:link reftype=hd refid=1.Geluid :elink.wordt geleverd via de OS/2 multimedia klassen&per.
:p.:hp7.Puntentelling
.br
:ehp7.De puntentelling is gebaseerd op het aantal letters in het gevormde woord&colon.
:p.   2 letters   = 1 Punt
.br
   3 letters   = 1 Punt
.br
   4 letters   = 1 Punt
.br
   5 letters   = 2 Punten
.br
   6 letters   = 3 Punten
.br
   7 letters   = 5 Punten
:p.   Meer dan 7 letters = 11 Punten&per.
.br

:h1 id=1 res=2.Het Spel Spelen
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Begin
.br
:ehp7.Om het spel te starten, klik op Spel/Nieuw&per. De timer begint het
voortgangsindicator onderaan het scherm te verplaatsen volgens het
timer-interval ingesteld in het opties/instellingen scherm&per. De standaard
is 1&per.5 seconden per timer-tick&per.
:p.Klik op een letter met de linkermuisknop en de letter wordt gemarkeerd en
gekopieerd naar het tekstveld voor het woord in uitvoering&per. Klik op
aangrenzende letters om woorden te vormen&per. Wanneer een volledig woord
is gevormd, klik met de rechtermuisknop&per.
:p.:hp7.Tip
.br
:ehp7.U kunt ook de linkermuisknop ingedrukt houden en woorden vormen door
:link reftype=hd refid=2.te slepen:elink. over de gewenste letters&per.
:p.:hp7.Opmerking
.br
:ehp7.De systeemgeluiden kunnen uitgeschakeld zijn als u DOS/Windows
applicaties gebruikt&per.
.br

:h1 id=2 res=3.Functies
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
:p.Het spel ondersteunt het vormen van woorden door de muis te slepen terwijl
de linkermuisknop ingedrukt is&per.
.br

.br
:link reftype=hd refid=1.Geluid :elink.wordt geleverd via de OS/2 multimedia klassen&per.
U kunt geluiden in- en uitschakelen via het dialoogvenster
:link reftype=hd refid=1.opties:elink./instellingen&per.
.br

.br
De lengte van elke timer-tick is standaard 1&per.5 seconden&per. U kunt dit
wijzigen in het dialoogvenster :link reftype=hd refid=1.opties:elink./instellingen&per.
Na honderd timer-intervallen is het spel voorbij&per.
.br

:h1 id=3 res=4.Toetsen en Muisacties
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp2.Linkermuisknop :ehp2. - om letters op het spelbord te selecteren&per.
:p.:hp2.Rechtermuisknop :ehp2. - om een woord te voltooien&per.
:p.F1              Help Menu&per.
.br
F3              Spel beeindigen&per.
.br
<Ctrl-N>        Nieuw Spel&per.
.br
<Ctrl-Q>        Spel stoppen&per.
.br
<Ctrl-P>        Spel pauzeren&per.
.br
<Ctrl-S>        Instellingen dialoogvenster&per.
.br

:h1 id=4 res=5.Ontwikkelomgeving
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Systeem
.br
:ehp7.Het Boggle spel is geporteerd naar ArcaOS met de Open Watcom compiler&per.
De originele code werd geschreven door David Boudah voor IBM VisualAge C++
en geporteerd naar gewone C voor compatibiliteit met Open Watcom&per.
:p.:hp7.Compiler
.br
:ehp7.De gebruikte compiler is Open Watcom C/C++ voor OS/2&per.
:p.:hp7.Help Systeem
.br
:ehp7.Het helpsysteem is gemaakt met WIPFC, de Open Watcom helpcompiler
voor het OS/2 IPF-formaat&per.
.br

:h1 id=5 res=6.Licentie
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
Dit programma wordt gedistribueerd onder de GNU GPL v2 Licentie&per.
:p.Originele code &colon. David Boudah (1996)
.br
Poort naar Open Watcom &colon. OS2World (2026)
.br

:h1 id=6 res=7.Garantie
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Disclaimer
.br
:ehp7.Deze software wordt geleverd zoals ze is, zonder enige garantie met
betrekking tot prestaties of andere garanties, uitdrukkelijk of impliciet&per.
Vanwege de vele hardware- en softwareomgevingen waarin dit programma
gebruikt kan worden, wordt geen garantie van geschiktheid voor een bepaald
doel aangeboden&per. De gebruiker draagt het volledige risico van het gebruik
van het programma&per.
.br
:euserdoc.
