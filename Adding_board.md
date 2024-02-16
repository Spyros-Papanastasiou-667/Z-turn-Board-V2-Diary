## Adding z-turn board to vivado:

### Primary through GUI
### Secondary/(tmp?) through TCL [command line]

* clone `stv0g`'s repository:
    * $ git clone [https://github.com/stv0g/zturn-stuff.git](https://github.com/stv0g/zturn-stuff)
* Inform Vivado of a new "board's definitions"'s location:
    * Through the TCL command line:
        * `$ set_param board.repoPaths /path/to/stv0g\'s/zturn-stuff`
            * WARN: Without spaces!
* ### Other boards:
    * $ git clone [https://github.com/Xilinx/XilinxBoardStore.git](https://github.com/Xilinx/XilinxBoardStore/)
    * (TCL command line):
        * `$ set_param board.repoPaths /path/to/XilinxBoardStore`
            * WARN: Without spaces!
* ### Notes:
    * Although these changes are not permanent, a new project defined on a new board, will retain the board configuration/files.
    * Alternatively, you can add them [(probably) permanently] through the GUI: ![image](.site/board_repos.gui.jpg "<image:Adding board repositories through the GUI>")
        * WARN: Without spaces!

## Go to: [README](README.md)