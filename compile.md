### Cara Compile Game

* Windows
```console
:~$ cd Game
:~/Game$ gcc -o Chess Chess.c array.c board.c Commandmove.c Commandspecialmove.c leaderboard.c listlinier.c piece.c queue.c stack.c turn.c Undo.c
:~/Game$ Chess.exe
```

* Linux
```console
:~$ cd Game
:~/Game$ gcc -o ChessLinux ChessLinux.c array.c board.c Commandmove.c Commandspecialmove.c leaderboard.c listlinier.c piece.c queue.c stack.c turn.c Undo.c bufferscreen.c
:~/Game$ ./ChessLinux
```

### Cara Compile Driver
* Driver untuk Array
```console
:~$ cd Driver 
:~/Driver$ gcc -o arraydriver arraydriver.c ../Game/piece.c ../Game/listlinier.c ../Game/array.c ../Game/board.c
:~/Driver$ ./arraydriver
```

* Driver untuk Board
```console
:~$ cd Driver 
:~/Driver$ gcc -o boarddriver boarddriver.c ../Game/board.c ../Game/piece.c
:~/Driver$ ./boarddriver
```

* Driver untuk Leaderboard
```console
:~$ cd Driver 
:~/Driver$ gcc -o leaderboarddriver leaderboarddriver.c ../Game/leaderboard.c
:~/Driver$ ./leaderboarddriver
```

* Driver untuk List Linier
```console
:~$ cd Driver 
:~/Driver$ gcc -o listlinierdriver listlinierdriver.c ../Game/listlinier.c ../Game/board.c ../Game/piece.c
:~/Driver$ ./listlinierdriver
```