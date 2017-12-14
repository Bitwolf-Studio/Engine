# Mitentwickeln
! __*Diese Datei wird laufend angepasst.*__

Wir versuchen folgende IDEs einzusetzen:
- Clion
- VisualStudio
- Qt Creator

Beim Stand vom 14. Dezember, haben wir leider noch probleme auf Windows zu kompilieren. (bzw. Die IDEs einzurichten)

# Build System
Wir verwenden CMake, dies ermöglicht es uns mit verschiedenen IDEs daran zu arbeiten.

# Ordner Struktur
Dies ist nur die Engine für das Spiel. 
Das eigentliche Spiel dass man mit der Engine entwickelt gehört in das `game`-Verzeichnis.
In dem Verzeichni legen ein kleines Beispiel ab.

Engine spezifischer Code gehört (wen möglich) in das `utils`-Verzeichnis.

## Game
Ein Spiel ist in verschiedenen Scenen unterteilt. 
(Wie in einem Theaterspiel. Für jede Umgebung eine eigene Scene.)

Ein Beispiel für eine Scene ist vielleicht das Haus des Protagonisten.
Eine Scene wird in einer Scenenkonfigurationsdatei deklariert.

Die Scene gehört in den Ordner `game/scenes/` und die Scenenkonfigurationen in den Ordner `game/scene_config/`.
Ein Beispiel für eine Scene liegt bereits in den jeweiligen Ordnern.

Die Scenenkonfiguration beinhaltet die Informationen über alle Objekte welche sich in der Scene befinden.
Zum Beispiel den Startpunkt des Spielers.

## Engine
Für Basisklassen verwenden wir den Ordner `utils/base/`.
Um mehrere Basisklassen zu gruppieren, welche einen starken Zusammenhang haben, 
können wir bei Bedarf Unterordner in `utils/base/` verwenden.

# Code-Konventionen
Wir arbeiten möglichst Objekt-Orientiert. 
Dies ermöglicht es eine saubere und übersichtliche Struktur zu bewahren.

## Klassen und Header-Dateien
Um zu verhindern dass Header-Dateien mehrmals eingelesen werden, verwendet man Compiler-Definitionen.
Der Name der Definition muss folgendem Standard entsprechen: 

`BITWOLF_ENGINE_{{name der Klasse}}_H` => `BITWOLF_ENGINE_SCENE_H`

Siehe [Scene.h](./utils/base/Scene.h).


## Kommentieren
Funktionen und Klassen müssen dokumentiert werden.
Ansonsten gilt: Da dokumentieren wo nötig; prich, wo es eine Erklärung braucht.

