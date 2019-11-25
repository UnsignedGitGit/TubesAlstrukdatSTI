### Cara Compile Game

* Windows
```console
$ cd Game
$ gcc -o Chess Chess.c array.c board.c Commandmove.c Commandspecialmove.c leaderboard.c listlinier.c piece.c queue.c stack.c turn.c Undo.c
$ Chess.exe
```

* Linux
```console
$ cd Game
$ gcc -o ChessLinux ChessLinux.c array.c board.c Commandmove.c Commandspecialmove.c leaderboard.c listlinier.c piece.c queue.c stack.c turn.c Undo.c bufferscreen.c
$ ./ChessLinux
```

### Cara Compile Driver
* Driver untuk Array
```console
$ cd Driver 
$ gcc -o arraydriver arraydriver.c ../Game/piece.c ../Game/listlinier.c ../Game/array.c ../Game/board.c
$ ./arraydriver
```

* Driver untuk Board
```console
$ cd Driver 
$ gcc -o boarddriver boarddriver.c ../Game/board.c ../Game/piece.c
$ ./boarddriver
```

* Driver untuk Leaderboard
```console
$ cd Driver 
$ gcc -o leaderboarddriver leaderboarddriver.c ../Game/leaderboard.c
$ ./leaderboarddriver
```

* Driver untuk List Linier
```console
$ cd Driver 
$ gcc -o listlinierdriver listlinierdriver.c ../Game/listlinier.c ../Game/board.c ../Game/piece.c
$ ./listlinierdriver
```