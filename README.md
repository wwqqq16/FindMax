# Fire Insurance Rates Calculation Program

This program calculates one criterion for fire insurance rates in a city: the maximum time it takes for a fire engine to reach the most distant location in that city. The city is divided into street blocks, and the program determines the optimal fire station locations based on street-block information.

## Specifications

1. The program is provided with a city file in `.txt` format.
2. The city file contains:
   - City size and the number of street-blocks.
   - Coordinates of the four fire stations.
   - Coordinates of the most distant location and time to reach it.
   - Details of each street-block (starting and ending coordinates, speed limit).
3. Speed limits are based on location relative to the center of the city.
4. Street-blocks are connected, running north-south or east-west.
5. The program calculates CPU time for the solution.

## Execution

1. Compile the program using the provided `Makefile`.
2. Run the program with the city file as a command line parameter.

## Coordinate System

- Each coordinate unit represents one-tenth of a mile.
- The coordinate system starts at [0,0] in the Northwest corner.

## Note

- Street-blocks may have extensions up to an additional 12 tenths.
- The program must consider travel in both directions for street-blocks.

