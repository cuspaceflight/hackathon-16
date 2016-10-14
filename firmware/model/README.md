# M3 Avionics Firmware Template

Copy this folder's contents to `m3bla/firmware` (including `.gitignore`), then:
1. Modify `Makefile` and set `PROJECT=m3bla` (adjust for your board name).
2. Modify `board.yaml` to reflect your PCB, leaving the current pins all in 
   place (but changing the board name)
3. Run gen-board.h (in shared/gen-board.h) to generate your board.h file
3. Write your code! Probably we'll have some shared libraries that you can link 
   against but at the moment they're not in place. You can add new files for 
   compilation to `CSRC` in `Makefile` after `main.c`.
