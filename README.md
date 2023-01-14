# 4-Gewinnt

 C++ Projektarbeit von Nina Schmid und Emma Weiß
 
## Anleitung zu dem Spiel
### Wie wird das Spiel gestartet? 
In dem main branch auf GitHub befindet sich die aktuelle Version des Spiels.
Bauen mithilfe der Makefile: make
Starten mit: ./4gewinnt
### Wie wird das Spiel gespielt?
1.    Startmenü auswählen zwischen 
    * 1. Spiel starten 
    * 2. Gespeichertes Level aufrufen
    * 3. Hilfe 
2.    Spiel wird gestartet
3.    'O' User; 'X' Computer/Gegenspieler
3.    Durch die Tastatur Eingabe kann entschieden werden in welche Spalte der Stein gelegt 
      wird
4.    Abwechselndes Spielen mit dem Random Computer
5.    Weiterspielen, bis man gewinnt oder verliert 
6.    Nach Gewinn kann entschieden werden, ob weitergespielt wird oder zum nächsten Level 
      gegangen werden soll

### Spielregeln

Die Spieler setzen abwechselnd ihre Spielsteine durch Eingabe in das Feld. Das Feldbesteht pro Level aus einer unterschiedlichen Anzahl an Spalten (senkrecht) und Reihen (waagerecht). Jeder Spieler besitzt eine Farbe an Spielsteinen. Wenn ein Spieler einen Spielstein in eine Spalte setzt, besetzt dieser den untersten freien Platz der Spalte. Gewinner ist der Spieler, der es als erster schafft, vier oder mehr seiner Spielsteine waagerecht, senkrecht oder diagonal in eine Linie zu bringen.

Unsere Anpassungen der Regeln:
*    Bei gefüllten Feld wird das Feld geleert und fängt von vorne an.
*    Pro Level wird erklärt wie viele Spalten und Reihen das Spielfeld hat und mit wie 
     vielen Steinen gewonnen ist 
 
## Hauptideen zur Implementierung

Am Anfang wird ein Field Objekt erstellt als zweidimensionales Array. Dieses enthält alle wichtigen Daten zum Spielfeld, die GameLogic verarbeiet alle Ein- und Ausgaben und schaut ob gewonnen oder verloren ist.

Über Level Objekte werden die einzelne Level mit Spalten, Reihen und Anzahl der Chips zu gewinnen definiert. Insgesamt werden 7 Level Methoden definiert.

Das StartGame Objekt implementiert den Ablauf des Spieles und gibt diesen aus. 

Für die Anzeigen beim Starten des Spieles und bei Gewinnen und Verlieren ist die Screen Klasse verantwortlich.

Bis auf die Nice-to-have Anforderungen das die KI schlau ist, wurden alle Anforderungen, wie im Projektvorschlag dokumentiert, implementiert