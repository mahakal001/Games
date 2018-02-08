WHAT ? : The famous board game "The 8 Puzzle"

REQUIREMENTS: SFML LIBRARY + LINUX_X86_64 + C++ LIB

SURPRISE: The game will exit as soon as you got to the final state.
           The total move will be shown in the terminal.

 NOTE: In grid.cpp,Grid::init() ,The shuffle is off but can be swithcd on by uncommenting the following lines.
But in 8 puzzle there are two discrete sets of grid configuration.The configuration
in one grid set can only be change to the configuration in the same set.But here we have
hardcoded our final desired configuration
             1   2
        3    4   5
        6    7   8
Now the random shuffle may come out with an initial configuration which does not belong
to the same set from which above configuration belong.So does not matter how hard you try
you will not be able to achieve the goal state

In future update, the random shuffle will be allowed with a configuration_matcher ,such that only
that shuffled configuration will be allowed which match the goal configuraion.
