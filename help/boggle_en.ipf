:userdoc.
:docprof toc=123456.
:title.Boggle Game Help System

:h1 id=0 res=1.Introduction
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br 
:hp7.Introduction 
.br 
:ehp7.The Boggle computer game is based on the board game of the same name&per.  The 
game consists of a game board,  16 dice, and a timer&per.  The object of the game is 
to roll the dice and create as many words as possible using the letters that show 
up on the die face&per. The words have to be at least three letters in length and 
the letters that you use have to be adjacent to each other&per. 
:p.The computer game has a built in dictionary with 29956 words in it&per.  After 
the game has ended,  you may choose :link reftype=hd refid=1.options:elink./Find all and the computer will list 
every word that it found based on this dictionary&per.  The words that you found are 
hilighted in the word list list box as well&per. 
:p.:link reftype=hd refid=1.Sound :elink.is provided via the OS/2 multimedia classes&per.  You will notice 
different sounds are played when correct words are moved to the word list, words greater 
than four characters in length are formed,  incorrect words are formed,  and when the 
timer increments itself during game play&per. 
:p.:hp7.Scoring 
.br 
:ehp7.Scoring is based on number of letters in the formed word as shown below&colon. 
:p.   2 letters   = 1 Point 
.br 
   3 letters   = 1 Point 
.br 
   4 letters   = 1 Point 
.br 
   5 letters   = 2 Points 
.br 
   6 letters   = 3 Points 
.br 
   7 letters   = 5 Points 
:p.   Anything greater than 7 letters = 11 Points&per. 
:p.  
.br 
  
:h1 id=1 res=2.Playing the Game
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br 
:hp7.Starting Out 
.br 
:ehp7.To begin the game,  click on game/new&per.  The timer will begin moving the 
progress indicator along at the bottom of the screen according to the timer interval set 
in the options/settings screen&per.  The default is 1&per.5 seconds per timer tick
&per. 
:p.Click on a letter with the left mouse button and the letter will be hilighted 
and copied to the word in progress edit field&per.  Click on adjacent letters to 
form words in the word in progress edit field&per.  When a completed word is formed,  
click with the right mouse button&per.  The word will be validated against the :link reftype=hd refid=0.
dictionary :elink.and the :link reftype=hd refid=0.scoring :elink.will be determined&per.  If the word was valid,  it will be moved 
to the word list box on the right hand side of the screen&per. 
:p.:hp7.Tip 
.br 
:ehp7.You can also hold down the left mouse button and form words by :link reftype=hd refid=2.dragging :elink.the 
mouse over the desired letters&per.  If the word you form is not valid,  you can clear 
it and start again by right clicking on any of the letters&per. 
:p.:hp7.Note 
.br 
:ehp7.The system sounds might be disabled if you are currently running any DOS/Windows 
applications&per.  I found that on my machine if I simply closed the DOS-based application,  
the sound worked just fine&per.   
.br 
  
:h1 id=2 res=3.Features
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
:p.The game supports the creation of a word by dragging the mouse while the 
left mouse button is held down&per.  The program is configured so that the outermost 
edges are ignored during the drag mode process&per.  This makes it harder to select 
the wrong letter as the mouse must be closer to the center of the square for it to 
be selected 
.br 

.br 
:link reftype=hd refid=1.Sound :elink.is provided via the OS/2 multimedia classes&per.  You can turn the sounds 
on and off by selecting the :link reftype=hd refid=1.options:elink./settings dialog box&per.  You can even change 
the sounds by substituting your favorite &per.WAV files in place of the ones used 
by the system 
.br 

.br 
The length of each timer tick defaults to 1&per.5 seconds&per.  You can change 
this  in the :link reftype=hd refid=1.options:elink./settings dialog box to whatever value you like&per.  After one  
hundred timer intervals,  the game is over 
.br 
-During game play,  you can pause the current game,  resume it,  or stop the game 
in process 
.br 

.br 
-The computer game has a built in :link reftype=hd refid=0.dictionary :elink.with 29956 words in it&per.  After 
the game has ended,  you may choose :link reftype=hd refid=1.options:elink./Find all and the computer will list 
every word that it found based on this dictionary&per.  The words that you found are 
hilighted in the word list list box as well   
.br 
  
:h1 id=3 res=4.Keys and Mouse actions
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br 
:hp2.Left mouse button :ehp2.    - used to select letters on the game board&per.  Can also be 
used in :link reftype=hd refid=2.drag :elink.mode&per. 
:p.:hp2.Right mouse button :ehp2.   - used to complete a word&per. It will move the word from 
the word-in-progress box to the word list on the right side of the screen&per. 
:p.F1              Help Menu&per. 
.br 
F3              End the game&per. 
.br 
<Ctrl-N>        Game New&per. 
.br 
<Ctrl-Q>        Stop game&per. 
.br 
<Ctrl-P>        Pause game&per. 
.br 
<Ctrl-R>        Resume game&per. 
.br 
<Ctrl-F>        Find all possible words&per. 
.br 
<Ctrl-S>        Settings dialog box&per.   
.br 
  
:h1 id=4 res=5.Development Environment
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br 
:hp7.System 
.br 
:ehp7.The Boggle game was developed on a Dell XPS90 computer running OS/2 WARP Red 
Spline with no CSDs applied&per.  The :link reftype=hd refid=1.sound :elink.card in the development computer is a Media 
Vision Pro Audio 16&per.  The two lines in the config&per.sys for the sound 
configuration are as follows&colon. 
:p.DEVICE=f&colon.&bsl.MVPRODD&per.SYS /I&colon.11 /D&colon.6 /S&colon.1,220,1,5 
/N&colon.PAS161$ 
.br 
DEVICE=d&colon.&bsl.MMOS2&bsl.AUDIOVDD&per.SYS PAS161$ 
:p.The timestamp of the driver that I used in development is as follows&colon. 
:p.MVPRODD&per.SYS    59480  12-25-93   2&colon.04p 
:p.:hp7.Compiler 
.br 
:ehp7.The C++ compiler used is the IBM VisualAge C++ compiler with CSD level CTC301 
applied&per.  The class library component has no CSDs applied&per. 
:p.:hp7.Help System 
.br 
:ehp7.The help system was developed using the MAKEIPF help compiler developed by
&colon. 
:p. Dr&per. Martin Vieregg 
.br 
 Hubertusstr&per. 26 
.br 
 D-85521 Ottobrunn 
.br 
 Germany 
.br 
 Compuserve 100661,626   
.br 
  
:h1 id=5 res=6.Registration
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br 
This product is released as Shareware&per.  If you like the product,  please 
register with the author by sending $5&per.00 to&colon. 
:p.David Boudah 
.br 
180 Cottage Road 
.br 
Enfield, CT 06082 
.br 
Compuserve ID - 73163,3657 
.br 
InterNet - dboudah&atsign.ibm&per.net 
:p.:hp7.Note 
.br 
:ehp7.Supporting Shareware only encourages the author to continue to supply products 
into the market&per.   
.br 
  
:h1 id=6 res=7.Warranty
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br 
:hp7.Disclaimer 
.br 
:ehp7.This software is sold as is, without any warranty as to performance or any other 
warranties whether expressed or implied&per.  Because of the many hardware and software 
environments into which this program may be used, no warranty of fitness for a particular 
purpose is offered&per.  The user must assume the entire risk of using the program&per.  
Any liability of the seller will be limited exclusively to product replacement or 
the refund of the registration fee&per. 
.br 
:euserdoc.
