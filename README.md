# FindMax

One criterion for fire insurance rates in a city is the maximum time it takes for a fire engine to reach the most distant location in that city. This project aims to calculate this criterion by analyzing the street layout of the city of Davis. The city has four fire stations, each located at an intersection.

## Problem Statement

The problem involves determining the maximum time it takes for a fire engine to reach the furthest location in the city based on the street layout. The city's streets are composed of street-blocks, each having two ends represented by global positioning coordinates (x, y). The goal is to find the optimal locations for the four fire stations at intersections to minimize the maximum response time.

## Approach

To solve this problem, the program takes a list of street-blocks' coordinates as input and calculates the maximum time it takes for a fire engine to reach the furthest location from each fire station. The algorithm involves the following steps:

1. Read and parse the list of street-blocks' coordinates.
2. Identify intersections where fire stations can be placed (four unique coordinates).
3. For each fire station, calculate the maximum response time to the furthest location using appropriate distance metrics (e.g., Euclidean distance).
4. Determine the overall maximum response time among the four stations.

## Usage

To use the program:

1. Provide a list of street-blocks' coordinates in the input format.
2. Run the program to calculate the maximum response time for each fire station.
3. Obtain the final maximum response time for the city.


