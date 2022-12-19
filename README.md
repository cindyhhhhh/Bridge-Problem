# Bridge-Problem


There is a mysterious country famous for nuts and pies. The land of this country is rectangular, and the lower-left and upper-right corners are at (0, 0) and (109, 109) on a two-dimensional coordinate system, respectively. In this country, each city is located at a point of integer coordinates, and a city located at (x,y) can produce x nuts and y pies per unit time. We say that the city has x nut-productivity and y pie-productivity.
The capital O, located at (0,0), has no productivity itself, but is a trading center. Now you are asked to select two cities A and B from N candidate cities, and build two bridges: one between A and O, and the other between B and O. Constructing the bridges requires cost, but the trade after completion can bring profits. The cost of constructing a bridge is equal to the square of the Euclidean distance between two ends of the bridge. After finishing building these two bridges, the total profit will be twice the product of A and B’s nut-productivity (2Ax · Bx) and pie-productivity (2Ay · By).
Given N candidate cities, please select two cities to build bridges in order to maximize the net revenue (that is, profits minus cost).


Input:
The first line of the input file contains an integer indicating N.
The i-th of the next N lines contains two integers xi,yi — the coordinates of the i-th city.
