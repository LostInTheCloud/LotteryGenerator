# LotteryGenerator
### by lennihein

This lottery number generator is as universal as possible. Use the generic functions to build your own executable. EuroJackpot, Euromillion and 6aus49 have been implemented already.

### To compile and run:

requirements:

- cmake
- make
- sodium

on Arch:

```
sudo pacman -S cmake make libsodium
```

finally:

```bash
cmake .
make
./6aus49
```

### To add new games:

create a GAME_NAME.c file with the following contents:

```C
#include "lottolib.h"
int main()
{
    printf("GAME_NAME\n");
    def(MIN, MAX, #NUMBERS, MIN_BONUS, MAX_BONUS, #BONUS_NUMBERS);
}
```

Where:

- `GAME_NAME` is the name of the game, e.g. 'Eurojackpot'
- `MIN`, `MAX` and `#NUMBERS` are the minimum, maximum and number of numbers, e.g. 1,50 and 5 for 5 numbers between 1 and 50
- and `BONUS_*` are the modifiers for the additional number(s) working the same way as with the normal base numbers