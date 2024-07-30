//! dan diker gula age jante hobe, to solve it
//$ wordSearch2 -> Trie -> Prefix Tree

// * A trie or a prefix tree is a particular kind of search tree, where nodes are usually keyed by strings. Tries can be used to implement data structures like sets and associative arrays, but they really shine when we need to perform an ordered traversal or to efficiently search for keys starting with a specific prefix

const board = [
	["A", "B", "C", "E"],
	["S", "F", "C", "S"],
	["A", "D", "E", "E"],
];

const print = () => {
	for (let i = 0; i < board.length; i++) {
		console.log(board[i]);
	}
};

var exist = function (board, word) {
	const m = board.length;
	const n = board[0].length;

	let dfs = (row, col, flag) => {
		print();
		// base true case
		if (flag >= word.length) return true;

		console.log(`flag = ${flag}`);

		// base false case
		if (
			row >= m ||
			col >= n ||
			row < 0 ||
			col < 0 ||
			board[row][col] !== word[flag]
		)
			return false;

		const backup = board[row][col];
		board[row][col] = "*";

		if (
			dfs(row + 1, col, flag + 1) ||
			dfs(row, col + 1, flag + 1) ||
			dfs(row - 1, col, flag + 1) ||
			dfs(row, col - 1, flag + 1)
		) {
			return true;
		}
		board[row][col] = backup;
		return false;
	};

	for (let i = 0; i < m; i++) {
		for (let j = 0; j < n; j++) {
			console.log(`i=${i}, j=${j}`);
			if (dfs(i, j, 0)) return true;
		}
	}

	return false;
};

console.log(exist(board, word));
