## Adding the board to the Vivado repository

We will prefer `stv0g`'s repository..

Lack of spaces is important! In any **path**, try to ensure absence of **spaces**.

### Preferred method: Through the GUI

* Clone the repo:  $ git clone [https://github.com/stv0g/zturn-stuff.git](https://github.com/stv0g/zturn-stuff)
* Open the `Board Repository` through `Vivado:Tools/Settings/Tool_Settings/Vivado_Store/Board_Repository`:
![image](images/board_repos.gui.jpg "-image:Adding board repositories through the GUI-")
* Add the path to the root of the repository

### (Alternative method: (Probably) Temporary: Through the [TCL] command line)
* Enter `$ set_param board.repoPaths /path/to/stv0g\'s/zturn-stuff` at the TCL command line.

## Notes
More boards at [XilinxBoardStore](https://github.com/Xilinx/XilinxBoardStore/)
