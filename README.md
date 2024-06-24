# Connect4 🪙

## Table of contents 📑
- [Description](https://github.com/toro-nicolas/connect4/blob/main/README.md#description-)
- [Usage](https://github.com/toro-nicolas/connect4/blob/main/README.md#usage-%EF%B8%8F)
- [Result](https://github.com/toro-nicolas/connect4/blob/main/README.md#result-)
- [Compilation](https://github.com/toro-nicolas/connect4/blob/main/README.md#compilation-%EF%B8%8F)
- [Code mandatory](https://github.com/toro-nicolas/connect4/blob/main/README.md#code-mandatory-)
- [What's next ?](https://github.com/toro-nicolas/connect4/blob/main/README.md#whats-next--)
- [Contributors](https://github.com/toro-nicolas/connect4/blob/main/README.md#contributors-)


## Description 📝
The **Connect4** is a **personal project** I did on my own during a study break.  
Its purpose is to create in [**C**](https://en.wikipedia.org/wiki/C_(programming_language)) a **Connect4 game**.  
This project applies to the **EPITECH Duo Stumper**.


## Usage ⚔️
You can run the connect4 like this :
- Play in real time :
```sh
./connect4
```
- Play with prepared moves :
```sh
./connect4 < moves/win_vertical
```


## Result 🚩
The result of this project is a **perfect Connect4**.  
If you discover a **problem** or an **error**, don't hesitate to **create an issue** and **report it** to us as soon as possible.


### Tests and code coverage
**Unit tests** were performed using [criterion](https://criterion.readthedocs.io/en/master/intro.html).  
In this project, **only** the **library code is covered**.
Unit tests are still to be performed, but a large part of the code is already covered.

You can compile the project and run the unit tests with this command :
```sh
make tests_run
```


## Compilation 🛠️
You can compile the project with this command :
```sh
make
```

If you want clean the project, you can run this command :
```sh
make fclean
```

You can clean and compile the project with ```make re```.

You can compile the unit tests with this command :
```sh
make unit_tests
```


## Code mandatory 📦
- You'll need to create a branch where you'll push your code. Once you've completed your tasks on this branch, we'll work together to merge it and check that everything works.
- Every function you add must be code-style.
- Before merging, you'll need to check that all unit tests pass by running ```make tests_run```.
- Each commit will contain ```[+]``` or ```[-]``` or ```[~]``` followed by a message
    - ```[+]``` : Add feature
    - ```[-]``` : Delete feature
    - ```[~]``` : Edit feature

**Of course, in exceptional cases, we may depart from these rules.**


## What's next ? 🚀
- Add help section
- Add a graphical visualization
- Add github actions
- Add a documentation for each function
- Add unit tests on each piece of code


## Contributors 👤
This project was carried out alone by [**Nicolas TORO**](https://github.com/toro-nicolas).
