# Assassin's Creed Lag Fixer
Just a simple executable that does the work for you...

### Init
This tool just search for the string inside the binary file of Assassin's Creed 1 ( tested on Steam only ) and it cut it out off.

### How to use
Copy the executable file into the same folder as the executable of AC (You can go via Steam doing right click on the game -> Manage -> Browse Local Files). When you are here, just drag & drop on at time, the executables for Assassin's Creed (should be named AssassinsCreed_Dx9.exe and AssassinsCreed_Dx10.exe).

The tool will automatically create a bak file for your executable before doing the edit.

### How it works
It search for a specific string into the executable (**gconnect.ubi.com**) that is an unused Ubisoft server that did something for statistical analysis before, but now was shutted down.
It just zeroes out the bytes for this string, so the game doesn't try anymore to contact it.

### Credits:
Credits to [J3r0m3](https://www.nexusmods.com/assassinscreed/users/40473025) that posted other than the executable already edited, also the workaround to do.

You can find the original mod here:
[Assassin's Creed Lag Fix - No more lag or frame freezes](https://www.nexusmods.com/assassinscreed/mods/81)

© 2008 Ubisoft Entertainment. All Rights Reserved. Assassin’s Creed, Ubisoft, and the Ubisoft logo are trademarks of Ubisoft Entertainment in the US and/or other countries.
