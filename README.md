# ConsoleScape
Text based game in which you try to escape the console you are playing it in

**Note:** The actions performed to win game are not intended to be technically accurate.

## How to play:
This is a command based game, use the following commands to navigate.
**Note:** all words are case sensitive.

### Commands:
- **go <direction>** goes to a specific direction.
- **grab <item>** grabs an item.
- **drop <item>** drops an item.
- **talk <npc>** talks to a npc (they give tips or funny responses).
- **inspect <target>** (no target means inspect room) inspect anything, some items might have useful descriptions.
- **items** shows your inventory
- **unlock <direction>** unlocks a door on the specified direction, they might need certain permissions or a password
- **use <item>** uses an item, many of them have no effect
- **surrender** leaves the game at any moment
- a couple secret and useless comamands included

## Spoiler: Game map & solution route:
  
![Game Map](https://github.com/Bernatmago/ConsoleScape/blob/master/game_map.PNG)
  
```
Booting up system!
Username: Bernat
Welcome Bernat, you can start writting commands (help to see commands)
grab cd
cd obtained!
use cd
You have gained the ability of changing directories!
go north
Current directory: root/home/Bernat
go east
Current directory: root/home/Bernat/music
inspect password.txt
Super secret password: 1234
go west
Current directory: root/home/Bernat
grab sudo
sudo obtained!
go west
Current directory: root/home/Bernat/pictures
grab forkbomb
forkbomb obtained!
go east
Current directory: root/home/Bernat
unlock north
Please input the correct password
1234
Correct password introduced
go north
Current directory: root/home
use sudo
[WARNING] Admin permissions have been granted, proceed with caution!
unlock north
Access permission granted!
go north
Current directory: root
use forkbomb
System destruction initialized, you have won the game!
Press ENTER to close the game
```
