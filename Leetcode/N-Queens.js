const n = 4;

const NQueens = () => {
	const board = new Array(n).fill(null);
	board.map(() => new Array(n).fill("."));

	const solve = (row, col) => {
		for (let j = 0; j < col; j++) {
			if (isSafe(board[row][j])) {
				board[row][j] = "Q";
				solve(row + 1, 0);
			} else solve(row, col + 1);
		}
	};
};
