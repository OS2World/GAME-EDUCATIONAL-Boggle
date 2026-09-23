:userdoc.
:docprof toc=123456.
:title.Ayuda del Juego Boggle

:h1 id=0 res=1.Introduccion
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Introduccion
.br
:ehp7.El juego de computadora Boggle esta basado en el juego de mesa del mismo nombre&per.
El juego consiste en un tablero, 16 dados y un temporizador&per. El objetivo del juego es
tirar los dados y crear tantas palabras como sea posible usando las letras que aparecen
en la cara de los dados&per. Las palabras deben tener al menos tres letras y las letras
que se usen deben ser adyacentes entre si&per.
:p.El juego de computadora tiene un diccionario integrado con 29956 palabras&per. Despues
de que el juego termina, puede elegir :link reftype=hd refid=1.opciones:elink./Encontrar todas y la computadora
listara cada palabra que encontro basandose en este diccionario&per. Las palabras que
usted encontro se resaltan en el cuadro de lista de palabras&per.
:p.:link reftype=hd refid=1.El sonido :elink.se proporciona a traves de las clases multimedia de OS/2&per.
:p.:hp7.Puntuacion
.br
:ehp7.La puntuacion se basa en el numero de letras en la palabra formada como se muestra a continuacion&colon.
:p.   2 letras   = 1 Punto
.br
   3 letras   = 1 Punto
.br
   4 letras   = 1 Punto
.br
   5 letras   = 2 Puntos
.br
   6 letras   = 3 Puntos
.br
   7 letras   = 5 Puntos
:p.   Mas de 7 letras = 11 Puntos&per.
.br

:h1 id=1 res=2.Jugando
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Inicio
.br
:ehp7.Para comenzar el juego, haga clic en Juego/Nuevo&per. El temporizador comenzara a
mover el indicador de progreso en la parte inferior de la pantalla segun el intervalo
configurado en la pantalla de opciones/ajustes&per. El valor predeterminado es 1&per.5
segundos por tick del temporizador&per.
:p.Haga clic en una letra con el boton izquierdo del raton y la letra se resaltara y se
copiara al campo de texto de palabra en curso&per. Haga clic en letras adyacentes para
formar palabras&per. Cuando se forme una palabra completa, haga clic con el boton derecho
del raton&per. La palabra se validara contra el :link reftype=hd refid=0.diccionario:elink. y se determinara
la :link reftype=hd refid=0.puntuacion:elink.&per.
:p.:hp7.Consejo
.br
:ehp7.Tambien puede mantener presionado el boton izquierdo del raton y formar palabras
:link reftype=hd refid=2.arrastrando:elink. el raton sobre las letras deseadas&per. Si la palabra no es valida,
puede borrarla haciendo clic derecho en cualquier letra&per.
:p.:hp7.Nota
.br
:ehp7.Es posible que los sonidos del sistema esten desactivados si esta ejecutando
aplicaciones DOS/Windows&per.
.br

:h1 id=2 res=3.Caracteristicas
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
:p.El juego admite la creacion de una palabra arrastrando el raton mientras se mantiene
presionado el boton izquierdo&per. El programa esta configurado para que los bordes mas
externos se ignoren durante el modo de arrastre&per.
.br

.br
:link reftype=hd refid=1.El sonido :elink.se proporciona a traves de las clases multimedia de OS/2&per.
Puede activar y desactivar los sonidos seleccionando el cuadro de dialogo de
:link reftype=hd refid=1.opciones:elink./ajustes&per. Puede cambiar los sonidos sustituyendo sus archivos
&per.WAV favoritos&per.
.br

.br
La longitud de cada tick del temporizador es de 1&per.5 segundos por defecto&per. Puede
cambiarlo en el cuadro de dialogo de :link reftype=hd refid=1.opciones:elink./ajustes&per. Despues de cien
intervalos del temporizador, el juego termina&per.
.br

:h1 id=3 res=4.Teclado y Raton
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp2.Boton izquierdo del raton :ehp2. - usado para seleccionar letras en el tablero&per.
:p.:hp2.Boton derecho del raton :ehp2. - usado para completar una palabra&per.
:p.F1              Menu de Ayuda&per.
.br
F3              Finalizar el juego&per.
.br
<Ctrl-N>        Nuevo Juego&per.
.br
<Ctrl-Q>        Detener juego&per.
.br
<Ctrl-P>        Pausar juego&per.
.br
<Ctrl-S>        Cuadro de dialogo de Ajustes&per.
.br

:h1 id=4 res=5.Entorno de Desarrollo
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Sistema
.br
:ehp7.El juego Boggle fue portado a ArcaOS usando el compilador Open Watcom&per.
El codigo original fue escrito por David Boudah para IBM VisualAge C++ y
portado a C plano para ser compatible con Open Watcom&per.
:p.:hp7.Compilador
.br
:ehp7.El compilador utilizado es Open Watcom C/C++ para OS/2&per.
:p.:hp7.Sistema de Ayuda
.br
:ehp7.El sistema de ayuda fue creado usando WIPFC, el compilador de ayuda
de Open Watcom para el formato IPF de OS/2&per.
.br

:h1 id=5 res=6.Licencia
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
Este programa se distribuye bajo la Licencia GNU GPL v2&per.
:p.Codigo original &colon. David Boudah (1996)
.br
Puerto a Open Watcom &colon. OS2World (2026)
.br

:h1 id=6 res=7.Garantia
  :font facename='Courier' size=12x7.:color fc=default.:color bc=default.
.br
:hp7.Descargo de Responsabilidad
.br
:ehp7.Este software se vende tal como esta, sin ninguna garantia de
rendimiento ni otras garantias expresas o implicitas&per. Debido a los
muchos entornos de hardware y software en los que se puede usar este
programa, no se ofrece ninguna garantia de idoneidad para un proposito
particular&per. El usuario debe asumir todo el riesgo de uso del programa&per.
.br
:euserdoc.
