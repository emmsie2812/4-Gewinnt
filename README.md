# 4-Gewinnt
 C++ Projektarbeit von Nina Schmid und Emma Weiß
 
## Anleitung zu dem Spiel
Bis auf die "Nice-to-have" Anforderungen, dass die KI schlau ist, wurden alle Anforderungen, wie im Projektvorschlag dokumentiert, implementiert.

### Wie wird das Spiel gestartet? 
In dem Main Branch auf GitHub (https://github.com/emmsie2812/4-Gewinnt.git) befindet sich die aktuelle Version des Spiels.
Zum Bauen mithilfe des Makefiles folgenden Befehl ausführen: make
Das Spiel starten mit: ./4gewinnt

### Wie wird das Spiel gespielt?
1.    Im Startmenü zwischen folgenden Optionen auswählen: 
      * 1. Spiel in Level 1 starten 
      * 2. Gespeichertes Level aufrufen und starten
      * 3. Hilfe 
2.    Spiel wird gestartet (Bei Auswahl 1 und 2):
      'O' Benutzer; 'X' Computer/Gegenspieler
3.    Durch die Eingabe über die Tastatur kann entschieden werden, in welche Spalte der Stein gelegt wird
      Der Stein "fällt" an den untersten freien Platz der Spalte
4.    Abwechselndes Spielen mit dem Randomcomputer
5.    Weiterspielen, bis der Benutzer oder der Randomcomputer gewinnt 
6.    Nach Gewinn des Benutzers kann entschieden werden, ob das nächste Level gespielt werden soll oder das Spiel beendet werden soll
      Nach Gewinn des Randomcomputers kann entschieden werden, ob das Level erneut gespielt werden soll oder das Spiel beendet werden soll

### Spielregeln
Die Spieler setzen abwechselnd ihre Spielsteine durch Eingabe in das Feld. Das Feld besteht pro Level aus einer unterschiedlichen Anzahl an Spalten (senkrecht) und Reihen (waagerecht). Jeder Spieler besitzt eine Farbe an Spielsteinen. Wenn ein Spieler einen Spielstein in eine Spalte setzt, besetzt dieser den untersten freien Platz der Spalte. Gewinner ist der Spieler, der es als Erster schafft, vier oder mehr seiner Spielsteine senkrecht, waagerecht oder diagonal in eine Linie zu bringen.

### Benutzerfreundliche Spieleinstellungen
1. Wenn das Spielfeld so mit Spielsteinen belegt ist, sodass kein Gewinn mehr möglich ist, wird das Feld geleert und das Level von vorne gestartet.
2. Pro Level wird erklärt, wie viele Spalten und Reihen das Spielfeld hat und mit wie vielen Steinen das Level gewonnen werden kann.

## Hauptideen zur Implementierung
Zu Beginn wird ein Objekt vom Typ "Field" als zweidimensionales Array erzeugt. Dieses enthält alle wichtigen Daten zum Spielfeld, die "GameLogic" verarbeitet alle Ein- und Ausgaben und schaut, ob das Level von dem Benutzer gewonnen oder verloren wurde.

Über Objekte vom Typ "Level" werden die einzelnen Level mit Spalten, Reihen und Anzahl der Steine zu gewinnen definiert. Insgesamt werden 7 Levelmethoden definiert.

Das "StartGame" Objekt implementiert den Ablauf des Spieles und gibt diesen aus. 

Für die Anzeigen beim Starten des Spieles sowie bei einem Gewinn und Niederlage ist die Klasse Screen verantwortlich.