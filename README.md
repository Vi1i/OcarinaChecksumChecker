# OcarinaChecksumChecker
Program to create correct Ocarina Of Time save file checksum

### Save Data Memory Offsets
| Debug E   	| NTSC 1.0 	| NTSC 1.1 	| NTSC 1.2 	| PAL 1.0 	| PAL 1.1 	|
|-----------	|----------	|----------	|----------	|---------	|---------	|
| 0x15E660  	| 0x11A5D0 	| 0x11A790 	| 0x11AC80 	| 0x1183D0	| 0x118410	|

This command has yet to have any safety implemented on it, so if anything other the `command file offset`, where *file* is the file to be calculated on and the *offset* is the hexadecimal offset from the above table, it could fail.

Example:
  `a.out memoryDump/memory.z64 11A790` should return `0x4DC5`
