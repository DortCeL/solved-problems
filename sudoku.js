/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


! I CAN'T SOLVE THIS
? link : https://leetcode.com/problems/sudoku-solver/description/

*/

const n = 9;

const board = [
	["5", "3", ".", ".", "7", ".", ".", ".", "."],
	["6", ".", ".", "1", "9", "5", ".", ".", "."],
	[".", "9", "8", ".", ".", ".", ".", "6", "."],
	["8", ".", ".", ".", "6", ".", ".", ".", "3"],
	["4", ".", ".", "8", ".", "3", ".", ".", "1"],
	["7", ".", ".", ".", "2", ".", ".", ".", "6"],
	[".", "6", ".", ".", ".", ".", "2", "8", "."],
	[".", ".", ".", "4", "1", "9", ".", ".", "5"],
	[".", ".", ".", ".", "8", ".", ".", "7", "9"],
];

const array = [];

// Create the 2D array with empty arrays
for (let i = 0; i < n; i++) {
	array[i] = [];
}

// Fill the 2D array with Sets
for (let i = 0; i < n; i++) {
	for (let j = 0; j < n; j++) {
		array[i][j] = new Set();
	}
}

console.log(array);

for (let i = 0; i < n; i++) {
	for (let j = 0; j < n; j++) {
		if (board[i][j] === ".") {
			for (let r = 0; r < n; r++) {
				if (board[r][j] != ".") array[i][j].add(board[r][j]);
			}

			for (let c = 0; c < n; c++) {
				if (board[i][c] != ".") array[i][j].add(board[i][c]);
			}
		}
	}
}

console.log(array);
